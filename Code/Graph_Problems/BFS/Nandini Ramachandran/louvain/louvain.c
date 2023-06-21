//
//  louvain_seq.c
//  Louvain Algorithm for Community Detection
//
//  Created by Nandini Ramachandran on 6/15/23
//  References: https://arxiv.org/pdf/0803.0476.pdf

// High Level Overview of Louvain Algorithm
/* 
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
4. Repeat steps 2 and 3 until no further improvement in modularity is possible or until a predefined number of levels is reached.
5. Return the final set of communities. */

// System Imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// User Imports
#include "louvain.h"


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

// Function to perform the Louvain algorithm
void louvain(Graph* graph) {
    bool improvement = true;
    while (improvement) {
        improvement = false;
        for (int i = 0; i < graph->numNodes; i++) {
            Node* node = graph->nodes[i];
            int originalCommunity = node->community;
            double maxDeltaQ = 0.0;
            int bestCommunity = originalCommunity;

            // Compute the modularity gain for moving the node to each neighbor's community
            for (int j = 0; j < node->degree; j++) {
                Node* neighbor = node->neighbors[j];
                int neighborCommunity = neighbor->community;
                double deltaQ = 0.0;

                // Compute the change in modularity by moving the node to the neighbor's community
                if (originalCommunity != neighborCommunity) {
                    deltaQ = ((double)neighbor->degree - (double)node->degree) / (2.0 * (double)graph->numNodes);
                }

                if (deltaQ > maxDeltaQ) {
                    maxDeltaQ = deltaQ;
                    bestCommunity = neighborCommunity;
                }
            }

            // Move the node to the community with the maximum modularity gain
            if (maxDeltaQ > 0.0) {
                node->community = bestCommunity;
                improvement = true;
            }
        }
    }
}

// Function to print the communities in the graph
void printCommunities(Graph* graph) {
    int* communitySizes = (int*)calloc(graph->numNodes, sizeof(int));
    for (int i = 0; i < graph->numNodes; i++) {
        communitySizes[graph->nodes[i]->community]++;
    }

    for (int i = 0; i < graph->numNodes; i++) {
        printf("Node %d belongs to community %d\n", i, graph->nodes[i]->community);
    }

    printf("Community sizes:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        printf("Community %d: %d nodes\n", i, communitySizes[i]);
    }

    free(communitySizes);
}

// int main() {
//     int numNodes = 10;
//     Graph* graph = createGraph(numNodes);

//     // Add edges to the graph
//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 0, 3);
//     addEdge(graph, 1, 2);
//     addEdge(graph, 1, 3);
//     addEdge(graph, 2, 3);
//     addEdge(graph, 2, 4);
//     addEdge(graph, 3, 4);
//     addEdge(graph, 4, 5);
//     addEdge(graph, 5, 6);
//     addEdge(graph, 6, 7);
//     addEdge(graph, 6, 8);
//     addEdge(graph, 7, 8);
//     addEdge(graph, 8, 9);
//     addEdge(graph, 9, 5);

//     // Perform Louvain algorithm
//     louvain(graph);

//     // Print the communities
//     printCommunities(graph);

//     // Cleanup
//     for (int i = 0; i < numNodes; i++) {
//         free(graph->nodes[i]->neighbors);
//         free(graph->nodes[i]);
//     }
//     free(graph->nodes);
//     free(graph);

//     return 0;
// }
