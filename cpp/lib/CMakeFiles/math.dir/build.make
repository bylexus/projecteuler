# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /src

# Include any dependencies generated for this target.
include lib/CMakeFiles/math.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/math.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/math.dir/flags.make

lib/CMakeFiles/math.dir/math.cpp.o: lib/CMakeFiles/math.dir/flags.make
lib/CMakeFiles/math.dir/math.cpp.o: lib/math.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/math.dir/math.cpp.o"
	cd /src/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/math.dir/math.cpp.o -c /src/lib/math.cpp

lib/CMakeFiles/math.dir/math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/math.cpp.i"
	cd /src/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /src/lib/math.cpp > CMakeFiles/math.dir/math.cpp.i

lib/CMakeFiles/math.dir/math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/math.cpp.s"
	cd /src/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /src/lib/math.cpp -o CMakeFiles/math.dir/math.cpp.s

lib/CMakeFiles/math.dir/math.cpp.o.requires:

.PHONY : lib/CMakeFiles/math.dir/math.cpp.o.requires

lib/CMakeFiles/math.dir/math.cpp.o.provides: lib/CMakeFiles/math.dir/math.cpp.o.requires
	$(MAKE) -f lib/CMakeFiles/math.dir/build.make lib/CMakeFiles/math.dir/math.cpp.o.provides.build
.PHONY : lib/CMakeFiles/math.dir/math.cpp.o.provides

lib/CMakeFiles/math.dir/math.cpp.o.provides.build: lib/CMakeFiles/math.dir/math.cpp.o


# Object files for target math
math_OBJECTS = \
"CMakeFiles/math.dir/math.cpp.o"

# External object files for target math
math_EXTERNAL_OBJECTS =

lib/libmath.a: lib/CMakeFiles/math.dir/math.cpp.o
lib/libmath.a: lib/CMakeFiles/math.dir/build.make
lib/libmath.a: lib/CMakeFiles/math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmath.a"
	cd /src/lib && $(CMAKE_COMMAND) -P CMakeFiles/math.dir/cmake_clean_target.cmake
	cd /src/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/math.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/math.dir/build: lib/libmath.a

.PHONY : lib/CMakeFiles/math.dir/build

lib/CMakeFiles/math.dir/requires: lib/CMakeFiles/math.dir/math.cpp.o.requires

.PHONY : lib/CMakeFiles/math.dir/requires

lib/CMakeFiles/math.dir/clean:
	cd /src/lib && $(CMAKE_COMMAND) -P CMakeFiles/math.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/math.dir/clean

lib/CMakeFiles/math.dir/depend:
	cd /src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /src /src/lib /src /src/lib /src/lib/CMakeFiles/math.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/math.dir/depend

