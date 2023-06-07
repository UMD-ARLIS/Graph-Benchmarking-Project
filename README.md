# Overview
Repo for Summer 2023 Graph Benchmarking Project.

## Battle Rhythm: 
See [Project Calendar](https://calendar.google.com/calendar/u/1?cid=Y19kMmQwNDUxY2RjYmFlNWUxOTgxY2JkMDc4Y2NjNjhkZGQ0NDUyMmFhNzMzZmFkMzQzNjUwZGVlOWEzMWM5MTFiQGdyb3VwLmNhbGVuZGFyLmdvb2dsZS5jb20) for details, but in general: 
 
- 1 x Weekly meeting with faculty mentors @ 1600 (EDT) on Wednesdays. 
- 1 x Daily scrum with Kent @ 1145. 
- Routine Comms through Slack. 
- Formal Meetings / Workshops for RISC through Teams. 

## Useful Links:

[Project Github](https://github.com/osullik)

[Project Google Drive](https://drive.google.com/drive/folders/19-CboH6ZahDUuIYqDbroJ4DJIftPY_6s?usp=sharing)

[Project Jira Board](https://osullik.atlassian.net/jira/software/projects/HIVE/boards/1)

[Project Slack - RISC Minnesota 2023 Workspace](https://riscminnesota2023.slack.com)

[Project Calendar](https://calendar.google.com/calendar/u/1?cid=Y19kMmQwNDUxY2RjYmFlNWUxOTgxY2JkMDc4Y2NjNjhkZGQ0NDUyMmFhNzMzZmFkMzQzNjUwZGVlOWEzMWM5MTFiQGdyb3VwLmNhbGVuZGFyLmdvb2dsZS5jb20)

[Project Overlead (LaTeX)](https://www.overleaf.com/5589556986bvqfbthdvdjc)

## Repo Structure:

### Papers
 Contains all files relevant to papers, presentations etc. Primarily LaTeX. Included the bibliography file.

### Code
 Contains all code relevant to the solving the problem at hand. Primarily C, little bit of python. Possibly some assembly, depending how unlucky we get. 

### Data 
 Contains TRIVIAL code examples for testing code only. All large data files are stored externally. 

# Initial Setup

## Working with git
check if you have it installed:

      git --version

if you don't then install it (I recommend using homebrew, since we're all of the superior Mac User subspecies)

      brew install git

If you don't have homebrew then install it with:

      /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

Once you have git up and running you want to use the git clone command to get the repo on your local system:

      git clone https://github.com/osullik/summer2023.git

Once you've got it replicated on your local you can get to work.

You can add single files, multiple files or directories all at once. ( I caution against using the * wildcard operator). for example if we were working on test.c and code.c we might use

      git add code.c 
      git add test.c

or, we could also do

      git add code.c test.c

or assuming that they are the only two files in the directory

      git add .

Once you have added the file to the staging area you need to commit it (that is, on your local system, you create an entry in the version control system). I recommend using the -m tag to add a comment to the commit. The comments should be descriptive and meaningful (imagine you, in a panic at 3am before a demo sorting through 100 commit messages that say "updated code" trying to find the one you actually want)

      git commit -m "Added the hello_world unit test to test.c and the hello_world function to code.c. The unit test passes"

To make those changes to the github page itself use:

      git push 

Sometimes you may get an error when running the push command saying that there are changes you don't yet have on your local machine and that you need to reconcile those first. something like this:
   
      ! [rejected]        main -> main (fetch first)
      error: failed to push some refs to 'https://github.com/osullik/summer2023.git'
      hint: Updates were rejected because the remote contains work that you do
      hint: not have locally. This is usually caused by another repository pushing
      hint: to the same ref. You may want to first integrate the remote changes
      hint: (e.g., 'git pull ...') before pushing again.
      hint: See the 'Note about fast-forwards' in 'git push --help' for details.

This means that someone else (or you) has modified the github repo and it no longer matches yours. To reconcile those you want to use:

      git pull

All going well, it should not have any merge conflict (i.e. two people editing the same file at the same time). If you manage to hit a merge conflict ping me on here and I'll come help you. It might ask you to add a merge message, if so, just use the same comment you used for your git commit.

If in doubt, check the status with:

      git status

My rule of thumb is to commit whenever you have a new unit-test passing, so that you've got it as a working 'checkpoint'. But more often is better than not often enough.

## Getting Jabref [Optional]
For JABREF, you can grab it at the following link: https://www.jabref.org/

# Ways of Work

## Writing

We'll cover in more detail if/when we get to it.

If you're new to LaTeX we can use Overleaf to get started: [Link to Overleaf]([https://overleaf.com](https://www.overleaf.com/5589556986bvqfbthdvdjc))

If you want to use LaTeX locally and get access to all the cool editing scripts I've acquired (read: took directly from Prof Boyd-Graber) you can set up the environment using homebrew:

      brew install mactex

it should give you the warning, but in case not you'll need to either restart your terminal or run the following command: 

      eval "$(/usr/libexec/path_helper)"

Then, to compile the vector graphics that look much nicer in rendered pdfs we need to install inkscape: 

      brew install inkscape

then you should be good to go by navigating to the directory with the .tex file in question and adding in a makefile (ask kent for the makefile and the scripts directory)

with the makefile in the directory, you can then compile your pdf using: 

      make <myFile>.pdf


## Coding

We'll use git to our advantage, but will work through how we want to handle branching, merges etc and document here. 

We should aim for Test-Driven development. In general: 
- identify a problem
- write a test that fails that problem
- write code to solve the problem
- pass the test
- refactor the code to solve the general case. 

If not fully test-driven, we should at least produce a unit test for each function that we write. As we mature we can add regression testing, integration testing etc. 

## Collaborative Coding

We will use VSCode liveshare to conduct pair programming. 

To install VSCode I recommend (as always) using homebrew with: 

      brew install --cask visual-studio-code

note that specifying --case indicates to homebrew that this will be a standalone app, usually with a GUI. 

Once installed you can launch VSCODE from the command line with: 

      code 

Once opened, you'll need to install two extensions to VSCODE by navigating to the extensions menu (or use COMD + SHIFT + X) and searching for: 
- C/C++ for VSCODE
- Live Share

To share a file, open your file of interest in the editor and look in the bottom left of the VSCode screen. There will be an option to "live share". Click it. You may need to sign in using github. You then have a link you can send to people to start collaborating!

## Reference Management 
Update the reference details in the Project .bib file for now. If things get out of hand we can split to seperate ones. 

Add any paper of use to the google drive with the naming convention <FirstAuthorLastName><year>.*** eg osullivan2023.pdf

## Data management 

We'll use Google Drive at the link above Initially, with a TO-DO of finding a better version control system for datasets. 

## Task Tracking

We'll use Jira at this link: [Jira Board](https://osullik.atlassian.net/jira/software/projects/HIVE/boards/1) 
