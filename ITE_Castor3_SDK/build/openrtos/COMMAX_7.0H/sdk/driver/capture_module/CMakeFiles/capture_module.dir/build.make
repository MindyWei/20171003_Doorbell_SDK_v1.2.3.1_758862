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
include sdk/driver/capture_module/CMakeFiles/capture_module.dir/depend.make

# Include the progress variables for this target.
include sdk/driver/capture_module/CMakeFiles/capture_module.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/driver/capture_module/CMakeFiles/capture_module.dir/flags.make

sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj: sdk/driver/capture_module/CMakeFiles/capture_module.dir/flags.make
sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj: ../../../sdk/driver/capture_module/adv7180.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/capture_module.dir/adv7180.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/adv7180.c

sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/capture_module.dir/adv7180.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/adv7180.c > CMakeFiles/capture_module.dir/adv7180.c.i

sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/capture_module.dir/adv7180.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/adv7180.c -o CMakeFiles/capture_module.dir/adv7180.c.s

sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj.requires:
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj.requires

sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj.provides: sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj.requires
	$(MAKE) -f sdk/driver/capture_module/CMakeFiles/capture_module.dir/build.make sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj.provides.build
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj.provides

sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj.provides.build: sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj: sdk/driver/capture_module/CMakeFiles/capture_module.dir/flags.make
sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj: ../../../sdk/driver/capture_module/gc0308.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/capture_module.dir/gc0308.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/gc0308.c

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/capture_module.dir/gc0308.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/gc0308.c > CMakeFiles/capture_module.dir/gc0308.c.i

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/capture_module.dir/gc0308.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/gc0308.c -o CMakeFiles/capture_module.dir/gc0308.c.s

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj.requires:
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj.requires

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj.provides: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj.requires
	$(MAKE) -f sdk/driver/capture_module/CMakeFiles/capture_module.dir/build.make sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj.provides.build
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj.provides

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj.provides.build: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj: sdk/driver/capture_module/CMakeFiles/capture_module.dir/flags.make
sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj: ../../../sdk/driver/capture_module/gc0328.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/capture_module.dir/gc0328.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/gc0328.c

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/capture_module.dir/gc0328.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/gc0328.c > CMakeFiles/capture_module.dir/gc0328.c.i

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/capture_module.dir/gc0328.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/gc0328.c -o CMakeFiles/capture_module.dir/gc0328.c.s

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj.requires:
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj.requires

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj.provides: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj.requires
	$(MAKE) -f sdk/driver/capture_module/CMakeFiles/capture_module.dir/build.make sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj.provides.build
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj.provides

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj.provides.build: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj: sdk/driver/capture_module/CMakeFiles/capture_module.dir/flags.make
sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj: ../../../sdk/driver/capture_module/gt5110e1.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/capture_module.dir/gt5110e1.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/gt5110e1.c

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/capture_module.dir/gt5110e1.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/gt5110e1.c > CMakeFiles/capture_module.dir/gt5110e1.c.i

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/capture_module.dir/gt5110e1.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/gt5110e1.c -o CMakeFiles/capture_module.dir/gt5110e1.c.s

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj.requires:
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj.requires

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj.provides: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj.requires
	$(MAKE) -f sdk/driver/capture_module/CMakeFiles/capture_module.dir/build.make sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj.provides.build
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj.provides

sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj.provides.build: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj

sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj: sdk/driver/capture_module/CMakeFiles/capture_module.dir/flags.make
sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj: ../../../sdk/driver/capture_module/hm1375.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/capture_module.dir/hm1375.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/hm1375.c

sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/capture_module.dir/hm1375.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/hm1375.c > CMakeFiles/capture_module.dir/hm1375.c.i

sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/capture_module.dir/hm1375.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/hm1375.c -o CMakeFiles/capture_module.dir/hm1375.c.s

sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj.requires:
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj.requires

sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj.provides: sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj.requires
	$(MAKE) -f sdk/driver/capture_module/CMakeFiles/capture_module.dir/build.make sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj.provides.build
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj.provides

sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj.provides.build: sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj

sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj: sdk/driver/capture_module/CMakeFiles/capture_module.dir/flags.make
sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj: ../../../sdk/driver/capture_module/pr2000.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/capture_module.dir/pr2000.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/pr2000.c

sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/capture_module.dir/pr2000.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/pr2000.c > CMakeFiles/capture_module.dir/pr2000.c.i

sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/capture_module.dir/pr2000.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/pr2000.c -o CMakeFiles/capture_module.dir/pr2000.c.s

sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj.requires:
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj.requires

sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj.provides: sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj.requires
	$(MAKE) -f sdk/driver/capture_module/CMakeFiles/capture_module.dir/build.make sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj.provides.build
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj.provides

sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj.provides.build: sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj

sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj: sdk/driver/capture_module/CMakeFiles/capture_module.dir/flags.make
sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj: ../../../sdk/driver/capture_module/TVP5155.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/capture_module.dir/TVP5155.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/TVP5155.c

sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/capture_module.dir/TVP5155.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/TVP5155.c > CMakeFiles/capture_module.dir/TVP5155.c.i

sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/capture_module.dir/TVP5155.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/TVP5155.c -o CMakeFiles/capture_module.dir/TVP5155.c.s

sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj.requires:
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj.requires

sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj.provides: sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj.requires
	$(MAKE) -f sdk/driver/capture_module/CMakeFiles/capture_module.dir/build.make sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj.provides.build
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj.provides

sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj.provides.build: sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj

sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj: sdk/driver/capture_module/CMakeFiles/capture_module.dir/flags.make
sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj: ../../../sdk/driver/capture_module/capture_module.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/capture_module.dir/capture_module.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/capture_module.c

sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/capture_module.dir/capture_module.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/capture_module.c > CMakeFiles/capture_module.dir/capture_module.c.i

sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/capture_module.dir/capture_module.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module/capture_module.c -o CMakeFiles/capture_module.dir/capture_module.c.s

sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj.requires:
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj.requires

sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj.provides: sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj.requires
	$(MAKE) -f sdk/driver/capture_module/CMakeFiles/capture_module.dir/build.make sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj.provides.build
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj.provides

sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj.provides.build: sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj

# Object files for target capture_module
capture_module_OBJECTS = \
"CMakeFiles/capture_module.dir/adv7180.c.obj" \
"CMakeFiles/capture_module.dir/gc0308.c.obj" \
"CMakeFiles/capture_module.dir/gc0328.c.obj" \
"CMakeFiles/capture_module.dir/gt5110e1.c.obj" \
"CMakeFiles/capture_module.dir/hm1375.c.obj" \
"CMakeFiles/capture_module.dir/pr2000.c.obj" \
"CMakeFiles/capture_module.dir/TVP5155.c.obj" \
"CMakeFiles/capture_module.dir/capture_module.c.obj"

# External object files for target capture_module
capture_module_EXTERNAL_OBJECTS =

lib/fa626/libcapture_module.a: sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj
lib/fa626/libcapture_module.a: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj
lib/fa626/libcapture_module.a: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj
lib/fa626/libcapture_module.a: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj
lib/fa626/libcapture_module.a: sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj
lib/fa626/libcapture_module.a: sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj
lib/fa626/libcapture_module.a: sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj
lib/fa626/libcapture_module.a: sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj
lib/fa626/libcapture_module.a: sdk/driver/capture_module/CMakeFiles/capture_module.dir/build.make
lib/fa626/libcapture_module.a: sdk/driver/capture_module/CMakeFiles/capture_module.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library ../../../lib/fa626/libcapture_module.a"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && $(CMAKE_COMMAND) -P CMakeFiles/capture_module.dir/cmake_clean_target.cmake
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/capture_module.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/driver/capture_module/CMakeFiles/capture_module.dir/build: lib/fa626/libcapture_module.a
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/build

sdk/driver/capture_module/CMakeFiles/capture_module.dir/requires: sdk/driver/capture_module/CMakeFiles/capture_module.dir/adv7180.c.obj.requires
sdk/driver/capture_module/CMakeFiles/capture_module.dir/requires: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0308.c.obj.requires
sdk/driver/capture_module/CMakeFiles/capture_module.dir/requires: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gc0328.c.obj.requires
sdk/driver/capture_module/CMakeFiles/capture_module.dir/requires: sdk/driver/capture_module/CMakeFiles/capture_module.dir/gt5110e1.c.obj.requires
sdk/driver/capture_module/CMakeFiles/capture_module.dir/requires: sdk/driver/capture_module/CMakeFiles/capture_module.dir/hm1375.c.obj.requires
sdk/driver/capture_module/CMakeFiles/capture_module.dir/requires: sdk/driver/capture_module/CMakeFiles/capture_module.dir/pr2000.c.obj.requires
sdk/driver/capture_module/CMakeFiles/capture_module.dir/requires: sdk/driver/capture_module/CMakeFiles/capture_module.dir/TVP5155.c.obj.requires
sdk/driver/capture_module/CMakeFiles/capture_module.dir/requires: sdk/driver/capture_module/CMakeFiles/capture_module.dir/capture_module.c.obj.requires
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/requires

sdk/driver/capture_module/CMakeFiles/capture_module.dir/clean:
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module && $(CMAKE_COMMAND) -P CMakeFiles/capture_module.dir/cmake_clean.cmake
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/clean

sdk/driver/capture_module/CMakeFiles/capture_module.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/capture_module D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/sdk/driver/capture_module/CMakeFiles/capture_module.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/driver/capture_module/CMakeFiles/capture_module.dir/depend
