import subprocess
import pandas as pd
import os
import matplotlib.pyplot as plt
import argparse
import re
import paramiko

def parse_arguments():
    parser = argparse.ArgumentParser(description="Run CUDA code and extract benchmarking data.")
    parser.add_argument("algorithm", type=str, choices=["louvain", "sm"], help="Type of algorithm")
    parser.add_argument("dataset_file", type=str, help="File name of the dataset")
    parser.add_argument("num_threads", type=str, choices=["sequential", "parallel"], help="Number of threads (sequential or parallel)")
    parser.add_argument("--ssh-key-path", type=str, required=True, help="Path to the SSH key file")
    parser.add_argument("--ec2-instance-ip", type=str, required=True, help="EC2 instance IP address")
    parser.add_argument("--ec2-instance-username", type=str, required=True, help="EC2 instance username")
    
    return parser.parse_args()

def run_cuda_remotely(algorithm, dataset_file, num_threads, ssh_key_path, ec2_instance_ip, ec2_instance_username):
    # Establish an SSH connection
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    ssh.connect(ec2_instance_ip, username=ec2_instance_username, key_filename=ssh_key_path)

    try:
        if algorithm == "louvain":
            if num_threads == "sequential":
                omp_threads = 1
            elif num_threads == "parallel":
                omp_threads = 32
            else:
                raise ValueError("Invalid number of threads. Use 'sequential' or 'parallel'.")
            cuda_code_path = f"./nanir/examples/louvain/bin/test_louvain_12.2_x86_64 --omp-threads={omp_threads} --iter-stats --pass-stats --advance-mode=ALL_EDGES --unify-segments=true --validation=each --num-runs=10 --graph-type=market --graph-file=nanir/dataset/small/{dataset_file}"
        # CUDA command for Louvain algorithm
        # cuda_code_path = f"./gunrock/examples/louvain/bin/test_louvain_12.2_x86_64 --omp-threads={omp_threads} --iter-stats --pass-stats --advance-mode=ALL_EDGES --unify-segments=true --validation=each --num-runs=10 --graph-type=market --graph-file=gunrock/dataset/small/{dataset_file}"
        # REVISED CODE PATH WITH WORKING GUNROCK IMPLEMENTATION
                
        elif algorithm == "sm":
            if num_threads == "sequential":
                omp_threads = 1
            elif num_threads == "parallel":
                omp_threads = 32
            else:
                raise ValueError("Invalid number of threads. Use 'sequential' or 'parallel'.")

        # CUDA command for SM algorithm
        # cuda_code_path = f"./nanir/gunrock/examples/sm/bin/test_sm_12.2_x86_64 --omp-threads={omp_threads} --pattern-graph-type=market --pattern-graph-file=gunrock/dataset/small/{dataset_file} --undirected=1 --pattern-undirected=1 --num-runs=1 --graph-type=market --graph-file=gunrock/dataset/small/{dataset_file}"
        # REVISED CODE PATH WITH WORKING GUNROCK IMPLEMENTATION
            cuda_code_path = f"./nanir/examples/sm/bin/test_sm_12.2_x86_64 --omp-threads={omp_threads} --pattern-graph-type=market --pattern-graph-file=gunrock/dataset/small/{dataset_file} --undirected=1 --pattern-undirected=1 --num-runs=1 --graph-type=market --graph-file=nanir/dataset/small/{dataset_file}"
        else:
            raise ValueError("Invalid algorithm type. Use 'louvain' or 'sm'.")

        # Run the CUDA code remotely
        stdin, stdout, stderr = ssh.exec_command(cuda_code_path)

        # Print the remote command's output
        print(stdout.read().decode())
        print(stderr.read().decode())

        # Run Valgrind remotely
        """ valgrind_command = f"sudo valgrind --log-file=valgrind.out {cuda_code_path}"
        stdin, stdout, stderr = ssh.exec_command(valgrind_command)

        # Print the Valgrind command's output
        print(stdout.read().decode())
        print(stderr.read().decode())

        # Transfer the valgrind.out file back to the local machine
        subprocess.check_call(f"scp -i {ssh_key_path} {ec2_instance_username}@{ec2_instance_ip}:valgrind.out ./valgrind.out", shell=True)

        # Process the output to extract memory metrics using grep and sed
        memory_output = subprocess.check_output("grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\\1 allocs\\n\\2 frees\\n\\3 bytes allocated/'", shell=True, universal_newlines=True)
        print(memory_output) """

        # Close the SSH connection
        ssh.close()

    except Exception as e:
        print("Error:", str(e))
        ssh.close()

def main():
    # Parse command-line arguments
    args = parse_arguments()
    algorithm = args.algorithm
    dataset_file = args.dataset_file
    num_threads = args.num_threads
    ssh_key_path = args.ssh_key_path
    ec2_instance_ip = args.ec2_instance_ip
    ec2_instance_username = args.ec2_instance_username

    # Run the CUDA benchmark remotely
    run_cuda_remotely(algorithm, dataset_file, num_threads, ssh_key_path, ec2_instance_ip, ec2_instance_username)


    
if __name__ == "__main__":
    main()
