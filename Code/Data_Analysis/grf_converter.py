#Python Core Imports
import argparse
import itertools

#External Library imports
import networkx as nx

#User file imports.

def load_graph(txt_file_path):
    # Read the text file and create a graph
    G = nx.Graph()
    with open(txt_file_path, 'r') as txt_file:
        for line in txt_file:
            if not line.strip():  # Skip empty lines
                continue
            if line.startswith("//"):  # Skip comment lines
                continue
            subgraph = line.split()
            
            if len(subgraph) == 1:
                pass #skip first line
            else:
                #Generate the undirected edges
                edges = list(map(int, subgraph[1:]))
                combinations = list(itertools.combinations(edges, 2))
                for combo in combinations:
                    #print(combo[0], combo[1])
                    G.add_edge(combo[0], combo[1])

            #source, target = map(int, line.strip().split())
            #G.add_edge(source, target)
    return G

def load_AL_graph(txt_file_path):
    # Read the text file and create a graph
    G = nx.Graph()
    with open(txt_file_path, 'r') as txt_file:
        for line in txt_file:
            if not line.strip():  # Skip empty lines
                continue
            if line.startswith("//"):  # Skip comment lines
                continue

            if line.startswith("#"):  # Skip comment lines
                continue

            source, target = map(int, line.strip().split())
            G.add_edge(source, target)
    return G

def load_TSV_graph(txt_file_path):
    G = nx.Graph()
    with open(txt_file_path, 'r') as txt_file:
        for line in txt_file:
            if not line.strip():  # Skip empty lines
                continue
            if line.startswith("//"):  # Skip comment lines
                continue

            if line.startswith("#"):  # Skip comment lines
                continue

            source, target, attribute = map(int, line.strip().split())
            G.add_edge(source, target)
    G.to_undirected()   #Make Undirected - Hard coded for now, TODO - make this a parameter. 
    return G

def convert_to_ordered_graph(G):
    nodeMappings = {}
    counter = 0
    for node in G.nodes:
        nodeMappings[node] = str(counter)
        counter +=1

    return nx.relabel_nodes(G, nodeMappings, True)

def save_graph(G, outputFilePath):
    '''
    .grf Format is: 
    # Number of nodes
    3

    # Node attributes
    0 27
    1 42
    2 13	 

    # Edges coming out of node 0\n
    2
    0 1  24
    0 2  73

    # Edges coming out of node 1
    1
    1 3  66

    # Edges coming out of node 2
    0
    '''
    num_nodes = len(G.nodes())

    with open(outputFilePath, 'w') as grf_file:
        #Number of Nodes
        grf_file.write(str(num_nodes)+"\n")

        #Node Attributes
        for node in G.nodes:
            #grf_file.write(i, G.nodes[i],"\n")
            grf_file.write(str(node)+" 1\n")
        #Edges
        for node in G.nodes:
            #print(nx.neighbors(G,node))
            count = 0
            for neighbor in nx.neighbors(G,node):
                count += 1    
            grf_file.write(str(count)+"\n")
            if count == 0:
                grf_file.write((str(node))+"\n")
            else:
                for neighbor in nx.neighbors(G,node):
                    grf_file.write((str(node))+" "+str(neighbor)+"\n")


#Define an argument parser to accept input through the command line
parser = argparse.ArgumentParser(
                    prog='graphConverter',
                    description='Converts between graph formats',
                    epilog='Currently only implemented txt to grf')

parser.add_argument('-i', '--inputFile',
                    help="The input file of graph to convert",
                    required=True,
                    default=None)

parser.add_argument('-o', '--outputFile',
                    help="The name of the file to output",
                    required=True,
                    default="graph.grf")

parser.add_argument('-t', '--inputType',
                    help="The fileType: AL for txt adjacency list",
                    required=True,
                    default="Other")

if __name__ == "__main__":
    '''
    Main function to run all your code
    '''
    flags = parser.parse_args()

    input_txt_file = flags.inputFile
    output_grf_file = flags.outputFile

    inputType = flags.inputType


    if output_grf_file.endswith(".grf") == False:
        output_grf_file = output_grf_file+".grf"

    if input_txt_file is not None: 
        if inputType == "AL":
            graphFromTxt = load_AL_graph(input_txt_file)
        elif inputType == "TSV": #process a TSV File:
            graphFromTxt = load_TSV_graph(input_txt_file)
        else:
            graphFromTxt = load_graph(input_txt_file)

        orderedGraph = convert_to_ordered_graph(graphFromTxt)
        print("Converted to:", orderedGraph)
        save_graph(orderedGraph, output_grf_file)
    else: 
        exit("No input file specified")
