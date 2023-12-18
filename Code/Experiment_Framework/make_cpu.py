import subprocess
import os
import sys
import argparse

def modify_makefile_nvcc_values(NVCC, NVCC_VERSION):
        #@vlad - Changing hard coded files to relative pathing
        with open(os.path.join("..","Graph_Problems","CommunityDetection","Louvian","CPU","vite_louvain","BaseMakefile.mk"), 'r') as file:
            filedata = file.read()

    # Replace NVCC and NVCC_VERSION values
        filedata = filedata.replace('NVCC = "/usr/local/cuda-12.2/bin/nvcc"', f'NVCC = "{NVCC}"')
        filedata = filedata.replace('NVCC_VERSION = 12.2', f'NVCC_VERSION = {NVCC_VERSION}')

        with open(os.path.join("..","Graph_Problems","CommunityDetection","Louvian","CPU","vite_louvain","BaseMakefile.mk"), 'w') as file:
            file.write(filedata)

# Function to build using CMake
def cmake_build():
    #@vlad - Updated to use relative pathing rather than hard-coding (note: need to tighten this up, doesn't work for direct and relative compilation)
    #Also - why do you need to pass it the CUDA version... this shouldnt' be touching the GPU...
    tgt_dir = os.path.join("..","..","Graph_Problems","CommunityDetection","Louvian","CPU","vite_louvain")
    subprocess.run(f'cd {tgt_dir} && mkdir -p build && cd build && cmake -D CUDA_TOOLKIT_ROOT_DIR=/usr/local/cuda-12.2 ..', shell=True, executable="/usr/bin/bash")
    print(os.getcwd())

# Function to make louvain tests
def louvain_test():
    #@vlad - Updated to use relative pathing rather than hard-coding
    tgt_dir = os.path.join("..","..","Graph_Problems","CommunityDetection","Louvian","CPU","vite_louvain")
    if os.name == 'posix':
        subprocess.run(f'cd {tgt_dir} && make clean && make', shell=True, executable="/usr/bin/bash")
    if os.name == 'nt':
        subprocess.run(f'cd {tgt_dir} && make clean && make', shell=True)

# Function to simulate deployment
def deploy():
    print('Branch: gunrock_integration.')
    print('Pipeline finished.')


# if len(sys.argv) > 1:
#     NVCC = sys.argv[1]
#     NVCC_VERSION = sys.argv[2]

def main():
    # parser = argparse.ArgumentParser(description="Build script for project")
    # parser.add_argument("--nvcc", help="Path to nvcc executable", default="/usr/local/cuda-12.2/bin/nvcc")
    # parser.add_argument("--nvcc_version", help="NVCC version", default="12.2")
    
    # args = parser.parse_args()

    # modify_makefile_nvcc_values(args.nvcc, args.nvcc_version)
    # cmake_build()
    louvain_test()
    deploy()

if __name__ == "__main__":
    main()
