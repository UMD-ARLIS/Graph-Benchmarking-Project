# Code/Graph_Problems/CommunityDetection/Louvian/Parallel/Makefile

# Nandini's Makefile for the Louvain Project

CFLAGS= -Wall -g

all: clean test						# Run all commands

test: 
	gcc test_louvian_parallel.c louvian_parallel.c -o test.o

#BREAKDOWN OF THE test COMMAND:
# gcc: specifices the compiler that we will use to compile the following c files (could also use cc) 
# test_louvian_parallel.c : includes an input file for the compiler
# louvian_parallel.c : tells the compiler "compile louvain.c"
# -o : tells the compiler we are going to specify the name of an output file. 
# test.o : name of the output file

clean:
	rm -f louvian_parallel.o test.o a.out