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

# Utility rule file for ContinuousMemCheck.

# Include any custom commands dependencies for this target.
include _deps/rapidjson-build/CMakeFiles/ContinuousMemCheck.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/rapidjson-build/CMakeFiles/ContinuousMemCheck.dir/progress.make

_deps/rapidjson-build/CMakeFiles/ContinuousMemCheck:
	cd /home/nanir/gunrock/build/_deps/rapidjson-build && /usr/bin/ctest -D ContinuousMemCheck

ContinuousMemCheck: _deps/rapidjson-build/CMakeFiles/ContinuousMemCheck
ContinuousMemCheck: _deps/rapidjson-build/CMakeFiles/ContinuousMemCheck.dir/build.make
.PHONY : ContinuousMemCheck

# Rule to build all files generated by this target.
_deps/rapidjson-build/CMakeFiles/ContinuousMemCheck.dir/build: ContinuousMemCheck
.PHONY : _deps/rapidjson-build/CMakeFiles/ContinuousMemCheck.dir/build

_deps/rapidjson-build/CMakeFiles/ContinuousMemCheck.dir/clean:
	cd /home/nanir/gunrock/build/_deps/rapidjson-build && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousMemCheck.dir/cmake_clean.cmake
.PHONY : _deps/rapidjson-build/CMakeFiles/ContinuousMemCheck.dir/clean

_deps/rapidjson-build/CMakeFiles/ContinuousMemCheck.dir/depend:
	cd /home/nanir/gunrock/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nanir/gunrock /home/nanir/gunrock/externals/rapidjson /home/nanir/gunrock/build /home/nanir/gunrock/build/_deps/rapidjson-build /home/nanir/gunrock/build/_deps/rapidjson-build/CMakeFiles/ContinuousMemCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/rapidjson-build/CMakeFiles/ContinuousMemCheck.dir/depend

