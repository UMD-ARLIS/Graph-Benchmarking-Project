#Python Core Imports
import argparse

#External Library imports
import networkx as nx

#User file imports.

def load_graoh(txt_file_path):
    # Read the text file and create a graph
    G = nx.Graph()
    with open(txt_file_path, 'r') as txt_file:
        for line in txt_file:
            if not line.strip():  # Skip empty lines
                continue
            if line.startswith("//"):  # Skip comment lines
                continue

            source, target = map(int, line.strip().split())
            G.add_edge(source, target)
    return G


def save_graph(G, outputFilePath):
    num_nodes = len(G.nodes())
    num_edges = len(G.edges())
    ascii_header = ("%%MatrixMarket matrix coordinate real general\n").encode("ascii")

    with open(outputFilePath, 'wb') as mtx_file:
        mtx_file.write(ascii_header)
        mtx_file.write((str(num_nodes) + " " + str(num_nodes) + " " + str(num_edges)).encode("ascii"))
        for edge in G.edges():
            mtx_file.write(("\n"+str(edge[0]) + " " + str(edge[1])).encode("ascii"))


#Define an argument parser to accept input through the command line
parser = argparse.ArgumentParser(
                    prog='graphConverter',
                    description='Converts between graph formats',
                    epilog='Currently only implemented txt to mtx')

parser.add_argument('-i', '--inputFile',
                    help="The input file of graph to convert",
                    required=True,
                    default=None)

parser.add_argument('-o', '--outputFile',
                    help="The name of the file to output",
                    required=True,
                    default="graph.mtx")

if __name__ == "__main__":
    '''
    Main function to run all your code
    '''
    flags = parser.parse_args()

    input_txt_file = flags.inputFile
    output_mtx_file = flags.outputFile

    if input_txt_file is not None: 
        graphFromTxt = load_graoh(input_txt_file,)
        save_graph(graphFromTxt, output_mtx_file)
    else: 
        exit("No input file specified")
