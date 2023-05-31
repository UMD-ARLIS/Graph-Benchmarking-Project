# HelloWorld program

A first attempt at a 'hello world' in C using a Test Driven Development approach. 

## Structure
**makefile** 		- provides the compiler instructions on how to make the file. 

**helloworld.c**	- defines the function for the hello world program

**test.c** 			- defines the test for the hello world program

**helloworld.h** 	- header file for helloworld, defines functions. 


## Compilation Instructions

Compiled on my machine using Apple clang version 13.0.0 (clang-1300.0.29.30)

Using the make file: 

	make all

Using the compiler:

	cc test.c -o test 

Either way, to run it: 

	./test

To get rid of the binaries: 

	make clean

## Did TDD Help?

To see what happens when our assert fails, try changing the value of the following line in **helloworld.c**: 

	char* message = "hello world";

to: 

	char* message = "helloworld";

when you try to compile the test file, you should see something like: 

	Assertion failed: ((strcmp(helloWorldOutput, "hello world")) == 0), function test_hello_world, file test.c, line 27. "helloworld"
