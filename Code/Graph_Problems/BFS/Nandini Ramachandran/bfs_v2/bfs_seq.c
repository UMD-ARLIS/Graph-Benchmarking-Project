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


struct Graph* createGraph(struct Edge edges[], int numEdges){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    
    //sets all the head references to null
    for (int i = 0; i < NUM_VERTICES; i++){
        graph->head[i] = NULL;
    }
    for (int i = 0; i < numEdges; i++){
        //gets start and end vertices
        int start = edges[i].start;
        int end = edges[i].end;
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->end = end;
        
        //points the new node to the current head
        newNode->next = graph->head[start];
        //points head to the new node
        graph->head[start] = newNode;
    }
    return graph;
}

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

