# summer2023/Code/Utilities/dataLoader/Makefile

# Kent's Makefile for the dataloader

# format is the command: instructions

CFLAGS= -Wall -g

all: clean test						# Run all commands

#dataLoader: 						# Compile the dataLoader file
#	cc dataLoader.c -o dataLoader.o

test:								# Compile the test file
	cc test.c dataLoader.c ../c-utils/src/graph.c ../c-utils/src/fileutils.c ../c-utils/src/stringlib.c -o test.o

clean: 								# Clean the compiled files
	rm -f dataLoader.o test.o    