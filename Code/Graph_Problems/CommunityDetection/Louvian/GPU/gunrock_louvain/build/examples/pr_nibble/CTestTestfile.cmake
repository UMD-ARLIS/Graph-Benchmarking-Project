# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/pr_nibble
# Build directory: /home/nanir/gunrock/build/examples/pr_nibble
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_PR_NIBBLE_CMD "/home/nanir/gunrock/build/bin/pr_nibble" "--help")
set_tests_properties(TEST_PR_NIBBLE_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/pr_nibble/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/pr_nibble/CMakeLists.txt;0;")
add_test(TEST_PR_NIBBLE "/home/nanir/gunrock/build/bin/pr_nibble" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx")
set_tests_properties(TEST_PR_NIBBLE PROPERTIES  PASS_REGULAR_EXPRESSION "PASSED" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/pr_nibble/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/pr_nibble/CMakeLists.txt;0;")
