# Louvian Algorithm - Sequential

## Description
Basic sequential implementation of Louvian Algorithm for Community Detection on a graph. Essentially, the algorithm detects communities/clusters within a graph based on a modularity score, or how connected nodes are to one another, in order to dissect a graph into multiple communities.

#### High Level Overview
1. Initialization:
    Each node in the graph is assigned to its own community.
    Compute the modularity of the initial partition.
2. Repeat until no improvement in modularity is possible:
    a. For each node:
        Compute the change in modularity if the node is moved to each of its neighboring communities.
        Select the community that yields the maximum increase in modularity and move the node to that community.
    b. If any node changed its community, go back to step 2a.
3. Post-processing:
    Each community is represented by a "super-node" in a new graph.
    The weights of the edges between super-nodes are the sum of the weights of the edges between their respective communities in the original graph.
    Apply the Louvain algorithm to the new graph to find the communities at the next level.
4. Repeat steps 2 and 3 until no further improvement in modularity is possible or until a       predefined number of levels is reached.
5. Return the final set of communities.

## Known Issues / Future Work
When lots of nodes and edges are added on a graph (approx 10+) the program stalls and takes a very long time. This may be due to the lengthy process needed to recalculate modularity for every edge or a bug in the code. This needs to be looked into as we hope to implement this algorithm on large datasets.

## Usage
This algorithm can be used for community detection applications such as social network analysis, biological networks, web analysis and search engine optimization, data mining, and many more cases.

## Tests
Tests are included for small graphs (<6 nodes) and cases such as empty graphs, single nodes, and multiple nodes are all provided.

## Example
