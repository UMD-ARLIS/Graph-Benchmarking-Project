# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/color
# Build directory: /home/nanir/gunrock/build/examples/color
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_COLOR_CMD "/home/nanir/gunrock/build/bin/color" "--help")
set_tests_properties(TEST_COLOR_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/color/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/color/CMakeLists.txt;0;")
add_test(TEST_COLOR "/home/nanir/gunrock/build/bin/color" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx" "--undirected")
set_tests_properties(TEST_COLOR PROPERTIES  PASS_REGULAR_EXPRESSION "0 errors occurred." _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/color/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/color/CMakeLists.txt;0;")
