# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists/build

# Include any dependencies generated for this target.
include CMakeFiles/test_deque.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_deque.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_deque.dir/flags.make

CMakeFiles/test_deque.dir/src/test_deque.cpp.o: CMakeFiles/test_deque.dir/flags.make
CMakeFiles/test_deque.dir/src/test_deque.cpp.o: ../src/test_deque.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_deque.dir/src/test_deque.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_deque.dir/src/test_deque.cpp.o -c /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists/src/test_deque.cpp

CMakeFiles/test_deque.dir/src/test_deque.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_deque.dir/src/test_deque.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists/src/test_deque.cpp > CMakeFiles/test_deque.dir/src/test_deque.cpp.i

CMakeFiles/test_deque.dir/src/test_deque.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_deque.dir/src/test_deque.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists/src/test_deque.cpp -o CMakeFiles/test_deque.dir/src/test_deque.cpp.s

# Object files for target test_deque
test_deque_OBJECTS = \
"CMakeFiles/test_deque.dir/src/test_deque.cpp.o"

# External object files for target test_deque
test_deque_EXTERNAL_OBJECTS =

test_deque: CMakeFiles/test_deque.dir/src/test_deque.cpp.o
test_deque: CMakeFiles/test_deque.dir/build.make
test_deque: CMakeFiles/test_deque.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_deque"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_deque.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_deque.dir/build: test_deque

.PHONY : CMakeFiles/test_deque.dir/build

CMakeFiles/test_deque.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_deque.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_deque.dir/clean

CMakeFiles/test_deque.dir/depend:
	cd /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists/build /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists/build /home/roy/programming/DataStructure_Algorithm/DataStructure/MySTL/arrayBasedLists/build/CMakeFiles/test_deque.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_deque.dir/depend

