import subprocess
import os
import sys
import argparse

def modify_makefile_nvcc_values(NVCC, NVCC_VERSION):
        with open('/home/test-gunrock/Graph-Benchmarking-Project/Code/Graph_Problems/CommunityDetection/Louvian/GPU/gunrock_louvain/examples/BaseMakefile.mk', 'r') as file:
            filedata = file.read()

    # Replace NVCC and NVCC_VERSION values
        filedata = filedata.replace('NVCC = "/usr/local/cuda-12.2/bin/nvcc"', f'NVCC = "{NVCC}"')
        filedata = filedata.replace('NVCC_VERSION = 12.2', f'NVCC_VERSION = {NVCC_VERSION}')

        with open('/home/test-gunrock/Graph-Benchmarking-Project/Code/Graph_Problems/CommunityDetection/Louvian/GPU/gunrock_louvain/examples/BaseMakefile.mk', 'w') as file:
            file.write(filedata)

# Function to build using CMake
def cmake_build():
    subprocess.run('cd /home/test-gunrock/Graph-Benchmarking-Project/Code/Graph_Problems/CommunityDetection/Louvian/GPU/gunrock_louvain && mkdir -p build && cd build && cmake -D CUDA_TOOLKIT_ROOT_DIR=/usr/local/cuda-12.2 ..', shell=True, executable="/usr/bin/bash")
    print(os.getcwd())

# Function to make louvain tests
def louvain_test():
    subprocess.run('cd /home/test-gunrock/Graph-Benchmarking-Project/Code/Graph_Problems/CommunityDetection/Louvian/GPU/gunrock_louvain/examples/louvain && make clean && make', shell=True, executable="/usr/bin/bash")

# Function to simulate deployment
def deploy():
    print('Branch: gunrock_integration.')
    print('Pipeline finished.')


if len(sys.argv) > 1:
    NVCC = sys.argv[1]
    NVCC_VERSION = sys.argv[2]

def main():
    parser = argparse.ArgumentParser(description="Build script for project")
    parser.add_argument("--nvcc", help="Path to nvcc executable", default="/usr/local/cuda-12.2/bin/nvcc")
    parser.add_argument("--nvcc_version", help="NVCC version", default="12.2")
    
    args = parser.parse_args()

    modify_makefile_nvcc_values(args.nvcc, args.nvcc_version)
    cmake_build()
    louvain_test()
    deploy()

if __name__ == "__main__":
    main()
