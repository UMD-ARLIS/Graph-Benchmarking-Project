// test.c (for testing helloworld.c)

// system inclusions
# include <assert.h>
# include <stdbool.h>
# include <string.h>

// User inclusions
# include "helloworld.h"
# include "helloworld.c" 			//Bug: Need to import directly becuase of conflicting main functions

// Fucntions
static void test_hello_world(){
	/*
	Tests the hello world function

	input args: 
		none
	processes: 
		uses an assertion to stop execution if the hello_world program does not return "hello world"
	outputs:
		none
	*/
	char* helloWorldOutput = hello_world();					//Get value of hello_world function

															//Check value of hello_world matches test
	assert((strcmp(helloWorldOutput, "hello world")) == 0);
}


// main function

int main() {
	test_hello_world();
}