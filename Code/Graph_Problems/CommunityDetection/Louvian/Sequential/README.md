# Louvian Algorithm - Sequential

## Description
Basic sequential implementation of Louvian Algorithm for Community Detection on a graph. Essentially, the algorithm detects communities/clusters within a graph based on a modularity score, or how connected nodes are to one another, in order to dissect a graph into multiple communities.

## Known Issues / Future Work
When lots of nodes and edges are added on a graph (approx 10+) the program stalls and takes a very long time. This may be due to the lengthy process needed to recalculate modularity for every edge or a bug in the code. This needs to be looked into as we hope to implement this algorithm on large datasets.

## Usage
This algorithm can be used for community detection applications such as social network analysis, biological networks, web analysis and search engine optimization, data mining, and many more cases.

## Tests
Tests are included for small graphs (<6 nodes) and cases such as empty graphs, single nodes, and multiple nodes are all provided.

## Example
