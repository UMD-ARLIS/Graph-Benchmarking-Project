import os
from experiment import Experiment
import subprocess

# add functionality to activate virtual environment
class CPUExperiment(Experiment):
    def __init__(self, name: str, num_workers: int, algorithm: str, graph_file: str):
        super().__init__(name, algorithm, num_workers)
        self._graph_file = graph_file

    def compile_code(self):
        make_file_path = "/home/test-gunrock/Graph-Benchmarking-Project/Code/Experiment_Framework/make_cpu.py"

        """ if os.path.isfile(self._graph_file):
            self.load_graph(self._graph_file) """

        # Compile the code using make.py script with parameters
        subprocess.run(f"sudo python {make_file_path}", shell=True)

    def bin_convert(self, dataset_path):
        # In our case, dataset_path="/home/test-gunrock/Graph-Benchmarking-Project/Data_Analysis/chesapeake.txt"
        # General case, dataset_path="home/test-gunrock/Graph-Benchmarking-Project/.../<prefix>.txt"
        base = os.path.basename(dataset_path) # "<prefix>.txt" or "chesapeake.txt"
        prefix,postfix = os.path.splitext() # "<prefix>" or "chesapeake"

        # How would I define the arguments acording to the postfix (.txt or whatever)?
        command = f"bin/./fileConvert -s -z -w -f {base} -o {prefix}.bin"

        subprocess.run(command, shell=True)

    def run_command(self, dataset_path, num_workers, algorithm):
        # louvain_executable = f"./examples/{algorithm}/bin/test_{algorithm}_{nvcc_version}_x86_64"
        # command = f"{louvain_executable} --omp-threads={num_workers} --iter-stats --pass-stats " \
        #           f"--advance-mode=ALL_EDGES --unify-segments=true --validation=each " \
        #           f"--num-runs=10 --graph-type=market --graph-file=dataset/small/chesapeake.mtx"
        # make sure to update the dataset path to come from github directly

        base = os.path.basename(dataset_path) # "<prefix>.txt" or "chesapeake.txt"
        prefix,postfix = os.path.splitext() # "<prefix>" or "chesapeake"

        # How would I define the arguments acording to the user preferences?
        command = "mpiexec -n {num_workers} ./bin/./graphClustering -f {prefix}.bin"

        # Store the current directory
        current_directory = os.getcwd()

        try:
            # Change directory to the desired location
            os.chdir("/home/test-gunrock/Graph-Benchmarking-Project/Code/Graph_Problems/CommunityDetection/Louvian/CPU/vite_louvain")

            subprocess.run(command, shell=True)

        finally:
            # Change back to the original directory
            os.chdir(current_directory)

    def run_experiment(self):
        self.compile_code()
        self.bin_convert(self._graph_file)
        self.run_command(self._graph_file, self._num_workers, self._algorithm)

if __name__ == "__main__":
    # Create an instance of CPUExperiment
    cpu_exp = CPUExperiment(name="cpu001", algorithm="louvain", num_workers=16, graph_file="/home/test-gunrock/Graph-Benchmarking-Project/Data_Analysis/chesapeake.txt")
    # nvcc_path = "/usr/local/cuda-12.2/bin/nvcc"  # Set your NVCC path
    # nvcc_version = "12.2"  # Set your NVCC version

    cpu_exp.run_experiment()
