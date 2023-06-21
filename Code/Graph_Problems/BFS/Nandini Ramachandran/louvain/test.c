//System Imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


//Util Imports
#include "../../../../Utilities/c-utils/src/minunit.h"

//User Imports
#include "louvain.h"

// Function to compare the community assignments in the graph with the expected assignments
void compareCommunities(Graph* graph, int* expectedCommunities) {
    for (int i = 0; i < graph->numNodes; i++) {
        assert(graph->nodes[i]->community == expectedCommunities[i]);
    }
}

MU_TEST(test_louvain_5N_6E){
  printf("this test checks if this works on a graph with 5 nodes and 6 edges\n");

      Graph* graph;
    int expectedCommunities[10];

    // Test 1: Graph with 5 nodes and 6 edges
    graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    expectedCommunities[0] = 0;
    expectedCommunities[1] = 0;
    expectedCommunities[2] = 0;
    expectedCommunities[3] = 0;
    expectedCommunities[4] = 4;

    louvain(graph);
    compareCommunities(graph, expectedCommunities);

    // Cleanup
    for (int i = 0; i < graph->numNodes; i++) {
        free(graph->nodes[i]->neighbors);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);
}



MU_TEST_SUITE(louvain_tests){
  printf("========== TEST SUITE 1 ==========\n");
  MU_RUN_TEST(test_louvain_5N_6E);

}

int main(){
  MU_RUN_SUITE(louvain_tests);
  MU_REPORT();

}