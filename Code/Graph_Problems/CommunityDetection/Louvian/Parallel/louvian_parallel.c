// Code/Graph_Problems/CommunityDetection/Louvian/Parallel/louvian_parallel.c

//
//  louvain_parallel.c
//  Louvain Algorithm for Community Detection
//
//  Created by Nandini Ramachandran on 6/23/23
//  References: https://arxiv.org/pdf/0803.0476.pdf

// Implementation High Level Overview for Parallel Processing of Louvian Algorithm 
/*
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
*/

/*
The parallelization is achieved by dividing the nodes among multiple threads. Each thread processes a subset of nodes, and synchronization points are added to ensure that all nodes have been processed before updating the modularity and moving to the next iteration. The critical section is protected using a mutex to prevent data races when updating the node's community.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

// User Imports
#include "louvian_parallel.h"



// Function to create a new node
Node* createNode(int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->community = id;  // Initially, each node is in its own community
    newNode->degree = 0;
    newNode->neighbors = NULL;
    return newNode;
}

// Function to create a new graph
Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->nodes = (Node**)malloc(numNodes * sizeof(Node*));
    for (int i = 0; i < numNodes; i++) {
        graph->nodes[i] = createNode(i);
    }
    return graph;
}

// Function to add an undirected edge between two nodes
void addEdge(Graph* graph, int src, int dest) {
    Node* srcNode = graph->nodes[src];
    Node* destNode = graph->nodes[dest];

    // Update the degrees of the nodes
    srcNode->degree++;
    destNode->degree++;

    // Add the nodes as neighbors to each other
    srcNode->neighbors = (Node**)realloc(srcNode->neighbors, srcNode->degree * sizeof(Node*));
    destNode->neighbors = (Node**)realloc(destNode->neighbors, destNode->degree * sizeof(Node*));

    srcNode->neighbors[srcNode->degree - 1] = destNode;
    destNode->neighbors[destNode->degree - 1] = srcNode;
}

// Function to compute the modularity of the graph
double computeModularity(Graph* graph) {
    double modularity = 0.0;
    for (int i = 0; i < graph->numNodes; i++) {
        Node* node = graph->nodes[i];
        for (int j = 0; j < node->degree; j++) {
            Node* neighbor = node->neighbors[j];
            if (node->community == neighbor->community) {
                modularity += 1.0;
            }
        }
        modularity -= ((double)node->degree * (double)node->degree) / (2.0 * (double)graph->numNodes);
    }
    return modularity / (2.0 * (double)graph->numNodes);
}

// Function to process a node
void processNode(Node* node, Graph* graph) {
    int originalCommunity = node->community;
    double maxDeltaQ = 0.0;
    int bestCommunity = originalCommunity;

    // Compute the modularity gain for moving the node to each neighbor's community
    for (int j = 0; j < node->degree; j++) {
        Node* neighbor = node->neighbors[j];
        int neighborCommunity = neighbor->community;
        double deltaQ = ((double)neighbor->degree - (double)node->degree) / (2.0 * (double)graph->numNodes) -
                        ((double)(neighbor->degree * node->degree)) / (4.0 * (double)(graph->numNodes * graph->numNodes));
        if (deltaQ > maxDeltaQ) {
            maxDeltaQ = deltaQ;
            bestCommunity = neighborCommunity;
        }
    }

    // Update the node's community if the modularity gain is positive
    if (maxDeltaQ > 0.0) {
        pthread_mutex_lock(&mutex);
        node->community = bestCommunity;
        pthread_mutex_unlock(&mutex);
    }
}

// Function to perform Louvain community detection in parallel
void* parallelLouvain(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    Graph* graph = args->graph;
    int start = args->start;
    int end = args->end;

    // Process the nodes
    for (int i = start; i < end; i++) {
        Node* node = graph->nodes[i];
        processNode(node, graph);
    }

    pthread_exit(NULL);
}

// Function to print the communities
void printCommunities(Graph* graph) {
    printf("Communities:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        printf("Node %d belongs to community %d\n", i, graph->nodes[i]->community);
    }
}

/* int main() {
    // Create the graph
    int numNodes = 6;
    Graph* graph = createGraph(numNodes);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 3, 5);

    int numThreads = 2;  // Number of threads to use

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    ThreadArgs* threadArgs = (ThreadArgs*)malloc(numThreads * sizeof(ThreadArgs));
    int nodesPerThread = graph->numNodes / numThreads;
    int remainingNodes = graph->numNodes % numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; i++) {
        int end = start + nodesPerThread;

        // Distribute remaining nodes among threads
        if (remainingNodes > 0) {
            end++;
            remainingNodes--;
        }

        threadArgs[i].graph = graph;
        threadArgs[i].start = start;
        threadArgs[i].end = end;

        pthread_create(&threads[i], NULL, parallelLouvain, (void*)&threadArgs[i]);

        start = end;
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    free(threads);
    free(threadArgs);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Print the communities
    printCommunities(graph);

    // Cleanup and return
    // ...

    return 0;
} */
