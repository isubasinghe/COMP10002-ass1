# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/isitha/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3968.17/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/isitha/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3968.17/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/isitha/Projects/UoM/COMP10002/ass1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/isitha/Projects/UoM/COMP10002/ass1

# Include any dependencies generated for this target.
include CMakeFiles/ass1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ass1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ass1.dir/flags.make

CMakeFiles/ass1.dir/main.c.o: CMakeFiles/ass1.dir/flags.make
CMakeFiles/ass1.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/isitha/Projects/UoM/COMP10002/ass1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ass1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ass1.dir/main.c.o   -c /home/isitha/Projects/UoM/COMP10002/ass1/main.c

CMakeFiles/ass1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ass1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/isitha/Projects/UoM/COMP10002/ass1/main.c > CMakeFiles/ass1.dir/main.c.i

CMakeFiles/ass1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ass1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/isitha/Projects/UoM/COMP10002/ass1/main.c -o CMakeFiles/ass1.dir/main.c.s

CMakeFiles/ass1.dir/main.c.o.requires:

.PHONY : CMakeFiles/ass1.dir/main.c.o.requires

CMakeFiles/ass1.dir/main.c.o.provides: CMakeFiles/ass1.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/ass1.dir/build.make CMakeFiles/ass1.dir/main.c.o.provides.build
.PHONY : CMakeFiles/ass1.dir/main.c.o.provides

CMakeFiles/ass1.dir/main.c.o.provides.build: CMakeFiles/ass1.dir/main.c.o


# Object files for target ass1
ass1_OBJECTS = \
"CMakeFiles/ass1.dir/main.c.o"

# External object files for target ass1
ass1_EXTERNAL_OBJECTS =

ass1: CMakeFiles/ass1.dir/main.c.o
ass1: CMakeFiles/ass1.dir/build.make
ass1: CMakeFiles/ass1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/isitha/Projects/UoM/COMP10002/ass1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ass1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ass1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ass1.dir/build: ass1

.PHONY : CMakeFiles/ass1.dir/build

CMakeFiles/ass1.dir/requires: CMakeFiles/ass1.dir/main.c.o.requires

.PHONY : CMakeFiles/ass1.dir/requires

CMakeFiles/ass1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ass1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ass1.dir/clean

CMakeFiles/ass1.dir/depend:
	cd /home/isitha/Projects/UoM/COMP10002/ass1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/isitha/Projects/UoM/COMP10002/ass1 /home/isitha/Projects/UoM/COMP10002/ass1 /home/isitha/Projects/UoM/COMP10002/ass1 /home/isitha/Projects/UoM/COMP10002/ass1 /home/isitha/Projects/UoM/COMP10002/ass1/CMakeFiles/ass1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ass1.dir/depend

