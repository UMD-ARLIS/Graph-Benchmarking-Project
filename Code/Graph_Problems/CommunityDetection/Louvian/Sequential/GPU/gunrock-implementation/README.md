# Gunrock GPU Implementation of Louvian Algorithm   

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
./examples/louvain/bin/test_louvain_12.2_x86_64 --omp-threads=32 --iter-stats --pass-stats \
--advance-mode=ALL_EDGES --unify-segments=true --validation=each --num-runs=10 \
--graph-type=market --graph-file=[FILE_PATH]
````


* Add --undirected, if the graph is indeed undirected.
* Remove --iter-stats or --pass-stats, if detailed timings are not required.
* Remove --validation=each, to only compute the modularity for the last run.
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

* For example, when CATEGORY = small and FILE_NAME = chesapeake, the FILE_PATH is
  > dataset/small/chesapeake.mtx


#### Example:
```
./examples/louvain/bin/test_louvain_12.2_x86_64 --omp-threads=32 --iter-stats --pass-stats \
--advance-mode=ALL_EDGES --unify-segments=true --validation=each --num-runs=10 \
--graph-type=market --graph-file=dataset/small/chesapeake.mtx
```
---

## Output

The output should appear immediately. For the example above, check out [sample_output.txt](https://github.com/osullik/summer2023/edit/main/Code/Graph_Problems/CommunityDetection/Louvian/Sequential/GPU/gunrock-implementation/sample_output.txt)

## Proof using GPU Power
![Screenshot 2023-07-15 at 10 06 29 AM](https://github.com/osullik/summer2023/assets/98720566/9e3a3087-e995-42f8-a269-3244492993dc)
