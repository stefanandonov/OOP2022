# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stefan.a/CLionProjects/OOP2022

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/intro_to_cpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/intro_to_cpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/intro_to_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/intro_to_cpp.dir/flags.make

CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.o: CMakeFiles/intro_to_cpp.dir/flags.make
CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.o: ../EN/ex2/intro_to_cpp.cpp
CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.o: CMakeFiles/intro_to_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.o -MF CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.o.d -o CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.o -c /Users/stefan.a/CLionProjects/OOP2022/EN/ex2/intro_to_cpp.cpp

CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stefan.a/CLionProjects/OOP2022/EN/ex2/intro_to_cpp.cpp > CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.i

CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stefan.a/CLionProjects/OOP2022/EN/ex2/intro_to_cpp.cpp -o CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.s

# Object files for target intro_to_cpp
intro_to_cpp_OBJECTS = \
"CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.o"

# External object files for target intro_to_cpp
intro_to_cpp_EXTERNAL_OBJECTS =

intro_to_cpp: CMakeFiles/intro_to_cpp.dir/EN/ex2/intro_to_cpp.cpp.o
intro_to_cpp: CMakeFiles/intro_to_cpp.dir/build.make
intro_to_cpp: CMakeFiles/intro_to_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable intro_to_cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/intro_to_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/intro_to_cpp.dir/build: intro_to_cpp
.PHONY : CMakeFiles/intro_to_cpp.dir/build

CMakeFiles/intro_to_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/intro_to_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/intro_to_cpp.dir/clean

CMakeFiles/intro_to_cpp.dir/depend:
	cd /Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stefan.a/CLionProjects/OOP2022 /Users/stefan.a/CLionProjects/OOP2022 /Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug /Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug /Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles/intro_to_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/intro_to_cpp.dir/depend

