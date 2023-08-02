#!/bin/bash
echo SMALL-3
sudo valgrind --log-file='valgrind.out' ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\n\2 frees\n\3 bytes allocated/'        
echo SMALL-4
sudo valgrind --log-file='valgrind.out' ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\n\2 frees\n\3 bytes allocated/'
echo SMALL-P2-3
sudo valgrind --log-file='valgrind.out' ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf -a 1 -t 2; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\n\2 frees\n\3 bytes allocated/'
echo SMALL-P2-4
sudo valgrind --log-file='valgrind.out' ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf -a 1 -t 2; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\n\2 frees\n\3 bytes allocated/'
echo SMALL-P10-3
sudo valgrind --log-file='valgrind.out' ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf -a 1 -t 10; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\n\2 frees\n\3 bytes allocated/'
echo SMALL-P2-4
sudo valgrind --log-file='valgrind.out' ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf -a 1 -t 10; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\n\2 frees\n\3 bytes allocated/'