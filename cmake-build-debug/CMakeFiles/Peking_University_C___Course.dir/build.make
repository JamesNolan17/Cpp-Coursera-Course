# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "/Users/home/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/211.7442.42/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/home/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/211.7442.42/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/home/Documents/CLion/Peking University C++ Course"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/home/Documents/CLion/Peking University C++ Course/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Peking_University_C___Course.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Peking_University_C___Course.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Peking_University_C___Course.dir/flags.make

CMakeFiles/Peking_University_C___Course.dir/main.cpp.o: CMakeFiles/Peking_University_C___Course.dir/flags.make
CMakeFiles/Peking_University_C___Course.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/home/Documents/CLion/Peking University C++ Course/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Peking_University_C___Course.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Peking_University_C___Course.dir/main.cpp.o -c "/Users/home/Documents/CLion/Peking University C++ Course/main.cpp"

CMakeFiles/Peking_University_C___Course.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Peking_University_C___Course.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/home/Documents/CLion/Peking University C++ Course/main.cpp" > CMakeFiles/Peking_University_C___Course.dir/main.cpp.i

CMakeFiles/Peking_University_C___Course.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Peking_University_C___Course.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/home/Documents/CLion/Peking University C++ Course/main.cpp" -o CMakeFiles/Peking_University_C___Course.dir/main.cpp.s

# Object files for target Peking_University_C___Course
Peking_University_C___Course_OBJECTS = \
"CMakeFiles/Peking_University_C___Course.dir/main.cpp.o"

# External object files for target Peking_University_C___Course
Peking_University_C___Course_EXTERNAL_OBJECTS =

Peking_University_C___Course: CMakeFiles/Peking_University_C___Course.dir/main.cpp.o
Peking_University_C___Course: CMakeFiles/Peking_University_C___Course.dir/build.make
Peking_University_C___Course: CMakeFiles/Peking_University_C___Course.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/home/Documents/CLion/Peking University C++ Course/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Peking_University_C___Course"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Peking_University_C___Course.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Peking_University_C___Course.dir/build: Peking_University_C___Course

.PHONY : CMakeFiles/Peking_University_C___Course.dir/build

CMakeFiles/Peking_University_C___Course.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Peking_University_C___Course.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Peking_University_C___Course.dir/clean

CMakeFiles/Peking_University_C___Course.dir/depend:
	cd "/Users/home/Documents/CLion/Peking University C++ Course/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/home/Documents/CLion/Peking University C++ Course" "/Users/home/Documents/CLion/Peking University C++ Course" "/Users/home/Documents/CLion/Peking University C++ Course/cmake-build-debug" "/Users/home/Documents/CLion/Peking University C++ Course/cmake-build-debug" "/Users/home/Documents/CLion/Peking University C++ Course/cmake-build-debug/CMakeFiles/Peking_University_C___Course.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Peking_University_C___Course.dir/depend

