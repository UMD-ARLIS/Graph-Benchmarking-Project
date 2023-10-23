# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/sssp
# Build directory: /home/nanir/gunrock/build/examples/sssp
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_SSSP_CMD "/home/nanir/gunrock/build/bin/sssp" "--help")
set_tests_properties(TEST_SSSP_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/sssp/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/sssp/CMakeLists.txt;0;")
add_test(TEST_SSSP "/home/nanir/gunrock/build/bin/sssp" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx" "--undirected" "--src=0")
set_tests_properties(TEST_SSSP PROPERTIES  FAIL_REGULAR_EXPRESSION "errors" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/sssp/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/sssp/CMakeLists.txt;0;")
add_test(TEST_SSSP_QUICK_VALIDATION "/home/nanir/gunrock/build/bin/sssp" "market" "/home/nanir/gunrock/dataset/small/bips98_606.mtx" "--validation=each" "--quick")
set_tests_properties(TEST_SSSP_QUICK_VALIDATION PROPERTIES  FAIL_REGULAR_EXPRESSION "errors" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/sssp/CMakeLists.txt;15;add_test;/home/nanir/gunrock/examples/sssp/CMakeLists.txt;0;")
