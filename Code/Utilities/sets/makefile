# Kent's Makefile for the set tests

# format is the command: instructions

CFLAGS= -Wall -g

all: clean test	testsuite			# Run all commands

test:								# Compile the test file
	cc src/set.c tests/set_test.c -o test.o

testsuite: 							# Compile the testSuite file
	cc src/set.c tests/testsuite.c -o testsuite.o

clean: 								# Clean the compiled files
	rm -f bfs.o test.o testsuite.o


