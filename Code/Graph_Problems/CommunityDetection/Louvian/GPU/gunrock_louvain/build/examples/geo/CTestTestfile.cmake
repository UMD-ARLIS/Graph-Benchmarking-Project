# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/geo
# Build directory: /home/nanir/gunrock/build/examples/geo
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_GEO_CMD "/home/nanir/gunrock/build/bin/geo" "--help")
set_tests_properties(TEST_GEO_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/geo/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/geo/CMakeLists.txt;0;")
add_test(TEST_GEO "/home/nanir/gunrock/build/bin/geo" "market" "/home/nanir/gunrock/dataset/small/chesapeake.mtx" "--labels-file=/home/nanir/gunrock/examples/geo/_data/samples/sample.labels")
set_tests_properties(TEST_GEO PROPERTIES  PASS_REGULAR_EXPRESSION "0 errors occurred" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/geo/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/geo/CMakeLists.txt;0;")
