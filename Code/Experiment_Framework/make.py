import subprocess

# Function to build using CMake
def cmake_build():
    subprocess.run('cd ../Graph_Problems/CommunityDetection/Louvian/GPU/gunrock_louvain && mkdir -p build && cd build && cmake ..', shell=True)

# Function to make louvain tests
def louvain_test():
    subprocess.run('cd ../Graph_Problems/CommunityDetection/Louvian/GPU/gunrock_louvain/examples/louvain && make', shell=True)

# Function to simulate deployment
def deploy():
    print('Branch: gunrock_integration.')
    print('Pipeline finished.')

# Execute the functions
cmake_build()
louvain_test()
deploy()
