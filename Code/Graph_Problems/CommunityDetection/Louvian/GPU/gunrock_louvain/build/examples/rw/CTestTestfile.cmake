# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/rw
# Build directory: /home/nanir/gunrock/build/examples/rw
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_RW_CMD "/home/nanir/gunrock/build/bin/rw" "--help")
set_tests_properties(TEST_RW_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/rw/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/rw/CMakeLists.txt;0;")
add_test(TEST_RW "/home/nanir/gunrock/build/bin/rw" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx")
set_tests_properties(TEST_RW PROPERTIES  PASS_REGULAR_EXPRESSION "0 errors occurred" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/rw/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/rw/CMakeLists.txt;0;")
