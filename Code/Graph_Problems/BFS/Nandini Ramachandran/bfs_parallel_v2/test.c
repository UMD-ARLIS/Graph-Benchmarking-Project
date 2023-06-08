//System Imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>

//Util Imports
#include "../../../../Utilities/c-utils/src/minunit.h"

//User Imports
#include "bfs.h"

MU_TEST(test_bfs_single_edge){
  printf("this test checks if this graph works on a single edge\n");

   // Define the graph edges
    struct Edge edges[] = {
        {0, 1}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    // Create the graph
    struct Graph* graph = createGraph(edges, numEdges);

    const char * test_bfs_start_0 = bfs(graph, 0);
    mu_assert_int_eq(strcmp(test_bfs_start_0, "0 1 "),0);

    // Cleanup and exit
    free(graph);
}

MU_TEST(test_bfs_multiple_edges){
  printf("this test checks if the bfs algo works on a graph with multiple edges\n");

   // Define the graph edges
    struct Edge edges[] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 1}, {2, 4}, {3, 4}, {4, 3}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    // Create the graph
    struct Graph* graph = createGraph(edges, numEdges);

    const char * test_bfs_start_0 = bfs(graph, 0);
    mu_assert_int_eq(strcmp(test_bfs_start_0, "0 2 1 4 3 "),0);

    // Cleanup and exit
    free(graph);
}

MU_TEST(test_bfs_disconnected_graph){
  printf("this test checks if the bfs algo works on a disconnected graph\n");

   // Define the graph edges
    struct Edge edges[] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 1}, {2, 4}, {3, 4}, {4, 3}, {5, 6}, {6, 7}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    // Create the graph
    struct Graph* graph = createGraph(edges, numEdges);

    const char * test_bfs_start_0 = bfs(graph, 0);
    mu_assert_int_eq(strcmp(test_bfs_start_0, "0 2 1 4 3 "),0);

    const char * test_bfs_start_5 = bfs(graph, 5);
    mu_assert_int_eq(strcmp(test_bfs_start_5, "5 6 7 "),0);

    // Cleanup and exit
    free(graph);
}

MU_TEST(test_bfs_empty_graph){
  printf("this test checks if the bfs algo works on an empty graph\n");

    struct Graph* graph = createGraph(NULL, 0);

    const char * test_bfs_start_0 = bfs(graph, 0);
    mu_assert_int_eq(strcmp(test_bfs_start_0, ""),0);

    // Cleanup and exit
    free(graph);
}

MU_TEST(test_bfs_cycle_graph){
  printf("this test checks if the bfs algo works on a graph with cycles\n");

   // Define the graph edges
    struct Edge edges[] = {
        {0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 2}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    // Create the graph
    struct Graph* graph = createGraph(edges, numEdges);

    const char * test_bfs_start_0 = bfs(graph, 0);
    mu_assert_int_eq(strcmp(test_bfs_start_0, "0 1 2 3 4 "),0);

    // Cleanup and exit
    free(graph);
}

MU_TEST_SUITE(bfs_tests){
  printf("========== TEST SUITE 1 ==========\n");
  MU_RUN_TEST(test_bfs_single_edge);
  MU_RUN_TEST(test_bfs_multiple_edges);
  MU_RUN_TEST(test_bfs_disconnected_graph);
  MU_RUN_TEST(test_bfs_empty_graph);
  MU_RUN_TEST(test_bfs_cycle_graph);
}

int main(){
  //test_one();
  MU_RUN_SUITE(bfs_tests);
  MU_REPORT();
}