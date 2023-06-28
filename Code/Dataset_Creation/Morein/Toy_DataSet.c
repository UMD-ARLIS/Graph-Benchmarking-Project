#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_NODES 100
#define MAX_EDGES 200
#define NUM_COMMUNITIES 4


typedef struct {
   int node1;
   int node2;
} Edge;


typedef struct {
   int node;
   int community;
} Node;


//modify the values of numNodes and numEdges to generate graphs of different sizes.


int main() {
   int numNodes = 20;  // Number of nodes in the graph
   int numEdges = 30;  // Number of edges in the graph


   // Initialize random number generator
   srand(time(NULL));


   // Create an array of nodes
   Node nodes[MAX_NODES];


   // Assign each node to a random community
   for (int i = 0; i < numNodes; i++) {
       nodes[i].node = i;
       nodes[i].community = rand() % NUM_COMMUNITIES;
   }


   // Create an array of edges
   Edge edges[MAX_EDGES];


   // Generate random edges between nodes
   int edgeCount = 0;
   while (edgeCount < numEdges) {
       int node1 = rand() % numNodes;
       int node2 = rand() % numNodes;


       // Ensure that the two nodes are distinct and the edge does not already exist
       if (node1 != node2) {
           int exists = 0;
           for (int i = 0; i < edgeCount; i++) {
               if ((edges[i].node1 == node1 && edges[i].node2 == node2) ||
                   (edges[i].node1 == node2 && edges[i].node2 == node1)) {
                   exists = 1;
                   break;
               }
           }


           if (!exists) {
               edges[edgeCount].node1 = node1;
               edges[edgeCount].node2 = node2;
               edgeCount++;
           }
       }
   }


   // Print the graph in the following format: node1 node2
   for (int i = 0; i < numEdges; i++) {
       printf("%d %d\n", edges[i].node1, edges[i].node2);
   }


   return 0;
}
