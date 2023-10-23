# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/hits
# Build directory: /home/nanir/gunrock/build/examples/hits
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_HITS_CMD "/home/nanir/gunrock/build/bin/hits" "--help")
set_tests_properties(TEST_HITS_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/hits/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/hits/CMakeLists.txt;0;")
add_test(TEST_HITS "/home/nanir/gunrock/build/bin/hits" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx")
set_tests_properties(TEST_HITS PROPERTIES  FAIL_REGULAR_EXPRESSION "[1-9]+[0-9]* errors occurred;FAIL;INCORRECT" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/hits/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/hits/CMakeLists.txt;0;")
add_test(TEST_HITS_BIPS "/home/nanir/gunrock/build/bin/hits" "market" "/home/nanir/gunrock/dataset/small/bips98_606.mtx")
set_tests_properties(TEST_HITS_BIPS PROPERTIES  FAIL_REGULAR_EXPRESSION "[1-9]+[0-9]* errors occurred;FAIL;INCORRECT" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/hits/CMakeLists.txt;10;add_test;/home/nanir/gunrock/examples/hits/CMakeLists.txt;0;")
