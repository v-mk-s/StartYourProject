# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/sklaa00/main_course/first/StartYourProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sklaa00/main_course/first/StartYourProject/build

# Include any dependencies generated for this target.
include client/CMakeFiles/client_syp.dir/depend.make

# Include the progress variables for this target.
include client/CMakeFiles/client_syp.dir/progress.make

# Include the compile flags for this target's objects.
include client/CMakeFiles/client_syp.dir/flags.make

client/CMakeFiles/client_syp.dir/basic/validation.cpp.o: client/CMakeFiles/client_syp.dir/flags.make
client/CMakeFiles/client_syp.dir/basic/validation.cpp.o: ../client/basic/validation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sklaa00/main_course/first/StartYourProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object client/CMakeFiles/client_syp.dir/basic/validation.cpp.o"
	cd /home/sklaa00/main_course/first/StartYourProject/build/client && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client_syp.dir/basic/validation.cpp.o -c /home/sklaa00/main_course/first/StartYourProject/client/basic/validation.cpp

client/CMakeFiles/client_syp.dir/basic/validation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client_syp.dir/basic/validation.cpp.i"
	cd /home/sklaa00/main_course/first/StartYourProject/build/client && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sklaa00/main_course/first/StartYourProject/client/basic/validation.cpp > CMakeFiles/client_syp.dir/basic/validation.cpp.i

client/CMakeFiles/client_syp.dir/basic/validation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client_syp.dir/basic/validation.cpp.s"
	cd /home/sklaa00/main_course/first/StartYourProject/build/client && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sklaa00/main_course/first/StartYourProject/client/basic/validation.cpp -o CMakeFiles/client_syp.dir/basic/validation.cpp.s

# Object files for target client_syp
client_syp_OBJECTS = \
"CMakeFiles/client_syp.dir/basic/validation.cpp.o"

# External object files for target client_syp
client_syp_EXTERNAL_OBJECTS =

client/libclient_syp.a: client/CMakeFiles/client_syp.dir/basic/validation.cpp.o
client/libclient_syp.a: client/CMakeFiles/client_syp.dir/build.make
client/libclient_syp.a: client/CMakeFiles/client_syp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sklaa00/main_course/first/StartYourProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libclient_syp.a"
	cd /home/sklaa00/main_course/first/StartYourProject/build/client && $(CMAKE_COMMAND) -P CMakeFiles/client_syp.dir/cmake_clean_target.cmake
	cd /home/sklaa00/main_course/first/StartYourProject/build/client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client_syp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
client/CMakeFiles/client_syp.dir/build: client/libclient_syp.a

.PHONY : client/CMakeFiles/client_syp.dir/build

client/CMakeFiles/client_syp.dir/clean:
	cd /home/sklaa00/main_course/first/StartYourProject/build/client && $(CMAKE_COMMAND) -P CMakeFiles/client_syp.dir/cmake_clean.cmake
.PHONY : client/CMakeFiles/client_syp.dir/clean

client/CMakeFiles/client_syp.dir/depend:
	cd /home/sklaa00/main_course/first/StartYourProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sklaa00/main_course/first/StartYourProject /home/sklaa00/main_course/first/StartYourProject/client /home/sklaa00/main_course/first/StartYourProject/build /home/sklaa00/main_course/first/StartYourProject/build/client /home/sklaa00/main_course/first/StartYourProject/build/client/CMakeFiles/client_syp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : client/CMakeFiles/client_syp.dir/depend

