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
include _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/flags.make

_deps/rapidjson-build/example/CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.o: _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/flags.make
_deps/rapidjson-build/example/CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.o: ../externals/rapidjson/example/capitalize/capitalize.cpp
_deps/rapidjson-build/example/CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.o: _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nanir/gunrock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.o"
	cd /home/nanir/gunrock/build/_deps/rapidjson-build/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.o -MF CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.o.d -o CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.o -c /home/nanir/gunrock/externals/rapidjson/example/capitalize/capitalize.cpp

_deps/rapidjson-build/example/CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.i"
	cd /home/nanir/gunrock/build/_deps/rapidjson-build/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nanir/gunrock/externals/rapidjson/example/capitalize/capitalize.cpp > CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.i

_deps/rapidjson-build/example/CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.s"
	cd /home/nanir/gunrock/build/_deps/rapidjson-build/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nanir/gunrock/externals/rapidjson/example/capitalize/capitalize.cpp -o CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.s

# Object files for target capitalize
capitalize_OBJECTS = \
"CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.o"

# External object files for target capitalize
capitalize_EXTERNAL_OBJECTS =

bin/capitalize: _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/capitalize/capitalize.cpp.o
bin/capitalize: _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/build.make
bin/capitalize: _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nanir/gunrock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/capitalize"
	cd /home/nanir/gunrock/build/_deps/rapidjson-build/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/capitalize.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/rapidjson-build/example/CMakeFiles/capitalize.dir/build: bin/capitalize
.PHONY : _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/build

_deps/rapidjson-build/example/CMakeFiles/capitalize.dir/clean:
	cd /home/nanir/gunrock/build/_deps/rapidjson-build/example && $(CMAKE_COMMAND) -P CMakeFiles/capitalize.dir/cmake_clean.cmake
.PHONY : _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/clean

_deps/rapidjson-build/example/CMakeFiles/capitalize.dir/depend:
	cd /home/nanir/gunrock/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nanir/gunrock /home/nanir/gunrock/externals/rapidjson/example /home/nanir/gunrock/build /home/nanir/gunrock/build/_deps/rapidjson-build/example /home/nanir/gunrock/build/_deps/rapidjson-build/example/CMakeFiles/capitalize.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/rapidjson-build/example/CMakeFiles/capitalize.dir/depend

