// Code/Graph_Problems/CommunityDetection/Louvian/Parallel/test_louvian_parallel.c

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
#include "louvian_parallel.h"

MU_TEST(test_louvain_triangle_graph){
  printf("Unit test for a triangular graph\n");

  // Create the graph
    int numNodes = 6;
    Graph* graph = createGraph(numNodes);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 3, 5);

    int numThreads = 2;  // Number of threads to use

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    ThreadArgs* threadArgs = (ThreadArgs*)malloc(numThreads * sizeof(ThreadArgs));
    int nodesPerThread = graph->numNodes / numThreads;
    int remainingNodes = graph->numNodes % numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; i++) {
        int end = start + nodesPerThread;

        // Distribute remaining nodes among threads
        if (remainingNodes > 0) {
            end++;
            remainingNodes--;
        }

        threadArgs[i].graph = graph;
        threadArgs[i].start = start;
        threadArgs[i].end = end;

        pthread_create(&threads[i], NULL, parallelLouvain, (void*)&threadArgs[i]);

        start = end;
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    free(threads);
    free(threadArgs);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Check the communities
    assert(graph->nodes[0]->community == 0);
    assert(graph->nodes[1]->community == 1);
    assert(graph->nodes[2]->community == 2);
    assert(graph->nodes[3]->community == 3);
    assert(graph->nodes[4]->community == 4);
    assert(graph->nodes[5]->community == 5);

}

MU_TEST(test_louvain_different_communities){

  printf("Unit test for a graph with multiple communities\n");

  // Create the graph
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

    int numThreads = 2;  // Number of threads to use

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    ThreadArgs* threadArgs = (ThreadArgs*)malloc(numThreads * sizeof(ThreadArgs));
    int nodesPerThread = graph->numNodes / numThreads;
    int remainingNodes = graph->numNodes % numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; i++) {
        int end = start + nodesPerThread;

        // Distribute remaining nodes among threads
        if (remainingNodes > 0) {
            end++;
            remainingNodes--;
        }

        threadArgs[i].graph = graph;
        threadArgs[i].start = start;
        threadArgs[i].end = end;

        pthread_create(&threads[i], NULL, parallelLouvain, (void*)&threadArgs[i]);

        start = end;
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    free(threads);
    free(threadArgs);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Check the communities
    assert(graph->nodes[0]->community == graph->nodes[1]->community);
    assert(graph->nodes[0]->community == graph->nodes[2]->community);
    assert(graph->nodes[3]->community == graph->nodes[4]->community);
    assert(graph->nodes[3]->community == graph->nodes[5]->community);
    assert(graph->nodes[0]->community != graph->nodes[3]->community);


}

MU_TEST(test_louvain_empty_graph){
printf("Unit test for empty graph\n");

  // Create the graph
    int numNodes = 0;
        Graph* graph = createGraph(numNodes);

    int numThreads = 2;  // Number of threads to use

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    ThreadArgs* threadArgs = (ThreadArgs*)malloc(numThreads * sizeof(ThreadArgs));
    int nodesPerThread = graph->numNodes / numThreads;
    int remainingNodes = graph->numNodes % numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; i++) {
        int end = start + nodesPerThread;

        // Distribute remaining nodes among threads
        if (remainingNodes > 0) {
            end++;
            remainingNodes--;
        }

        threadArgs[i].graph = graph;
        threadArgs[i].start = start;
        threadArgs[i].end = end;

        pthread_create(&threads[i], NULL, parallelLouvain, (void*)&threadArgs[i]);

        start = end;
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    free(threads);
    free(threadArgs);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Check the communities
    assert(graph->numNodes == 0);

    
}

MU_TEST(test_louvain_single_node){
printf("Unit test for a single-node graph\n");

  // Create the graph
    int numNodes = 1;
        Graph* graph = createGraph(numNodes);

    int numThreads = 2;  // Number of threads to use

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    ThreadArgs* threadArgs = (ThreadArgs*)malloc(numThreads * sizeof(ThreadArgs));
    int nodesPerThread = graph->numNodes / numThreads;
    int remainingNodes = graph->numNodes % numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; i++) {
        int end = start + nodesPerThread;

        // Distribute remaining nodes among threads
        if (remainingNodes > 0) {
            end++;
            remainingNodes--;
        }

        threadArgs[i].graph = graph;
        threadArgs[i].start = start;
        threadArgs[i].end = end;

        pthread_create(&threads[i], NULL, parallelLouvain, (void*)&threadArgs[i]);

        start = end;
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    free(threads);
    free(threadArgs);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Check the communities
    assert(graph->nodes[0]->community == 0);

    
}

MU_TEST(test_louvain_disconnected_nodes){
printf("Unit test for disconnected nodes graph\n");

    // Create a graph with disconnected nodes
    Graph* graph = createGraph(5);

    // Add edges to create disconnected nodes
    addEdge(graph, 0, 1);
    addEdge(graph, 2, 3);

    int numThreads = 2;  // Number of threads to use

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    ThreadArgs* threadArgs = (ThreadArgs*)malloc(numThreads * sizeof(ThreadArgs));
    int nodesPerThread = graph->numNodes / numThreads;
    int remainingNodes = graph->numNodes % numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; i++) {
        int end = start + nodesPerThread;

        // Distribute remaining nodes among threads
        if (remainingNodes > 0) {
            end++;
            remainingNodes--;
        }

        threadArgs[i].graph = graph;
        threadArgs[i].start = start;
        threadArgs[i].end = end;

        pthread_create(&threads[i], NULL, parallelLouvain, (void*)&threadArgs[i]);

        start = end;
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    free(threads);
    free(threadArgs);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Check the communities
    for (int i = 0; i < graph->numNodes; i++) {
        assert(graph->nodes[i]->community == i);
    }

    // Cleanup
    free(graph);

    
}

MU_TEST(test_louvain_complete_graph){
   printf("Unit test for a complete graph\n");

    // Create a complete graph with 6 nodes
    Graph* graph = createGraph(6);

    // Add edges to form a complete graph
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            addEdge(graph, i, j);
        }
    }

    int numThreads = 2;  // Number of threads to use

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    ThreadArgs* threadArgs = (ThreadArgs*)malloc(numThreads * sizeof(ThreadArgs));
    int nodesPerThread = graph->numNodes / numThreads;
    int remainingNodes = graph->numNodes % numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; i++) {
        int end = start + nodesPerThread;

        // Distribute remaining nodes among threads
        if (remainingNodes > 0) {
            end++;
            remainingNodes--;
        }

        threadArgs[i].graph = graph;
        threadArgs[i].start = start;
        threadArgs[i].end = end;

        pthread_create(&threads[i], NULL, parallelLouvain, (void*)&threadArgs[i]);

        start = end;
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    free(threads);
    free(threadArgs);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Ensure the nodes are assigned to the correct communities
    for (int i = 0; i < 6; i++) {
        assert(graph->nodes[i]->community == i);
    }

}

MU_TEST(test_louvain_large_graph){
       printf("Unit test for a large graph\n");

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

    int numThreads = 2;  // Number of threads to use

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t* threads = (pthread_t*)malloc(numThreads * sizeof(pthread_t));
    ThreadArgs* threadArgs = (ThreadArgs*)malloc(numThreads * sizeof(ThreadArgs));
    int nodesPerThread = graph->numNodes / numThreads;
    int remainingNodes = graph->numNodes % numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; i++) {
        int end = start + nodesPerThread;

        // Distribute remaining nodes among threads
        if (remainingNodes > 0) {
            end++;
            remainingNodes--;
        }

        threadArgs[i].graph = graph;
        threadArgs[i].start = start;
        threadArgs[i].end = end;

        pthread_create(&threads[i], NULL, parallelLouvain, (void*)&threadArgs[i]);

        start = end;
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    free(threads);
    free(threadArgs);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Ensure the nodes are assigned to the correct communities
    // Assert the community assignments
    assert(graph->nodes[0]->community == 0);
    assert(graph->nodes[1]->community == 0);
    assert(graph->nodes[2]->community == 0);
    assert(graph->nodes[3]->community == 1);
    assert(graph->nodes[4]->community == 2);
    assert(graph->nodes[5]->community == 2);
    assert(graph->nodes[6]->community == 2);
    assert(graph->nodes[7]->community == 2);
}


MU_TEST_SUITE(louvain_tests){
  printf("========== TEST SUITE 1 ==========\n");
  MU_RUN_TEST(test_louvain_empty_graph);
  MU_RUN_TEST(test_louvain_single_node);
  MU_RUN_TEST(test_louvain_disconnected_nodes);
  MU_RUN_TEST(test_louvain_different_communities);
  MU_RUN_TEST(test_louvain_complete_graph);
  MU_RUN_TEST(test_louvain_triangle_graph);
  MU_RUN_TEST(test_louvain_large_graph);
}

int main(){
  MU_RUN_SUITE(louvain_tests);
  MU_REPORT();

}