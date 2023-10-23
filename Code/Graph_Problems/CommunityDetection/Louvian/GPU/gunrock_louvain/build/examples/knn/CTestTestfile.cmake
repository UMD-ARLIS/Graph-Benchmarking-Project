# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/examples/knn
# Build directory: /home/nanir/gunrock/build/examples/knn
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TEST_KNN_CMD "/home/nanir/gunrock/build/bin/knn" "--help")
set_tests_properties(TEST_KNN_CMD PROPERTIES  PASS_REGULAR_EXPRESSION "Required arguments:" _BACKTRACE_TRIPLES "/home/nanir/gunrock/cmake/SetSubProject.cmake;56;add_test;/home/nanir/gunrock/cmake/SetSubProject.cmake;0;;/home/nanir/gunrock/examples/knn/CMakeLists.txt;6;include;/home/nanir/gunrock/examples/knn/CMakeLists.txt;0;")
add_test(TEST_KNN "/home/nanir/gunrock/build/bin/knn" "market" "--labels-file" "/home/nanir/gunrock/dataset/small/stars_2total_separate" "--k=2")
set_tests_properties(TEST_KNN PROPERTIES  FAIL_REGULAR_EXPRESSION "[1-9]+[0-9]* errors occurred;FAIL;INCORRECT" PASS_REGULAR_EXPRESSION "PASSED KNN" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/knn/CMakeLists.txt;8;add_test;/home/nanir/gunrock/examples/knn/CMakeLists.txt;0;")
add_test(TEST_KNN_MULTIPLE_RUNS "/home/nanir/gunrock/build/bin/knn" "market" "--labels-file" "/home/nanir/gunrock/dataset/small/stars_2total_separate" "--k=3" "--quick" "--num-runs=10")
set_tests_properties(TEST_KNN_MULTIPLE_RUNS PROPERTIES  FAIL_REGULAR_EXPRESSION "[1-9]+[0-9]* errors occurred;FAIL;INCORRECT" _BACKTRACE_TRIPLES "/home/nanir/gunrock/examples/knn/CMakeLists.txt;13;add_test;/home/nanir/gunrock/examples/knn/CMakeLists.txt;0;")
