//System Imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>

//Util Imports
#include "/Users/nani/Documents/GitHub/summer2023/Code/Utilities/c-utils/src/string_builder.h"

//User Imports
#include "bfs.h"

static void test_one(){
    // Define the graph edges
    struct Edge edges[] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 1}, {2, 4}, {3, 4}, {4, 3}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    // Create the graph
    struct Graph* graph = createGraph(edges, numEdges);
    // Print the graph
    printGraph(graph);
      // TESTING
    // Perform BFS traversal starting from vertex 0 until end
    const char * test_bfs_start_0 = bfs(graph, 0);
    assert(strcmp(test_bfs_start_0, "0 2 1 4 3 ")==0);
    
    const char * test_bfs_start_1 = bfs(graph, 1);
    assert(strcmp(test_bfs_start_1, "1 3 4 ")==0);

    const char * test_bfs_start_2 = bfs(graph, 2);
    assert(strcmp(test_bfs_start_2, "2 4 1 3 ")==0);
    
    const char * test_bfs_start_3 = bfs(graph, 3);
    assert(strcmp(test_bfs_start_3, "3 4 ")==0);
    
    const char * test_bfs_start_4 = bfs(graph, 4);
    assert(strcmp(test_bfs_start_4, "4 3 ")==0);

    // Cleanup and exit
    free(graph);

}

