# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.1

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
CMAKE_COMMAND = D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/tool/bin/cmake.exe

# The command to remove a file.
RM = D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/tool/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec

# Utility rule file for default.ld.

# Include the progress variables for this target.
include project/codec/CMakeFiles/default.ld.dir/progress.make

project/codec/CMakeFiles/default.ld: lib/sm32/default.ld

lib/sm32/default.ld: ../../../project/codec/default.lds
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../../lib/sm32/default.ld"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec/project/codec && sm32-elf-cpp -ID:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/include -E -P -o D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec/lib/sm32/default.ld D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/project/codec/default.lds

default.ld: project/codec/CMakeFiles/default.ld
default.ld: lib/sm32/default.ld
default.ld: project/codec/CMakeFiles/default.ld.dir/build.make
.PHONY : default.ld

# Rule to build all files generated by this target.
project/codec/CMakeFiles/default.ld.dir/build: default.ld
.PHONY : project/codec/CMakeFiles/default.ld.dir/build

project/codec/CMakeFiles/default.ld.dir/clean:
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec/project/codec && $(CMAKE_COMMAND) -P CMakeFiles/default.ld.dir/cmake_clean.cmake
.PHONY : project/codec/CMakeFiles/default.ld.dir/clean

project/codec/CMakeFiles/default.ld.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/project/codec D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec/project/codec D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec/project/codec/CMakeFiles/default.ld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project/codec/CMakeFiles/default.ld.dir/depend

