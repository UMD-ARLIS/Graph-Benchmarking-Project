# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/snn
# Build directory: /home/nanir/gunrock/build/examples/snn
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_SNN_CMD "/home/nanir/gunrock/build/bin/snn" "--help")
set_tests_properties(TEST_SNN_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/snn/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/snn/CMakeLists.txt;0;")
add_test(TEST_SNN "/home/nanir/gunrock/build/bin/snn" "market" "--labels-file" "/home/nanir/gunrock/dataset/small/stars_2total_separate" "--k=2" "--eps=1" "--min-pts=1")
set_tests_properties(TEST_SNN PROPERTIES  PASS_REGULAR_EXPRESSION "PASSED SNN" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/snn/CMakeLists.txt;14;add_test;/home/nanir/gunrock/examples/snn/CMakeLists.txt;0;")
