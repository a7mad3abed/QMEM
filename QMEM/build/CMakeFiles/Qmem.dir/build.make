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
CMAKE_SOURCE_DIR = /home/ibrahiah/QMEM/QMEM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ibrahiah/QMEM/QMEM/build

# Include any dependencies generated for this target.
include CMakeFiles/Qmem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Qmem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Qmem.dir/flags.make

CMakeFiles/Qmem.dir/main.cpp.o: CMakeFiles/Qmem.dir/flags.make
CMakeFiles/Qmem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ibrahiah/QMEM/QMEM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Qmem.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Qmem.dir/main.cpp.o -c /home/ibrahiah/QMEM/QMEM/main.cpp

CMakeFiles/Qmem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Qmem.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ibrahiah/QMEM/QMEM/main.cpp > CMakeFiles/Qmem.dir/main.cpp.i

CMakeFiles/Qmem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Qmem.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ibrahiah/QMEM/QMEM/main.cpp -o CMakeFiles/Qmem.dir/main.cpp.s

CMakeFiles/Qmem.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Qmem.dir/main.cpp.o.requires

CMakeFiles/Qmem.dir/main.cpp.o.provides: CMakeFiles/Qmem.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Qmem.dir/build.make CMakeFiles/Qmem.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Qmem.dir/main.cpp.o.provides

CMakeFiles/Qmem.dir/main.cpp.o.provides.build: CMakeFiles/Qmem.dir/main.cpp.o


CMakeFiles/Qmem.dir/MyFrame.cpp.o: CMakeFiles/Qmem.dir/flags.make
CMakeFiles/Qmem.dir/MyFrame.cpp.o: ../MyFrame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ibrahiah/QMEM/QMEM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Qmem.dir/MyFrame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Qmem.dir/MyFrame.cpp.o -c /home/ibrahiah/QMEM/QMEM/MyFrame.cpp

CMakeFiles/Qmem.dir/MyFrame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Qmem.dir/MyFrame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ibrahiah/QMEM/QMEM/MyFrame.cpp > CMakeFiles/Qmem.dir/MyFrame.cpp.i

CMakeFiles/Qmem.dir/MyFrame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Qmem.dir/MyFrame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ibrahiah/QMEM/QMEM/MyFrame.cpp -o CMakeFiles/Qmem.dir/MyFrame.cpp.s

CMakeFiles/Qmem.dir/MyFrame.cpp.o.requires:

.PHONY : CMakeFiles/Qmem.dir/MyFrame.cpp.o.requires

CMakeFiles/Qmem.dir/MyFrame.cpp.o.provides: CMakeFiles/Qmem.dir/MyFrame.cpp.o.requires
	$(MAKE) -f CMakeFiles/Qmem.dir/build.make CMakeFiles/Qmem.dir/MyFrame.cpp.o.provides.build
.PHONY : CMakeFiles/Qmem.dir/MyFrame.cpp.o.provides

CMakeFiles/Qmem.dir/MyFrame.cpp.o.provides.build: CMakeFiles/Qmem.dir/MyFrame.cpp.o


# Object files for target Qmem
Qmem_OBJECTS = \
"CMakeFiles/Qmem.dir/main.cpp.o" \
"CMakeFiles/Qmem.dir/MyFrame.cpp.o"

# External object files for target Qmem
Qmem_EXTERNAL_OBJECTS =

Qmem: CMakeFiles/Qmem.dir/main.cpp.o
Qmem: CMakeFiles/Qmem.dir/MyFrame.cpp.o
Qmem: CMakeFiles/Qmem.dir/build.make
Qmem: CMakeFiles/Qmem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ibrahiah/QMEM/QMEM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Qmem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Qmem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Qmem.dir/build: Qmem

.PHONY : CMakeFiles/Qmem.dir/build

CMakeFiles/Qmem.dir/requires: CMakeFiles/Qmem.dir/main.cpp.o.requires
CMakeFiles/Qmem.dir/requires: CMakeFiles/Qmem.dir/MyFrame.cpp.o.requires

.PHONY : CMakeFiles/Qmem.dir/requires

CMakeFiles/Qmem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Qmem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Qmem.dir/clean

CMakeFiles/Qmem.dir/depend:
	cd /home/ibrahiah/QMEM/QMEM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ibrahiah/QMEM/QMEM /home/ibrahiah/QMEM/QMEM /home/ibrahiah/QMEM/QMEM/build /home/ibrahiah/QMEM/QMEM/build /home/ibrahiah/QMEM/QMEM/build/CMakeFiles/Qmem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Qmem.dir/depend

