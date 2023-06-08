//summer2023/Code/Utilities/dataLoader/test.c

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

# include "../c-utils/src/minunit.h"
# include "../c-utils/src/graph.h"
# include "dataLoader.h"

MU_TEST(test_no_input) {
    printf("Test that no input triggers a no input error\n");
	
	//init
	char* inputFile; 
	inputFile = "";

    graph_t output = g_init();
	output = loadGraph(inputFile, output);
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
	output = loadGraph(inputFile, output);											//return a graph generated from the input file to the output variable

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
	output = loadGraph(inputFile, output);											//return a graph generated from the input file to the output variable

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
	output = loadGraph(inputFile, output);											//return a graph generated from the input file to the output variable

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
	output = loadGraph(inputFile, output);											//return a graph generated from the input file to the output variable

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
	output = loadGraph(inputFile, output);											//return a graph generated from the input file to the output variable

	//tests 
	mu_assert_int_eq(13, g_num_vertices(output));
	mu_assert_int_eq(14,g_num_edges(output));

	//cleanup
	g_free_alt(output, FALSE);
}

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


int main() {
    MU_RUN_SUITE(suite_in_file);
    MU_REPORT();
    printf("Number failed tests: %d\n", minunit_fail);
    return minunit_fail;
}