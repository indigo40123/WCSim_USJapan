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

# Include any dependencies generated for this target.
include src/CMakeFiles/WCSim.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/WCSim.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/WCSim.dir/flags.make

src/CMakeFiles/WCSim.dir/__/WCSim.cc.o: src/CMakeFiles/WCSim.dir/flags.make
src/CMakeFiles/WCSim.dir/__/WCSim.cc.o: ../../WCSim.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/WCSim.dir/__/WCSim.cc.o"
	cd /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/src && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WCSim.dir/__/WCSim.cc.o -c /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim.cc

src/CMakeFiles/WCSim.dir/__/WCSim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WCSim.dir/__/WCSim.cc.i"
	cd /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim.cc > CMakeFiles/WCSim.dir/__/WCSim.cc.i

src/CMakeFiles/WCSim.dir/__/WCSim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WCSim.dir/__/WCSim.cc.s"
	cd /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim.cc -o CMakeFiles/WCSim.dir/__/WCSim.cc.s

# Object files for target WCSim
WCSim_OBJECTS = \
"CMakeFiles/WCSim.dir/__/WCSim.cc.o"

# External object files for target WCSim
WCSim_EXTERNAL_OBJECTS =

src/WCSim: src/CMakeFiles/WCSim.dir/__/WCSim.cc.o
src/WCSim: src/CMakeFiles/WCSim.dir/build.make
src/WCSim: src/libWCSimCore.so.1.10
src/WCSim: src/libWCSimRoot.so.1.10
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libCore.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libImt.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libRIO.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libNet.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libHist.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libGraf.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libGraf3d.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libGpad.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libROOTDataFrame.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libTree.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libTreePlayer.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libRint.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libPostscript.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libMatrix.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libPhysics.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libMathCore.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libThread.so
src/WCSim: /home/pronost/software/root-6.22.00-build/lib/libMultiProc.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4Tree.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4GMocren.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4visHepRep.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4RayTracer.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4VRML.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4OpenGL.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4gl2ps.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4interfaces.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4persistency.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4error_propagation.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4readout.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4physicslists.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4parmodels.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4FR.so
src/WCSim: /usr/lib64/libQt5OpenGL.so.5.15.2
src/WCSim: /usr/lib64/libGL.so
src/WCSim: /usr/lib64/libGLU.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4vis_management.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4modeling.so
src/WCSim: /usr/lib64/libXm.so
src/WCSim: /usr/lib64/libSM.so
src/WCSim: /usr/lib64/libICE.so
src/WCSim: /usr/lib64/libX11.so
src/WCSim: /usr/lib64/libXext.so
src/WCSim: /usr/lib64/libXt.so
src/WCSim: /usr/lib64/libXmu.so
src/WCSim: /usr/lib64/libQt5PrintSupport.so.5.15.2
src/WCSim: /usr/lib64/libQt5Widgets.so.5.15.2
src/WCSim: /usr/lib64/libQt5Gui.so.5.15.2
src/WCSim: /usr/lib64/libQt5Core.so.5.15.2
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/xerces-c-3.2.2/lib64/libxerces-c.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4run.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4event.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4tracking.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4processes.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4analysis.so
src/WCSim: /usr/lib64/libfreetype.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4digits_hits.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4track.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4particles.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4geometry.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4materials.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4graphics_reps.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4intercoms.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4global.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4clhep.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4expat.so
src/WCSim: /usr/local/sklib_gcc8/geant4.10.05.p01/geant4.10.05.p01-build/BuildProducts/lib64/libG4zlib.so
src/WCSim: src/CMakeFiles/WCSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WCSim"
	cd /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WCSim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/WCSim.dir/build: src/WCSim

.PHONY : src/CMakeFiles/WCSim.dir/build

src/CMakeFiles/WCSim.dir/clean:
	cd /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/src && $(CMAKE_COMMAND) -P CMakeFiles/WCSim.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/WCSim.dir/clean

src/CMakeFiles/WCSim.dir/depend:
	cd /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/src /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/src /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/src/CMakeFiles/WCSim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/WCSim.dir/depend

