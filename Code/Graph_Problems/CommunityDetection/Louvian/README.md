# Community Detection Problems - The Louvian Algorithm
This Readme contians general information on the algorithms and links to useful resources. Details of the implementations are in the child sequential and parallel folders respectively

## Background on Community Detection Problems

## Louvian Algorithm (Sequential)

### Algorithm

### Expected Behaviours (for testing)

### Dataset Requirements, Features and Notes

### Other Resources: 
- [ ] [Original Louvian Paper](https://github.com/osullik/summer2023/blob/main/Papers/bibliography/reference_papers/Blondel2008.pdf)
- [ ] [C/C++ Implementation of Louvian](https://sourceforge.net/projects/louvain/) Not verifed, but possible start point. 
- [ ] [C++ Implementation of Louvian](https://github.com/ECP-ExaGraph/vite) Also looks to include some graph generation code that might be useful


## Louvian Algorith (Parallel)

### Algorithm

### Expected Behaviours (for testing)

### Dataset Requirements, Features and Notes

### Other Resources

 - [ ] [Distributed Louvian](https://github.com/osullik/summer2023/blob/main/Papers/bibliography/reference_papers/Ghosh2018.pdf). [Code here](https://github.com/ECP-ExaGraph/vite)
 - [ ] [Graph Clustering](https://github.com/osullik/summer2023/blob/main/Papers/bibliography/reference_papers/Ghosh2019.pdf) [Code here](https://github.com/ECP-ExaGraph/vite)
 - [ ] 


## Alternatives

- [ ] [The Leiden Algorithm Neo4j page](https://neo4j.com/docs/graph-data-science/current/algorithms/leiden/#:~:text=The%20Leiden%20algorithm%20is%20an,modularity%20score%20for%20each%20community.) The Leiden algorithm is a hierarchical clustering algorithm, that recursively merges communities into single nodes by greedily optimizing the modularity and the process repeats in the condensed graph. It modifies the Louvain algorithm to address some of its shortcomings, namely the case where some of the communities found by Louvain are not well-connected. This is achieved by periodically randomly breaking down communities into smaller well-connected ones.

- [ ] [Leiden Algorithm Paper](https://github.com/osullik/summer2023/blob/main/Papers/bibliography/reference_papers/Traag2019.pdf)

- [ ] [Java Implementation of Leiden](https://github.com/CWTSLeiden/networkanalysis)