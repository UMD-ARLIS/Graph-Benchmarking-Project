import subprocess
import json
import re
import argparse

def extract_timing_data(output, algorithm, dataset_file, num_threads):
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
    
    timing_data["Algorithm"] = algorithm
    timing_data["Dataset File"] = dataset_file
    timing_data["Mode"] = num_threads
    
    return timing_data

def main():
    # Parse command-line arguments
    parser = argparse.ArgumentParser(description="Run CUDA code and extract benchmarking data.")
    parser.add_argument("algorithm", type=str, choices=["louvain", "sm"], help="Type of algorithm")
    parser.add_argument("dataset_file", type=str, help="File name of the dataset")
    parser.add_argument("num_threads", type=str, choices=["sequential", "parallel"], help="Number of threads (sequential or parallel)")
    parser.add_argument("--ssh-key-path", type=str, required=True, help="Path to the SSH key file")
    parser.add_argument("--ec2-instance-ip", type=str, required=True, help="EC2 instance IP address")
    parser.add_argument("--ec2-instance-username", type=str, required=True, help="EC2 instance username")
    args = parser.parse_args()

    try:
        # Execute the original script with the parameters from command-line arguments
        command = [
            "python3",
            "updated_gpu_script.py",
            args.algorithm,
            args.dataset_file,
            args.num_threads,
            "--ssh-key-path",
            args.ssh_key_path,
            "--ec2-instance-ip",
            args.ec2_instance_ip,
            "--ec2-instance-username",
            args.ec2_instance_username
        ]

        completed_process = subprocess.run(
            command,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True
        )

        # Extract timing data from the output
        timing_data = extract_timing_data(completed_process.stdout, args.algorithm, args.dataset_file, args.num_threads)

        # Output the timing data in JSON format
        with open("timing_metrics.json", "w") as json_file:
            json.dump(timing_data, json_file, indent=4)

        print("Timing data saved to timing_metrics.json")
    except subprocess.CalledProcessError as e:
        print(f"Error executing the script: {e}")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
