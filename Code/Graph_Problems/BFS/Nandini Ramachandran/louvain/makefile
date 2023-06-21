# Nandini's Makefile for the Louvain Project

CFLAGS= -Wall -g

all: clean test						# Run all commands

test: 
	gcc test.c louvain.c -o test.o

#BREAKDOWN OF THE test COMMAND:
# gcc: specifices the compiler that we will use to compile the following c files (could also use cc) 
# test.c : includes an input file for the compiler
# louvain.c : tells the compiler "compile louvain.c"
# -o : tells the compiler we are going to specify the name of an output file. 
# test.o : name of the output file

clean:
	rm -f louvain.o test.o a.out