# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/projects

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build

# Include any dependencies generated for this target.
include strategyapp/CMakeFiles/strategyapp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include strategyapp/CMakeFiles/strategyapp.dir/compiler_depend.make

# Include the progress variables for this target.
include strategyapp/CMakeFiles/strategyapp.dir/progress.make

# Include the compile flags for this target's objects.
include strategyapp/CMakeFiles/strategyapp.dir/flags.make

strategyapp/CMakeFiles/strategyapp.dir/main.cpp.o: strategyapp/CMakeFiles/strategyapp.dir/flags.make
strategyapp/CMakeFiles/strategyapp.dir/main.cpp.o: /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/projects/strategyapp/main.cpp
strategyapp/CMakeFiles/strategyapp.dir/main.cpp.o: strategyapp/CMakeFiles/strategyapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object strategyapp/CMakeFiles/strategyapp.dir/main.cpp.o"
	cd /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build/strategyapp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT strategyapp/CMakeFiles/strategyapp.dir/main.cpp.o -MF CMakeFiles/strategyapp.dir/main.cpp.o.d -o CMakeFiles/strategyapp.dir/main.cpp.o -c /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/projects/strategyapp/main.cpp

strategyapp/CMakeFiles/strategyapp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/strategyapp.dir/main.cpp.i"
	cd /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build/strategyapp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/projects/strategyapp/main.cpp > CMakeFiles/strategyapp.dir/main.cpp.i

strategyapp/CMakeFiles/strategyapp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/strategyapp.dir/main.cpp.s"
	cd /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build/strategyapp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/projects/strategyapp/main.cpp -o CMakeFiles/strategyapp.dir/main.cpp.s

# Object files for target strategyapp
strategyapp_OBJECTS = \
"CMakeFiles/strategyapp.dir/main.cpp.o"

# External object files for target strategyapp
strategyapp_EXTERNAL_OBJECTS =

strategyapp/strategyapp: strategyapp/CMakeFiles/strategyapp.dir/main.cpp.o
strategyapp/strategyapp: strategyapp/CMakeFiles/strategyapp.dir/build.make
strategyapp/strategyapp: strategy/src/libstrategy.a
strategyapp/strategyapp: common/src/libcommon.a
strategyapp/strategyapp: strategyapp/CMakeFiles/strategyapp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable strategyapp"
	cd /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build/strategyapp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/strategyapp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
strategyapp/CMakeFiles/strategyapp.dir/build: strategyapp/strategyapp
.PHONY : strategyapp/CMakeFiles/strategyapp.dir/build

strategyapp/CMakeFiles/strategyapp.dir/clean:
	cd /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build/strategyapp && $(CMAKE_COMMAND) -P CMakeFiles/strategyapp.dir/cmake_clean.cmake
.PHONY : strategyapp/CMakeFiles/strategyapp.dir/clean

strategyapp/CMakeFiles/strategyapp.dir/depend:
	cd /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/projects /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/projects/strategyapp /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build/strategyapp /home/airaqi/Documents/learn/courses/ossu/011-Design_Patterns/workspace/build/strategyapp/CMakeFiles/strategyapp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : strategyapp/CMakeFiles/strategyapp.dir/depend

