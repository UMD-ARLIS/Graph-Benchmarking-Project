# Onboarding

I've thrown together a collection of useful resources to kick start any areas (if any) we're weaker in. I've got no information about background / experience / interests at this stage, so assuming lowest common denominator. The list is by no means exhaustive and I'm not an expert in any of these areas. We'll largely all be learning together. 

## Productivity
I'm not sure if we'll all be co-located or distributed for this project, so I'm planning for distrubuted and we can change to suit co-located if the opportunity arises. 

Ideally, all of our work will exist on Github (less some of the bigger datasets which we will figure out when we get to it). I'm envisioning Jira as a mechanism to track task completion and improve overall transparency, but if it's a burden we can drop it in favour of doing everything through git. I'll set up a slack channel for us all to use for ongoing comms. 

### Jira

[Project Jira Board](https://osullik.atlassian.net/jira/software/projects/HIVE/boards/1)

### Github
[Intro to Github, a 'hello world' problem](https://docs.github.com/en/get-started/quickstart/hello-world). Worth stepping through if you're not au fait with github. 

[Git Cheat Sheet](https://training.github.com/downloads/github-git-cheat-sheet/). Useful Commands and glossary for working with git. 

### Slack

[Slack Workspace Link - Expires 23 Jun 23](https://join.slack.com/t/hive2023workspace/shared_invite/zt-1vleu4e07-xrSi57M7ZrCtWKc6VMnQbA)

### Jabref

[Download Jabref](https://www.jabref.org/#download)

[Offical 'Getting Started'](https://docs.jabref.org/getting-started)

To **import the library** that's (going to be) on the git repo.

In Jabref, go to file -> Open and navigate to where you have cloned the library. 
Point it at ~/summer2023/summer2023.bib

To **add a reference**,

Easiest way is to go go google scholar, hit cite and save the .bib file. 
Drag and drop that into the interface. 
To update, just edit it in the jabref editor and save (ctrl+s)
Alternately, you can just copy and paste raw BibTeX into JabRef and it'll work it out. 

### LaTeX

[Overleaf Tutorials](https://www.overleaf.com/learn/latex/Tutorials). About 95% of the things I need to figure out in LaTeX I use overleaf's help guides for. 

[Neil Spring's LaTeX Style Checking Scripts](https://github.com/nspring/style-check). The Test-Driven approach to writing in LaTeX. 

## Problem Domain

### HIVE
The [DARPA HIVE](https://www.darpa.mil/program/hierarchical-identify-verify-exploit) (Hierarchical Identify Verify Exploit) project is looking to build a graph analytics processor that can process streaming graphs 1000X faster and at much lower power than current processing technology. 

The [GraphChallenge](https://graphchallenge.mit.edu/darpa-hive) is run by MIT and AWS towards the DARPA HIVE program. There are many useful papers, datasets and other useful resources here. 

### Graph Data Structures

[Geeks4Geeks Introduction to Graphs](https://www.geeksforgeeks.org/introduction-to-graphs-data-structure-and-algorithm-tutorials/)

[Neo4j Graph Database Overview](https://neo4j.com/developer/graph-database/)

[NVIDIA Graph Analytics Introduction](https://www.nvidia.com/en-us/glossary/data-science/graph-analytics/#:~:text=Graph%20analytics%2C%20or%20Graph%20algorithms,the%20graph%20as%20a%20whole.)

### Graph Datasets

[Graph500 Website](https://graph500.org/). Useful overview of the project, including the kind of sizes that exist in the problem domain. 

[Graph500 Codebase](https://github.com/graph500/graph500). This will be the startpoint for generating our own graphs for testing. 

### Knowledge Graphs

A knowledge graph is an interconnected dataset enriched with semantics so we can reason about the underlying data and use it confidently for complex decision-making

[Neo4j Primer on Knowledge Graphs](https://neo4j.com/blog/from-graph-to-knowledge-graph-how-a-graph-becomes-a-knowledge-graph/)

[University of Southern California's Knowledge Graph Class Syllabus](https://classes.usc.edu/term-20203/course/dsci-558/)

### Community Detection

### Subgraph Matching

### High Performance & Parallel Computing

[UMD High Performance Computing Course](http://www.cs.umd.edu/class/fall2022/cmsc714/Lectures/lectures.shtml)

[UMD Parallel Computing Course](http://www.cs.umd.edu/class/spring2023/cmsc416/Lectures/lectures.shtml)

[Introduction to Parallel Algorithms: Belloch, Dhulipapa & Sun (2023)](https://www.cs.umd.edu/~laxman/notes/parallel.pdf)

### Telemetry and Measuring performance

[Intel Overview of Telemetry for Graph Analytics](https://www.intel.com/content/www/us/en/developer/articles/technical/measuring-graph-analytics-performance.html#gs.ygy868)

## Development

### Agile Software Development
[The Agile Manifesto](https://agilemanifesto.org/). Short list of guiding principles for Agile development. Just good for all computer people to know about. 

[The Scrum Guide](https://scrumguides.org/scrum-guide.html). The Handbook for how to do scrum. Good high-level context.

[Introduction to Scrum in 7 Minutes](https://www.youtube.com/watch?v=9TycLR0TqFA). 7 Minute video explaining how Scrum works. 

### Software Testing and Test Driven Development

[Atlassian Software Testing Primer ~5 Min Read](https://www.atlassian.com/continuous-delivery/software-testing/types-of-software-testing)

[IBM Test Driven Development Primer ~5 Min Read](https://www.ibm.com/garage/method/practices/code/practice_test_driven_development/)

[Test Driven Development Book - Kent Beck ~ Multi Hour read](https://github.com/clarabez/SoftwareTestingBooks/blob/master/Test-Driven%20Development%20By%20Example%20(Kent%20Beck).pdf). 

[Test Driven Development in C - Bowling Game Kata ~20 Min read](https://www.slideshare.net/amritayan/test-driven-development-in-c). Useful little presentation about how to do TDD in C

[Troubleshooting: Compiling Seperate Test Files](https://muizidn.medium.com/error-ld-symbol-not-found-for-architecture-x86-64-a5e5b648ffc)

### C Programming

[Learn C the Hard Way](https://shop.learncodethehardway.org/access/buy/3/); [Alternate Link](https://github.com/XWHQSJ/ebooks/blob/master/Cpp/C/Learn%20C%20the%20Hard%20Way.pdf). I like Zed's books for picking up new languages. Lost of repetition and just working with code to get across the line. 

[Intro to C Programming](https://www.cprogramming.com/tutorial/c-tutorial.html). Recommended by a colleague of mine. 

[University of Wisconsin Operating Systems course](https://pages.cs.wisc.edu/~remzi/OSTEP/). Recommended for a colleague for working with C in an OS context. Threading and concurrency in particular. 

[Loyola's C for Operating Systems Exercises](http://www.cs.loyola.edu/~binkley/466/handouts/01_IntroToOS.pdf). Recommended by a colleague for getting your head around concurrency. [Relevant code](http://www.cs.loyola.edu/~binkley/466/src/typical-server-code.c)
