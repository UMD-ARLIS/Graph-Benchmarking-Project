# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/ss
# Build directory: /home/nanir/gunrock/build/examples/ss
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_SS_CMD "/home/nanir/gunrock/build/bin/ss" "--help")
set_tests_properties(TEST_SS_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/ss/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/ss/CMakeLists.txt;0;")
add_test(TEST_SS "/home/nanir/gunrock/build/bin/ss" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx")
set_tests_properties(TEST_SS PROPERTIES  PASS_REGULAR_EXPRESSION "PASS" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/ss/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/ss/CMakeLists.txt;0;")
