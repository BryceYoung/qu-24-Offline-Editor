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
CMAKE_SOURCE_DIR = /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime

# Include any dependencies generated for this target.
include tests/CMakeFiles/unittest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/unittest.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/unittest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/unittest.dir/flags.make

tests/CMakeFiles/unittest.dir/unittest.cpp.o: tests/CMakeFiles/unittest.dir/flags.make
tests/CMakeFiles/unittest.dir/unittest.cpp.o: tests/unittest.cpp
tests/CMakeFiles/unittest.dir/unittest.cpp.o: tests/CMakeFiles/unittest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/unittest.dir/unittest.cpp.o"
	cd /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/unittest.dir/unittest.cpp.o -MF CMakeFiles/unittest.dir/unittest.cpp.o.d -o CMakeFiles/unittest.dir/unittest.cpp.o -c /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests/unittest.cpp

tests/CMakeFiles/unittest.dir/unittest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest.dir/unittest.cpp.i"
	cd /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests/unittest.cpp > CMakeFiles/unittest.dir/unittest.cpp.i

tests/CMakeFiles/unittest.dir/unittest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest.dir/unittest.cpp.s"
	cd /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests/unittest.cpp -o CMakeFiles/unittest.dir/unittest.cpp.s

# Object files for target unittest
unittest_OBJECTS = \
"CMakeFiles/unittest.dir/unittest.cpp.o"

# External object files for target unittest
unittest_EXTERNAL_OBJECTS =

tests/unittest: tests/CMakeFiles/unittest.dir/unittest.cpp.o
tests/unittest: tests/CMakeFiles/unittest.dir/build.make
tests/unittest: libkaitai_struct_cpp_stl_runtime.so
tests/unittest: /usr/lib/x86_64-linux-gnu/libgtest_main.a
tests/unittest: /usr/lib/x86_64-linux-gnu/libgtest.a
tests/unittest: tests/CMakeFiles/unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unittest"
	cd /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/unittest.dir/build: tests/unittest
.PHONY : tests/CMakeFiles/unittest.dir/build

tests/CMakeFiles/unittest.dir/clean:
	cd /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests && $(CMAKE_COMMAND) -P CMakeFiles/unittest.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/unittest.dir/clean

tests/CMakeFiles/unittest.dir/depend:
	cd /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests /home/bryce/prog/qu-24/kaitai_struct_cpp_stl_runtime/tests/CMakeFiles/unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/unittest.dir/depend

