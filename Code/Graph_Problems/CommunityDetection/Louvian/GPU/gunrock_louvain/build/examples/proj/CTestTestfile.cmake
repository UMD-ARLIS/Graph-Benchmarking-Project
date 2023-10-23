# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/proj
# Build directory: /home/nanir/gunrock/build/examples/proj
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_PROJ_CMD "/home/nanir/gunrock/build/bin/proj" "--help")
set_tests_properties(TEST_PROJ_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/proj/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/proj/CMakeLists.txt;0;")
add_test(TEST_PROJ "/home/nanir/gunrock/build/bin/proj" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx")
set_tests_properties(TEST_PROJ PROPERTIES  PASS_REGULAR_EXPRESSION "PASSED" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/proj/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/proj/CMakeLists.txt;0;")
