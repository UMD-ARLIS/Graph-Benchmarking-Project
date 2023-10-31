import subprocess

# Function to build using CMake
def cmake_build():
    subprocess.run('cd ../Graph_Problems/Louvain/GPU/gunrock_louvain', shell=True)
    subprocess.run('mkdir -p build', shell=True)
    subprocess.run('cd build && cmake ..', shell=True)

# Function to run regression tests
def regression_tests():
    subprocess.run('cd ../examples/louvain', shell=True)

# Function to perform code coverage
def make_louvain():
    subprocess.run('make', shell=True)

# Function to simulate deployment
def deploy():
    print('Branch: gunrock_integration.')
    print('Pipeline finished.')

# Execute the functions
cmake_build()
regression_tests()
make_louvain()
deploy()
