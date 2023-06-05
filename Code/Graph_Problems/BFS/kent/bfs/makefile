# Kent's Makefile for the bfs Project

# format is the command: instructions

CFLAGS= -Wall -g

all: clean test						# Run all commands

#bfs: 								# Compile the bfs file
#	cc bfs.c -o bfs.o

test:								# Compile the test file
	cc test.c ../../../../Utilities/c-utils/src/graph.c ../../../../Utilities/sets/src/set.c -o test.o

clean: 								# Clean the compiled files
	rm -f bfs.o test.o