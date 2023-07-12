A common subgraph matching algorithm that can be used for log files and kill chains in network data is the VF2 algorithm. VF2 (or VF2++) 
is a well-known algorithm for graph isomorphism and subgraph isomorphism. It efficiently finds all occurrences of a subgraph, also know as a 
query graph within a larger target graph.

Here's a high-level overview of the VF2 algorithm:

Define the subgraph: Construct a small graph that represents the pattern we are looking for within the larger log or network graph. 
This query graph can be constructed based on the log patterns or kill chain stages we want to match.

Initialize the VF2 algorithm: Initialize the algorithm with the subgraph and the target graph (log or network data) 
we want to search. The VF2 algorithm maintains two states: the current state of the mapping between nodes in the subgraph and the target graph, 
and the feasibility status indicating if a particular mapping is possible.

Explore the search space: The VF2 algorithm performs a depth-first search to explore the search space of possible mappings between the subgraph
and the target graph. It systematically tries to extend the current mapping by adding new nodes and edges, while ensuring that the structural 
constraints (such as edge connectivity and node labels) are satisfied.

Check feasibility and pruning: At each step, the algorithm checks the feasibility of the current mapping based on the structural constraints. 
If a certain condition is not met (e.g., node labels don't match), the algorithm prunes that branch of the search space, avoiding unnecessary 
exploration.

Collect matches: During the search, whenever a complete and valid mapping is found, it represents a match of the subgraph within the target graph. 
We can collect these matches and analyze them further for log analysis or identifying kill chain stages.


In short, VF2 algorithm is a widely used subgraph matching algorithm that efficiently finds all occurrences of a subgraph within a larger target 
graph. It utilizes a depth-first search and backtracking approach, considering node and edge labels, while maintaining the feasibility of mappings 
based on structural constraints. However, it's worth noting that graph matching is generally an NP-hard problem, and the VF2 algorithm may not be 
suitable for extremely large graphs or complex matching scenarios. In such cases, approximate or specialized algorithms may be required.





Other algos to consider if this fails to meet our requirements.

1. Ullmann algorithm: The Ullmann algorithm is a subgraph matching algorithm that uses backtracking and depth-first search to efficiently find all
   occurrences of a subraph in a larger target graph, considering both node and edge labels, while allowing for node and edge mappings to be
   one-to-one or many-to-one.
   
2. QuickSI algorithm: The QuickSI algorithm is a scalable and efficient subgraph matching algorithm that utilizes a combination of filtering and
   verification steps to quickly identify potential matches between a subgraph and a target graph, based on structural and label constraints,
   without exploring the entire search space.
