#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 100000

typedef struct {
    int node1;
    int node2;
} Edge;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <numNodes> <numEdges> <seed>\n", argv[0]);
        return 1;
    }

    int numNodes = atoi(argv[1]);    // Number of nodes in the graph
    int numEdges = atoi(argv[2]);    // Number of edges in the graph
    int seed = atoi(argv[3]);        // Random seed

    // Set the random seed
    srand(seed);

    // Create an array of edges
    Edge edges[MAX_EDGES];

    // Generate random edges between nodes
    int numGeneratedEdges = 0;
    while (numGeneratedEdges < numEdges) {
        int node1 = rand() % numNodes;
        int node2 = rand() % numNodes;

        // Ensure that the two nodes are distinct and the edge does not already exist
        if (node1 != node2) {
            int exists = 0;
            for (int i = 0; i < numGeneratedEdges; i++) {
                if ((edges[i].node1 == node1 && edges[i].node2 == node2) ||
                    (edges[i].node1 == node2 && edges[i].node2 == node1)) {
                    exists = 1;
                    break;
                }
            }

            if (!exists) {
                edges[numGeneratedEdges].node1 = node1;
                edges[numGeneratedEdges].node2 = node2;
                numGeneratedEdges++;
            }
        }
    }

    // Print the graph in the following format: node1 node2
    for (int i = 0; i < numEdges; i++) {
        printf("%d %d\n", edges[i].node1, edges[i].node2);
    }

    return 0;
}
