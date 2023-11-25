import os
<<<<<<< HEAD
from experiment import Experiment
import subprocess

# add functionality to activate virtual environment
=======
from experiment.experiment import Experiment
import subprocess

>>>>>>> e84f05e (added gpu_experiment.py which creates an experiment and compiles code)
class GPUExperiment(Experiment):
    def __init__(self, name: str, num_workers: int, algorithm: str, graph_file: str):
        super().__init__(name, algorithm, num_workers)
        self._graph_file = graph_file

<<<<<<< HEAD
    def compile_code(self, nvcc_path, nvcc_version):
        make_file_path = "/home/test-gunrock/Graph-Benchmarking-Project/Code/Experiment_Framework/make.py"

        """ if os.path.isfile(self._graph_file):
            self.load_graph(self._graph_file) """

        # Compile the code using make.py script with parameters
        subprocess.run(f"sudo python {make_file_path} --nvcc {nvcc_path} --nvcc_version {nvcc_version}", shell=True)

    def run_command(self, nvcc_version, dataset_path, num_workers, algorithm):
        louvain_executable = f"./examples/{algorithm}/bin/test_{algorithm}_{nvcc_version}_x86_64"
        command = f"{louvain_executable} --omp-threads={num_workers} --iter-stats --pass-stats " \
                  f"--advance-mode=ALL_EDGES --unify-segments=true --validation=each " \
                  f"--num-runs=10 --graph-type=market --graph-file=dataset/small/chesapeake.mtx"
        # make sure to update the dataset path to come from github directly

        # Store the current directory
        current_directory = os.getcwd()

        try:
            # Change directory to the desired location
            os.chdir("/home/test-gunrock/Graph-Benchmarking-Project/Code/Graph_Problems/CommunityDetection/Louvian/GPU/gunrock_louvain")

            subprocess.run(command, shell=True)

        finally:
            # Change back to the original directory
            os.chdir(current_directory)

    def run_experiment(self, nvcc_path, nvcc_version):
        self.compile_code(nvcc_path, nvcc_version)
        self.run_command(nvcc_version, self._graph_file, self._num_workers, self._algorithm)

if __name__ == "__main__":
    # Create an instance of GPUExperiment
    gpu_exp = GPUExperiment(name="gpu001", algorithm="louvain", num_workers=32, graph_file="/home/test-gunrock/Graph-Benchmarking-Project/Data/community_detection/SMALL_chesapeake.mtx")
    nvcc_path = "/usr/local/cuda-12.2/bin/nvcc"  # Set your NVCC path
    nvcc_version = "12.2"  # Set your NVCC version

    gpu_exp.run_experiment(nvcc_path, nvcc_version)
=======
    def compile_code(self):
        make_file_path = "../make.py"

        if os.path.isfile(self._graph_file):
            self.load_graph(self._graph_file)

        self.dump_experiment_metadata()

        # Assuming you want to run make.py for compilation
        subprocess.run(f"python {make_file_path}", shell=True)

if __name__ == "__main__":
    # Create an instance of GPUExperiment
    gpu_exp = GPUExperiment(name="gpu001", algorithm="Louvain", num_workers=1, graph_file="Data/community_detection/SMALL_chesapeake.mtx")
    gpu_exp.compile_code()
    # execute rest of processes
>>>>>>> e84f05e (added gpu_experiment.py which creates an experiment and compiles code)
