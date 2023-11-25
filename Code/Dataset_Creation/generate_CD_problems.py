#Author: Kent O'Sullivan // osullik@umd.edu

#Core Imports
import json
import argparse
import os

#Library Imports
import networkx as nx
import pygraphviz
import matplotlib.pyplot as plt
from networkx.generators.community import LFR_benchmark_graph
from networkx.readwrite import json_graph

#User Imports


#Functions

#ANSI Escapes for pretty printing
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

class LFR_generator():
    def __init__(self, n, tau1, tau2, mu, k, min_community, seed, dataset_number):
        self._n = n
        self._tau1 = tau1
        self._tau2 = tau2
        self._mu = mu
        self._k = k
        self._min_community = min_community
        self._seed = seed
        self._dataset_number = dataset_number
        self._G = None

        self._output_dir = os.path.join("..","..","Data","community_detection","gclr")
        if not os.path.exists(self._output_dir):
            print(f"{bcolors.WARNING}\t WARNING: Output Directory Not Found... Creating...{bcolors.ENDC}")
            try:
                os.makedirs(self._output_dir)
                print(f"{bcolors.OKGREEN}\t SUCCESS{bcolors.ENDC}")
            except:
                print(f"{bcolors.FAIL}\t FAILED{bcolors.ENDC}")


    def generate_dataset(self):
        self._G = LFR_benchmark_graph(n=self._n, 
                            tau1=self._tau1, 
                            tau2=self._tau2, 
                            mu=self._mu, 
                            average_degree=self._k, 
                            min_community=self._min_community, 
                            seed=self._seed
                            )
    
        print(self._G)

        

        #Get the communities
        communities = {frozenset(self._G.nodes[v]["community"]) for v in self._G}

        print("Generated {com} communities".format(com=len(communities)))

        #Dump the file, transforming sets into json serializable lists. 
        data = json_graph.adjacency_data(self._G)

        print("Writing Json...")
        try:
            with open(os.path.join(self._output_dir,"CD_DATASET_{num}.json".format(num=self._dataset_number)),"w") as f:
                json.dump(data,f, default=set_default)
                print(f"{bcolors.OKGREEN}\t SUCCESS{bcolors.ENDC}")
        except:
            print(f"{bcolors.FAIL}\t FAILED{bcolors.ENDC}")


        print("Writing adj list...")
        try:
            nx.write_adjlist(self._G, os.path.join(self._output_dir,"CD_DATASET_{num}.txt".format(num=self._dataset_number)), delimiter=",")
            print(f"{bcolors.OKGREEN}\t SUCCESS{bcolors.ENDC}")
        except:
            print(f"{bcolors.FAIL}\t FAILED{bcolors.ENDC}")


#Turns sets into lists
def set_default(obj):
    if isinstance(obj, set):
        return list(obj)
    raise TypeError


argparser = argparse.ArgumentParser()

argparser.add_argument("--n",
                       help="number of nodes", 
                       required=False,
                       type=int,
                       default=250)

argparser.add_argument("--tau1",
                       help="exponent for degree distribution", 
                       required=False,
                       type=float,
                       default=3.0)

argparser.add_argument("--tau2",
                       help="exponent for community size distribution", 
                       required=False,
                       type=float,
                       default=1.5)

argparser.add_argument("--mu",
                       help="mixing factor", 
                       required=False,
                       type=float,
                       default=0.1)

argparser.add_argument("--k",
                       help="average degree", 
                       required=False,
                       type=float,
                       default=5.0)

argparser.add_argument("--min_community",
                       help="minimum size to form a community", 
                       required=False,
                       type=int,
                       default=20)

argparser.add_argument("--seed",
                       help="random seed for generation", 
                       required=False,
                       type=int,
                       default=10)

argparser.add_argument("--dataset_number",
                        help="identifying number for the dataset",
                        required=True,
                        type=str,
                        default="000")

if __name__ == "__main__":
    flags = argparser.parse_args()
    print(flags)
    #Create a graph
    
    LFRG = LFR_generator(n=flags.n, 
                            tau1=flags.tau1, 
                            tau2=flags.tau2, 
                            mu=flags.mu, 
                            k=flags.k, 
                            min_community=flags.min_community, 
                            seed=flags.seed,
                            dataset_number=flags.dataset_number
                            )