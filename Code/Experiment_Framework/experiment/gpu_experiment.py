import os
from experiment.experiment import Experiment
import subprocess

class GPUExperiment(Experiment):
    def __init__(self, name: str, num_workers: int, algorithm: str, graph_file: str):
        super().__init__(name, algorithm, num_workers)
        self._graph_file = graph_file

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