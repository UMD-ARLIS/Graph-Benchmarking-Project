//summer2023/Code/Utilities/dataLoader/test.c

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

# include "../c-utils/src/minunit.h"
# include "../c-utils/src/graph.h"
# include "dataLoader.h"

/* # # # # # # # # # # # # #
# Tests - Directed Graphs
# # # # # # # # # # # # # #*/

MU_TEST(test_no_input) {
    printf("Test that no input returns an empty graph \n");
	
	//init
	char* inputFile; 
	inputFile = "";
	graph_t output = g_init();
	char mode = 'd';

	output = loadGraph(inputFile, output, mode);

    mu_assert_int_eq(0, g_num_vertices(output));

	g_free_alt(output, FALSE);
}


/*
MU_TEST(test_single_line){
	printf("Test that a single line can be loaded in from file\n");

	//init
	char* inputFile; 
	inputFile = "files_for_tests/01_singleLine.in";
	
	char *output = loadGraph(inputFile);
	mu_assert_string_eq("#TITLE: LINE01", output);
	}
*/

/*
MU_TEST(test_multi_line){
	printf("Test that multiple lines can be loaded in from file\n");

	//init
	char* inputFile; 
	inputFile = "files_for_tests/02_multiLine.in";
	
	char *output = loadGraph(inputFile);
	mu_assert_string_eq("#TITLE: LINE01\n#SOURCE: LINE02", output);
	}
	*/

MU_TEST(test_single_vertex){
	printf("Test that a single vertex can be created from file\n");

	//init
	char* inputFile; 
	inputFile = "files_for_tests/03_singleVertex.in";
	graph_t output = g_init();
	char mode = 'd';

	output = loadGraph(inputFile, output, mode);

	//tests 
	mu_assert_int_eq(1, g_num_vertices(output));
	mu_assert_int_eq(0,g_num_edges(output));

	//cleanup
	g_free_alt(output, FALSE);

}

MU_TEST(test_single_vertex_single_edge){
	printf("Test that a single vertex with self-pointing edge can be created from file\n");

	//init
	char* inputFile; 
	inputFile = "files_for_tests/04_singleVertexSingleEdge.in";
	graph_t output = g_init();
	char mode = 'd';

	output = loadGraph(inputFile, output, mode);
	//tests 
	mu_assert_int_eq(1, g_num_vertices(output));
	mu_assert_int_eq(1,g_num_edges(output));

	//cleanup
	g_free_alt(output, FALSE);

}

MU_TEST(test_two_vertex_single_edge){
	printf("Test that two verticies with simple edge can be created from file\n");

	//init
	char* inputFile; 
	inputFile = "files_for_tests/05_twoVertexSingleEdge.in";
	graph_t output = g_init();
	char mode = 'd';

	output = loadGraph(inputFile, output, mode);
	//tests 
	mu_assert_int_eq(2, g_num_vertices(output));
	mu_assert_int_eq(1,g_num_edges(output));

	//cleanup
	g_free_alt(output, FALSE);

}

MU_TEST(full_acyclic_graph){
	printf("Test that full acyclic graph can be created from file\n");

	//init
	char* inputFile; 
	inputFile = "files_for_tests/06_fullAcyclicGraph.in";
	graph_t output = g_init();
	char mode = 'd';

	output = loadGraph(inputFile, output, mode);
	//tests 
	mu_assert_int_eq(9, g_num_vertices(output));
	mu_assert_int_eq(8,g_num_edges(output));

	//cleanup
	g_free_alt(output, FALSE);

}

MU_TEST(hard_graph){
	printf("Test that the data loader can create a graph with disjoint subgraphs and cycles from file");
	
	//init
	char* inputFile; 
	inputFile = "files_for_tests/07_hardGraph.in";
	graph_t output = g_init();
	char mode = 'd';

	output = loadGraph(inputFile, output, mode);
	
		//tests 
	mu_assert_int_eq(13, g_num_vertices(output));
	mu_assert_int_eq(14,g_num_edges(output));

	//cleanup
	g_free_alt(output, FALSE);
}

/* # # # # # # # # # # # # #
# Tests - Undirected graphs
# # # # # # # # # # # # # #*/

MU_TEST(test_no_input_undirected) {
    printf("Test that no input returns an empty undirected graph \n");
	
	//init
	char* inputFile = "";
	char mode = 'u';								//undirected mode
    graph_t output = g_init();
	output = loadGraph(inputFile, output, mode);
	
	//Test
    mu_assert_int_eq(0, g_num_vertices(output));
	mu_assert_int_eq(0, g_num_edges(output));
	
	//Cleanup
	g_free_alt(output, FALSE);
}

MU_TEST(test_single_node_undirected) {
    printf("Test that a single node returns a graph with a single node \n");
	
	//init
	char* inputFile = "files_for_tests/03_singleVertex.in";
	char mode = 'u';								//undirected mode
    graph_t output = g_init();
	output = loadGraph(inputFile, output, mode);
	
	//Test
    mu_assert_int_eq(1, g_num_vertices(output));
	mu_assert_int_eq(0, g_num_edges(output));

	
	//Cleanup
	g_free_alt(output, FALSE);
}

MU_TEST(test_single_node_single_edge_undirected) {
    printf("Test that a single node and single returns a graph with a single node and self-referent edge \n");
	
	//init
	char* inputFile = "files_for_tests/04_singleVertexSingleEdge.in";
	char mode = 'u';								//undirected mode
    graph_t output = g_init();
	output = loadGraph(inputFile, output, mode);
	
	//Test
    mu_assert_int_eq(1, g_num_vertices(output));
	mu_assert_int_eq(1, g_num_edges(output));

	
	//Cleanup
	g_free_alt(output, FALSE);
}

MU_TEST(test_two_node_single_edge_undirected) {
    printf("Test that two node and single returns a graph with a single node and undirected edges \n");
	
	//init
	char* inputFile = "files_for_tests/05_twoVertexSingleEdge.in";
	char mode = 'u';								//undirected mode
    graph_t output = g_init();
	output = loadGraph(inputFile, output, mode);
	
	//Test
    mu_assert_int_eq(2, g_num_vertices(output));
	mu_assert_int_eq(2, g_num_edges(output));					//Undirected implemented as edges exist in both directions. 

	
	//Cleanup
	g_free_alt(output, FALSE);
}

MU_TEST(test_full_acyclic_graph_undirected) {
    printf("Test that full Acyclic graph can be made undirected \n");
	
	//init
	char* inputFile = "files_for_tests/06_fullAcyclicGraph.in";
	char mode = 'u';								//undirected mode
    graph_t output = g_init();
	output = loadGraph(inputFile, output, mode);
	
	//Test
    mu_assert_int_eq(9, g_num_vertices(output));
	mu_assert_int_eq(16, g_num_edges(output));					//Undirected implemented as edges exist in both directions. 

	
	//Cleanup
	g_free_alt(output, FALSE);
}

MU_TEST(test_hard_graph_undirected) {
    printf("Test that graph with disjoint subgraphs and cycles can be made undirected \n");
	
	//init
	char* inputFile = "files_for_tests/07_hardGraph.in";
	char mode = 'u';								//undirected mode
    graph_t output = g_init();
	output = loadGraph(inputFile, output, mode);
	
	//Test
    mu_assert_int_eq(13, g_num_vertices(output));
	mu_assert_int_eq(28, g_num_edges(output));					//Undirected implemented as edges exist in both directions. 

	
	//Cleanup
	g_free_alt(output, FALSE);
}



/* # # # # # # # # # # # # #
# Tests Suite Defintions
# # # # # # # # # # # # # # */

// Test from file
MU_TEST_SUITE(suite_in_file) {
	printf("\n\n==========Test Suite - Load from File==========\n");
    MU_RUN_TEST(test_no_input);
    //MU_RUN_TEST(test_single_line);
   	//MU_RUN_TEST(test_multi_line);
    MU_RUN_TEST(test_single_vertex);
    MU_RUN_TEST(test_single_vertex_single_edge);
    MU_RUN_TEST(test_two_vertex_single_edge);
    MU_RUN_TEST(full_acyclic_graph); 
	MU_RUN_TEST(hard_graph);
}

MU_TEST_SUITE(suite_undirected_graphs){
	printf("\n\n==========Test Suite - Undirected Graph Tests==========\n");

	MU_RUN_TEST(test_no_input_undirected);
	MU_RUN_TEST(test_single_node_undirected);
	MU_RUN_TEST(test_single_node_single_edge_undirected);
	MU_RUN_TEST(test_two_node_single_edge_undirected);
	MU_RUN_TEST(test_full_acyclic_graph_undirected);
	MU_RUN_TEST(test_hard_graph_undirected);
}


/* # # # # # # # # # # # # #
# Main Program invocation
# # # # # # # # # # # # # # */

int main() {
    MU_RUN_SUITE(suite_in_file);
	MU_RUN_SUITE(suite_undirected_graphs);
    MU_REPORT();
    printf("Number failed tests: %d\n", minunit_fail);
    return minunit_fail;
}