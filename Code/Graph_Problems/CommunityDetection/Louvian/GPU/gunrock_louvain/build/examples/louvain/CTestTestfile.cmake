# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/louvain
# Build directory: /home/nanir/gunrock/build/examples/louvain
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_LOUVAIN_CMD "/home/nanir/gunrock/build/bin/louvain" "--help")
set_tests_properties(TEST_LOUVAIN_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/louvain/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/louvain/CMakeLists.txt;0;")
add_test(TEST_LOUVAIN "/home/nanir/gunrock/build/bin/louvain" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx" "--omp-threads=32" "--advance-mode=ALL_EDGES" "--unify-segments=true")
set_tests_properties(TEST_LOUVAIN PROPERTIES  PASS_REGULAR_EXPRESSION "PASS" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/louvain/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/louvain/CMakeLists.txt;0;")
