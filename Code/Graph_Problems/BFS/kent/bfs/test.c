// test.c (for testing bfs.c)

//System imports
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Util Imports
# include "../../../../Utilities/c-utils/src/graph.h"

//User defined imports
#include "bfs.h"

// Gobal Variables

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KCYN  "\x1B[36m"

// Global Functions

void success_or_failure(int res) {
    if (res == 1) {
        printf(KGRN "success!\n" KNRM);
    } else {
        printf(KRED "failure!\n" KNRM);
    }
}

//Test Functions

// Unit test for graph


static void test_empty_graph(){
	/*
	Tests that an empty graph has no nodes or edges
	*/

	printf("\n\n==== Test Empty Graph Properties ====\n");

	// Init

	graph_t test_graph = g_init();

	// Tests

	printf("Empty graph has 0 nodes: ");
	
	if (g_num_vertices(test_graph)==0){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	printf("Empty graph has 0 edges: ");
	
	if (g_num_edges(test_graph)==0){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	// Cleanup

	g_free_alt(test_graph, false);

}

static void test_single_node_exists(){
	/*
	Tests that a singleton graph has one nodes and no edges
	*/

	printf("\n\n==== Test Singleton Graph Properties ====\n");

	// Init
	
	graph_t test_graph = g_init();
	g_vertex_add(test_graph, "A");

	// Tests

	printf("Singleton graph has 1 node: ");

	if (g_num_vertices(test_graph)==1){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	printf("Singleton graph has 0 edges: ");
	
	if (g_num_edges(test_graph)==0){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	// Cleanup

	g_free_alt(test_graph, false);
}

static void test_node_edge_to_self_exists(){
	/*
	Tests that a self-referential node has one nodes and one edge to itself
	*/

	printf("\n\n==== Test Self-Reference Graph Properties ====\n");
	
	// Init for tests

	graph_t test_graph = g_init();
	g_vertex_add(test_graph, "A");
	g_edge_add(test_graph, 0, 0, "1");

	// Tests

	printf("Self-Reference graph has 1 node: ");

	if (g_num_vertices(test_graph)==1){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	printf("Self-Reference graph has 1 edge: ");
	
	if (g_num_edges(test_graph)==1){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	printf("Self-Reference graph has same source and origin: ");

	edge_t e = g_edge_get(test_graph, 0);

	unsigned int src_node = g_edge_src(e);
	unsigned int dst_node = g_edge_dest(e);

	if (src_node == dst_node){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	// Clean up

	g_free_alt(test_graph, false);

}


static void test_two_node_graph(){

	/*
	Tests that a simple two-node single edge graph behaves as expected
	*/

	printf("\n\n==== Test Two-Node Graph ====\n");
	
	// Init for tests

	graph_t test_graph = g_init();
	g_vertex_add(test_graph, "A");
	g_vertex_add(test_graph, "B");
	g_edge_add(test_graph, 0, 1, "1");

	// Tests

	printf("2-Node graph has 2 nodes: ");

	if (g_num_vertices(test_graph)==2){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	printf("2-Node graph has 1 edge: ");
	
	if (g_num_edges(test_graph)==1){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	printf("2-Node graph edge has different source and origin: ");

	edge_t e = g_edge_get(test_graph, 0);

	unsigned int src_node = g_edge_src(e);
	unsigned int dst_node = g_edge_dest(e);

	if (src_node != dst_node){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	// Clean up

	g_free_alt(test_graph, false);

}

static void test_get_all_edges_from_node(){

	printf("\n\n==== Test Get All Edges from Node ====\n");

	//Init (graph taken from Fig 3.1 of Kleinberg & Tardos)

	graph_t test_graph = g_init();
	g_vertex_add(test_graph, "1"); //0
	g_vertex_add(test_graph, "2"); //1
	g_vertex_add(test_graph, "3"); //2
	g_vertex_add(test_graph, "4"); //3
	g_vertex_add(test_graph, "5"); //4
	g_vertex_add(test_graph, "6"); //5
	g_vertex_add(test_graph, "7"); //6
	g_vertex_add(test_graph, "8"); //7
	g_vertex_add(test_graph, "9"); //8

	g_edge_add(test_graph, 0, 1, "A"); // (1,2)
	g_edge_add(test_graph, 1, 2, "B"); // (2,3)
	g_edge_add(test_graph, 1, 3, "C"); // (2,4)
	g_edge_add(test_graph, 0, 4, "D"); // (1,5)
	g_edge_add(test_graph, 4, 5, "E"); // (5,6)
	g_edge_add(test_graph, 0, 6, "F"); // (1,7)
	g_edge_add(test_graph, 6, 7, "G"); // (7,8)
	g_edge_add(test_graph, 6, 8, "H"); // (7,9)

	//Test

	printf("Node 1 in graph should have 3 edges: ");

	vertex_t node_1 = g_vertex_get(test_graph, 0);

	if ((g_vertex_num_edges_out(node_1)+ g_vertex_num_edges_in(node_1)) == 3){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	printf("Node 9 in graph should have 1 edge: ");

	vertex_t node_9 = g_vertex_get(test_graph, 8);

	if ((g_vertex_num_edges_out(node_9)+ g_vertex_num_edges_in(node_9)) == 1){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}

	//cleanup

	g_free_alt(test_graph, false);

}

static void test_get_adjacent_nodes(){

	printf("\n\n==== Test Get All Adjacent Nodes ====\n");

	//Init  - graph taken from Fig 3-1 of Kleinberg and Tardos -

	graph_t test_graph = g_init();

	printf("Graph Initalized\n");

	g_vertex_add(test_graph, "1"); //0
	g_vertex_add(test_graph, "2"); //1
	g_vertex_add(test_graph, "3"); //2
	g_vertex_add(test_graph, "4"); //3
	g_vertex_add(test_graph, "5"); //4
	g_vertex_add(test_graph, "6"); //5
	g_vertex_add(test_graph, "7"); //6
	g_vertex_add(test_graph, "8"); //7
	g_vertex_add(test_graph, "9"); //8

	printf("Nodes Initalized\n");

	g_edge_add(test_graph, 0, 1, "A"); // (1,2)
	g_edge_add(test_graph, 1, 2, "B"); // (2,3)
	g_edge_add(test_graph, 1, 3, "C"); // (2,4)
	g_edge_add(test_graph, 0, 4, "D"); // (1,5)
	g_edge_add(test_graph, 4, 5, "E"); // (5,6)
	g_edge_add(test_graph, 0, 6, "F"); // (1,7)
	g_edge_add(test_graph, 6, 7, "G"); // (7,8)
	g_edge_add(test_graph, 6, 8, "H"); // (7,9)

	printf("Edges Initalized\n");

	//Test

	printf("Node 1 should have neighbours 2, 5 and 7: ");

	vertex_t node_1 = g_vertex_get(test_graph, 0);
	int num_edges = (g_vertex_num_edges_out(node_1)+g_vertex_num_edges_in(node_1));
	char neighbours[10];

	for (int i = 0; i < num_edges; i++)
	{
		edge_t e = g_vertex_edge(node_1,i);
		unsigned int edge_id = g_edge_id(e);
		unsigned int u_id = g_edge_dest(e);
		vertex_t u = g_vertex_get(test_graph, u_id);
		char *u_metadata = g_vertex_metadata(u);		
		
		strcat(neighbours, u_metadata);
		strcat(neighbours," ");
	}

	if (strcmp(neighbours, "2 5 7 ") == 0){
		success_or_failure(1);
	}
	else{
		success_or_failure(0);
	}


	/*

	TO DO - FIGURE OUT HOW TO COUNT THE INCOMING EDGES AS WELL AS THE OUTGOING

	*/

	printf("Node 2 should have neighbours 1, 3 and 4: ");

	vertex_t node_2 = g_vertex_get(test_graph, 1);

	edge_t e2;
	unsigned int j;
	g_iterate_edges(node_2, e2, j) {
        vertex_t dest = g_vertex_get(test_graph, g_edge_dest(e2));
        printf("%s ", g_vertex_metadata(dest));
    }


	//cleanup

	g_free_alt(test_graph, false);



}

// Unit tests for set


static void test_set_empty(){


}

static void test_set_single_item(){

}

static void test_set_two_items(){

}

static void test_set_no_duplicates_added(){

}

// Unit tests for Queue

static void test_queue_empty(){

}

static void test_queue_single_item(){

}

static void test_queue_enqueue(){

}

static void test_queue_pop(){

}

// Unit Tests for BFS Primitives

static void test_get_node_children(){

}

static void test_add_child_to_queue(){

}

// BFS Integration Tests

static void test_bfs_single_vertex(){

}

static void test_bfs_single_vertex_with_loop(){

}

static void test_bfs_two_verticies_no_path(){

}

static void test_bfs_two_verticies_with_simple_path(){

}

static void test_bfs_complete_graph(){

}

static void test_bfs_cycle(){

}

//Main Function
int main(){
	test_empty_graph();
	test_single_node_exists();
	test_node_edge_to_self_exists();
	test_two_node_graph();
	test_get_all_edges_from_node();
	test_get_adjacent_nodes();
}