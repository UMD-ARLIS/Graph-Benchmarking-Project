#~/Code/Experiment_Framework/experiment/experiment.py

#Core Imports
import sys
import os
from datetime import datetime
import json

#Library Imports
import networkx as nx


#User File Imports


#Global Constants:

#Global Variables:

#Classes

class Experiment():
    def __init__(self, name:str, algorithm:str, num_workers:int=1):
        
        #User params
        self._name = name
        self._algorithm = algorithm
        self._num_workers = num_workers
        self._graph_file = None
        self._graph = nx.Graph()
        self._graph_summary = {}
        self._os_detail = {}
        self._timings = {"experiment_created": datetime.now(),
                            "experiment_start":None,
                            "metadata_dumped":None,
                            "etl_start":None,
                            "etl_end":None,
                            "test_start":None,
                            "test_end":None,
                            "results_dumped":None,
                            "experiment_end":None}
        
        #Default (update with 'set' methods)
        self._data_directory = os.path.join(os.getcwd(),"..","..","..","Data")
        self._results_directory = os.path.join(os.getcwd(),"..","..","..","Experiment_Results")
        self._experiment_directory = os.path.join(self._results_directory,self._name)

    def get_name(self)->str:
        return(self._name)
    
    def set_name(self, name:str)->None:
        self._name = name

    def get_algorithm(self)->str:
        return(self._algorithm)
    
    def set_algorithm(self, algorithm:str)->None:
        self._algorithm = algorithm

    def get_data_directory(self)->str:
        return self._data_directory

    def set_data_directory(self, data_directory:str)->None:
        self._data_directory = data_directory

    def get_results_directory(self)->str:
        return self._results_directory

    def set_results_directory(self, results_directory:str)->None:
        self._results_directory = results_directory

    def get_num_workers(self)->int:
        return(self._num_workers)
    
    def set_num_workers(self, num_workers:int)->None:
        self._num_workers = num_workers

    def get_os_detail(self)->dict:
        os_detail = os.uname()
        self._os_detail['sysname'] = os_detail.sysname
        self._os_detail['nodename'] = os_detail.nodename
        self._os_detail['release'] = os_detail.release
        self._os_detail['version'] = os_detail.version
        self._os_detail['machine'] = os_detail.machine
        self._os_detail['cpu_count'] = os.cpu_count()
        
        process = os.popen("sysctl -n hw.memsize")
        self._os_detail['total_memory_bytes'] = process.read().strip()

        process.close()
        del(os_detail)
        return self._os_detail
    
    def get_timings(self)->dict:
        return(self._timings)

    def load_graph(self, graph_file:str)->None:
        #Assumes an undirected, unlabelled graph
        self._timings['etl_start'] = datetime.now()
        assert os.path.isfile(graph_file)
        self._graph_file = graph_file
        with open(graph_file, 'r') as in_graph:
            edges = in_graph.readlines()
            for edge in edges:
                edge=edge.strip()
                src, dst = edge.split(",")
                self._graph.add_edge(src,dst)
        self._timings['etl_end'] = datetime.now()
        
    def get_graph_summary(self):
        assert self._graph is not None 
        self._graph_summary["bytes_on_disk"] = os.path.getsize(self._graph_file)
        self._graph_summary["node_count"] = self._graph.number_of_nodes()
        self._graph_summary["edge_count"] = self._graph.number_of_edges()
        self._graph_summary["bytes_in_memory"] = sys.getsizeof(self._graph)

        deg = nx.degree(self._graph)        
        total_degree = 0
        for node in deg:
            total_degree += node[1]
        self._graph_summary["mean_degree"] = total_degree/(len(deg))
        
        del(deg)
        del(total_degree)
        
        return self._graph_summary
    
    def dump_experiment_metadata(self)->None:

        experiment_metadata = {"name":self.get_name(),
                               "system_information":self._os_detail,
                               "dataset_information":{"source_file":self._graph_file,
                                                      "graph_summary":self._graph_summary},
                                "experiment_information":{"algorithm":self.get_algorithm(),
                                                         "num_workers":self.get_num_workers()},
                                }

        if os.path.isdir(self._results_directory) == False:
            os.makedirs(self._results_directory)
        
        if os.path.isdir(self._experiment_directory) == False:
            os.makedirs(self._experiment_directory)

        assert os.path.isdir(self._results_directory)
        assert os.path.isdir(self._experiment_directory)

        with open(os.path.join(self._experiment_directory, "metadata.json"), 'w') as out_file:
            json.dump(experiment_metadata, out_file, indent=2)
        
        self._timings['metadata_dumped'] = datetime.now()

#Main Method