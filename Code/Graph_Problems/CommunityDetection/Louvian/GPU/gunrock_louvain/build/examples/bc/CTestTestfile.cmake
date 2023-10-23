# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/bc
# Build directory: /home/nanir/gunrock/build/examples/bc
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_BC_CMD "/home/nanir/gunrock/build/bin/bc" "--help")
set_tests_properties(TEST_BC_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/bc/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/bc/CMakeLists.txt;0;")
add_test(TEST_BC "/home/nanir/gunrock/build/bin/bc" "market" "/home/nanir/gunrock/dataset/small/bips98_606.mtx" "--undirected" "--src=0")
set_tests_properties(TEST_BC PROPERTIES  FAIL_REGULAR_EXPRESSION "INCORRECT" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/bc/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/bc/CMakeLists.txt;0;")
