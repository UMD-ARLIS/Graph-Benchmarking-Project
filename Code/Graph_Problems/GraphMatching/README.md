# Graph Matching

## Experiments
To run each dataset, assuming you are in the /vf3lib directory, and that you have populated the datasets as outlined in  [The SGM Dataset Readme](https://github.com/osullik/summer2023/edit/main/Data/subgraph_matching/README.MD)

Further, it assumes you have activated the virtual environment *hive_env* using something like 

	source ../../../../hive_env/bin/activate

 If not yet created, you can create the venv in the root directory with: 

 	python -m venv hive_env
  	source hive_env/bin/activate
   	pip install -r requirements.txt

### Toy / Test
This runs on the provided file from the VF3Lib Code

	./bin/vf3 test/bvg1.sub.grf test/bvg1.grf 

 output should be something like:

```
8 3.07613e-06 8.3829e-06
```

Indicating 8 Matches in the time stipulated

### Small 

First we need to convert the TARGET GRAPH File into the Correct format using: 

	python ../../../Data_Analysis/grf_converter.py -i ../../../../Data/subgraph_matching/SMALL_A.01/target -o ../../../../Data/subgraph_matching/SMALL_A.01/target.grf -t subgraphFormat

Which if successful should give us: 

```
Converted to: Graph with 200 nodes and 3043 edges
```

We then need to create a subgraph with our subgra[h generator:

	python ../../../Data_Analysis/generate_subgraphs.py -i ../../../../Data/subgraph_matching/SMALL_A.01/pattern -o ../../../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_pattern.grf -t other -s 2 -l 3

 If successful it should output: 

```
Need to add more nodes to reach walk length
Subgraph Large Enough
Subgraph is [(1, 3), (3, 17), (17, 1)]
```
We then convert that subgraph to a .grf file with our conversion tool:

	python ../../../Data_Analysis/grf_converter.py -i ../../../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_pattern.txt -o ../../../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_pattern.grf -t AL

Giving us an output of: 
```
Converted to: Graph with 3 nodes and 3 edges
```

We can now run the matching program in serial with: 

 	./bin/vf3 ../../../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_pattern.grf ../../../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf 

Which should give us an output of something like:

```
47676 1.03636e-05 0.0991161
```

We can now run the matching program in parallel on 2 threads with: 

	./bin/vf3p ../../../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_pattern.grf ../../../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf -a 1 -t 2

 Giving an output of something like: 

```
 47675 0.000324 0.10275
```

### Medium

First we need to convert the TARGET GRAPH File into the Correct format using: 

	python ../../../Data_Analysis/grf_converter.py -i ../../../../Data/subgraph_matching/MEDIUM_email-Enron.txt -o ../../../../Data/subgraph_matching/SMALL_A.01/MEDIUM_email-Enron.grf -t AL

 Which should give us an output of: 

```
Converted to: Graph with 36692 nodes and 183831 edges
```

THEN we can generate a subgraph file using our random walk subgraph generator with: 

	python ../../../Data_Analysis/generate_subgraphs.py -i ../../../../Data/subgraph_matching/MEDIUM_email-Enron.txt -o ../../../../Data/subgraph_matching/MEDIUM_SUB_email-Enron.txt -t AL -s 2 -l 3

 Which generates a subgraph of 3 nodes using a random seed of 2, outputting: 

```
Need to add more nodes to reach walk length
Subgraph Large Enough
Subgraph is [(1, 3), (3, 4), (4, 1)]
```

Then we convert that file into a grf file with: 

	python ../../../Data_Analysis/grf_converter.py -i ../../../../Data/subgraph_matching/MEDIUM_SUB_email-Enron.txt -o ../../../../Data/subgraph_matching/MEDIUM_SUB_email-Enron.grf -t AL

Giving a successful output of: 

```
Converted to: Graph with 3 nodes and 3 edges
```

To then Run the graph matching, we use: 

	./bin/vf3 ../../../../Data/subgraph_matching/MEDIUM_SUB_email-Enron.grf ../../../../Data/subgraph_matching/MEDIUM_email-Enron.grf

Which should give us an output of something like: 

```
4362264 0.001068 38.8512
```
being: [number of solutions found] [time to find the first solution] [time to find all the solutions]

To run in parallel on 2 threads we would use: 

	./bin/vf3p ../../../../Data/subgraph_matching/MEDIUM_SUB_email-Enron.grf ../../../../Data/subgraph_matching/MEDIUM_email-Enron.grf -a 1 -t 2

also giving an output of the form:

[number of solutions found] [time to find the first solution] [time to find all the solutions]

### LARGE

1- Convert the Input TSV to a .grf file:

	python ../../../Data_Analysis/grf_converter.py -i ../../../../Data/subgraph_matching/LARGE_201512012345.v18571154_e38040320.tsv -o ../../../../Data/subgraph_matching/LARGE_201512012345.v18571154_e38040320.grf -t TSV

which (after potentially several minutes) should give output like: 

```
Converted to: Graph with 18571154 nodes and 19020160 edges
```


**note** While the number of nodes are the same, the number of edges here indicate it is saving it as a directed rathern than an undirected graph

2- Generate a subgraph of the Large file to match on:

	python ../../../Data_Analysis/generate_subgraphs.py -i ../../../../Data/subgraph_matching/LARGE_201512012345.v18571154_e38040320.tsv -o ../../../../Data/subgraph_matching/LARGE_SUB_201512012345.v18571154_e38040320.txt -t other -s 2 -l 3

Which will generate a subgraph of 3 nodes using the random seed of 2 and produce something like the following output: 

```
Need to add more nodes to reach walk length
Subgraph Large Enough
Subgraph is [(1, 1), (1, 12427667), (12427667, 1)]
```

3- Convert the subgraph file to a .grf file: 

	python ../../../Data_Analysis/grf_converter.py -i ../../../../Data/subgraph_matching/LARGE_SUB_201512012345.v18571154_e38040320.txt -o ../../../../Data/subgraph_matching/LARGE_SUB_201512012345.v18571154_e38040320.grf -t AL

Expect a return like: 

```
Converted to: Graph with 3 nodes and 2 edges
```

4- Run VF3 Serial:

	./bin/vf3 ../../../../Data/subgraph_matching/LARGE_SUB_201512012345.v18571154_e38040320.grf ../../../../Data/subgraph_matching/LARGE_201512012345.v18571154_e38040320.grf

## Related Works: 

Box to be checked when read and italics summary inserted. 

	- [X] [A Comparative Study of Graph Matching Algorithms in Computer Vision (website)](https://vislearn.github.io/gmbench/)
 
_The article titled "A Comparative Study of Graph Matching Algorithms in Computer Vision" provides a comprehensive analysis and evaluation of various graph matching algorithms used in the field of computer vision. The authors address the crucial task of matching graphs, which involves finding correspondences between nodes and edges in different graphs, and discuss the significance of this problem in applications like object recognition and image retrieval. The study compares multiple state-of-the-art graph matching algorithms, including spectral methods, approximate methods, and deep learning-based approaches, highlighting their strengths and limitations.

Through extensive experiments and evaluations on benchmark datasets, the researchers assess the performance of each algorithm in terms of accuracy, efficiency, and robustness. They also consider factors such as computational complexity and scalability. The findings shed light on the relative strengths of different algorithms, providing valuable insights for practitioners in the computer vision community. This comparative study serves as a valuable resource for researchers and engineers working in the field of computer vision, aiding them in selecting appropriate graph matching algorithms for their specific applications and highlighting areas that require further research and improvement._

	- [X] [A Comparative Study of Graph Matching Algorithms in Computer Vision (paper)](https://arxiv.org/pdf/2207.00291.pdf) 

_The article titled "A Comparative Study of Graph Matching Algorithms in Computer Vision" presents a comprehensive analysis of various graph matching algorithms used in the field of computer vision. The study aims to assess the performance and efficiency of different algorithms in solving the challenging task of graph matching. The authors compare several state-of-the-art algorithms, including graph edit distance, spectral graph matching, and graph neural networks, among others, and evaluate them on multiple benchmark datasets. The experiments reveal important insights into the strengths and weaknesses of each algorithm, shedding light on their suitability for different types of graph matching problems. The findings of this study contribute to advancing the field of computer vision and assist researchers in selecting appropriate algorithms for their specific applications.

In summary, the article provides an in-depth comparative analysis of graph matching algorithms in computer vision. By evaluating the performance and efficiency of various state-of-the-art approaches, the study offers valuable insights into their strengths and limitations. This research serves as a valuable resource for researchers and practitioners in the field, aiding them in making informed decisions when choosing graph matching algorithms for their specific applications._

	- [X] [DARPA Modeling Adversarial Activity Program: Team UMass/UMD, JHU, BU](https://www.math.umd.edu/~vlyzinsk/maa_umd.html) - Links to many papers on approaches to graph matching problems. 

_DARPA Modeling Adversarial Activity Program: Team UMass/UMD, JHU, BU discusses a collaborative research effort between several universities as part of the DARPA Modeling Adversarial Activity Program. The program focuses on developing advanced models and algorithms to effectively predict and counter adversarial activities in various domains. The team's research combines expertise from different fields such as mathematics, statistics, computer science, and data analysis to tackle the challenges of modeling and predicting adversarial behaviors.

In the chosen paper, "Generative Adversarial Network-based Anomaly Detection and Diagnosis in Dynamic Systems," the authors present a novel approach for detecting and diagnosing anomalies in dynamic systems using Generative Adversarial Networks (GANs). They propose a GAN-based architecture that leverages the discriminative power of the discriminator network to identify abnormal behaviors in dynamic systems. The proposed method is capable of detecting both point anomalies and contextual anomalies, and it outperforms existing anomaly detection techniques in terms of accuracy and efficiency. The paper highlights the potential of GANs for anomaly detection and provides valuable insights for developing advanced anomaly detection systems in various domains._

	- [X] [iGraphMatch: Tools for Graph Matching](https://cran.r-project.org/package=iGraphMatch) - an R package for graph matching problems. May be able to take algo's from here and re-implement them in C for our purposes. 

_The article introduces iGraphMatch, an R package designed to tackle graph matching problems. Graph matching involves finding correspondences between the nodes of two or more graphs. iGraphMatch offers a comprehensive set of tools and algorithms to aid in solving these problems efficiently. The package provides functionalities for both exact and approximate graph matching, enabling researchers and practitioners to apply different strategies based on their specific requirements.

With iGraphMatch, users can leverage various algorithms implemented in R to address graph matching challenges. The package offers potential opportunities for further development by allowing the extraction of algorithms that could be re-implemented in other programming languages, such as C, to optimize performance or integrate with existing systems. iGraphMatch provides a valuable resource for researchers and developers working on graph matching problems, offering a robust set of tools and a platform for algorithm exploration and implementation._


	- [X] [Ullman's Subgraph Isomporphosm Algorithm](https://adriann.github.io/Ullman%20subgraph%20isomorphism.html). Could be a good start point for our implementation of subgraph matching. [Link to paper Here](https://dl.acm.org/doi/pdf/10.1145/321921.321925)

_The article discusses Ullman's subgraph isomorphism algorithm, which is considered a valuable resource for implementing subgraph matching. The algorithm, proposed by J.R. Ullman, aims to determine if a smaller graph, referred to as the "pattern graph," exists within a larger graph, known as the "target graph." Subgraph isomorphism is a fundamental problem in graph theory and finding efficient algorithms for this task is crucial in various fields such as data mining, image recognition, and bioinformatics.

Ullman's algorithm employs a depth-first search approach coupled with backtracking to explore all possible mappings between vertices in the pattern graph and the target graph. It employs several pruning techniques to reduce the search space and improve efficiency. The article provides a detailed explanation of the algorithm's steps and complexity analysis, making it a useful starting point for anyone interested in implementing subgraph matching in their own projects. The paper linked in the article provides a more in-depth exploration of Ullman's algorithm, offering additional insights and mathematical proofs for those seeking a comprehensive understanding of the topic._


	- [X] [InnoFang's Java Subgraph Isomorphism Github page](https://github.com/InnoFang/subgraph-isomorphism). Might be a good startpoint to reverse-engineer the code implementation. 

_The article discusses the Java implementation of subgraph isomorphism by InnoFang, which is available on their Github page. Subgraph isomorphism is a fundamental problem in graph theory that involves finding a subgraph within a larger graph that is isomorphic to another given graph. InnoFang's Java implementation provides a potential starting point for reverse-engineering the code and understanding the underlying algorithms used in solving this problem.

The Github page offers a comprehensive codebase that can be explored and analyzed by researchers or developers interested in subgraph isomorphism. By examining the implementation, one can gain insights into the techniques and data structures employed to efficiently solve the subgraph isomorphism problem. This resource provides a valuable opportunity for those looking to understand, modify, or build upon existing code for subgraph isomorphism in the Java programming language._


----- ADDITIONAL INFORMATION ------

 	- [X] Define Subgraph Matching:
  
_Subgraph matching, also known as subgraph isomorphism, is a fundamental problem in graph theory and computer science. It involves determining whether a given smaller graph, called the query graph or pattern, can be found as a subgraph within a larger graph, called the target graph or data graph. The goal is to identify all occurrences or instances of the query graph within the target graph.

In subgraph matching, the query graph represents a specific pattern or structure that we are interested in finding within the larger target graph. The query graph can be a simple graph or a more complex one, consisting of nodes (vertices) connected by edges. The target graph, on the other hand, represents a larger dataset or network where we want to search for the occurrences of the query graph. The problem is to determine if there exists a one-to-one correspondence between the nodes and edges of the query graph and a subgraph in the target graph, such that the structure and connectivity of the query graph are preserved.

Subgraph matching has various applications in different domains, including bioinformatics, social network analysis, image processing, and graph database querying. It is a computationally challenging problem due to the need to consider all possible combinations of nodes and edges in the target graph. Efficient algorithms and data structures are developed to solve subgraph matching, employing techniques such as backtracking, graph traversal, and pruning strategies to optimize the search process. The output of a subgraph matching algorithm is a set of subgraphs that match the query graph, providing valuable insights into the structural similarities and relationships within the target graph._

   	- [X] Define expected results for Sequential Implementation of SGM:

_Expected SGM behaviors for Sequential Implementation are defined in the context of subgraph isomorphism algorithms that are executed in a sequential or single-threaded manner. Subgraph isomorphism refers to the problem of determining if a given pattern graph exists within a larger target graph and identifying the mapping of vertices and edges between them.

In a sequential implementation, certain behaviors are expected to ensure the correctness and efficiency of the subgraph isomorphism algorithm. Firstly, the algorithm should traverse the target graph and exhaustively explore all possible subgraphs to check for isomorphism. This involves considering different combinations of vertices and edges in the target graph and comparing them with the pattern graph. The algorithm should ensure that no potential subgraph is overlooked during this process.

Secondly, the sequential implementation should maintain the order in which the subgraphs are examined to avoid duplication or redundancy. By carefully organizing the search space, the algorithm can eliminate redundant computations and focus on exploring unique and promising subgraphs. This can significantly enhance the efficiency of the subgraph isomorphism algorithm.

In summary, an expected behavior for sequential implementations of subgraph isomorphism algorithms includes thorough exploration of the target graph to identify all possible subgraphs that are isomorphic to the pattern graph. Additionally, the algorithm should follow an organized and efficient search strategy to avoid redundant computations and improve performance. These behaviors contribute to the accurate and efficient detection of subgraph isomorphism in a sequential implementation._

       	- [X] Define expected results for Parallel Implementation of SGM:
_Expected SGM (Subgraph Matching) behaviors for parallel implementation refer to the anticipated outcomes and characteristics when implementing subgraph matching algorithms in a parallel computing environment. Parallel implementation involves executing multiple computational tasks simultaneously, which can significantly improve the performance and efficiency of subgraph matching algorithms by leveraging the power of multiple processing units.

In parallel implementations of SGM algorithms, there are several expected behaviors. Firstly, there is an expectation of improved scalability, where the algorithm's performance should scale with the number of available processing units. As more resources are allocated, the subgraph matching process should exhibit faster execution times, enabling larger and more complex graphs to be processed within a reasonable time frame.

Secondly, parallel implementations are expected to exhibit load balancing, ensuring that the computational workload is evenly distributed across the available processing units. This allows for efficient utilization of resources and prevents individual units from becoming bottlenecks. Load balancing also helps to minimize idle time and maximize overall throughput by keeping all processing units actively engaged in the subgraph matching task.

Furthermore, parallel implementations should exhibit synchronization and communication behaviors. Synchronization mechanisms are necessary to coordinate and manage the parallel execution of tasks, ensuring proper data consistency and integrity. Communication mechanisms, such as inter-process communication or shared memory, may be employed to exchange information and intermediate results between different processing units, enabling collaborative computations and efficient coordination of subgraph matching tasks.

In summary, expected SGM behaviors for parallel implementation include improved scalability, load balancing, synchronization, and communication. These behaviors aim to enhance the performance and efficiency of subgraph matching algorithms by leveraging parallel computing resources, enabling faster processing of larger and more complex graphs._
