//
//  bfs.c
//  BFS_Parallel_CPU
//
//  Created by Nandini Ramachandran on 6/7/23.
//

// BFS algorithm Parallelized in C
// This algorithm was written with the help of https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
// Reference: https://cse.buffalo.edu/faculty/miller/Courses/CSE633/Aditya-Nongmeikapam-Spring-2022.pdf

//System Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>

//Util Inclusion
#include "../../../../Utilities/c-utils/src/string_builder.h"


//User Inclusion
#include "bfs.h"


// Global mutex for synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to create a graph
struct Graph* createGraph(struct Edge edges[], int numEdges){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    // Sets all the head references to null
    for (int i = 0; i < NUM_VERTICES; i++){
        graph->head[i] = NULL;
    }
    
    // Build adjacency list representation of the graph
    for (int i = 0; i < numEdges; i++){
        // Get start and end vertices
        int start = edges[i].start;
        int end = edges[i].end;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->end = end;

        // Points the new node to the current head
        newNode->next = graph->head[start];
        // Points head to the new node
        graph->head[start] = newNode;
    }
    
    return graph;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < NUM_VERTICES; i++) {
        // Print current vertex and all its neighbors
        struct Node* ptr = graph->head[i];
        while (ptr != NULL) {
            printf("(%d —> %d)\t", i, ptr->end);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

// Thread function for performing BFS
void* bfsThread(void* arg) {
    struct BFSData* data = (struct BFSData*)arg;
    struct Graph* graph = data->graph;
    int s;

    // Loop until all vertices in the level are processed
    while (true) {
        // Lock the mutex to access the shared data
        pthread_mutex_lock(&mutex);
        // Check if the queue is empty
        if (data->front == data->rear) {
            // If queue is empty, unlock the mutex and exit the loop
            pthread_mutex_unlock(&mutex);
            break;
        }
        // Dequeue a vertex from the queue
        s = data->queue[data->front++];
        // Unlock the mutex
        pthread_mutex_unlock(&mutex);

        // Add the dequeued vertex to the BFS path
        str_builder_add_int(data->path, s);
        str_builder_add_char(data->path, ' ');
        printf("%d ", s);

        // Explore the adjacent vertices of the dequeued vertex
        struct Node* current = graph->head[s];
        while (current != NULL) {
            int adjacent = current->end;
            if (!data->visited[adjacent]) {
                // Lock the mutex to access the shared data
                pthread_mutex_lock(&mutex);
                // Mark the adjacent vertex as visited and enqueue it
                data->visited[adjacent] = true;
                data->queue[data->rear++] = adjacent;
                // Unlock the mutex
                pthread_mutex_unlock(&mutex);
            }
            current = current->next;
        }
    }

    return NULL;
}

// Function to perform BFS traversal
const char* bfs(struct Graph* graph, int startVertex) {
    //printf("BFS Traversal - Start Vertex: %d\n", startVertex);

    // Initialize BFS data structure
    struct BFSData bfsData;
    bfsData.graph = graph;
    bfsData.visited = (bool*)calloc(NUM_VERTICES, sizeof(bool));
    bfsData.queue = (int*)malloc(NUM_VERTICES * sizeof(int));
    bfsData.front = 0;
    bfsData.rear = 0;
    bfsData.path = str_builder_create();

    // Mark the start vertex as visited and enqueue it
    bfsData.visited[startVertex] = true;
    bfsData.queue[bfsData.rear++] = startVertex;

    // Create an array of threads
    pthread_t threads[NUM_VERTICES];

    // Create threads for BFS traversal
    for (int i = 0; i < NUM_VERTICES; i++) {
        pthread_create(&threads[i], NULL, bfsThread, (void*)&bfsData);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_VERTICES; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("\nBFS Traversal Path: %s\n", str_builder_peek(bfsData.path));
    const char* path = str_builder_peek(bfsData.path);
    
    // Clean up
    str_builder_destroy(bfsData.path);
    free(bfsData.visited);
    free(bfsData.queue);
    return path;
}



