# Templates
This directory contains all templates used in the ARLIS RISC project. 

## Mid Project Report Template. 
To use the ARLIS Mid Project Report Template

### Setup

To Use, first extract the template from the tarball: 

    tar -xf ARLIS_MPR_Template

Then navigate into the directory: 

    cd ARLIS_MPR_Template

To compile the file with the makefile I provide you need pdflatex on your machine. Odds are that you already have it, but if not using homebrew on macOS you can get it with 

    brew install --cask mactex

Or if you're on Ubuntu (not tested, just taking this from a how-to page): 

    sudo apt-get install texlive-latex-base
    sudo apt-get install texlive-fonts-recommended
    sudo apt-get install texlive-fonts-extra
    sudo apt-get install texlive-latex-extra

You're on your own for windows. 

Then, you can compile the LaTeX file to pdf using the makefile provided using

    make MPR.pdf

And delete all the noise after using 

    make clean

### Using Overleaf
You can just upload the content of the tarball right up to [overleaf](https://www.overleaf.com/) and edit it in there. 

### Editing the files
All of the content for your files that you need to change should be in MPR.tex, this is where you can edit the bits and pieces you need. You need to have preamble.tex in the same directory, but shouldn't need to edit it at all. 

If you want to add any images, I recommend you add them to the /Figures directory. I've set up the graphics path to look in there for images & it'll help keep things clean. 

To add references, you'll need to edit the .bib file to add those in. You can do this in the raw file, or use something like [Jabref](https://www.jabref.org/) as an editor. 


### Directory Structure:
```
.
└── ARLIS_MPR_Template
    ├── Figures
    │   └── arlis.png
    ├── MPR.pdf
    ├── MPR.tex
    ├── RISC.bib
    ├── makefile
    └── preamble.tex
```