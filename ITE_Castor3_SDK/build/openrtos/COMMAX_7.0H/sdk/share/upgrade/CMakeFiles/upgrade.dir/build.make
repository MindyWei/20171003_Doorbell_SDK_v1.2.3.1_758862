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
CMAKE_BINARY_DIR = D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H

# Include any dependencies generated for this target.
include sdk/share/upgrade/CMakeFiles/upgrade.dir/depend.make

# Include the progress variables for this target.
include sdk/share/upgrade/CMakeFiles/upgrade.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj: ../../../sdk/share/upgrade/ug_filecrc.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_filecrc.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_filecrc.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_filecrc.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_filecrc.c > CMakeFiles/upgrade.dir/ug_filecrc.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_filecrc.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_filecrc.c -o CMakeFiles/upgrade.dir/ug_filecrc.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj: ../../../sdk/share/upgrade/ug_device.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_device.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_device.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_device.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_device.c > CMakeFiles/upgrade.dir/ug_device.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_device.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_device.c -o CMakeFiles/upgrade.dir/ug_device.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj: ../../../sdk/share/upgrade/ug_directory.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_directory.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_directory.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_directory.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_directory.c > CMakeFiles/upgrade.dir/ug_directory.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_directory.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_directory.c -o CMakeFiles/upgrade.dir/ug_directory.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj: ../../../sdk/share/upgrade/ug_end.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_end.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_end.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_end.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_end.c > CMakeFiles/upgrade.dir/ug_end.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_end.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_end.c -o CMakeFiles/upgrade.dir/ug_end.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj: ../../../sdk/share/upgrade/ug_file.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_file.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_file.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_file.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_file.c > CMakeFiles/upgrade.dir/ug_file.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_file.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_file.c -o CMakeFiles/upgrade.dir/ug_file.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj: ../../../sdk/share/upgrade/ug_package.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_package.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_package.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_package.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_package.c > CMakeFiles/upgrade.dir/ug_package.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_package.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_package.c -o CMakeFiles/upgrade.dir/ug_package.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj: ../../../sdk/share/upgrade/ug_partition.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_partition.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_partition.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_partition.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_partition.c > CMakeFiles/upgrade.dir/ug_partition.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_partition.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_partition.c -o CMakeFiles/upgrade.dir/ug_partition.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj: ../../../sdk/share/upgrade/ug_rawdata.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_rawdata.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_rawdata.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_rawdata.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_rawdata.c > CMakeFiles/upgrade.dir/ug_rawdata.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_rawdata.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_rawdata.c -o CMakeFiles/upgrade.dir/ug_rawdata.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj: ../../../sdk/share/upgrade/ug_reset.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_reset.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_reset.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_reset.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_reset.c > CMakeFiles/upgrade.dir/ug_reset.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_reset.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_reset.c -o CMakeFiles/upgrade.dir/ug_reset.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj: ../../../sdk/share/upgrade/ug_unformatted.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_unformatted.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_unformatted.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_unformatted.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_unformatted.c > CMakeFiles/upgrade.dir/ug_unformatted.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_unformatted.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_unformatted.c -o CMakeFiles/upgrade.dir/ug_unformatted.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj: sdk/share/upgrade/CMakeFiles/upgrade.dir/flags.make
sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj: ../../../sdk/share/upgrade/ug_crc.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/upgrade.dir/ug_crc.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_crc.c

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/upgrade.dir/ug_crc.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_crc.c > CMakeFiles/upgrade.dir/ug_crc.c.i

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/upgrade.dir/ug_crc.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade/ug_crc.c -o CMakeFiles/upgrade.dir/ug_crc.c.s

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj.requires:
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj.requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj.provides: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj.requires
	$(MAKE) -f sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj.provides.build
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj.provides

sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj.provides.build: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj

# Object files for target upgrade
upgrade_OBJECTS = \
"CMakeFiles/upgrade.dir/ug_filecrc.c.obj" \
"CMakeFiles/upgrade.dir/ug_device.c.obj" \
"CMakeFiles/upgrade.dir/ug_directory.c.obj" \
"CMakeFiles/upgrade.dir/ug_end.c.obj" \
"CMakeFiles/upgrade.dir/ug_file.c.obj" \
"CMakeFiles/upgrade.dir/ug_package.c.obj" \
"CMakeFiles/upgrade.dir/ug_partition.c.obj" \
"CMakeFiles/upgrade.dir/ug_rawdata.c.obj" \
"CMakeFiles/upgrade.dir/ug_reset.c.obj" \
"CMakeFiles/upgrade.dir/ug_unformatted.c.obj" \
"CMakeFiles/upgrade.dir/ug_crc.c.obj"

# External object files for target upgrade
upgrade_EXTERNAL_OBJECTS =

lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/build.make
lib/fa626/libupgrade.a: sdk/share/upgrade/CMakeFiles/upgrade.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library ../../../lib/fa626/libupgrade.a"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && $(CMAKE_COMMAND) -P CMakeFiles/upgrade.dir/cmake_clean_target.cmake
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/upgrade.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/share/upgrade/CMakeFiles/upgrade.dir/build: lib/fa626/libupgrade.a
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/build

sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_filecrc.c.obj.requires
sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_device.c.obj.requires
sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_directory.c.obj.requires
sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_end.c.obj.requires
sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_file.c.obj.requires
sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_package.c.obj.requires
sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_partition.c.obj.requires
sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_rawdata.c.obj.requires
sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_reset.c.obj.requires
sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_unformatted.c.obj.requires
sdk/share/upgrade/CMakeFiles/upgrade.dir/requires: sdk/share/upgrade/CMakeFiles/upgrade.dir/ug_crc.c.obj.requires
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/requires

sdk/share/upgrade/CMakeFiles/upgrade.dir/clean:
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade && $(CMAKE_COMMAND) -P CMakeFiles/upgrade.dir/cmake_clean.cmake
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/clean

sdk/share/upgrade/CMakeFiles/upgrade.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/share/upgrade D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/share/upgrade/CMakeFiles/upgrade.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/share/upgrade/CMakeFiles/upgrade.dir/depend

