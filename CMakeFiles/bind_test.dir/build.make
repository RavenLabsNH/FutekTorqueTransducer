# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64

# Include any dependencies generated for this target.
include CMakeFiles/bind_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bind_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bind_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bind_test.dir/flags.make

CMakeFiles/bind_test.dir/main.cpp.o: CMakeFiles/bind_test.dir/flags.make
CMakeFiles/bind_test.dir/main.cpp.o: main.cpp
CMakeFiles/bind_test.dir/main.cpp.o: CMakeFiles/bind_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bind_test.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bind_test.dir/main.cpp.o -MF CMakeFiles/bind_test.dir/main.cpp.o.d -o CMakeFiles/bind_test.dir/main.cpp.o -c /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64/main.cpp

CMakeFiles/bind_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bind_test.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64/main.cpp > CMakeFiles/bind_test.dir/main.cpp.i

CMakeFiles/bind_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bind_test.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64/main.cpp -o CMakeFiles/bind_test.dir/main.cpp.s

# Object files for target bind_test
bind_test_OBJECTS = \
"CMakeFiles/bind_test.dir/main.cpp.o"

# External object files for target bind_test
bind_test_EXTERNAL_OBJECTS =

bind_test.cpython-310-x86_64-linux-gnu.so: CMakeFiles/bind_test.dir/main.cpp.o
bind_test.cpython-310-x86_64-linux-gnu.so: CMakeFiles/bind_test.dir/build.make
bind_test.cpython-310-x86_64-linux-gnu.so: /usr/local/lib/libFUTEK_USB-x86_64.so
bind_test.cpython-310-x86_64-linux-gnu.so: /usr/local/lib/libftd2xx.so
bind_test.cpython-310-x86_64-linux-gnu.so: CMakeFiles/bind_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module bind_test.cpython-310-x86_64-linux-gnu.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bind_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bind_test.dir/build: bind_test.cpython-310-x86_64-linux-gnu.so
.PHONY : CMakeFiles/bind_test.dir/build

CMakeFiles/bind_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bind_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bind_test.dir/clean

CMakeFiles/bind_test.dir/depend:
	cd /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64 /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64 /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64 /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64 /home/dyno/Downloads/futek_usb_linux_x86_64/FUTEK_USB-x86_64/CMakeFiles/bind_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bind_test.dir/depend

