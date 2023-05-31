# HelloWorld program

A first attempt at a 'hello world' in C using a Test Driven Development approach. 

## Structure
makefile 		- provides the compiler instructions on how to make the file. 
helloworld.c 	- defines the function for the hello world program
test.c 			- defines the test for the hello world program
helloworld.h 	- header file for helloworld, defines functions. 


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