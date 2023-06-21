# Dataloader 

## Description
The dataLoader utility is designed to ingest specifically formatted files that define a graph data structure.

## Input Format
To be ingested by the dataloader the input format needs to be as follows: 

        #TITLE: **title of the file**
        #SOURCE: **reference to any source files. If no external source, can be safely omitted but consider putting author attribution on this line**
        #NODES:
        node1
        node2
        node3
        ...
        nodeN
        #EDGES:
        (0,1)
        (1,2)
        (1,3)
        ...
        (n,m)

The parser looks for the #TITLE: and #SOURCE: tags to omit those files. It uses the NODES: line to activate the "node processing mode" and remains in that mode until it hits an #EDGES at which point it swaps to edge processing mode. 

The code is still quite brittle, so this input format must be covered exactly. 

Another **GOTCHA** to be aware of: the edge definitions are created by the nodeID, not the name. The nodeID is dynamically calculated by the graph library based on the order of ingestion. So, in the above file, **(0,1)** is a link from **node1** to **node2**; and **(1,2)** is a link from **node2** to **node3**, NOT node 1 to node 2. 

## Known Issues / Future Work

    - ISSUE1: Currently only able to create edges based on the index of the node, rather than its metadata 'name'
	    - TODO1: Implement searching for node by Metadata for edge creation. 
	- ISSUE2: Minimal input sanitization, very brittle to expected file format
	    - TODO2: Implement input sanitization 
	- ISSUE3: Only able to create directed graphs
		- TODO3: Add support for createing undirected graphs

## Usage

        graph_t loadGraph(char *fileName, graph_t g)

The loadGraph function accepts two parameters: **fileName** and **g**. 
    - **fileName** is the path to the data file you wish to ingest.
    - **g** is the initialized graph that dataLoader should insert the nodes and edges into

The loadGraph function returns a graph data structure


## Tests

to run the tests: 

    make test

    ./test.o

## Example

If I were using this from another c file it might look something like: 


        //printGraphStats.c

        #include "summer2023/Code/Utilities/c-utils/graph.h"
        #include "summer2023/Code/Utilities/dataLoader/dataLoader.h"

        graph_t graph_to_populate_from_file = g_init();
        char *inputFile = "summer2023/Data/bfs/toy/toyTree.in";

        graph_to_populate_from_file = loadGraph(inputFile,graph_to_populate_from_file);

        printf("The number of nodes in the graph is %d, and the number of edges is %d\n", g_num_vertices(graph_to_populate_from_file), g_num_edges(graph_to_populate_from_file))

        g_free_alt(graph_to_populate_from_file, FALSE);


Which we would of course need to compile by passing the correct files to the compiler (here assuming GCC)

        gcc printGraphStats.c summer2023/Code/Utilities/c-utils/graph.c summer2023/Code/Utilities/dataLoader/dataLoader.c -o printGraphStats.o 

which you could then run from the command line with something like:

        ./printGraphStats.o