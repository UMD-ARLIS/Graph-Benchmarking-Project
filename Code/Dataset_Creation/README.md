# Dataset_Creation

All files relating to the creation of graph datasets. Boxes to be checked once read & a summary line added in *italics*. 

Papers added to summer2023.bib file and are stored by SurnameYear.pdf here: [Reference Papers](https://github.com/osullik/summer2023/tree/main/Papers/bibliography/reference_papers)


## Benchmark Datasets

### Synthetic Graph Generation
- [ ] [Graph500 v3.0.0 Generator](https://github.com/graph500/graph500). Written in C to meet the standards of the Graph500 benchmark. 

- [ ] [R-MAT (Chakrabarti et al 2004)](https://www.cs.cmu.edu/~christos/PUBLICATIONS/siam04.pdf).

- [ ] [plantri and fullgen planar graph generators](https://users.cecs.anu.edu.au/~bdm/plantri/). A planar graph is a graph that can drawn on a plane in such a way that its edges intersect only at their endpoints - that is, no edges cross each other. May be of use for subgraph matching? [The Paper is here](https://users.cecs.anu.edu.au/~bdm/papers/plantri-full.pdf)

- [ ] [Synthetic Data and Graph Generation for Modeling Adversarial Activity](https://www.osti.gov/biblio/1871012). Looks to be useful for generating things that look like Knowledge Graphs. 

- [ ] [C++ Implementation of Louvian](https://github.com/ECP-ExaGraph/vite) Also looks to include some graph generation code that might be useful

### Existing Graph Datasets
- [ ] [Stanford Large Network Dataset Collection](https://snap.stanford.edu/data/index.html) - Large collection of datasets, including several appropriate for community detection applications. 

- [ ] [SuiteSparse Matrix Collection](https://sparse.tamu.edu/about) - Large collection of sparse matrix datasets for a large number of applications. Noting that these are matricies they may require a bit of work for us to convert into Adjacency Lists if we choose to use them. 

- [ ] [Stanford Open Graph Benchmark](https://ogb.stanford.edu/) - Datasets to support Machine Learning on Graphs. Mainly focused on Node, Link and Graph property prediction (2023). 

### Graph Sampling

- [ ] [Network Sampling via Edge-based Node Selection with Graph Induction](https://docs.lib.purdue.edu/cgi/viewcontent.cgi?article=2743&context=cstech) - Paper on how to sample graphs. Note that commentary from Ben Johnson that graph sampling while maintaining topological properties is a hard problem. 