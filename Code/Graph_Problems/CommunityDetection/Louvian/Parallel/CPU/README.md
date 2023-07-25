# Louvian Algorithm - Parallel

## Description
Basic parallel implementation of Louvian Algorithm for Community Detection on a graph. Essentially, the algorithm works similarly to the sequential implemention. However, the parallelization is achieved by dividing the nodes among multiple threads. Each thread processes a subset of nodes, and synchronization points are added to ensure that all nodes have been processed before updating the modularity and moving to the next iteration. The critical section is protected using a mutex to prevent data races when updating the node's community.

#### High Level Overview
1. Initialization:
    Each node in the graph is assigned to its own community.
    Compute the modularity of the initial partition.
2. Repeat until no improvement in modularity is possible:
    a. Divide the nodes among multiple threads.
    b. Process the nodes in parallel:
        For each node, compute the change in modularity if the node is moved to each of its neighboring communities.
        Select the community that yields the maximum increase in modularity and update the node's community accordingly.
    c. Synchronize the threads to ensure all nodes have been processed.
    d. Update the graph's modularity based on the community changes.
3. Post-processing:
    Each community is represented by a "super-node" in a new graph.
    The weights of the edges between super-nodes are the sum of the weights of the edges between their respective communities in the original graph.
    Apply the Louvain algorithm to the new graph to find the communities at the next level.
4. Repeat steps 2 and 3 until no further improvement in modularity is possible or until a predefined number of levels is reached.
5. Return the final set of communities
6. Cleanup

## Known Issues / Future Work

## Usage
This method has similar use cases to the sequential version of the algorithm. It is important to note that parallel processing allows the Louvain algorithm to scale effectively as the size of the graph increases. By dividing the graph into smaller portions and processing them in parallel, the algorithm can handle larger graphs and deliver results in a reasonable amount of time. Additionally, community assignments for different nodes are computed independently so concurrency can be achieved, improving the overall speed of the algorithm.

## Tests
The tests provided go over similar test cases as the sequential method.

## Example
