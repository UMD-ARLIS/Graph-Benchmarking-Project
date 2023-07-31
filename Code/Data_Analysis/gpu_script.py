import subprocess
import pandas as pd
import os
import matplotlib.pyplot as plt
import argparse
import re

# Replace these values with EC2 instance details
EC2_INSTANCE_IP = "54.84.25.80"
EC2_INSTANCE_USERNAME = "ubuntu"
MN_KEY_PAIR_PATH = "/Users/nani/Desktop/mnKeyPair.pem" ############# CHANGEME #############
BENCHMARK_OUTPUT_FILE = "benchmark_results.csv"

def parse_arguments():
    parser = argparse.ArgumentParser(description="Run CUDA code and extract benchmarking data.")
    parser.add_argument("algorithm", type=str, choices=["louvain", "sm"], help="Type of algorithm")
    parser.add_argument("dataset_file", type=str, help="File name of the dataset")
    parser.add_argument("num_threads", type=str, choices=["sequential", "parallel"], help="Number of threads (sequential or parallel)")
    
    return parser.parse_args()

def run_cuda_benchmark(algorithm, dataset_file, num_threads):
    if algorithm == "louvain":
        if num_threads == "sequential":
            omp_threads = 1
        elif num_threads == "parallel":
            omp_threads = 32
        else:
            raise ValueError("Invalid number of threads. Use 'sequential' or 'parallel'.")

        # CUDA command for Louvain algorithm
        cuda_code_path = f"./gunrock/examples/louvain/bin/test_louvain_12.2_x86_64 --omp-threads={omp_threads} --iter-stats --pass-stats --advance-mode=ALL_EDGES --unify-segments=true --validation=each --num-runs=10 --graph-type=market --graph-file=gunrock/dataset/small/{dataset_file}"

    elif algorithm == "sm":
        if num_threads == "sequential":
            omp_threads = 1
        elif num_threads == "parallel":
            omp_threads = 32
        else:
            raise ValueError("Invalid number of threads. Use 'sequential' or 'parallel'.")

        # CUDA command for SM algorithm
        cuda_code_path = f"./gunrock/examples/sm/bin/test_sm_12.2_x86_64 --omp-threads={omp_threads} --pattern-graph-type=market --pattern-graph-file=gunrock/dataset/small/{dataset_file} --undirected=1 --pattern-undirected=1 --num-runs=1 --graph-type=market --graph-file=gunrock/dataset/small/{dataset_file}"

    else:
        raise ValueError("Invalid algorithm type. Use 'louvain' or 'sm'.")

    # Save the current working directory
    current_directory = os.getcwd()

    # Change directory to desired location (e.g., Desktop)
    os.chdir("/Users/nani/Desktop") ############# CHANGEME #############

    try:
        # Command to execute CUDA code on the EC2 instance and capture the output
        output = subprocess.check_output(f"ssh -i {MN_KEY_PAIR_PATH} {EC2_INSTANCE_USERNAME}@{EC2_INSTANCE_IP} '{cuda_code_path}'", shell=True, universal_newlines=True)

        # Run the CUDA code again with valgrind and capture the output
        valgrind_command = f"sudo valgrind --log-file=valgrind.out {cuda_code_path}"
        subprocess.check_call(f"ssh -i {MN_KEY_PAIR_PATH} {EC2_INSTANCE_USERNAME}@{EC2_INSTANCE_IP} '{valgrind_command}'", shell=True)

        # Transfer the valgrind.out file back to the local machine
        subprocess.check_call(f"scp -i {MN_KEY_PAIR_PATH} {EC2_INSTANCE_USERNAME}@{EC2_INSTANCE_IP}:valgrind.out ./valgrind.out", shell=True)

        # Process the output to extract memory metrics using grep and sed
        memory_output = subprocess.check_output("grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\\1 allocs\\n\\2 frees\\n\\3 bytes allocated/'", shell=True, universal_newlines=True)

        # Change back to the original working directory
        os.chdir(current_directory)

        # Process the output to extract timing metrics
        timing_data = {}
        for line in output.strip().split('\n'):
            if line.startswith(" avg. elapsed:"):
                timing_data["Average Elapsed Time (ms)"] = float(line.split(":")[1].strip().split()[0])
            elif line.startswith(" min. elapsed:"):
                timing_data["Minimum Elapsed Time (ms)"] = float(line.split(":")[1].strip().split()[0])
            elif line.startswith(" max. elapsed:"):
                timing_data["Maximum Elapsed Time (ms)"] = float(line.split(":")[1].strip().split()[0])
            elif line.startswith(" preprocess time:"):
                timing_data["Preprocess Time (ms)"] = float(line.split(":")[1].strip().split()[0])
            elif line.startswith(" postprocess time:"):
                timing_data["Postprocess Time (ms)"] = float(line.split(":")[1].strip().split()[0])
            elif line.startswith(" total time:"):
                timing_data["Total Time (ms)"] = float(line.split(":")[1].strip().split()[0])

        # Use regular expressions to extract allocs, frees, and bytes allocated
        allocs_match = re.search(r"(\d+(,\d+)?) allocs", memory_output)
        frees_match = re.search(r"(\d+(,\d+)?) frees", memory_output)
        bytes_allocated_match = re.search(r"(\d+(,\d+)?) bytes allocated", memory_output)

        allocs = int(allocs_match.group(1).replace(",", "")) if allocs_match else None
        frees = int(frees_match.group(1).replace(",", "")) if frees_match else None
        bytes_allocated = int(bytes_allocated_match.group(1).replace(",", "")) if bytes_allocated_match else None

        memory_data = {
            "Allocs": allocs,
            "Frees": frees,
            "Bytes Allocated": bytes_allocated
        }

        return timing_data, memory_data

    finally:
        # Remove the valgrind.out file from the EC2 instance
        subprocess.check_call(f"ssh -i {MN_KEY_PAIR_PATH} {EC2_INSTANCE_USERNAME}@{EC2_INSTANCE_IP} 'rm valgrind.out'", shell=True)

def main():
    # Parse command-line arguments
    args = parse_arguments()
    algorithm = args.algorithm
    dataset_file = args.dataset_file
    num_threads = args.num_threads

    # Run the CUDA benchmark and get the results
    timing_results, memory_results = run_cuda_benchmark(algorithm, dataset_file, num_threads)

    # Combine the timing and memory results into a single dictionary
    benchmark_results = {**timing_results, **memory_results}

    # Create a Pandas DataFrame from the results
    df = pd.DataFrame([benchmark_results])

    # Write the benchmark results to a CSV file
    df.to_csv(BENCHMARK_OUTPUT_FILE, index=False)

    print("Benchmarking results saved to", BENCHMARK_OUTPUT_FILE)

if __name__ == "__main__":
    main()

