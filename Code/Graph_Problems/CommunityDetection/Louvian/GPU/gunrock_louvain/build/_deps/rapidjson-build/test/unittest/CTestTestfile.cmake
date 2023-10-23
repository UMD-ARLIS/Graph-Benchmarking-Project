# CMake generated Testfile for 
# Source directory: /home/nanir/gunrock/externals/rapidjson/test/unittest
# Build directory: /home/nanir/gunrock/build/_deps/rapidjson-build/test/unittest
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unittest "/home/nanir/gunrock/build/bin/unittest")
set_tests_properties(unittest PROPERTIES  WORKING_DIRECTORY "/home/nanir/gunrock/bin" _BACKTRACE_TRIPLES "/home/nanir/gunrock/externals/rapidjson/test/unittest/CMakeLists.txt;76;add_test;/home/nanir/gunrock/externals/rapidjson/test/unittest/CMakeLists.txt;0;")
add_test(valgrind_unittest "valgrind" "--suppressions=/home/nanir/gunrock/test/valgrind.supp" "--leak-check=full" "--error-exitcode=1" "/home/nanir/gunrock/build/bin/unittest" "--gtest_filter=-SIMD.*")
set_tests_properties(valgrind_unittest PROPERTIES  WORKING_DIRECTORY "/home/nanir/gunrock/bin" _BACKTRACE_TRIPLES "/home/nanir/gunrock/externals/rapidjson/test/unittest/CMakeLists.txt;82;add_test;/home/nanir/gunrock/externals/rapidjson/test/unittest/CMakeLists.txt;0;")
