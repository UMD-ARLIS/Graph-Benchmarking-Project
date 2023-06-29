# Running The Louvian Algorithm (Open Source)

1. Move the DataSetCreationTool.c into the louvain-generic directory

2. Change into the louvain-generic directory. May have to adjust path as necessary
```
cd Downloads
cd louvain-generic
```
3. Compile the dataset creation tool
```
cc DataSetCreationTool.c -o DataSetCreationTool.o
```
4. Output the results to a file called graph.txt
```
./DataSetCreationTool.o <num_nodes> <num_edges> <random_seed> > graph.txt
```
5. Convert from text format
```
./convert -i graph.txt -o graph.bin
```
6. Compute Communities
```
./louvain graph.bin -l -1 -v -q id_qual > graph.tree
```
7. Display information on tree structure
```
./hierarchy graph.tree 
```


# Sample Metrics

***
## <span style="color: blue;">Graph 1</span>
### Information: 
    Number Nodes - 1000  
    Number Edges - 1000  
    Random Seed - 1234  

### Results:  
    Number of levels: 5  
    level 0: 1000 nodes  
    level 1: 492 nodes  
    level 2: 302 nodes  
    level 3: 215 nodes  
    level 4: 180 nodes  

### Time: 
    Total duration: 0 sec  
    0.804371       
***
## <span style="color: blue;">Graph 2</span>
### Information: 
    Number Nodes - 3  
    Number Edges - 3  
    Random Seed - 1  

### Results:  
    Number of levels: 2  
    level 0: 3 nodes  
    level 1: 1 nodes   

### Time: 
    Total duration: 0 sec  
    0      
***
## <span style="color: blue;">Graph 3</span>
### Information: 
    Number Nodes - 100,000  
    Number Edges - 100,000  
    Random Seed - 2  

### Results:  
    Number of levels: 9  
    level 0: 100000 nodes  
    level 1: 49845 nodes  
    level 2: 30691 nodes  
    level 3: 22731 nodes  
    level 4: 19272 nodes  
    level 5: 17633 nodes  
    level 6: 16640 nodes  
    level 7: 16404 nodes  
    level 8: 16403 nodes   

### Time: 
    Total duration: 1 sec  
    0.840275     
***


### Information on Compiling code in C

Potential Solutions
1. Create a copy of the louvian generic directory. Rename all the files to .c. Try running code
2. Re-write code in C