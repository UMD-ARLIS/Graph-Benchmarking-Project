//summer2023/Code/Utilities/dataLoader/test.c

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "../c-utils/src/minunit.h"
# include "../c-utils/src/graph.h"
# include "dataLoader.h"

MU_TEST(test_no_input) {
    printf("Test that no input triggers a no input error\n");
    char* output = loadGraph("");
    mu_assert_string_eq("<null pointer>", output);
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
	printf("Test that a single vertex can be created from file");

	//init
	char* inputFile; 
	inputFile = "files_for_tests/03_singleVertex.in";

	char* output = loadGraph(inputFile);
	mu_assert_string_eq("NODES CREATED: 1, EDGES CREATED: 0",output);

}

MU_TEST(test_single_vertex_single_edge){
	printf("Test that a single vertex with self-pointing edge can be created from file");

	//init
	char* inputFile; 
	inputFile = "files_for_tests/04_singleVertexSingleEdge.in";

	char* output = loadGraph(inputFile);
	mu_assert_string_eq("NODES CREATED: 1, EDGES CREATED: 1",output);

}

// Test from in memory
MU_TEST_SUITE(suite_in_file) {
	printf("\n\n==========Test Suite - Load from File==========\n");
    MU_RUN_TEST(test_no_input);
    //MU_RUN_TEST(test_single_line);
   	//MU_RUN_TEST(test_multi_line);
    MU_RUN_TEST(test_single_vertex);
    MU_RUN_TEST(test_single_vertex_single_edge);
}


int main() {
    MU_RUN_SUITE(suite_in_file);
    MU_REPORT();
    printf("Number failed tests: %d\n", minunit_fail);
    return minunit_fail;
}