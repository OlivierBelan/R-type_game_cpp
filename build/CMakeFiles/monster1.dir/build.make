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
CMAKE_SOURCE_DIR = /home/takoo/on/CPP_rtype_2019

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/takoo/on/CPP_rtype_2019/build

# Include any dependencies generated for this target.
include CMakeFiles/monster1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/monster1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/monster1.dir/flags.make

CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o: CMakeFiles/monster1.dir/flags.make
CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o: ../lib/src/Monster1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/takoo/on/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o -c /home/takoo/on/CPP_rtype_2019/lib/src/Monster1.cpp

CMakeFiles/monster1.dir/lib/src/Monster1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/monster1.dir/lib/src/Monster1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/takoo/on/CPP_rtype_2019/lib/src/Monster1.cpp > CMakeFiles/monster1.dir/lib/src/Monster1.cpp.i

CMakeFiles/monster1.dir/lib/src/Monster1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/monster1.dir/lib/src/Monster1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/takoo/on/CPP_rtype_2019/lib/src/Monster1.cpp -o CMakeFiles/monster1.dir/lib/src/Monster1.cpp.s

CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o.requires:

.PHONY : CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o.requires

CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o.provides: CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o.requires
	$(MAKE) -f CMakeFiles/monster1.dir/build.make CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o.provides.build
.PHONY : CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o.provides

CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o.provides.build: CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o


CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o: CMakeFiles/monster1.dir/flags.make
CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o: ../ECS/src/Manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/takoo/on/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o -c /home/takoo/on/CPP_rtype_2019/ECS/src/Manager.cpp

CMakeFiles/monster1.dir/ECS/src/Manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/monster1.dir/ECS/src/Manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/takoo/on/CPP_rtype_2019/ECS/src/Manager.cpp > CMakeFiles/monster1.dir/ECS/src/Manager.cpp.i

CMakeFiles/monster1.dir/ECS/src/Manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/monster1.dir/ECS/src/Manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/takoo/on/CPP_rtype_2019/ECS/src/Manager.cpp -o CMakeFiles/monster1.dir/ECS/src/Manager.cpp.s

CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o.requires:

.PHONY : CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o.requires

CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o.provides: CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o.requires
	$(MAKE) -f CMakeFiles/monster1.dir/build.make CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o.provides.build
.PHONY : CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o.provides

CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o.provides.build: CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o


CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o: CMakeFiles/monster1.dir/flags.make
CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o: ../ECS/src/ComponentManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/takoo/on/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o -c /home/takoo/on/CPP_rtype_2019/ECS/src/ComponentManager.cpp

CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/takoo/on/CPP_rtype_2019/ECS/src/ComponentManager.cpp > CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.i

CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/takoo/on/CPP_rtype_2019/ECS/src/ComponentManager.cpp -o CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.s

CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o.requires:

.PHONY : CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o.requires

CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o.provides: CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/monster1.dir/build.make CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o.provides.build
.PHONY : CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o.provides

CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o.provides.build: CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o


# Object files for target monster1
monster1_OBJECTS = \
"CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o" \
"CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o" \
"CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o"

# External object files for target monster1
monster1_EXTERNAL_OBJECTS =

lib/libmonster1.so: CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o
lib/libmonster1.so: CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o
lib/libmonster1.so: CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o
lib/libmonster1.so: CMakeFiles/monster1.dir/build.make
lib/libmonster1.so: CMakeFiles/monster1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/takoo/on/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library lib/libmonster1.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/monster1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/monster1.dir/build: lib/libmonster1.so

.PHONY : CMakeFiles/monster1.dir/build

CMakeFiles/monster1.dir/requires: CMakeFiles/monster1.dir/lib/src/Monster1.cpp.o.requires
CMakeFiles/monster1.dir/requires: CMakeFiles/monster1.dir/ECS/src/Manager.cpp.o.requires
CMakeFiles/monster1.dir/requires: CMakeFiles/monster1.dir/ECS/src/ComponentManager.cpp.o.requires

.PHONY : CMakeFiles/monster1.dir/requires

CMakeFiles/monster1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/monster1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/monster1.dir/clean

CMakeFiles/monster1.dir/depend:
	cd /home/takoo/on/CPP_rtype_2019/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/takoo/on/CPP_rtype_2019 /home/takoo/on/CPP_rtype_2019 /home/takoo/on/CPP_rtype_2019/build /home/takoo/on/CPP_rtype_2019/build /home/takoo/on/CPP_rtype_2019/build/CMakeFiles/monster1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/monster1.dir/depend
