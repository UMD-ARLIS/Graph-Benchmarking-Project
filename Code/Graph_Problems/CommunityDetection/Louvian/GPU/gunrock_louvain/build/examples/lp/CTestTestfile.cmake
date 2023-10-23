# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/lp
# Build directory: /home/nanir/gunrock/build/examples/lp
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_LP_CMD "/home/nanir/gunrock/build/bin/lp" "--help")
set_tests_properties(TEST_LP_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/lp/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/lp/CMakeLists.txt;0;")
add_test(TEST_LP "/home/nanir/gunrock/build/bin/lp" "market" "/home/nanir/gunrock/dataset/small/test_lp_1.mtx" "--test=1" "--remove-self-loops=false")
set_tests_properties(TEST_LP PROPERTIES  _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/lp/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/lp/CMakeLists.txt;0;")
