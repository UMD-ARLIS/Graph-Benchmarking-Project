# USC Cloud Parallel CPU Implementation of Louvian Algorithm   

### ssh into the ubuntu user on AWS EC2 Instance
```
ssh -i <keyName>.pem <username>@##.##.##.##
```  
### Change into the parallel sub directory
```
cd parallel-louvain-modularity/src/parallel/
```
---

## Running The Sample
A Sample small graph is located in this directory.  
* example.txt - graph in edge list format.  
* example.graph - graph in Metis graph format.

# 1
First step of execution is partitioning the graph to desired # partitions and creating the graph partitions for the parallel Louvain algorithm. This is done using:
```
gpmetis ./example.graph 2
```
This will create a partition file example.graph.part.2

# 2
Then you need to convert the graph using the conversion tool to binery format. This will create .bin and .remote file for each partition. .bin file contains the local graph for each partition while .remote files contain mappings of cross partition edges.

Example:
```
./convert -i example.txt -o example -p example.graph.part.2 -n 2
```

General format is :
```
./convert -i  -o  -p  -n 
```

This will create .bin files with format example_.bin and .remote files with format example_.remote.

# 3
Use the Open MPI’s mpi-run command to start the algorithm using the desired number of processors (NOTE: This should be equal to the number of partitions)

example:
```
mpirun -np 2 ./community 4elt -r 4elt -l 2 -v > level2.txt
```

the general format is:
```
mpirun -np  ./community  -r  -l  -v verbose > output file 
```
# 4
Executing this will run the algorithm in two MPI processors and output the community graph at 2nd level of louvain method in level2.txt:
level2.txt display the community graph in adjacency list format. each line is in following format
source: (sink1 weight1) (sink2 weight2) . . .(sinkN weightN)

Example:

0: (0 1)  
1: (1 1) (2 1) (3 1) (4 1) (5 1) (6 1) (7 1) (8 1)  
2:  
3:  
4:  
5:  
6:  
7:  
8:  
9: (9 1) (10 1) (11 2) (0 20)  
10:  
11: (9 1) (11 1) (12 1) (13 1) (14 1) (20 1) (21 1) (0 7) (4 1)  
12:  
13:  
14: (11 1) (14 1) (15 1) (16 1) (17 1) (18 1) (19 1) (0 8)  
15:  
16:  
17:  
18:  
19:  
20:  
21:  

--- 
## Sample Output
For this example, check out [sample-output.txt](https://github.com/osullik/summer2023/main/Code/Graph_Problems/CommunityDetection/Louvian/Parallel/CPU/UDC-Cloud-Implementation/sample-output.txt)  
  
## Data Format
This implementation uses the standard usnweighted METIS graph data format for input graphs. 

To summarize, the metis format of the following

First line indicating the number of vertices and edges

All subsequent lines contain the data per vertex and its (undirected) edges in following format

e1 e2 …

Metis File:

4 5 //4: num vertices, 5: num edges

2 3 4 // e1 w1 e2 w2 e3 w3 for vertex 1

1 3 4

1 2

1 2

Edge List file is just a standered undirected list of edges. Each line corresponds to an edge in metis formated graph. Same vertex ids must be used in both files.

Following is the edge list for above graph

1 2

1 3

1 4

2 1

2 3

2 4

3 1

3 2

4 1

4 2