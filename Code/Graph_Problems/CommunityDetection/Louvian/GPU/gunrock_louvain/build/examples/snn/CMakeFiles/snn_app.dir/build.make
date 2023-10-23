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
include examples/snn/CMakeFiles/snn_app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/snn/CMakeFiles/snn_app.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/snn/CMakeFiles/snn_app.dir/progress.make

# Include the compile flags for this target's objects.
include examples/snn/CMakeFiles/snn_app.dir/flags.make

examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o: examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o.depend
examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o: examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o.RelWithDebInfo.cmake
examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o: ../gunrock/app/snn/snn_app.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building NVCC (Device) object examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o"
	cd /home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn && /usr/bin/cmake -E make_directory /home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/.
	cd /home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn && /usr/bin/cmake -D verbose:BOOL=$(VERBOSE) -D build_configuration:STRING=RelWithDebInfo -D generated_file:STRING=/home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/./snn_app_generated_snn_app.cu.o -D generated_cubin_file:STRING=/home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/./snn_app_generated_snn_app.cu.o.cubin.txt -P /home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o.RelWithDebInfo.cmake

examples/snn/CMakeFiles/snn_app.dir/snn_app_intermediate_link.o: examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building NVCC intermediate link file examples/snn/CMakeFiles/snn_app.dir/snn_app_intermediate_link.o"
	cd /home/nanir/gunrock/build/examples/snn && /usr/local/cuda-12.2/bin/nvcc --expt-extended-lambda -rdc=true "-lcudadevrt -w" -gencode=arch=compute_70,code=sm_70 -gencode=arch=compute_70,code=compute_70 -m64 -ccbin /usr/bin/cc -dlink /home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/./snn_app_generated_snn_app.cu.o -o /home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/./snn_app_intermediate_link.o -Xcompiler -fPIC

# Object files for target snn_app
snn_app_OBJECTS =

# External object files for target snn_app
snn_app_EXTERNAL_OBJECTS = \
"/home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o" \
"/home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/snn_app_intermediate_link.o"

lib/libsnn_app.a: examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o
lib/libsnn_app.a: examples/snn/CMakeFiles/snn_app.dir/snn_app_intermediate_link.o
lib/libsnn_app.a: examples/snn/CMakeFiles/snn_app.dir/build.make
lib/libsnn_app.a: examples/snn/CMakeFiles/snn_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nanir/gunrock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../lib/libsnn_app.a"
	cd /home/nanir/gunrock/build/examples/snn && $(CMAKE_COMMAND) -P CMakeFiles/snn_app.dir/cmake_clean_target.cmake
	cd /home/nanir/gunrock/build/examples/snn && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snn_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/snn/CMakeFiles/snn_app.dir/build: lib/libsnn_app.a
.PHONY : examples/snn/CMakeFiles/snn_app.dir/build

examples/snn/CMakeFiles/snn_app.dir/clean:
	cd /home/nanir/gunrock/build/examples/snn && $(CMAKE_COMMAND) -P CMakeFiles/snn_app.dir/cmake_clean.cmake
.PHONY : examples/snn/CMakeFiles/snn_app.dir/clean

examples/snn/CMakeFiles/snn_app.dir/depend: examples/snn/CMakeFiles/snn_app.dir/__/__/gunrock/app/snn/snn_app_generated_snn_app.cu.o
examples/snn/CMakeFiles/snn_app.dir/depend: examples/snn/CMakeFiles/snn_app.dir/snn_app_intermediate_link.o
	cd /home/nanir/gunrock/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nanir/gunrock /home/nanir/gunrock/examples/snn /home/nanir/gunrock/build /home/nanir/gunrock/build/examples/snn /home/nanir/gunrock/build/examples/snn/CMakeFiles/snn_app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/snn/CMakeFiles/snn_app.dir/depend
