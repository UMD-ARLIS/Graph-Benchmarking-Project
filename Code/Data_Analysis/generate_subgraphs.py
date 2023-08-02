# Core python Importa
import random
import argparse
import itertools

# External Library Imports
import networkx as nx

# User File Imports

#Functions

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
    # Read the a graph from an adjacency list text file and create a graph
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



def random_walk(graph, start_node, walk_length):
    '''
    Conduct a random walk of the graph to generate a subgraph that we know will exist in the parent
    INPUT ARGS: 
        graph - networkX graph - The graph to walk on
        start_node - int - the lable of the node to start the walk from 
        walk_length - int - the lenght of the walk to take
    PROCESS:
        Get the list of neighbours for the current node
        Randomly traverse to one of those nodes
        Append that to the list
        Stop when you have walked far enough
    RETURNS:
        walk_path - list of strings - the labels of the nodes that have been traversed
    '''
    current_node = start_node
    walk_path = [current_node]

    for _ in range(walk_length):
        neighbors = list(graph.neighbors(current_node))
        if len(neighbors) == 0:
            break

        next_node = random.choice(neighbors)
        walk_path.append(next_node)
        current_node = next_node

    return walk_path

def saveSubgraph(subgraphList,outputFilePath):
    with open(outputFilePath, 'w') as adj_file:
        for node in subgraphList:
            adj_file.write(str(node[0])+" "+str(node[1])+"\n")

def findCycle(graph, startNode=None):
    print("Finding Cycle")
    candidate = nx.find_cycle(graphFromTxt, startNode)
    for node in candidate:
        if node[0] == node[1]:
            candidate = findCycle(graph, startNode=node).copy()
    
    return candidate


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
                    help="The fileType: AL for txt adjacency list, 'Other' for other",
                    required=False,
                    default="Other")

parser.add_argument('-l', '--walkLength',
                    help="The size of the walk to take, deaults to '5'",
                    required=True,
                    default=5)

parser.add_argument('-s', '--randomSeed',
                    help="The random seedm defauls to '2'",
                    required=False,
                    default=2)

if __name__ == "__main__":
    '''
    Main function to run all your code

    Effectively, it finds a cycle in the graph, then uses the origin of that cycle to commence a random walk
    '''
    flags = parser.parse_args()

    input_txt_file = flags.inputFile
    output_file = flags.outputFile
    inputType = flags.inputType
    walkLength = int(flags.walkLength)
    random.seed(flags.randomSeed)

 
    if input_txt_file is not None: 
        if inputType == "AL":   #process an Adjacency list
            graphFromTxt = load_AL_graph(input_txt_file)
        elif inputType == "TSV": #process a TSV File:
            graphFromTxt = load_TSV_graph(input_txt_file)
        else:
            graphFromTxt = load_graph(input_txt_file)

        
        subgraph = []
        
        try:
            #Find the first cycle in the graph
            cycle = findCycle(graphFromTxt)

            for node in cycle: 
                subgraph.append(node)


            #if the cycle is longer than the size of the subgraph we want, return it. 
            if len(subgraph) > walkLength:
                print("Visited Enough Nodes:")
                print("Subgraph is", subgraph)
                saveSubgraph(subgraph,output_file)
                exit()
                
            else:
                #If not long enough, append steps from the random walk until it is long enough. 
                print("Need to add more nodes to reach walk length")
                randomWalk = random_walk(graphFromTxt,subgraph[0][0],walkLength)
                try:
                    i = 0
                    while len(subgraph) < walkLength:
                        subgraph.append((randomWalk[i], randomWalk[i+1]))
                        i+= 1
                    print("Subgraph Large Enough")
                    print("Subgraph is", subgraph)
                    saveSubgraph(subgraph,output_file)

                except IndexError:
                    #If we go out of range of the index, just return what we have so far. 
                    print('Subgraph At Max Size of Random Walk')
                    print("Subgraph is", subgraph)
                    saveSubgraph(subgraph,output_file)

        except:
            #If there are no cycles, just use the random walk to generate the subgraph.
            randomWalk = random_walk(graphFromTxt,random.randrange(0,len(graphFromTxt.nodes)),(walkLength+1))
            try:
                i = 0
                while len(subgraph) < walkLength:
                    subgraph.append((randomWalk[i], randomWalk[i+1]))
                    i+= 1
                print("Subgraph Large Enough")
                print("Subgraph is", subgraph)
                saveSubgraph(subgraph,output_file)
      
            except IndexError:
                #Again, if we go out of bounds of the index, just return what we have so far
                print('Subgraph At Max Size of Random Walk')
                print("Subgraph is", subgraph)
                saveSubgraph(subgraph,output_file)
    else:

        exit("No input file found")


