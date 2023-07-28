import networkx as nx

def convert_txt_to_mtx(txt_file_path, mtx_file_path):
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

    num_nodes = len(G.nodes())
    num_edges = len(G.edges())

    # Save the graph in Matrix Market coordinate format
    with open(mtx_file_path, 'w') as mtx_file:
        mtx_file.write("%%MatrixMarket matrix coordinate real general\n")
        mtx_file.write(f"{num_nodes} {num_nodes} {num_edges}\n")
        for edge in G.edges():
            mtx_file.write(f"{edge[0]} {edge[1]}\n")


# Replace these file paths with your input text file and desired output mtx file paths

input_txt_file = "/Users/nani/Downloads/SmallDataSet.txt"
output_mtx_file = "/Users/nani/Downloads/SmallDataSet.mtx"

convert_txt_to_mtx(input_txt_file, output_mtx_file)

