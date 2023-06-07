# Nandini's Makefile for the bfs Project

CFLAGS= -Wall -g

all: clean test						# Run all commands

test: 
	gcc test.c bfs.c ../../../../Utilities/c-utils/src/string_builder.c -o test.o

#BREAKDOWN OF THE test COMMAND:
# gcc: specifices the compiler that we will use to compile the following c files (could also use cc) 
# test.c : includes an input file for the compiler
# bfs.c : tells the compiler "compile bfs.c"
# ../../../../Utilities/c-utils/src/string_builder.c : tells the compiler to compile ~/string_builder.cc
# -o : tells the compiler we are going to specify the name of an output file. 
# test.o : name of the output file

clean:
	rm -f bfs.o test.o a.out