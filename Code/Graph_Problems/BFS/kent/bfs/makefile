# Kent's Makefile for the bfs Project

# format is the command: instructions

CFLAGS= -Wall -g -c

all: clean test						# Run all commands

#bfs: 								# Compile the bfs file
#	cc bfs.c -o bfs.o

test:								# Compile the test file
	cc test.c bfs.c ../../../../Utilities/c-utils/src/graph.c ../../../../Utilities/sets/src/set.c ../../../../Utilities/c-utils/src/queue.c -o test.o

profile:
	cc test.c bfs.c ../../../../Utilities/c-utils/src/graph.c ../../../../Utilities/sets/src/set.c ../../../../Utilities/c-utils/src/queue.c -o profile.o -fprofile-arcs -ftest-coverage


clean: 								# Clean the compiled files
	rm -f bfs.o test.o