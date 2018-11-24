# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/benek/workspace/g1/Grafika-master/OGLSamples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benek/workspace/g1/Grafika-master/OGLSamples

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/benek/workspace/g1/Grafika-master/OGLSamples/CMakeFiles /home/benek/workspace/g1/Grafika-master/OGLSamples/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/benek/workspace/g1/Grafika-master/OGLSamples/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named OGLSample1

# Build rule for target.
OGLSample1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 OGLSample1
.PHONY : OGLSample1

# fast build rule for target.
OGLSample1/fast:
	$(MAKE) -f OGLSample1/CMakeFiles/OGLSample1.dir/build.make OGLSample1/CMakeFiles/OGLSample1.dir/build
.PHONY : OGLSample1/fast

#=============================================================================
# Target rules for targets named OGLSample2_IB_VBO

# Build rule for target.
OGLSample2_IB_VBO: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 OGLSample2_IB_VBO
.PHONY : OGLSample2_IB_VBO

# fast build rule for target.
OGLSample2_IB_VBO/fast:
	$(MAKE) -f OGLSample2_IB_VBO/CMakeFiles/OGLSample2_IB_VBO.dir/build.make OGLSample2_IB_VBO/CMakeFiles/OGLSample2_IB_VBO.dir/build
.PHONY : OGLSample2_IB_VBO/fast

#=============================================================================
# Target rules for targets named buffor1

# Build rule for target.
buffor1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 buffor1
.PHONY : buffor1

# fast build rule for target.
buffor1/fast:
	$(MAKE) -f buffor1/CMakeFiles/buffor1.dir/build.make buffor1/CMakeFiles/buffor1.dir/build
.PHONY : buffor1/fast

#=============================================================================
# Target rules for targets named buffor2

# Build rule for target.
buffor2: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 buffor2
.PHONY : buffor2

# fast build rule for target.
buffor2/fast:
	$(MAKE) -f buffor2/CMakeFiles/buffor2.dir/build.make buffor2/CMakeFiles/buffor2.dir/build
.PHONY : buffor2/fast

#=============================================================================
# Target rules for targets named buffor3

# Build rule for target.
buffor3: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 buffor3
.PHONY : buffor3

# fast build rule for target.
buffor3/fast:
	$(MAKE) -f buffor3/CMakeFiles/buffor3.dir/build.make buffor3/CMakeFiles/buffor3.dir/build
.PHONY : buffor3/fast

#=============================================================================
# Target rules for targets named uniform1

# Build rule for target.
uniform1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 uniform1
.PHONY : uniform1

# fast build rule for target.
uniform1/fast:
	$(MAKE) -f uniform1/CMakeFiles/uniform1.dir/build.make uniform1/CMakeFiles/uniform1.dir/build
.PHONY : uniform1/fast

#=============================================================================
# Target rules for targets named przeksztalceniaPVM

# Build rule for target.
przeksztalceniaPVM: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 przeksztalceniaPVM
.PHONY : przeksztalceniaPVM

# fast build rule for target.
przeksztalceniaPVM/fast:
	$(MAKE) -f przeksztalceniaPVM/CMakeFiles/przeksztalceniaPVM.dir/build.make przeksztalceniaPVM/CMakeFiles/przeksztalceniaPVM.dir/build
.PHONY : przeksztalceniaPVM/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install"
	@echo "... install/local"
	@echo "... list_install_components"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... OGLSample1"
	@echo "... OGLSample2_IB_VBO"
	@echo "... buffor1"
	@echo "... buffor2"
	@echo "... buffor3"
	@echo "... uniform1"
	@echo "... przeksztalceniaPVM"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

