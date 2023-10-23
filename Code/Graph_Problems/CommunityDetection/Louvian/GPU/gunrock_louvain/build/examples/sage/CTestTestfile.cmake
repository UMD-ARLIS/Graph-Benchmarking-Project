# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/sage
# Build directory: /home/nanir/gunrock/build/examples/sage
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_SAGE_CMD "/home/nanir/gunrock/build/bin/sage" "--help")
set_tests_properties(TEST_SAGE_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/sage/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/sage/CMakeLists.txt;0;")
add_test(TEST_SAGE "/home/nanir/gunrock/build/bin/sage" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx")
set_tests_properties(TEST_SAGE PROPERTIES  PASS_REGULAR_EXPRESSION "Embedding validation: PASS" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/sage/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/sage/CMakeLists.txt;0;")
