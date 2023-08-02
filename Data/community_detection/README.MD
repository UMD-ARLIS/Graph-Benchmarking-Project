# Community Detection Datasets. 

Due to the sizes of these files, we include here the sources of the datasets we use, rather than the full dataset. 

## Small Dataset
The Small Dataset is derived from 

**Name:** Chesepeake

**Nodes:** 39 

**Edges:** 170

**SOD:** 22 Kb

**Source:** [Gunrock Benchmark](https://github.com/gunrock/gunrock/tree/main/datasets/chesapeake)

	wget https://github.com/gunrock/gunrock/blob/main/datasets/chesapeake/chesapeake.mtx
	mv chesapeake.mtx SMALL_chesapeake.mtx

**Format:** (MTX file, the [Matrix Market Format](https://people.sc.fsu.edu/~jburkardt/data/mm/mm.html). Will work with GUNROCK GPU implementations out-of-the-box, but needs to be reformatted to work with CPU implementations.)

## Medium Dataset

**Name:** email-EU-Core

**Nodes:** 1,005

**Edges:** 25,571        

**SOD:** 189 Kb

**Source:**  [The Stanford Network Analysis Project](https://snap.stanford.edu/data/email-Eu-core.html)

	wget https://snap.stanford.edu/data/email-Eu-core.txt.gz
	gunzip email-Eu-core.txt.gz
	mv email-Eu-core.txt MEDIUM_email-Eu-core.txt
	
**Format:** .txt adjacency list. Will work out-of-the-box on sequential louvain, but will require conversion to mtx format for GPU. 

## Large Dataset

**Name:** wiki-talk

**Nodes:** 2,394,385

**Edges:** 4,659,565

**SOD:** 64,911 Kb

**Source:**  [Stanford Network Analysis Project](https://snap.stanford.edu/data/wiki-Talk.html)


	wget https://snap.stanford.edu/data/wiki-Talk.txt.gz
	gunzip wiki-Talk.txt.gz
	mv wiki-Talk.txt LARGE_wiki-Talk.txt

**Format:** .txt adjacency list with # prepended comments. Will need to be transformed into mtx format to work in GPU implementation. 
## Huge Dataset
The huge datset is derived from the twitter benchmark dataset used by thge UC Berkeley GAP benchmark. 

**Name:** Twitter RV

**Nodes:** 61,578,415

**Edges:** 2,405,026,930

**SOD:** 25,558,868 Kb

**Source:** [ANLAB KAIST Twitter Dataset](https://github.com/ANLAB-KAIST/traces/releases/tag/twitter_rv.net)
	
	wget https://github.com/ANLAB-KAIST/traces/releases/download/twitter_rv.net/twitter_rv.net.00.gz
	wget https://github.com/ANLAB-KAIST/traces/releases/download/twitter_rv.net/twitter_rv.net.01.gz
	wget https://github.com/ANLAB-KAIST/traces/releases/download/twitter_rv.net/twitter_rv.net.02.gz
	wget https://github.com/ANLAB-KAIST/traces/releases/download/twitter_rv.net/twitter_rv.net.03.gz
	gunzip -c twitter_rv.net.00 twitter_rv.net.01 twitter_rv.net.02 twitter_rv.net.03 > HUGE_twitter_rv.net

**Format:** .txt Adjacency List
