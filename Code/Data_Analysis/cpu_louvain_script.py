import subprocess
import pandas as pd
import os
import argparse
import matplotlib.pyplot as plt
import re


# Replace these values with EC2 instance details
EC2_INSTANCE_IP = "54.84.25.80"
EC2_INSTANCE_USERNAME = "ubuntu"
NANI_KEY_PAIR_PATH = "/Users/nani/Desktop/mnKeyPair.pem" ############# CHANGEME #############
BENCHMARK_OUTPUT_FILE = "benchmark_results.csv"


def convert_to_bin(filename):
    # Save the current working directory
    current_directory = os.getcwd()

    # Change directory to desired location (e.g., Desktop)
    os.chdir("/Users/nani/Desktop") ############# CHANGEME #############

    try:
        # Command to convert graph.txt to graph.bin
        command = f"ssh -i {NANI_KEY_PAIR_PATH} {EC2_INSTANCE_USERNAME}@{EC2_INSTANCE_IP} \
                   'cd louvain-generic && ./convert -i {filename}.txt -o {filename}.bin'"

        # Run the conversion command using subprocess
        subprocess.run(command, shell=True, check=True)

    finally:
        # Change back to the original working directory
        os.chdir(current_directory)


def run_cuda_benchmark(filename):
    # Save the current working directory
    current_directory = os.getcwd()

    # Change directory to desired location (e.g., Desktop)
    os.chdir("/Users/nani/Desktop") ############# CHANGEME #############

    try:
        # Convert graph.txt to graph.bin
        convert_to_bin(filename)

        # Command to execute CUDA code on the EC2 instance for timing information
        command = f"ssh -i {NANI_KEY_PAIR_PATH} {EC2_INSTANCE_USERNAME}@{EC2_INSTANCE_IP} \
                   'cd louvain-generic && ./louvain {filename}.bin -l -1 -v -q id_qual > {filename}.tree'"

        # Run the CUDA code using subprocess and capture the timing output
        timing_output = subprocess.check_output(command, shell=True, universal_newlines=True, stderr=subprocess.STDOUT)

        # Use regular expression to search for "Total duration" line and extract the value
        total_duration_ms = None
        match = re.search(r"Total duration \(ms\):\s+(\d+)", timing_output)
        if match:
            total_duration_ms = int(match.group(1))
        else:
            raise Exception("Total duration (ms) not found in the output.")

        # Command to execute CUDA code on the EC2 instance with Valgrind for memory information
        valgrind_command = f"ssh -i {NANI_KEY_PAIR_PATH} {EC2_INSTANCE_USERNAME}@{EC2_INSTANCE_IP} \
                            'cd louvain-generic && sudo valgrind --log-file=valgrind.out ./louvain {filename}.bin -l -1 -v -q id_qual; \
                            grep total valgrind.out | sed -E \"s/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\\1 allocs\\n\\2 frees\\n\\3 bytes allocated/\"'"

        # Run the CUDA code with Valgrind using subprocess and capture the Valgrind output
        valgrind_output = subprocess.check_output(valgrind_command, shell=True, universal_newlines=True, stderr=subprocess.STDOUT)

        # Use regular expressions to search for the values
        allocs_match = re.search(r"(\d+(,\d+)?) allocs", valgrind_output)
        frees_match = re.search(r"(\d+(,\d+)?) frees", valgrind_output)
        bytes_allocated_match = re.search(r"(\d+(,\d+)?) bytes allocated", valgrind_output)

        allocs = allocs_match.group(1) if allocs_match else None
        frees = frees_match.group(1) if frees_match else None
        bytes_allocated = bytes_allocated_match.group(1) if bytes_allocated_match else None

        # Return the benchmark results as a dictionary with lists
        benchmark_results = {
            "Dataset": [filename],
            "Total Duration (ms)": [total_duration_ms],
            "Allocs": [allocs],
            "Frees": [frees],
            "Bytes Allocated": [bytes_allocated]
        }

        return benchmark_results

    finally:
        # Change back to the original working directory
        os.chdir(current_directory)


def main():
    parser = argparse.ArgumentParser(description="CUDA Benchmark Script")
    parser.add_argument("dataset_name", help="Name of the dataset without extension (e.g., 'graph' for 'graph.txt')")
    args = parser.parse_args()

    dataset_name = args.dataset_name

    # Run the CUDA benchmark and get the results
    benchmark_results = run_cuda_benchmark(dataset_name)
    print(benchmark_results)  # Debug print to check the benchmark_results

    # Create a Pandas DataFrame from the results
    df = pd.DataFrame(benchmark_results)

    # Write the benchmark results to a CSV file
    df.to_csv(BENCHMARK_OUTPUT_FILE, index=False)

    print("Benchmarking results saved to", BENCHMARK_OUTPUT_FILE)


if __name__ == "__main__":
    main()
