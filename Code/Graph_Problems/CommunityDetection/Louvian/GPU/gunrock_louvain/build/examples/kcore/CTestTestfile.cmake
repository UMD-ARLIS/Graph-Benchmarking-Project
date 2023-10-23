# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/kcore
# Build directory: /home/nanir/gunrock/build/examples/kcore
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_KCORE_CMD "/home/nanir/gunrock/build/bin/kcore" "--help")
set_tests_properties(TEST_KCORE_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/kcore/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/kcore/CMakeLists.txt;0;")
add_test(TEST_KCORE "/home/nanir/gunrock/build/bin/kcore" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx")
set_tests_properties(TEST_KCORE PROPERTIES  FAIL_REGULAR_EXPRESSION "[1-9]+[0-9]* errors occurred;FAIL;INCORRECT" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/kcore/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/kcore/CMakeLists.txt;0;")
