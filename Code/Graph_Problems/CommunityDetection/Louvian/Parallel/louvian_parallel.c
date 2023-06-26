// Code/Graph_Problems/CommunityDetection/Louvian/Parallel/louvian_parallel.c

//
//  louvain_parallel.c
//  Louvain Algorithm for Community Detection
//
//  Created by Nandini Ramachandran on 6/15/23
//  References: https://arxiv.org/pdf/0803.0476.pdf

// Implementation High Level Overview for Parallel Processing of Louvian Algorithm 
/*
1. Divide the Nodes: Split the nodes of the graph into multiple subsets, assigning each subset to a different thread. The division can be done based on node indices or any other suitable criterion.
2. Thread Synchronization: Use appropriate synchronization mechanisms, such as mutexes or barriers, to ensure proper synchronization between threads. This is necessary to avoid race conditions and ensure data consistency.
3. Parallel Iterations: Each thread independently performs iterations of the Louvain algorithm on its assigned subset of nodes. Within each iteration, the thread processes its nodes, calculates modularity changes, and updates the node's community assignment based on the maximum gain.
4. Thread Communication: At the end of each iteration, threads need to communicate to exchange information about community assignments. This information is necessary for the next iteration as it affects the modularity calculations and community updates. Thread synchronization mechanisms, like barriers, can be used to facilitate this communication.
5. Termination Condition: After each iteration, threads check for improvements in modularity. If any thread detects an improvement, the algorithm continues with the next iteration. Otherwise, the algorithm terminates.
6. Finalization: Once the algorithm terminates, the resulting community assignments can be collected and processed as required. This may involve merging communities, post-processing steps, or further analysis.
7. Thread Cleanup: Proper cleanup should be performed to release any resources and synchronization mechanisms used by the threads
*/