# Papers

## Introduction 
This direcotry contains all the paterial relating to the writing of papers, reports or other documents in this project. 

## Structure

In this directory is \<parentTexFile.tex\>. That file is used to create the title page of the LaTeX document, and pull together each of the subsections. 

The Sections Directory contains each individual LaTeX .tex file used to build the paper. One .tex file corresponds to one paper section

The Scripts Directory contains a number of useful scripts for checking spelling, grammar, structure etc. 

The Figures Directory contains any relevant figures. Prefer the use of .svg figures where possible, and doubly prefer dynamically generating data analysis figures from code on compilation. 

The Style Directory contains relevant style files for the construction of the paper. 

the bibliography directory contails the .bib file for the project, and the reference_papers directory. The directory will hold the PDF copies of useful papers we come across in our travels. 

## Compilation Instructions

### Environment

Your system will need to have a LaTeX compiler and a vector graphics editor. Here we use: 

[latexmk](https://mg.readthedocs.io/latexmk.html) for LaTeX compilation, and

[Inkscape](https://inkscape.org/) for vector graphics. 

### Instructions

**Compile the PDF** Run the Makefile with a command like: 
	
	make <parentTexFile>.pdf 

**Clean up the log files** Run the clean command:
	
	make clean
