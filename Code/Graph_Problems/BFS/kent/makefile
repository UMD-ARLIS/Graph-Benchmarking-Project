# Kent's Makefile for the Hello World Project

# format is the command: instructions

CFLAGS=-Wall -g

all: clean helloworld test							# Run all commands

test:												# Compile the test file
	cc test.c -o test

helloworld: 										# Compile the hello world file
	cc helloworld.c -o helloworld

clean: 												# Clean the compiled files
	rm -f helloworld test