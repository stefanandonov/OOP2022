# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = "/Users/stefanandonov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/stefanandonov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stefanandonov/CLionProjects/OOP2022

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ski.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ski.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ski.dir/flags.make

CMakeFiles/ski.dir/EN/ex2/ski.c.o: CMakeFiles/ski.dir/flags.make
CMakeFiles/ski.dir/EN/ex2/ski.c.o: ../EN/ex2/ski.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ski.dir/EN/ex2/ski.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ski.dir/EN/ex2/ski.c.o   -c /Users/stefanandonov/CLionProjects/OOP2022/EN/ex2/ski.c

CMakeFiles/ski.dir/EN/ex2/ski.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ski.dir/EN/ex2/ski.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/stefanandonov/CLionProjects/OOP2022/EN/ex2/ski.c > CMakeFiles/ski.dir/EN/ex2/ski.c.i

CMakeFiles/ski.dir/EN/ex2/ski.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ski.dir/EN/ex2/ski.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/stefanandonov/CLionProjects/OOP2022/EN/ex2/ski.c -o CMakeFiles/ski.dir/EN/ex2/ski.c.s

# Object files for target ski
ski_OBJECTS = \
"CMakeFiles/ski.dir/EN/ex2/ski.c.o"

# External object files for target ski
ski_EXTERNAL_OBJECTS =

ski: CMakeFiles/ski.dir/EN/ex2/ski.c.o
ski: CMakeFiles/ski.dir/build.make
ski: CMakeFiles/ski.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ski"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ski.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ski.dir/build: ski

.PHONY : CMakeFiles/ski.dir/build

CMakeFiles/ski.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ski.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ski.dir/clean

CMakeFiles/ski.dir/depend:
	cd /Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stefanandonov/CLionProjects/OOP2022 /Users/stefanandonov/CLionProjects/OOP2022 /Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug /Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug /Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles/ski.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ski.dir/depend

