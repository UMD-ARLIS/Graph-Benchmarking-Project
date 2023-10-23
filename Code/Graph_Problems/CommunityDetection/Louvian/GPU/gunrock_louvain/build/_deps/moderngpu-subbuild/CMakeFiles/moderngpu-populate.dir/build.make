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
CMAKE_SOURCE_DIR = /home/nanir/gunrock/build/_deps/moderngpu-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nanir/gunrock/build/_deps/moderngpu-subbuild

# Utility rule file for moderngpu-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/moderngpu-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/moderngpu-populate.dir/progress.make

CMakeFiles/moderngpu-populate: CMakeFiles/moderngpu-populate-complete

CMakeFiles/moderngpu-populate-complete: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-install
CMakeFiles/moderngpu-populate-complete: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-mkdir
CMakeFiles/moderngpu-populate-complete: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-download
CMakeFiles/moderngpu-populate-complete: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-update
CMakeFiles/moderngpu-populate-complete: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-patch
CMakeFiles/moderngpu-populate-complete: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-configure
CMakeFiles/moderngpu-populate-complete: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-build
CMakeFiles/moderngpu-populate-complete: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-install
CMakeFiles/moderngpu-populate-complete: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'moderngpu-populate'"
	/usr/bin/cmake -E make_directory /home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles
	/usr/bin/cmake -E touch /home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles/moderngpu-populate-complete
	/usr/bin/cmake -E touch /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-done

moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-update:
.PHONY : moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-update

moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-build: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'moderngpu-populate'"
	cd /home/nanir/gunrock/build/_deps/moderngpu-build && /usr/bin/cmake -E echo_append
	cd /home/nanir/gunrock/build/_deps/moderngpu-build && /usr/bin/cmake -E touch /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-build

moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-configure: moderngpu-populate-prefix/tmp/moderngpu-populate-cfgcmd.txt
moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-configure: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'moderngpu-populate'"
	cd /home/nanir/gunrock/build/_deps/moderngpu-build && /usr/bin/cmake -E echo_append
	cd /home/nanir/gunrock/build/_deps/moderngpu-build && /usr/bin/cmake -E touch /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-configure

moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-download: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-gitinfo.txt
moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-download: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'moderngpu-populate'"
	cd /home/nanir/gunrock/externals && /usr/bin/cmake -P /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/tmp/moderngpu-populate-gitclone.cmake
	cd /home/nanir/gunrock/externals && /usr/bin/cmake -E touch /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-download

moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-install: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'moderngpu-populate'"
	cd /home/nanir/gunrock/build/_deps/moderngpu-build && /usr/bin/cmake -E echo_append
	cd /home/nanir/gunrock/build/_deps/moderngpu-build && /usr/bin/cmake -E touch /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-install

moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'moderngpu-populate'"
	/usr/bin/cmake -E make_directory /home/nanir/gunrock/externals/moderngpu
	/usr/bin/cmake -E make_directory /home/nanir/gunrock/build/_deps/moderngpu-build
	/usr/bin/cmake -E make_directory /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix
	/usr/bin/cmake -E make_directory /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/tmp
	/usr/bin/cmake -E make_directory /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src/moderngpu-populate-stamp
	/usr/bin/cmake -E make_directory /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src
	/usr/bin/cmake -E make_directory /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src/moderngpu-populate-stamp
	/usr/bin/cmake -E touch /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-mkdir

moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-patch: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'moderngpu-populate'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-patch

moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-update:
.PHONY : moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-update

moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-test: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'moderngpu-populate'"
	cd /home/nanir/gunrock/build/_deps/moderngpu-build && /usr/bin/cmake -E echo_append
	cd /home/nanir/gunrock/build/_deps/moderngpu-build && /usr/bin/cmake -E touch /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-test

moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-update: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'moderngpu-populate'"
	cd /home/nanir/gunrock/externals/moderngpu && /usr/bin/cmake -P /home/nanir/gunrock/build/_deps/moderngpu-subbuild/moderngpu-populate-prefix/tmp/moderngpu-populate-gitupdate.cmake

moderngpu-populate: CMakeFiles/moderngpu-populate
moderngpu-populate: CMakeFiles/moderngpu-populate-complete
moderngpu-populate: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-build
moderngpu-populate: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-configure
moderngpu-populate: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-download
moderngpu-populate: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-install
moderngpu-populate: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-mkdir
moderngpu-populate: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-patch
moderngpu-populate: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-test
moderngpu-populate: moderngpu-populate-prefix/src/moderngpu-populate-stamp/moderngpu-populate-update
moderngpu-populate: CMakeFiles/moderngpu-populate.dir/build.make
.PHONY : moderngpu-populate

# Rule to build all files generated by this target.
CMakeFiles/moderngpu-populate.dir/build: moderngpu-populate
.PHONY : CMakeFiles/moderngpu-populate.dir/build

CMakeFiles/moderngpu-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/moderngpu-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/moderngpu-populate.dir/clean

CMakeFiles/moderngpu-populate.dir/depend:
	cd /home/nanir/gunrock/build/_deps/moderngpu-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nanir/gunrock/build/_deps/moderngpu-subbuild /home/nanir/gunrock/build/_deps/moderngpu-subbuild /home/nanir/gunrock/build/_deps/moderngpu-subbuild /home/nanir/gunrock/build/_deps/moderngpu-subbuild /home/nanir/gunrock/build/_deps/moderngpu-subbuild/CMakeFiles/moderngpu-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/moderngpu-populate.dir/depend

