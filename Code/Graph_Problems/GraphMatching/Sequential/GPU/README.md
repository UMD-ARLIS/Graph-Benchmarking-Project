# Gunrock GPU Implementation of Subgraph Matching VF2 Algorithm   

### ssh into the ubuntu user on AWS EC2 Instance
```
ssh -i <keyName>.pem <username>@##.##.##.##
```  
### Change into the gunrock directory
```
cd gunrock
```
---
## Runing the algorithm


#### Format: 
````
./examples/sm/bin/test_sm_12.2_x86_64 --pattern-graph-type=market --pattern-graph-file=[FILE_PATH] --undirected=1 --pattern-undirected=1 --num-runs=1 --graph-type=market --graph-file=[FILE_PATH] 
````

* Replace [FILE_PATH] with the path to specified dataset file 
    1. Use your own dataset (must be an market file .mtx)
    2. Use existing available datasets as instructed below:

        Gunrock provides small and large datasets. You can familiarize yourself with them [here](https://github.com/gunrock/gunrock/tree/master/dataset)


          - For small datasets, simply the name of the .mtx file is needed  
            > * FILE_PATH = dataset/small/[FILE_NAME].mtx

          - For large datasets follow procedure below:
            ```
                cd gunrock/dataset/large
                make recurse
            ```
            > * FILE_PATH = dataset/large/[FILE_NAME]/[FILE_NAME].mtx

* For example, when CATEGORY = small and FILE_NAME = tri_sm, the FILE_PATH is
  > dataset/small/tri_sm.mtx


#### Example:
```
./examples/sm/bin/test_sm_12.2_x86_64 --pattern-graph-type=market --pattern-graph-file=dataset/small/tri_sm.mtx --undirected=1 --pattern-undirected=1 --num-runs=1 --graph-type=market --graph-file=dataset/small/tri_sm.mtx
```
---

## Output

The output should appear immediately. For the example above, check out [sample_output.txt](https://github.com/osullik/summer2023/main/Code/Graph_Problems/GraphMatching/Sequential/GPU/sample_output.txt)

## Proof using GPU Power

