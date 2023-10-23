# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nanir/gunrock

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nanir/gunrock/build

# Include any dependencies generated for this target.
include examples/color/CMakeFiles/color.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/color/CMakeFiles/color.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/color/CMakeFiles/color.dir/progress.make

# Include the compile flags for this target's objects.
include examples/color/CMakeFiles/color.dir/flags.make

examples/color/CMakeFiles/color.dir/color_generated_test_color.cu.o: examples/color/CMakeFiles/color.dir/color_generated_test_color.cu.o.depend
examples/color/CMakeFiles/color.dir/color_generated_test_color.cu.o: examples/color/CMakeFiles/color.dir/color_generated_test_color.cu.o.RelWithDebInfo.cmake
examples/color/CMakeFiles/color.dir/color_generated_test_color.cu.o: ../examples/color/test_color.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building NVCC (Device) object examples/color/CMakeFiles/color.dir/color_generated_test_color.cu.o"
	cd /home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir && /usr/bin/cmake -E make_directory /home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir//.
	cd /home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir && /usr/bin/cmake -D verbose:BOOL=$(VERBOSE) -D build_configuration:STRING=RelWithDebInfo -D generated_file:STRING=/home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir//./color_generated_test_color.cu.o -D generated_cubin_file:STRING=/home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir//./color_generated_test_color.cu.o.cubin.txt -P /home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir//color_generated_test_color.cu.o.RelWithDebInfo.cmake

examples/color/CMakeFiles/color.dir/color_intermediate_link.o: examples/color/CMakeFiles/color.dir/color_generated_test_color.cu.o
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building NVCC intermediate link file examples/color/CMakeFiles/color.dir/color_intermediate_link.o"
	cd /home/nanir/gunrock/build/examples/color && /usr/local/cuda-12.2/bin/nvcc --expt-extended-lambda -rdc=true "-lcudadevrt -w" -gencode=arch=compute_70,code=sm_70 -gencode=arch=compute_70,code=compute_70 -m64 -ccbin /usr/bin/cc -dlink /home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir//./color_generated_test_color.cu.o -o /home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir/./color_intermediate_link.o -Xcompiler -fPIC

# Object files for target color
color_OBJECTS =

# External object files for target color
color_EXTERNAL_OBJECTS = \
"/home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir/color_generated_test_color.cu.o" \
"/home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir/color_intermediate_link.o"

bin/color: examples/color/CMakeFiles/color.dir/color_generated_test_color.cu.o
bin/color: examples/color/CMakeFiles/color.dir/color_intermediate_link.o
bin/color: examples/color/CMakeFiles/color.dir/build.make
bin/color: /usr/local/cuda-12.2/lib64/libcudart_static.a
bin/color: /usr/lib/x86_64-linux-gnu/librt.a
bin/color: /usr/local/cuda-12.2/lib64/libcurand.so
bin/color: lib/libcolor_app.a
bin/color: lib/libgunrock_utils.so
bin/color: /usr/local/cuda-12.2/lib64/libcudart_static.a
bin/color: /usr/lib/x86_64-linux-gnu/librt.a
bin/color: /usr/local/cuda-12.2/lib64/libcurand.so
bin/color: /usr/local/cuda-12.2/lib64/libcudadevrt.a
bin/color: examples/color/CMakeFiles/color.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nanir/gunrock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/color"
	cd /home/nanir/gunrock/build/examples/color && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/color.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/color/CMakeFiles/color.dir/build: bin/color
.PHONY : examples/color/CMakeFiles/color.dir/build

examples/color/CMakeFiles/color.dir/clean:
	cd /home/nanir/gunrock/build/examples/color && $(CMAKE_COMMAND) -P CMakeFiles/color.dir/cmake_clean.cmake
.PHONY : examples/color/CMakeFiles/color.dir/clean

examples/color/CMakeFiles/color.dir/depend: examples/color/CMakeFiles/color.dir/color_generated_test_color.cu.o
examples/color/CMakeFiles/color.dir/depend: examples/color/CMakeFiles/color.dir/color_intermediate_link.o
	cd /home/nanir/gunrock/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nanir/gunrock /home/nanir/gunrock/examples/color /home/nanir/gunrock/build /home/nanir/gunrock/build/examples/color /home/nanir/gunrock/build/examples/color/CMakeFiles/color.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/color/CMakeFiles/color.dir/depend

