<H1>Quick Start Guide For Parallel Louvain Method For Fast Community Detection</H1>

<H2>Community Detection In Graphs</H2>
<p>
Interactions in online social networks, communication networks can be naturally modelled as graphs. Structural communities in graphs generally defined as groups of highly connected vertices/nodes in the graph. These groups generally represent similar interest groups, friend communities etc., that have more interactions or similarities with each other. 
<br>
Finding communities in large graphs is a very useful technique when trying to narrow down analytics to smaller targeted groups, identifying interest groups etc. This can be used for online marketing, online surveillance etc. 
<br>
Detecting communities in graphs can be a computationally very expensive task, specially for large graphs.
</p>

<img src="http://farm8.staticflickr.com/7100/7046439385_b83413587a_b.jpg" height="500" width="500"/>

<H2>Parallel Algorithm For Fast Community Detection</H2>
<p>
This document provides a quick guide to setting up and running our parallel implementation for <a href="https://sites.google.com/site/findcommunities/"> Louvain community detection method</a> to identify non overlapping communities in large graphs . 
<br>
Lovain community detection method detect communities in a graph in a hierarchical manner. At each level detected communities are reduced to vertices, reducing the graph size. This enable zoom in and out of high level communities to find communities at a lower level. 
</p>

<img src="https://sites.google.com/site/findcommunities/pol.jpg" height="300" width="500"/>
<p>Detailed description of Parallel Louvain method can be found <a href="https://xd-web-proxy.data-tactics-corp.com/wiki/display/ANL/GoFFish+Subgraph+Oriented+Graph+Analytics+Experiments">here</a>.</p>

<H2>Quick Start With Development VM</H2>

Our distributed memory parallel implementation of Louvain community detection is based on MPI 2.0 runtime environment. Following instructions guide you through how to run a this implementation on a sample graph to detect communities.

Pre installed virtual machine is used in this guide which can be installed in your local machine. Following installation instructions assume a Linux operating system environment.	

<H3>Download Virtual Machine</H3>
<p> Download the pre installed virtual machine from <a href="http://losangeles.usc.edu/usc-cloud/goffish/parallel-louvain-mpi.zip">here</a>
</p>

<H3>Setting up</H3>
<p>
Install Oracle Virtual Box 4.3.8. You can download it from <a href="https://www.virtualbox.org/wiki/Download_Old_Builds_4_3">here</a>.
<br>
Install and configure Vagrant:<br>
<code>sudo apt-get install vagrant</code>
<br>
Add Vagrant plugin that keeps Virtual Box Guest Additions in sync:<br>
<code>vagrant plugin install vagrant-vbguest</code>
<br>
Extract the downloaded virtual machine.<br>

Go to the virtual machine directory and start the environment:<br>
<code>vagrant up</code><br>
<br>
After it boots, log in to the VM:<br>
<code>vagrant ssh</code><br>
<br>
Other useful vagrant commands:<br>
<code>vagrant suspend</code> saves the current running state of the machine and stops it. vagrant up will resume.
<br>
<code>vagrant halt</code> gracefully shuts down the vm. vagrant up will boot it back up.
<br>
<code>vagrant destroy</code> destroys the VM (and all the cruft inside of it). Running <code>vagrant up</code> will reprovision and run the deploy scripts again.
<br>
More info at http://www.vagrantup.com/
</p>

<H3>Running The Sample</H3>
<p>
Log in to the virtual machine:
<code>vagrant ssh</code><br>

Source code and sample data sets are located in <i>/vagrant/code/louvain-mpi</i> directory: 
<code>cd /vagrant/code/louvain-mpi</code><br>

A Sample small graph is located in this directory. <br>
<ul>
<li>4elt.txt - graph in edge list format.</li>
<li>4elt.graph - graph in Metis graph format. </li>
</ul>
</p>

<br>
<p>
First step of execution is partitioning the graph and creating the graph partitions for the parallel Louvain algorithm. This is done using <i>converter-script.sh</i>: <br> 
<code>./converter-script.sh</code><br>
</p>
<br>
<p>
Executing this will compile the source code, partition the graph into 2 partitions, and create graph partitions.<br>
To run the the parallel louvain algorithm run the <i>run-louvain.sh</i> script:<br>
<code>./run-louvain.sh</code>
</p><p>
Executing this script with run the algorithm in two MPI processors and output the community graph at 2nd level of louvain method in <i>level2.txt</i>:
<br>
level2.txt display the community graph in adjacency list format.
each line is in following format<br>
source: (sink1 weight1) (sink2 weight2) . . .(sinkN weightN)
<br>
</p><p>
Example:<br><br></p>

<p>
0: (0 14) (1 1) (23 3) (33 4) (128 1) (134 2) (183 3) (3037 2) (3038 2) (3078 1)<br>
1: (0 1) (1 14) (6 3) (33 4) (48 3) (74 1) (3037 1) (3053 3)<br>
2: (2 14) (3 3) (5 3) (8 1) (9 3) (3106 2) (3108 3) (3110 1)<br>
3: (2 3) (3 10) (4 3) (7 1) (8 3) (3110 4)<br>
4: (3 3) (4 6) (7 3) (8 2) (10 3) (13 1)<br>
5: (2 3) (5 10) (9 1) (12 3) (16 2) (19 1) (3108 2) (3111 3)<br>
6: (1 3) (6 10) (21 3) (48 3) (86 1) (222 2) (3053 3)<br>
7: (3 1) (4 3) (7 18) (13 5) (3110 1) (3112 4)<br>
8: (2 1) (3 3) (4 2) (8 10) (9 3) (10 1) (11 3)<br>
9: (2 3) (5 1) (8 3) (9 6) (11 1) (15 1) (16 3)<br>
10: (4 3) (8 1) (10 6) (11 3) (13 2) (14 3)<br>
11: (8 3) (9 1) (10 3) (11 6) (14 1) (15 3) (27 1)<br>
12: (5 3) (12 10) (17 3) (19 3) (31 1) (3111 1) (3120 3)<br>
13: (4 1) (7 5) (10 2) (13 14) (14 3) (18 3)<br>
14: (10 3) (11 1) (13 3) (14 10) (18 1) (20 3) (27 3)<br>
15: (9 1) (11 3) (15 6) (16 3) (27 3) (29 2)<br>
16: (5 2) (9 3) (15 3) (16 10) (19 4) (29 1)<br>
17: (12 3) (17 6) (24 2) (31 3) (51 2) (72 3) (3120 1)<br>
</p>

Publications: <br>

 <a href="http://www-scf.usc.edu/~cwickram/pubs/wickramaarachchi_hpec_2014.pdf">Fast Parallel Algorithm For Unfolding Of Communities In Large Graphs</a>, 
Charith Wickramaarachchi, Marc Frincu, Patrick Small and Viktor Prasanna,
IEEE High Performance Extreme Computing Conference (HPEC '14), 2014

</p>

