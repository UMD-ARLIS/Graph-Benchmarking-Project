============
BFS Datasets
============

The BFS Datasets are broken down into toy size (here), and small, medium, and large (external).

Toy Dataset
-----------

The toy graphs are taken from the book "Kleinberg & Tardos, Algorithm Design (2014)".

The .in files consist of the adjacency lists for each graph, assuming a directed graph.

Their format is as follows:

.. code-block:: text

    # Title
    # Source
    NODES
    1
    2
    ...
    n
    EDGES
    (1,2)
    (2,3)
    ...
    (m,n)

The .out files consist of the parameters and results expected for a BFS. They have multiple test cases, laid out as follows:

.. code-block:: text

    # Title
    source: <startNode>
    target: <node being searched for>
    traversal 1,2,3,4,...n

Note, the program should return "FAIL" as the final traversal if it does not find the search target.

ToyTree
~~~~~~~

![The ToyTree Graph](figures/toyTree.jpeg)

ToyHard
~~~~~~~

![The ToyHard Graph](figures/toyHard.jpeg)
