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
CMAKE_BINARY_DIR = D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850

# Include any dependencies generated for this target.
include sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/depend.make

# Include the progress variables for this target.
include sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/flags.make

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/flags.make
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj: ../../../sdk/codec/tsdemux/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tsdemux.plugin.dir/main.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/main.c

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tsdemux.plugin.dir/main.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/main.c > CMakeFiles/tsdemux.plugin.dir/main.c.i

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tsdemux.plugin.dir/main.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/main.c -o CMakeFiles/tsdemux.plugin.dir/main.c.s

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj.requires:
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj.requires

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj.provides: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj.requires
	$(MAKE) -f sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/build.make sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj.provides.build
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj.provides

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj.provides.build: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/flags.make
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj: ../../../sdk/codec/tsdemux/pes_packet.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/pes_packet.c

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tsdemux.plugin.dir/pes_packet.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/pes_packet.c > CMakeFiles/tsdemux.plugin.dir/pes_packet.c.i

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tsdemux.plugin.dir/pes_packet.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/pes_packet.c -o CMakeFiles/tsdemux.plugin.dir/pes_packet.c.s

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj.requires:
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj.requires

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj.provides: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj.requires
	$(MAKE) -f sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/build.make sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj.provides.build
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj.provides

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj.provides.build: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/flags.make
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj: ../../../sdk/codec/tsdemux/queue_mgr.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/queue_mgr.c

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/queue_mgr.c > CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.i

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/queue_mgr.c -o CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.s

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj.requires:
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj.requires

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj.provides: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj.requires
	$(MAKE) -f sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/build.make sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj.provides.build
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj.provides

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj.provides.build: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/flags.make
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj: ../../../sdk/codec/tsdemux/share_info.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tsdemux.plugin.dir/share_info.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/share_info.c

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tsdemux.plugin.dir/share_info.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/share_info.c > CMakeFiles/tsdemux.plugin.dir/share_info.c.i

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tsdemux.plugin.dir/share_info.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/share_info.c -o CMakeFiles/tsdemux.plugin.dir/share_info.c.s

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj.requires:
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj.requires

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj.provides: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj.requires
	$(MAKE) -f sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/build.make sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj.provides.build
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj.provides

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj.provides.build: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/flags.make
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj: ../../../sdk/codec/tsdemux/string.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tsdemux.plugin.dir/string.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/string.c

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tsdemux.plugin.dir/string.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/string.c > CMakeFiles/tsdemux.plugin.dir/string.c.i

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tsdemux.plugin.dir/string.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/string.c -o CMakeFiles/tsdemux.plugin.dir/string.c.s

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj.requires:
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj.requires

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj.provides: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj.requires
	$(MAKE) -f sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/build.make sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj.provides.build
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj.provides

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj.provides.build: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/flags.make
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj: ../../../sdk/codec/tsdemux/ts.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tsdemux.plugin.dir/ts.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/ts.c

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tsdemux.plugin.dir/ts.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/ts.c > CMakeFiles/tsdemux.plugin.dir/ts.c.i

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tsdemux.plugin.dir/ts.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/ts.c -o CMakeFiles/tsdemux.plugin.dir/ts.c.s

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj.requires:
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj.requires

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj.provides: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj.requires
	$(MAKE) -f sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/build.make sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj.provides.build
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj.provides

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj.provides.build: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/flags.make
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj: ../../../sdk/codec/tsdemux/tsi.c
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tsdemux.plugin.dir/tsi.c.obj   -c D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/tsi.c

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tsdemux.plugin.dir/tsi.c.i"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/tsi.c > CMakeFiles/tsdemux.plugin.dir/tsi.c.i

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tsdemux.plugin.dir/tsi.c.s"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux/tsi.c -o CMakeFiles/tsdemux.plugin.dir/tsi.c.s

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj.requires:
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj.requires

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj.provides: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj.requires
	$(MAKE) -f sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/build.make sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj.provides.build
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj.provides

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj.provides.build: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj

# Object files for target tsdemux.plugin
tsdemux_plugin_OBJECTS = \
"CMakeFiles/tsdemux.plugin.dir/main.c.obj" \
"CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj" \
"CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj" \
"CMakeFiles/tsdemux.plugin.dir/share_info.c.obj" \
"CMakeFiles/tsdemux.plugin.dir/string.c.obj" \
"CMakeFiles/tsdemux.plugin.dir/ts.c.obj" \
"CMakeFiles/tsdemux.plugin.dir/tsi.c.obj"

# External object files for target tsdemux.plugin
tsdemux_plugin_EXTERNAL_OBJECTS =

sdk/codec/tsdemux/tsdemux.plugin: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj
sdk/codec/tsdemux/tsdemux.plugin: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj
sdk/codec/tsdemux/tsdemux.plugin: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj
sdk/codec/tsdemux/tsdemux.plugin: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj
sdk/codec/tsdemux/tsdemux.plugin: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj
sdk/codec/tsdemux/tsdemux.plugin: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj
sdk/codec/tsdemux/tsdemux.plugin: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj
sdk/codec/tsdemux/tsdemux.plugin: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable tsdemux.plugin"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-gcc.exe   -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -gstabs -O3 -g3 -mhard-div -fno-short-enums -DNDEBUG   -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -gstabs -nostartfiles -T"D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/lib/sm32/default.ld" "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/lib/sm32/or32_crt0.o" "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/lib/sm32/codec_crt0.o" "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/lib/sm32/ticktimer.o" $(tsdemux_plugin_OBJECTS) $(tsdemux_plugin_EXTERNAL_OBJECTS)  -o tsdemux.plugin  -LD:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/lib/sm32  
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && C:/ITEGCC/bin/sm32-elf-objcopy.exe -O binary -j .risc1_header -j .text -j .data D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux/tsdemux.plugin D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/lib/sm32/ts.codecs
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && dataconv -x D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/lib/sm32/ts.codecs

# Rule to build all files generated by this target.
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/build: sdk/codec/tsdemux/tsdemux.plugin
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/build

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/requires: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/main.c.obj.requires
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/requires: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/pes_packet.c.obj.requires
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/requires: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/queue_mgr.c.obj.requires
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/requires: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/share_info.c.obj.requires
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/requires: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/string.c.obj.requires
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/requires: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/ts.c.obj.requires
sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/requires: sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/tsi.c.obj.requires
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/requires

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/clean:
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux && $(CMAKE_COMMAND) -P CMakeFiles/tsdemux.plugin.dir/cmake_clean.cmake
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/clean

sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec/tsdemux D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850 D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_it9850/sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/codec/tsdemux/CMakeFiles/tsdemux.plugin.dir/depend

