// helloworld.c

// System Inclusions
# include <stdio.h>

// User Inclusions
# include "helloworld.h"

// Functions 
char* hello_world(){
	/*
	A simple hello world function
	
	input args: 
		none
	outputs: 
		a pointer to a character array containing the hello world message
	*/
	char* message = "hello world";
	printf("\"%s\"", message);

	return message;
}
