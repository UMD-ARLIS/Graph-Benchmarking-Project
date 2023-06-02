//
//  main.m
//  BFS
//
//  Created by Nandini Ramachandran on 5/31/23.
//

// BFS algorithm in C

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

// Define the maximum number of vertices in the graph
#define NUM_VERTICES 6



struct Graph{
    struct Node* head[NUM_VERTICES];
};

struct Node{
    int end;
    struct Node* next;
};

struct Edge{
    int start;
    int end;
};

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

void bfs(struct Graph* graph, int s){
    printf("BFS Traversal - Start Vertex: ");
    printf("%d",s);
    printf("\n");
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
            // Dequeue a vertex from queue and print it
            s = queue[front++];
            printf("%d ", s);
     
            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (int adjacent = 0; adjacent < NUM_VERTICES;
                 adjacent++) {
                if (graph->head[adjacent] && !visited[adjacent]) {
                    visited[adjacent] = true;
                    queue[rear++] = adjacent;
                }
            }
        }
      
    printf("\n");
}


void test(void){
    struct Edge edges[] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 1}, {2, 4}, {3, 4}, {4, 3}
    };
    int numEdges = sizeof(edges)/sizeof(edges[0]);
    struct Graph* graph = createGraph(edges, numEdges);
    printGraph(graph);
    bfs(graph, 0);
    bfs(graph, 1);
    bfs(graph, 2);
    bfs(graph, 3);
    bfs(graph, 4);
    
}




int main(void) {
    test();
  return 0;
}


