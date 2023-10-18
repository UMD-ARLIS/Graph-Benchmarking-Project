========================
Vite - Parallel Louvain implementation
========================

ABOUT
************************

`Vite` is an MPI+OpenMP implementation of Louvain method for 
(undirected) graph clustering or community detection, that supports 
a number of heuristics to improve the scalability. Vite can use both 
real-world and synthetic graph (uses an in-memory random geometric 
graph generator).

COMPILATION
************************

Build the program with the standard `make` command.

Upon building, the program will generate two binaries:
bin/graphClustering (parallel) and bin/fileConvert (serial).

We'll use bin/fileConvert for input graph conversion from native 
formats to a binary format that bin/graphClustering will be able 
to read. 

INPUT GRAPH CONVERSION
************************

Convert input files to binary from various formats. 
Possible options (should be used in combination):

1. -n               Input graph in SNAP format
2. -m               Input graph in Matrix-market format
3. -e               Input graph in METIS format
4. -p               Input graph in Pajek format
5. -d               Input graph in DIMACS format. Pass 0 or 1
                      to indicate undirected/directed graph
6. -s               Input graph is directed edge list
7. -u               Input graph is undirected edge list 
                      (Can be used for Graph Challenge official 
                      datasets - http://graphchallenge.mit.edu/) 
8. -x               Read a number of files with edge list 
                      information, usage e.g.: 	
                      -x "<file-path> <start-chunk> <end-chunk>"
                      Requires conformant file names.
9. -i               Accept weights as is from the file. If this 
                      option is not passed, then by default the 
                      absolute value of the original weight is 
                      chosen. 
10. -r              Create random edge weights
11. -w              Initialize edge weights to 1.0
12. -o              Output binary file with full path
13. -z              If the index of input graph is 1-based,
                      then this option makes it 0-based
14. -f              Option preceding input graph file  

Our examples:

Simple directed edge list

.. code-block:: bash

   bin/./fileConvert -s -z -w -f simple_example.txt -o simple_example.bin


Small dataset directed edge list

.. code-block:: bash

   bin/./fileConvert -s -z -w -f chesapeake.txt -o chesapeake.bin

PROGRAM EXECUTION
************************

Our examples:

Simple directed edge list

.. code-block:: bash

   mpiexec -n 2 ./bin/./graphClustering -f simple_example.bin



Small dataset directed edge list

.. code-block:: bash

   mpiexec -n 2 ./bin/./graphClustering -f chesapeake.bin

OUTPUT
************************

If -DDONT_CREATE_DIAG_FILES is passed during compilation (default 
setting), then output is send to stdout. Otherwise, the output 
result is dumped per process on files named as dat.out.<process-id>.

Output files are cleared with: `make clean`.

FURTHER INQUIRY
************************

For troubleshooting, see the README.md , the github (https://github.com/ECP-ExaGraph/vite),
or email myself (vrife@umd.edu) or the original author (sg0@pnnl.gov), I found
them to be very responsive.
