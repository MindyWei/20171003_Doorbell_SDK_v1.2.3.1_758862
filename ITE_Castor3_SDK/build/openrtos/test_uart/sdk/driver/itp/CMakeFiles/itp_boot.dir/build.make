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
CMAKE_COMMAND = D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/tool/bin/cmake.exe

# The command to remove a file.
RM = D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/tool/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart

# Include any dependencies generated for this target.
include sdk/driver/itp/CMakeFiles/itp_boot.dir/depend.make

# Include the progress variables for this target.
include sdk/driver/itp/CMakeFiles/itp_boot.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj: ../../../sdk/driver/itp/itp_backtrace.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_backtrace.c.obj   -c D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_backtrace.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_backtrace.c.i"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_backtrace.c > CMakeFiles/itp_boot.dir/itp_backtrace.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_backtrace.c.s"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_backtrace.c -o CMakeFiles/itp_boot.dir/itp_backtrace.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj.requires:
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj.requires

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj.provides: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj.requires
	$(MAKE) -f sdk/driver/itp/CMakeFiles/itp_boot.dir/build.make sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj.provides.build
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj.provides

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj.provides.build: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj: ../../../sdk/driver/itp/itp_base.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_base.c.obj   -c D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_base.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_base.c.i"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_base.c > CMakeFiles/itp_boot.dir/itp_base.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_base.c.s"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_base.c -o CMakeFiles/itp_boot.dir/itp_base.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj.requires:
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj.requires

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj.provides: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj.requires
	$(MAKE) -f sdk/driver/itp/CMakeFiles/itp_boot.dir/build.make sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj.provides.build
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj.provides

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj.provides.build: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj: ../../../sdk/driver/itp/itp_defer.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_defer.c.obj   -c D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_defer.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_defer.c.i"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_defer.c > CMakeFiles/itp_boot.dir/itp_defer.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_defer.c.s"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_defer.c -o CMakeFiles/itp_boot.dir/itp_defer.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj.requires:
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj.requires

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj.provides: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj.requires
	$(MAKE) -f sdk/driver/itp/CMakeFiles/itp_boot.dir/build.make sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj.provides.build
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj.provides

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj.provides.build: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj: ../../../sdk/driver/itp/itp_error.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_error.c.obj   -c D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_error.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_error.c.i"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_error.c > CMakeFiles/itp_boot.dir/itp_error.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_error.c.s"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_error.c -o CMakeFiles/itp_boot.dir/itp_error.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj.requires:
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj.requires

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj.provides: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj.requires
	$(MAKE) -f sdk/driver/itp/CMakeFiles/itp_boot.dir/build.make sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj.provides.build
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj.provides

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj.provides.build: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj: ../../../sdk/driver/itp/itp_vmem.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_vmem.c.obj   -c D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_vmem.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_vmem.c.i"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_vmem.c > CMakeFiles/itp_boot.dir/itp_vmem.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_vmem.c.s"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_vmem.c -o CMakeFiles/itp_boot.dir/itp_vmem.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj.requires:
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj.requires

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj.provides: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj.requires
	$(MAKE) -f sdk/driver/itp/CMakeFiles/itp_boot.dir/build.make sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj.provides.build
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj.provides

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj.provides.build: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj: ../../../sdk/driver/itp/itp_uart.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_uart.c.obj   -c D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_uart.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_uart.c.i"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_uart.c > CMakeFiles/itp_boot.dir/itp_uart.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_uart.c.s"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_uart.c -o CMakeFiles/itp_boot.dir/itp_uart.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj.requires:
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj.requires

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj.provides: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj.requires
	$(MAKE) -f sdk/driver/itp/CMakeFiles/itp_boot.dir/build.make sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj.provides.build
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj.provides

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj.provides.build: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj: ../../../sdk/driver/itp/itp_posix_openrtos.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj   -c D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_posix_openrtos.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.i"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_posix_openrtos.c > CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.s"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp/itp_posix_openrtos.c -o CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj.requires:
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj.requires

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj.provides: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj.requires
	$(MAKE) -f sdk/driver/itp/CMakeFiles/itp_boot.dir/build.make sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj.provides.build
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj.provides

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj.provides.build: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj

# Object files for target itp_boot
itp_boot_OBJECTS = \
"CMakeFiles/itp_boot.dir/itp_backtrace.c.obj" \
"CMakeFiles/itp_boot.dir/itp_base.c.obj" \
"CMakeFiles/itp_boot.dir/itp_defer.c.obj" \
"CMakeFiles/itp_boot.dir/itp_error.c.obj" \
"CMakeFiles/itp_boot.dir/itp_vmem.c.obj" \
"CMakeFiles/itp_boot.dir/itp_uart.c.obj" \
"CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj"

# External object files for target itp_boot
itp_boot_EXTERNAL_OBJECTS =

lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/build.make
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library ../../../lib/fa626/libitp_boot.a"
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && $(CMAKE_COMMAND) -P CMakeFiles/itp_boot.dir/cmake_clean_target.cmake
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/itp_boot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/driver/itp/CMakeFiles/itp_boot.dir/build: lib/fa626/libitp_boot.a
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/build

sdk/driver/itp/CMakeFiles/itp_boot.dir/requires: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj.requires
sdk/driver/itp/CMakeFiles/itp_boot.dir/requires: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj.requires
sdk/driver/itp/CMakeFiles/itp_boot.dir/requires: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj.requires
sdk/driver/itp/CMakeFiles/itp_boot.dir/requires: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj.requires
sdk/driver/itp/CMakeFiles/itp_boot.dir/requires: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj.requires
sdk/driver/itp/CMakeFiles/itp_boot.dir/requires: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj.requires
sdk/driver/itp/CMakeFiles/itp_boot.dir/requires: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj.requires
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/requires

sdk/driver/itp/CMakeFiles/itp_boot.dir/clean:
	cd D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp && $(CMAKE_COMMAND) -P CMakeFiles/itp_boot.dir/cmake_clean.cmake
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/clean

sdk/driver/itp/CMakeFiles/itp_boot.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/driver/itp D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp D:/WorkSpace/Project/DoorBell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/test_uart/sdk/driver/itp/CMakeFiles/itp_boot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/depend
