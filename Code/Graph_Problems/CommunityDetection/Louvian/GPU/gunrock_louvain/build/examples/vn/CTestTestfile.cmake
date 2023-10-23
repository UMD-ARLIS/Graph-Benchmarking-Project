# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/vn
# Build directory: /home/nanir/gunrock/build/examples/vn
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_VN_CMD "/home/nanir/gunrock/build/bin/vn" "--help")
set_tests_properties(TEST_VN_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/vn/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/vn/CMakeLists.txt;0;")
