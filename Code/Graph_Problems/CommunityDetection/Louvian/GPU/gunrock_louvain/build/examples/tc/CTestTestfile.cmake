# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/tc
# Build directory: /home/nanir/gunrock/build/examples/tc
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_TC_CMD "/home/nanir/gunrock/build/bin/tc" "--help")
set_tests_properties(TEST_TC_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/tc/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/tc/CMakeLists.txt;0;")
add_test(TEST_TC "/home/nanir/gunrock/build/bin/tc" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx" "--sort-csr")
set_tests_properties(TEST_TC PROPERTIES  PASS_REGULAR_EXPRESSION "PASS" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/tc/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/tc/CMakeLists.txt;0;")
