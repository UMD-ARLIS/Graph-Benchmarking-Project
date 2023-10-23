# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/lcc
# Build directory: /home/nanir/gunrock/build/examples/lcc
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_LCC_CMD "/home/nanir/gunrock/build/bin/lcc" "--help")
set_tests_properties(TEST_LCC_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/lcc/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/lcc/CMakeLists.txt;0;")
add_test(TEST_LCC "/home/nanir/gunrock/build/bin/lcc" "--undirected=true" "market" "/home/nanir/gunrock/dataset/small/test_lcc.mtx" "--sort-csr")
set_tests_properties(TEST_LCC PROPERTIES  PASS_REGULAR_EXPRESSION "PASS" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/lcc/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/lcc/CMakeLists.txt;0;")
