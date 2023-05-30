# Overview
Repo for Summer 2023 Graph Benchmarking Project

## Battle Rhythm: 
TBC but plan on: 
- 2 x Weekly meeting with faculty mentor
- 1 x Daily standup with Kent
- Routine Comms through Slack in the 
- Formal Meetings through Teams

## Useful Links:

[Project Github](https://github.com/osullik)

[Project Google Drive](https://drive.google.com/drive/folders/19-CboH6ZahDUuIYqDbroJ4DJIftPY_6s?usp=sharing)

[Project Jira Board](https://osullik.atlassian.net/jira/software/projects/HIVE/boards/1)

[Project Slack - RISC Minnesota 2023 Workspace](https://riscminnesota2023.slack.com)


## Repo Structure:

### Papers
 Contains all files relevant to papers, presentations etc. Primarily LaTeX. Included the bibliography file.

### Code
 Contains all code relevant to the solving the problem at hand. Primarily C, little bit of python. Possibly some assembly, depending how unlucky we get. 

### Data 
 Contains TRIVIAL code examples for testing code only. All large data files are stored externally. 

# Initial Setup

## Cloning the Repo
assuming you have git installed locally, you should be able to just clone the repo with something like

`git clone https://github.com/osullik/summer2023.git`

check that the .gitignore comes down with it. And you should be right to go.

## Getting Jabref [Optional]
For JABREF, you can grab it at the following link: https://www.jabref.org/

# Ways of Work

## Writing

We'll cover in more detail if/when we get to it.

If you're new to LaTeX we can use Overleaf to get started: [Link to Overleaf](https://overleaf.com)

## Coding

We'll use git to our advantage, but will work through how we want to handle branching, merges etc and document here. 

We should aim for Test-Driven development. In general: 
- identify a problem
- write a test that fails that problem
- write code to solve the problem
- pass the test
- refactor the code to solve the general case. 

If not fully test-driven, we should at least produce a unit test for each function that we write. As we mature we can add regression testing, integration testing etc. 

## Reference Management 
Update the reference details in the Project .bib file for now. If things get out of hand we can split to seperate ones. 

Add any paper of use to the google drive with the naming convention <FirstAuthorLastName><year>.*** eg osullivan2023.pdf

## Data management 

We'll use Google Drive at the link above Initially, with a TO-DO of finding a better version control system for datasets. 

## Task Tracking

We'll use Jira at this link: [Jira Board](https://osullik.atlassian.net/jira/software/projects/HIVE/boards/1) 
