// Code/Graph_Problems/CommunityDetection/Louvian/Sequential/test_louvian.c

//System Imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


//Util Imports
#include "../../../../Utilities/c-utils/src/minunit.h"

//User Imports
#include "louvian_sequential.h"



MU_TEST(test_louvain_3N_5E){
  printf("this test checks if this works on a graph with 3 nodes and 5 edges\n");

  int numNodes = 3;
    Graph* graph = createGraph(numNodes);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 0);
    addEdge(graph, 2, 0);

    // Perform Louvain algorithm
    louvain(graph);

    // Check the communities
    assert(graph->nodes[0]->community == graph->nodes[1]->community);
    assert(graph->nodes[0]->community == graph->nodes[2]->community);

    // Cleanup
    for (int i = 0; i < numNodes; i++) {
        free(graph->nodes[i]->neighbors);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);

}

MU_TEST(test_louvain_different_communities){

  printf("this test checks if louvain alg works on a graph with multiple communities\n");

  int numNodes = 6;
    Graph* graph = createGraph(numNodes);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 0);

    // Perform Louvain algorithm
    louvain(graph);

    // Check the communities
    assert(graph->nodes[0]->community == graph->nodes[1]->community);
    assert(graph->nodes[0]->community == graph->nodes[2]->community);
    assert(graph->nodes[3]->community == graph->nodes[4]->community);
    assert(graph->nodes[3]->community == graph->nodes[5]->community);
    assert(graph->nodes[0]->community != graph->nodes[3]->community);

    // Cleanup
    for (int i = 0; i < numNodes; i++) {
        free(graph->nodes[i]->neighbors);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);

}

MU_TEST(test_louvain_empty_graph){

  printf("this test checks if louvain alg works on an empty graph\n");
      int numNodes = 0;
    Graph* graph = createGraph(numNodes);

    // Perform Louvain algorithm
    louvain(graph);

    // No communities should be detected in an empty graph
    assert(graph->numNodes == 0);

    // Cleanup
    free(graph);
}

MU_TEST(test_louvain_single_node){

  printf("this test checks if louvain alg works on a graph with a single node\n");

  int numNodes = 1;
    Graph* graph = createGraph(numNodes);

    // Perform Louvain algorithm
    louvain(graph);

    // The single node should be assigned to its own community
    assert(graph->nodes[0]->community == 0);

    // Cleanup
    free(graph->nodes[0]->neighbors);
    free(graph->nodes[0]);
    free(graph->nodes);
    free(graph);
}

MU_TEST(test_louvain_disconnected_nodes){

  printf("this test checks if louvain alg works on a graph with disconnected nodes\n");

  int numNodes = 2;
    Graph* graph = createGraph(numNodes);

    // Perform Louvain algorithm
    louvain(graph);

    // Each node should be assigned to its own community
    assert(graph->nodes[0]->community == 0);
    assert(graph->nodes[1]->community == 1);

    // Cleanup
    for (int i = 0; i < numNodes; i++) {
        free(graph->nodes[i]->neighbors);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);
}

MU_TEST(test_louvain_complete_graph){
  printf("this test checks if louvain alg works on a complete graph\n");
   int numNodes = 5;
    Graph* graph = createGraph(numNodes);

    // Add edges to create a complete graph
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            addEdge(graph, i, j);
        }
    }

    // Perform Louvain algorithm
    louvain(graph);

    // All nodes should be assigned to the same community
    for (int i = 0; i < numNodes; i++) {
        assert(graph->nodes[i]->community == 0);
    }

    // Cleanup
    for (int i = 0; i < numNodes; i++) {
        free(graph->nodes[i]->neighbors);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);
}

MU_TEST(test_louvain_triangle_graph){
  printf("this test checks if louvain alg works on a triangle graph\n");
  int numNodes = 3;
    Graph* graph = createGraph(numNodes);

    // Add edges to create a triangle graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    // Perform Louvain algorithm
    louvain(graph);

    // Each node should be assigned to their own community
    assert(graph->nodes[0]->community == 0);
    assert(graph->nodes[1]->community == 1);
    assert(graph->nodes[2]->community == 2);

    // Cleanup
    for (int i = 0; i < numNodes; i++) {
        free(graph->nodes[i]->neighbors);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);
}

MU_TEST(test_louvain_large_graph){
  printf("This test checks if Louvain algorithm works on a large graph\n");
    int numNodes = 8;
    Graph* graph = createGraph(numNodes);

    // Add edges to create a graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 7);

    // Perform Louvain algorithm
    louvain(graph);

    // Assert the community assignments
    assert(graph->nodes[0]->community == 0);
    assert(graph->nodes[1]->community == 0);
    assert(graph->nodes[2]->community == 0);
    assert(graph->nodes[3]->community == 1);
    assert(graph->nodes[4]->community == 2);
    assert(graph->nodes[5]->community == 2);
    assert(graph->nodes[6]->community == 2);
    assert(graph->nodes[7]->community == 2);

    // Cleanup
    for (int i = 0; i < numNodes; i++) {
        free(graph->nodes[i]->neighbors);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);
}






MU_TEST_SUITE(louvain_tests){
  printf("========== TEST SUITE 1 ==========\n");
  MU_RUN_TEST(test_louvain_3N_5E);
  MU_RUN_TEST(test_louvain_empty_graph);
  MU_RUN_TEST(test_louvain_single_node);
  MU_RUN_TEST(test_louvain_disconnected_nodes);
  MU_RUN_TEST(test_louvain_different_communities);
  MU_RUN_TEST(test_louvain_triangle_graph);
  MU_RUN_TEST(test_louvain_large_graph);

}

int main(){
  MU_RUN_SUITE(louvain_tests);
  MU_REPORT();

}