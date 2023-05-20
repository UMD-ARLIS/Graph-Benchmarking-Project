# summer2023
Repo for Summer 2023 Graph Benchmarking Project

## Battle Rhythm: 
TBC but plan on: 
- 2 x Weekly meeting with faculty mentor
- 1 x Daily standup with Kent
- Routine Comms through Slack
- Formal Meetings through Teams

## Project Structure:

### Papers
 Contains all files relevant to papers, presentations etc. Primarily LaTeX. Included the bibliography file.

### Code
 Contains all code relevant to the solving the problem at hand. Primarily C, little bit of python. Possibly some assembly, depending how unlucky we get. 

### Data 
 Contains TRIVIAL code examples for testing code only. All large data files are stored externally. 


## Initial Setup

assuming you have git installed locally, you should be able to just clone the repo with something like

`git clone https://github.com/osullik/summer2023.git`

check that the .gitignore comes down with it. And you should be right to go.

For JABREF, you can grab it at the following link: https://www.jabref.org/
To import the library.

In Jabref, go to file -> Open and navigate to where you have cloned the library. 
Point it at ~/summer2023/summer2023.bib

To add a reference,

Easiest way is to go go google scholar, hit cite and save the .bib file. 
Drag and drop that into the interface. 
To update, just edit it in the jabref editor and save (ctrl+s)

## Writing

We'll cover in more detail when we get to it.

If you're new to LaTeX we can use Overleaf to get started (Link Here)

## Coding

We'll use git to our advantage, but will work through how we want to handle branching, merges etc and document here. 

We should aim for Test-Driven development. In general: 
- identify a problem
- write a test that fails that problem
- write code to solve the problem
- pass the test
- refactor the code to solve the general case. 

If not fully test-driven, we should at least produce a unit test for each function that we write. As we mature we can add regression testing, integration testing etc. 

## Data management 

We'll use Google Drive Initially, with a TO-DO of finding a better version control system for datasets. 

## Task Tracking

We'll use Jira at this link: 


# TO DO

Add in big-hands things to-do here for our visibility and tracking. Primary task management is through Jira. 
