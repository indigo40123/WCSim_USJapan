# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev

# Utility rule file for install_WCSim.

# Include the progress variables for this target.
include CMakeFiles/install_WCSim.dir/progress.make

CMakeFiles/install_WCSim:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Installing WCSim"
	/usr/bin/cmake --build /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev --target install

install_WCSim: CMakeFiles/install_WCSim
install_WCSim: CMakeFiles/install_WCSim.dir/build.make

.PHONY : install_WCSim

# Rule to build all files generated by this target.
CMakeFiles/install_WCSim.dir/build: install_WCSim

.PHONY : CMakeFiles/install_WCSim.dir/build

CMakeFiles/install_WCSim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/install_WCSim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/install_WCSim.dir/clean

CMakeFiles/install_WCSim.dir/depend:
	cd /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/CMakeFiles/install_WCSim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/install_WCSim.dir/depend

