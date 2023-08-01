# Subgraph Matching  Datasets. 

Due to the sizes of these files, we include here the sources of the datasets we use, rather than the full dataset. 

## Small Dataset

**Name:** Benchmarks for the Subgraph Isomorhism Problem - Scale Free Graphs - A.01

**Nodes:** 200

**Edges:** 3043

**SOD:** 5 Kb

**Source:** [Benchmarks for the Subgraphs Isomorphism Problem](https://perso.liris.cnrs.fr/christine.solnon/SIP.html)

        wget http://liris.cnrs.fr/csolnon/newSIPbenchmarks.tgz
        tar -zxvf newSIPbenchmarks.tgz
        rm newSIPbenchmarks.tgz
        cd newSIPbenchmarks.tgz/scalefree/A.01
	cp -r newSIPbenchmarks.tgz/scalefree/A.01 SMALL_A.01
        

**Format:** Unsure of the format, but needs to be converted into something that the fv3 algorithm can eat using our grf_converter script
which assuming you are in the subgraph_matching directory should be 

        python ../../Code/Data_Analysis/grf_converter.py -i target -o target.grf

### Pattern

**Number of Subgraphs:** 180

**Number of Nodes:** 180

**Number of Edges:** 180

**SOD:** 4 Kb

**Source:** Same as A.01 Target. To convert the pattern file into the graph file, assuming you are in the subgraph_matching directory.

	python ../../Code/Data_Analysis/grf_converter.py -i pattern -o pattern.grf



## Medium Dataset

### Target

**Name:** Enron Email Dataset

**Nodes:** 36,692 

**Edges:** 183,131

**SOD:** 3,955 Kb

**Source:** [Stanford Network Analytics Program (SNAP)](https://snap.stanford.edu/data/email-Enron.html) via the [MIT Graph Challenge Datasets](h>

        wget https://snap.stanford.edu/data/email-Enron.txt.gz
        gunzip email-Enron.txt.gz
	mv email-Enron.txt MEDIUM_email-Enron.txt
        
**Format:** 

comes in an adjacency list format with some leading comments, can be moved into the required GRF format for vf3 with our converter. Assuming you >

        python ../../Code/Data_Analysis/grf_converter.py -i email-Enron.txt -o email-Enron.grf -AL

### Pattern

None Provided.

## Large Dataset

### Target 
**Name:** Measurement and Analysis on the Wide Internet (MAWI) Graph 1

**Nodes:** 18,571,154

**Edges:** 38,040,320

**SOD:** 684,690 Kb

**Source:** [MIT Graph Challenge Datasets](https://graphchallenge.mit.edu/data-sets) generated from [MWAI Archives](http://mawi.wide.ad.jp/mawi/)


	wget https://graphchallenge.s3.amazonaws.com/synthetic/gc5/201512012345.v18571154_e38040320.tsv
	mv 201512012345.v18571154_e38040320.tsv LARGE_201512012345.v18571154_e38040320.tsv

**Format:** Tab Seperated Adjacency List, needs to be converted into a grf format with: 

	 

### Pattern

## Huge Dataset

**Name:** Measurement and Analysis on the Wide Internet (MAWI) Graph 5

**Nodes:** 226,196,185

**Edges:** 480,047,894

**SOD:** 10,048,635 Kb

**Source:** [MIT Graph Challenge Datasets](https://graphchallenge.mit.edu/data-sets) generated from [MWAI Archives](http://mawi.wide.ad.jp/mawi/)

	wget https://graphchallenge.s3.amazonaws.com/synthetic/gc5/201512020330.v226196185_e480047894.tsv
	mv 201512020330.v226196185_e480047894.tsv HUGE_201512020330.v226196185_e480047894.tsv

**Format:** Tab Seperated Adjacency List, needs to be converted into a grf format with: 

        
