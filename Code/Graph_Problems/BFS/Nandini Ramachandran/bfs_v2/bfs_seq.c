//
//  main.m
//  BFS
//
//  Created by Nandini Ramachandran on 5/31/23.
//

// BFS algorithm in C
// This algorithm was written with the help of https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

//System Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

//Util Inclusion
#include "../../../../Utilities/c-utils/src/string_builder.h"

//User Inclusion
#include "bfs_seq.h"



void printGraph(struct Graph* graph)
{
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        // print current vertex and all its neighbors
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->end);
            ptr = ptr->next;
        }
 
        printf("\n");
    }
}

const char * bfs(struct Graph* graph, int s){
    printf("BFS Traversal - Start Vertex: ");
    printf("%d",s);
    printf("\n");
    struct str_builder *path = str_builder_create();
    // Mark all the vertices as not visited
        bool visited[NUM_VERTICES];
        for (int i = 0; i < NUM_VERTICES; i++) {
            visited[i] = false;
        }
     
        // Create a queue for BFS
        int queue[NUM_VERTICES];
        int front = 0, rear = 0;
     
        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue[rear++] = s;
     
        while (front != rear) {
            // Dequeue a vertex from queue, add it to path, and print
            s = queue[front++];
            str_builder_add_int(path,s);
            str_builder_add_char(path, ' ');
            printf("%d ", s);
     
            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            struct Node* current = graph->head[s];
                    while (current != NULL) {
                        int adjacent = current->end;
                        if (!visited[adjacent]) {
                            visited[adjacent] = true;
                            queue[rear++] = adjacent;
                        }
                        current = current->next;
                    }
            
        }
      
    printf("\n");
    
    // return the completed BFS search path
    return str_builder_peek(path);
}


void test(struct Edge edges[], int numEdges){
    struct Graph* graph = createGraph(edges, numEdges);
    printGraph(graph);
    
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

}

void testOne(struct Edge edges[], int numEdges){
    struct Graph* graph = createGraph(edges, numEdges);
    printGraph(graph);
    
    const char * test_bfs_start_0 = bfs(graph, 0);
    assert(strcmp(test_bfs_start_0, "0 3 2 1 5 4 ")==0);
    
    const char * test_bfs_start_1 = bfs(graph, 1);
    assert(strcmp(test_bfs_start_1, "1 5 4 2 ")==0);

    const char * test_bfs_start_2 = bfs(graph, 2);
    assert(strcmp(test_bfs_start_2, "2 ")==0);

    const char * test_bfs_start_3 = bfs(graph, 3);
    assert(strcmp(test_bfs_start_3, "3 2 ")==0);

    const char * test_bfs_start_4 = bfs(graph, 4);
    assert(strcmp(test_bfs_start_4, "4 ")==0);
    
    const char * test_bfs_start_5 = bfs(graph, 5);
    assert(strcmp(test_bfs_start_5, "5 ")==0);

}

int main(void) {
    // testing BFS on first graph
    struct Edge edges[] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 1}, {2, 4}, {3, 4}, {4, 3}
    };
    int numEdges = sizeof(edges)/sizeof(edges[0]);
    test(edges, numEdges);
    
    //testing BFS on second graph
    struct Edge edgesOne[] = {
        {0, 1}, {0, 2}, {0, 3}, {3, 2}, {1, 2}, {1, 4}, {1, 5}
    };
    int numEdgesOne = sizeof(edgesOne)/sizeof(edgesOne[0]);
    testOne(edgesOne, numEdgesOne);
    
  return 0;
}


