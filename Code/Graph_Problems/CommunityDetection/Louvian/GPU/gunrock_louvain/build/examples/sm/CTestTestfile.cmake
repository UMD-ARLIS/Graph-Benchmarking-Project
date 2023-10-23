# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/sm
# Build directory: /home/nanir/gunrock/build/examples/sm
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_SM_CMD "/home/nanir/gunrock/build/bin/sm" "--help")
set_tests_properties(TEST_SM_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/sm/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/sm/CMakeLists.txt;0;")
add_test(TEST_SM "/home/nanir/gunrock/build/bin/sm" "market" "/home/nanir/gunrock/dataset/small/tree.mtx" "--pattern-graph-type=market" "--pattern-graph-file=/home/nanir/gunrock/dataset/small/query_sm.mtx" "--undirected=1" "--pattern-undirected=1" "--num-runs=1" "--quiet=false")
set_tests_properties(TEST_SM PROPERTIES  PASS_REGULAR_EXPRESSION "PASS" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/sm/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/sm/CMakeLists.txt;0;")
