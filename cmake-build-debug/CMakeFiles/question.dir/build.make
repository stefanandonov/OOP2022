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
include CMakeFiles/question.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/question.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/question.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/question.dir/flags.make

CMakeFiles/question.dir/EN/ex1/question.c.o: CMakeFiles/question.dir/flags.make
CMakeFiles/question.dir/EN/ex1/question.c.o: ../EN/ex1/question.c
CMakeFiles/question.dir/EN/ex1/question.c.o: CMakeFiles/question.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/question.dir/EN/ex1/question.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/question.dir/EN/ex1/question.c.o -MF CMakeFiles/question.dir/EN/ex1/question.c.o.d -o CMakeFiles/question.dir/EN/ex1/question.c.o -c /Users/stefan.a/CLionProjects/OOP2022/EN/ex1/question.c

CMakeFiles/question.dir/EN/ex1/question.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/question.dir/EN/ex1/question.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/stefan.a/CLionProjects/OOP2022/EN/ex1/question.c > CMakeFiles/question.dir/EN/ex1/question.c.i

CMakeFiles/question.dir/EN/ex1/question.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/question.dir/EN/ex1/question.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/stefan.a/CLionProjects/OOP2022/EN/ex1/question.c -o CMakeFiles/question.dir/EN/ex1/question.c.s

# Object files for target question
question_OBJECTS = \
"CMakeFiles/question.dir/EN/ex1/question.c.o"

# External object files for target question
question_EXTERNAL_OBJECTS =

question: CMakeFiles/question.dir/EN/ex1/question.c.o
question: CMakeFiles/question.dir/build.make
question: CMakeFiles/question.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable question"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/question.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/question.dir/build: question
.PHONY : CMakeFiles/question.dir/build

CMakeFiles/question.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/question.dir/cmake_clean.cmake
.PHONY : CMakeFiles/question.dir/clean

CMakeFiles/question.dir/depend:
	cd /Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stefan.a/CLionProjects/OOP2022 /Users/stefan.a/CLionProjects/OOP2022 /Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug /Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug /Users/stefan.a/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles/question.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/question.dir/depend

