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
include CMakeFiles/intro_to_references.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/intro_to_references.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/intro_to_references.dir/flags.make

CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.o: CMakeFiles/intro_to_references.dir/flags.make
CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.o: ../MK/av2/intro_to_references.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.o -c /Users/stefanandonov/CLionProjects/OOP2022/MK/av2/intro_to_references.cpp

CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stefanandonov/CLionProjects/OOP2022/MK/av2/intro_to_references.cpp > CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.i

CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stefanandonov/CLionProjects/OOP2022/MK/av2/intro_to_references.cpp -o CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.s

# Object files for target intro_to_references
intro_to_references_OBJECTS = \
"CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.o"

# External object files for target intro_to_references
intro_to_references_EXTERNAL_OBJECTS =

intro_to_references: CMakeFiles/intro_to_references.dir/MK/av2/intro_to_references.cpp.o
intro_to_references: CMakeFiles/intro_to_references.dir/build.make
intro_to_references: CMakeFiles/intro_to_references.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable intro_to_references"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/intro_to_references.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/intro_to_references.dir/build: intro_to_references

.PHONY : CMakeFiles/intro_to_references.dir/build

CMakeFiles/intro_to_references.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/intro_to_references.dir/cmake_clean.cmake
.PHONY : CMakeFiles/intro_to_references.dir/clean

CMakeFiles/intro_to_references.dir/depend:
	cd /Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stefanandonov/CLionProjects/OOP2022 /Users/stefanandonov/CLionProjects/OOP2022 /Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug /Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug /Users/stefanandonov/CLionProjects/OOP2022/cmake-build-debug/CMakeFiles/intro_to_references.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/intro_to_references.dir/depend
