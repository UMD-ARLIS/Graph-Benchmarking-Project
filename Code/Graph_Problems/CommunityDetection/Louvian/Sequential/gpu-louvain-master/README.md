# Original Github Information:
## Overview
Goal of this project was to implement Community detection algorithm (using Louvain method) 
based on a paper: [Community Detection on the GPU](http://dspace.uib.no/bitstream/handle/1956/16753/PaperIII.pdf).

## Usage
Flag `-f` specifies input file, `-g` gain threshold, `-v` represents verbose mode
```bash
make
./gpulouvain -f mtx-matrix-file -g min-gain [-v]
```

### Algorithm
Obviously, first step of the algorithm is to read data from input file. <br/>
I assume that given graph is undirected. <br/>
Actual algorithm is split into 2 parts:
  - modularity optimisation - in this step we find currently optimal community (group of vertices)
  - community aggregation - in this we merge vertices within a single community into one new vertex (keeping edges between communities)

These 2 steps are repeated as long as modularity gain is bigger than a threshold (provided by user).
In the end final modularity is printed. In verbose mode `original vertex -> final community` assignment is additionally printed. 

## Optimisation
During both phases vertices are divided into buckets based on degrees. This way, we dedicate more resources on a vertex with greater degree.
Buckets containing vertices with smaller degrees use only shared memory, this way we utilise slow global memory only when it is necessary.

---
# Known Issues/Bugs Fixed - Nandini's Updates
Fixed couple issues with original code: https://github.com/olearczuk/gpu-louvain
1. Makefile: Updated SM architecture to 90 instead of checking 30 35 37 50 52 60 because it was not compiling on the old versions
2. community_aggregation.cu: added 2 additional include statements as shown below since there were errors being thrown 
#include <thrust/execution_policy.h> (fixed 28 compilation errors)
#include <thrust/partition.h> (fixed 2 compilation errors)

## Instructions
```
make clean
```
```
make all
```
```
make ./gpulouvain -f sampleGraph.txt
```
Having issues with this step^

Keeps giving me this response: ```make: 'gpulouvain' is up to date```, however it should be printing out this information: algorithmTime, algorithmTime + memoryTime.

Question: Do I need to use NVCC for this?

# Documenting Debugging Process

First, issues came up when I tried to use biostat_graph.txt which was a mtx type file that the orig github readme requested for

However, after running ``` make ./gpulouvain -f biostat_graph.txt ``` I recieved this response ```biostat_graph.txt:1: *** missing separator.  Stop.```

--> Apparaently it doesn't like spaces between the numbers, so I made a new graph file that employs a ':' as a separator called sampleGraph.txt (you can see both graph files in the folder)

This outputs the phrase mentioned above ```make: 'gpulouvain' is up to date``` but no corresponding information is provided

I am not sure where the issue is since it compiles successfully, but its not printing out the results

