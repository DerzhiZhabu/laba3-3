# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/kali/Desktop/laba3-3/C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kali/Desktop/laba3-3/C++/build

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/tests/test_arr.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests/test_arr.cpp.o: /home/kali/Desktop/laba3-3/C++/tests/test_arr.cpp
CMakeFiles/tests.dir/tests/test_arr.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/Desktop/laba3-3/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/tests/test_arr.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/tests/test_arr.cpp.o -MF CMakeFiles/tests.dir/tests/test_arr.cpp.o.d -o CMakeFiles/tests.dir/tests/test_arr.cpp.o -c /home/kali/Desktop/laba3-3/C++/tests/test_arr.cpp

CMakeFiles/tests.dir/tests/test_arr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests/test_arr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Desktop/laba3-3/C++/tests/test_arr.cpp > CMakeFiles/tests.dir/tests/test_arr.cpp.i

CMakeFiles/tests.dir/tests/test_arr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests/test_arr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Desktop/laba3-3/C++/tests/test_arr.cpp -o CMakeFiles/tests.dir/tests/test_arr.cpp.s

CMakeFiles/tests.dir/tests/test_hashtable.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests/test_hashtable.cpp.o: /home/kali/Desktop/laba3-3/C++/tests/test_hashtable.cpp
CMakeFiles/tests.dir/tests/test_hashtable.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/Desktop/laba3-3/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/tests/test_hashtable.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/tests/test_hashtable.cpp.o -MF CMakeFiles/tests.dir/tests/test_hashtable.cpp.o.d -o CMakeFiles/tests.dir/tests/test_hashtable.cpp.o -c /home/kali/Desktop/laba3-3/C++/tests/test_hashtable.cpp

CMakeFiles/tests.dir/tests/test_hashtable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests/test_hashtable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Desktop/laba3-3/C++/tests/test_hashtable.cpp > CMakeFiles/tests.dir/tests/test_hashtable.cpp.i

CMakeFiles/tests.dir/tests/test_hashtable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests/test_hashtable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Desktop/laba3-3/C++/tests/test_hashtable.cpp -o CMakeFiles/tests.dir/tests/test_hashtable.cpp.s

CMakeFiles/tests.dir/tests/test_list.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests/test_list.cpp.o: /home/kali/Desktop/laba3-3/C++/tests/test_list.cpp
CMakeFiles/tests.dir/tests/test_list.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/Desktop/laba3-3/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/tests/test_list.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/tests/test_list.cpp.o -MF CMakeFiles/tests.dir/tests/test_list.cpp.o.d -o CMakeFiles/tests.dir/tests/test_list.cpp.o -c /home/kali/Desktop/laba3-3/C++/tests/test_list.cpp

CMakeFiles/tests.dir/tests/test_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests/test_list.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Desktop/laba3-3/C++/tests/test_list.cpp > CMakeFiles/tests.dir/tests/test_list.cpp.i

CMakeFiles/tests.dir/tests/test_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests/test_list.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Desktop/laba3-3/C++/tests/test_list.cpp -o CMakeFiles/tests.dir/tests/test_list.cpp.s

CMakeFiles/tests.dir/tests/test_queue.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests/test_queue.cpp.o: /home/kali/Desktop/laba3-3/C++/tests/test_queue.cpp
CMakeFiles/tests.dir/tests/test_queue.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/Desktop/laba3-3/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tests.dir/tests/test_queue.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/tests/test_queue.cpp.o -MF CMakeFiles/tests.dir/tests/test_queue.cpp.o.d -o CMakeFiles/tests.dir/tests/test_queue.cpp.o -c /home/kali/Desktop/laba3-3/C++/tests/test_queue.cpp

CMakeFiles/tests.dir/tests/test_queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests/test_queue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Desktop/laba3-3/C++/tests/test_queue.cpp > CMakeFiles/tests.dir/tests/test_queue.cpp.i

CMakeFiles/tests.dir/tests/test_queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests/test_queue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Desktop/laba3-3/C++/tests/test_queue.cpp -o CMakeFiles/tests.dir/tests/test_queue.cpp.s

CMakeFiles/tests.dir/tests/test_stack.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests/test_stack.cpp.o: /home/kali/Desktop/laba3-3/C++/tests/test_stack.cpp
CMakeFiles/tests.dir/tests/test_stack.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/Desktop/laba3-3/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tests.dir/tests/test_stack.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/tests/test_stack.cpp.o -MF CMakeFiles/tests.dir/tests/test_stack.cpp.o.d -o CMakeFiles/tests.dir/tests/test_stack.cpp.o -c /home/kali/Desktop/laba3-3/C++/tests/test_stack.cpp

CMakeFiles/tests.dir/tests/test_stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests/test_stack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Desktop/laba3-3/C++/tests/test_stack.cpp > CMakeFiles/tests.dir/tests/test_stack.cpp.i

CMakeFiles/tests.dir/tests/test_stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests/test_stack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Desktop/laba3-3/C++/tests/test_stack.cpp -o CMakeFiles/tests.dir/tests/test_stack.cpp.s

CMakeFiles/tests.dir/tests/test_tree.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests/test_tree.cpp.o: /home/kali/Desktop/laba3-3/C++/tests/test_tree.cpp
CMakeFiles/tests.dir/tests/test_tree.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/Desktop/laba3-3/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tests.dir/tests/test_tree.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/tests/test_tree.cpp.o -MF CMakeFiles/tests.dir/tests/test_tree.cpp.o.d -o CMakeFiles/tests.dir/tests/test_tree.cpp.o -c /home/kali/Desktop/laba3-3/C++/tests/test_tree.cpp

CMakeFiles/tests.dir/tests/test_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests/test_tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Desktop/laba3-3/C++/tests/test_tree.cpp > CMakeFiles/tests.dir/tests/test_tree.cpp.i

CMakeFiles/tests.dir/tests/test_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests/test_tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Desktop/laba3-3/C++/tests/test_tree.cpp -o CMakeFiles/tests.dir/tests/test_tree.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/tests/test_arr.cpp.o" \
"CMakeFiles/tests.dir/tests/test_hashtable.cpp.o" \
"CMakeFiles/tests.dir/tests/test_list.cpp.o" \
"CMakeFiles/tests.dir/tests/test_queue.cpp.o" \
"CMakeFiles/tests.dir/tests/test_stack.cpp.o" \
"CMakeFiles/tests.dir/tests/test_tree.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/tests/test_arr.cpp.o
tests: CMakeFiles/tests.dir/tests/test_hashtable.cpp.o
tests: CMakeFiles/tests.dir/tests/test_list.cpp.o
tests: CMakeFiles/tests.dir/tests/test_queue.cpp.o
tests: CMakeFiles/tests.dir/tests/test_stack.cpp.o
tests: CMakeFiles/tests.dir/tests/test_tree.cpp.o
tests: CMakeFiles/tests.dir/build.make
tests: /usr/lib/x86_64-linux-gnu/libgtest_main.a
tests: /usr/lib/x86_64-linux-gnu/libgtest.a
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kali/Desktop/laba3-3/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd /home/kali/Desktop/laba3-3/C++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kali/Desktop/laba3-3/C++ /home/kali/Desktop/laba3-3/C++ /home/kali/Desktop/laba3-3/C++/build /home/kali/Desktop/laba3-3/C++/build /home/kali/Desktop/laba3-3/C++/build/CMakeFiles/tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tests.dir/depend

