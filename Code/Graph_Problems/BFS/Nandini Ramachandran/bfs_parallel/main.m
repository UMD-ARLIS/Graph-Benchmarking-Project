//
//  main.m
//  BFS_Parallel_CPU
//
//  Created by Nandini Ramachandran on 6/4/23.
//

// BFS algorithm Parallelized in C
// This algorithm was written with the help of https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
// Reference: https://cse.buffalo.edu/faculty/miller/Courses/CSE633/Aditya-Nongmeikapam-Spring-2022.pdf

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include "string_builder.h"

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

// Structure to hold BFS data
struct BFSData {
    struct Graph* graph;
    bool* visited;
    int* queue;
    int front;
    int rear;
    struct str_builder* path;
};

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
    printf("BFS Traversal - Start Vertex: %d\n", startVertex);

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

    // Clean up
    //str_builder_destroy(bfsData.path);
    free(bfsData.visited);
    free(bfsData.queue);
    return str_builder_peek(bfsData.path);
}

int main(void) {
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

    return 0;
}

