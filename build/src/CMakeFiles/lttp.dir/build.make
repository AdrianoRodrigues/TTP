# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/adriano/workspace/TTP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adriano/workspace/TTP/build

# Include any dependencies generated for this target.
include src/CMakeFiles/lttp.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lttp.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lttp.dir/flags.make

src/CMakeFiles/lttp.dir/railway.cpp.o: src/CMakeFiles/lttp.dir/flags.make
src/CMakeFiles/lttp.dir/railway.cpp.o: ../src/railway.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adriano/workspace/TTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/lttp.dir/railway.cpp.o"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lttp.dir/railway.cpp.o -c /home/adriano/workspace/TTP/src/railway.cpp

src/CMakeFiles/lttp.dir/railway.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lttp.dir/railway.cpp.i"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adriano/workspace/TTP/src/railway.cpp > CMakeFiles/lttp.dir/railway.cpp.i

src/CMakeFiles/lttp.dir/railway.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lttp.dir/railway.cpp.s"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adriano/workspace/TTP/src/railway.cpp -o CMakeFiles/lttp.dir/railway.cpp.s

src/CMakeFiles/lttp.dir/railway.cpp.o.requires:

.PHONY : src/CMakeFiles/lttp.dir/railway.cpp.o.requires

src/CMakeFiles/lttp.dir/railway.cpp.o.provides: src/CMakeFiles/lttp.dir/railway.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/lttp.dir/build.make src/CMakeFiles/lttp.dir/railway.cpp.o.provides.build
.PHONY : src/CMakeFiles/lttp.dir/railway.cpp.o.provides

src/CMakeFiles/lttp.dir/railway.cpp.o.provides.build: src/CMakeFiles/lttp.dir/railway.cpp.o


src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o: src/CMakeFiles/lttp.dir/flags.make
src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o: ../src/schedulingDecoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adriano/workspace/TTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lttp.dir/schedulingDecoder.cpp.o -c /home/adriano/workspace/TTP/src/schedulingDecoder.cpp

src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lttp.dir/schedulingDecoder.cpp.i"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adriano/workspace/TTP/src/schedulingDecoder.cpp > CMakeFiles/lttp.dir/schedulingDecoder.cpp.i

src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lttp.dir/schedulingDecoder.cpp.s"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adriano/workspace/TTP/src/schedulingDecoder.cpp -o CMakeFiles/lttp.dir/schedulingDecoder.cpp.s

src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o.requires:

.PHONY : src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o.requires

src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o.provides: src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/lttp.dir/build.make src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o.provides.build
.PHONY : src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o.provides

src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o.provides.build: src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o


src/CMakeFiles/lttp.dir/schedulingEval.cpp.o: src/CMakeFiles/lttp.dir/flags.make
src/CMakeFiles/lttp.dir/schedulingEval.cpp.o: ../src/schedulingEval.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adriano/workspace/TTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/lttp.dir/schedulingEval.cpp.o"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lttp.dir/schedulingEval.cpp.o -c /home/adriano/workspace/TTP/src/schedulingEval.cpp

src/CMakeFiles/lttp.dir/schedulingEval.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lttp.dir/schedulingEval.cpp.i"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adriano/workspace/TTP/src/schedulingEval.cpp > CMakeFiles/lttp.dir/schedulingEval.cpp.i

src/CMakeFiles/lttp.dir/schedulingEval.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lttp.dir/schedulingEval.cpp.s"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adriano/workspace/TTP/src/schedulingEval.cpp -o CMakeFiles/lttp.dir/schedulingEval.cpp.s

src/CMakeFiles/lttp.dir/schedulingEval.cpp.o.requires:

.PHONY : src/CMakeFiles/lttp.dir/schedulingEval.cpp.o.requires

src/CMakeFiles/lttp.dir/schedulingEval.cpp.o.provides: src/CMakeFiles/lttp.dir/schedulingEval.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/lttp.dir/build.make src/CMakeFiles/lttp.dir/schedulingEval.cpp.o.provides.build
.PHONY : src/CMakeFiles/lttp.dir/schedulingEval.cpp.o.provides

src/CMakeFiles/lttp.dir/schedulingEval.cpp.o.provides.build: src/CMakeFiles/lttp.dir/schedulingEval.cpp.o


src/CMakeFiles/lttp.dir/schedulingInit.cpp.o: src/CMakeFiles/lttp.dir/flags.make
src/CMakeFiles/lttp.dir/schedulingInit.cpp.o: ../src/schedulingInit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adriano/workspace/TTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/lttp.dir/schedulingInit.cpp.o"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lttp.dir/schedulingInit.cpp.o -c /home/adriano/workspace/TTP/src/schedulingInit.cpp

src/CMakeFiles/lttp.dir/schedulingInit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lttp.dir/schedulingInit.cpp.i"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adriano/workspace/TTP/src/schedulingInit.cpp > CMakeFiles/lttp.dir/schedulingInit.cpp.i

src/CMakeFiles/lttp.dir/schedulingInit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lttp.dir/schedulingInit.cpp.s"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adriano/workspace/TTP/src/schedulingInit.cpp -o CMakeFiles/lttp.dir/schedulingInit.cpp.s

src/CMakeFiles/lttp.dir/schedulingInit.cpp.o.requires:

.PHONY : src/CMakeFiles/lttp.dir/schedulingInit.cpp.o.requires

src/CMakeFiles/lttp.dir/schedulingInit.cpp.o.provides: src/CMakeFiles/lttp.dir/schedulingInit.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/lttp.dir/build.make src/CMakeFiles/lttp.dir/schedulingInit.cpp.o.provides.build
.PHONY : src/CMakeFiles/lttp.dir/schedulingInit.cpp.o.provides

src/CMakeFiles/lttp.dir/schedulingInit.cpp.o.provides.build: src/CMakeFiles/lttp.dir/schedulingInit.cpp.o


src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o: src/CMakeFiles/lttp.dir/flags.make
src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o: ../src/schedulingSwap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adriano/workspace/TTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lttp.dir/schedulingSwap.cpp.o -c /home/adriano/workspace/TTP/src/schedulingSwap.cpp

src/CMakeFiles/lttp.dir/schedulingSwap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lttp.dir/schedulingSwap.cpp.i"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adriano/workspace/TTP/src/schedulingSwap.cpp > CMakeFiles/lttp.dir/schedulingSwap.cpp.i

src/CMakeFiles/lttp.dir/schedulingSwap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lttp.dir/schedulingSwap.cpp.s"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adriano/workspace/TTP/src/schedulingSwap.cpp -o CMakeFiles/lttp.dir/schedulingSwap.cpp.s

src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o.requires:

.PHONY : src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o.requires

src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o.provides: src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/lttp.dir/build.make src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o.provides.build
.PHONY : src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o.provides

src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o.provides.build: src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o


src/CMakeFiles/lttp.dir/schedulingValid.cpp.o: src/CMakeFiles/lttp.dir/flags.make
src/CMakeFiles/lttp.dir/schedulingValid.cpp.o: ../src/schedulingValid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adriano/workspace/TTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/lttp.dir/schedulingValid.cpp.o"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lttp.dir/schedulingValid.cpp.o -c /home/adriano/workspace/TTP/src/schedulingValid.cpp

src/CMakeFiles/lttp.dir/schedulingValid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lttp.dir/schedulingValid.cpp.i"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adriano/workspace/TTP/src/schedulingValid.cpp > CMakeFiles/lttp.dir/schedulingValid.cpp.i

src/CMakeFiles/lttp.dir/schedulingValid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lttp.dir/schedulingValid.cpp.s"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adriano/workspace/TTP/src/schedulingValid.cpp -o CMakeFiles/lttp.dir/schedulingValid.cpp.s

src/CMakeFiles/lttp.dir/schedulingValid.cpp.o.requires:

.PHONY : src/CMakeFiles/lttp.dir/schedulingValid.cpp.o.requires

src/CMakeFiles/lttp.dir/schedulingValid.cpp.o.provides: src/CMakeFiles/lttp.dir/schedulingValid.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/lttp.dir/build.make src/CMakeFiles/lttp.dir/schedulingValid.cpp.o.provides.build
.PHONY : src/CMakeFiles/lttp.dir/schedulingValid.cpp.o.provides

src/CMakeFiles/lttp.dir/schedulingValid.cpp.o.provides.build: src/CMakeFiles/lttp.dir/schedulingValid.cpp.o


src/CMakeFiles/lttp.dir/schedulingXover.cpp.o: src/CMakeFiles/lttp.dir/flags.make
src/CMakeFiles/lttp.dir/schedulingXover.cpp.o: ../src/schedulingXover.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adriano/workspace/TTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/lttp.dir/schedulingXover.cpp.o"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lttp.dir/schedulingXover.cpp.o -c /home/adriano/workspace/TTP/src/schedulingXover.cpp

src/CMakeFiles/lttp.dir/schedulingXover.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lttp.dir/schedulingXover.cpp.i"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adriano/workspace/TTP/src/schedulingXover.cpp > CMakeFiles/lttp.dir/schedulingXover.cpp.i

src/CMakeFiles/lttp.dir/schedulingXover.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lttp.dir/schedulingXover.cpp.s"
	cd /home/adriano/workspace/TTP/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adriano/workspace/TTP/src/schedulingXover.cpp -o CMakeFiles/lttp.dir/schedulingXover.cpp.s

src/CMakeFiles/lttp.dir/schedulingXover.cpp.o.requires:

.PHONY : src/CMakeFiles/lttp.dir/schedulingXover.cpp.o.requires

src/CMakeFiles/lttp.dir/schedulingXover.cpp.o.provides: src/CMakeFiles/lttp.dir/schedulingXover.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/lttp.dir/build.make src/CMakeFiles/lttp.dir/schedulingXover.cpp.o.provides.build
.PHONY : src/CMakeFiles/lttp.dir/schedulingXover.cpp.o.provides

src/CMakeFiles/lttp.dir/schedulingXover.cpp.o.provides.build: src/CMakeFiles/lttp.dir/schedulingXover.cpp.o


# Object files for target lttp
lttp_OBJECTS = \
"CMakeFiles/lttp.dir/railway.cpp.o" \
"CMakeFiles/lttp.dir/schedulingDecoder.cpp.o" \
"CMakeFiles/lttp.dir/schedulingEval.cpp.o" \
"CMakeFiles/lttp.dir/schedulingInit.cpp.o" \
"CMakeFiles/lttp.dir/schedulingSwap.cpp.o" \
"CMakeFiles/lttp.dir/schedulingValid.cpp.o" \
"CMakeFiles/lttp.dir/schedulingXover.cpp.o"

# External object files for target lttp
lttp_EXTERNAL_OBJECTS =

lib/liblttp.a: src/CMakeFiles/lttp.dir/railway.cpp.o
lib/liblttp.a: src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o
lib/liblttp.a: src/CMakeFiles/lttp.dir/schedulingEval.cpp.o
lib/liblttp.a: src/CMakeFiles/lttp.dir/schedulingInit.cpp.o
lib/liblttp.a: src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o
lib/liblttp.a: src/CMakeFiles/lttp.dir/schedulingValid.cpp.o
lib/liblttp.a: src/CMakeFiles/lttp.dir/schedulingXover.cpp.o
lib/liblttp.a: src/CMakeFiles/lttp.dir/build.make
lib/liblttp.a: src/CMakeFiles/lttp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adriano/workspace/TTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library ../lib/liblttp.a"
	cd /home/adriano/workspace/TTP/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lttp.dir/cmake_clean_target.cmake
	cd /home/adriano/workspace/TTP/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lttp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lttp.dir/build: lib/liblttp.a

.PHONY : src/CMakeFiles/lttp.dir/build

src/CMakeFiles/lttp.dir/requires: src/CMakeFiles/lttp.dir/railway.cpp.o.requires
src/CMakeFiles/lttp.dir/requires: src/CMakeFiles/lttp.dir/schedulingDecoder.cpp.o.requires
src/CMakeFiles/lttp.dir/requires: src/CMakeFiles/lttp.dir/schedulingEval.cpp.o.requires
src/CMakeFiles/lttp.dir/requires: src/CMakeFiles/lttp.dir/schedulingInit.cpp.o.requires
src/CMakeFiles/lttp.dir/requires: src/CMakeFiles/lttp.dir/schedulingSwap.cpp.o.requires
src/CMakeFiles/lttp.dir/requires: src/CMakeFiles/lttp.dir/schedulingValid.cpp.o.requires
src/CMakeFiles/lttp.dir/requires: src/CMakeFiles/lttp.dir/schedulingXover.cpp.o.requires

.PHONY : src/CMakeFiles/lttp.dir/requires

src/CMakeFiles/lttp.dir/clean:
	cd /home/adriano/workspace/TTP/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lttp.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lttp.dir/clean

src/CMakeFiles/lttp.dir/depend:
	cd /home/adriano/workspace/TTP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adriano/workspace/TTP /home/adriano/workspace/TTP/src /home/adriano/workspace/TTP/build /home/adriano/workspace/TTP/build/src /home/adriano/workspace/TTP/build/src/CMakeFiles/lttp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/lttp.dir/depend

