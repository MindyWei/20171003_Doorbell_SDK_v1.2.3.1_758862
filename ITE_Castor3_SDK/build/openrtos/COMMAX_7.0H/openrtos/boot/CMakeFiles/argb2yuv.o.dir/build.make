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

# Utility rule file for argb2yuv.o.

# Include the progress variables for this target.
include openrtos/boot/CMakeFiles/argb2yuv.o.dir/progress.make

openrtos/boot/CMakeFiles/argb2yuv.o: lib/fa626/argb2yuv.o

lib/fa626/argb2yuv.o: ../../../openrtos/boot/fa626/argb2yuv.s
	$(CMAKE_COMMAND) -E cmake_progress_report D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../../lib/fa626/argb2yuv.o"
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/openrtos/boot && C:/ITEGCC/bin/arm-none-eabi-gcc.exe -DCFG_CHIP_REV_A0 -DCFG_CHIP_PKG_IT9856 -DCFG_OSC_CLK=12000000 -DCFG_RTC_EXTCLK=12000000 -DCFG_CHIP_FAMILY=9850 -DCFG_RAM_SIZE=0x4000000 -DCFG_WATCHDOG_ENABLE -DCFG_WATCHDOG_TIMEOUT=10 -DCFG_WATCHDOG_REFRESH_INTERVAL=1 -DCFG_MEMDBG_ENABLE -DCFG_DCPS_ENABLE -DCFG_CPU_WB -DCFG_WT_SIZE=0x200000 -DCFG_LCD_ENABLE -DCFG_LCD_WIDTH=1024 -DCFG_LCD_HEIGHT=600 -DCFG_LCD_PITCH=2048 -DCFG_LCD_BPP=2 -DCFG_LCD_TRIPLE_BUFFER -DCFG_BL_SHOW_LOGO -DCFG_LCD_BOOT_BGCOLOR=0x000000 -DCFG_CMDQ_ENABLE -DCFG_CMDQ_SIZE=0x40000 -DCFG_M2D_ENABLE -DCFG_JPEG_HW_ENABLE -DCFG_FONT_FILENAME="DroidSansMono.ttf" -DCFG_AUDIO_ENABLE -DAUDIO_PLUGIN_MESSAGE_QUEUE -DENABLE_CODECS_PLUGIN -DCONFIG_ITADRIVER -DCFG_AUDIO_SAMPLING_RATE=8000 -DCFG_AEC_DELAY_MS=60 -DCFG_SPEAKER_GAIN=0 -DCFG_MIC_GAIN=0 -DCFG_NOISE_GATE_THRESHOLD=0.3 -DCFG_EQUALIZER_SPKGAIN_SET=NULL -DCFG_EQUALIZER_MICGAIN_SET=NULL -DCFG_AUDIO_CODEC_MP3DEC -DCFG_AUDIO_CODEC_WAV -DCFG_AUDIO_CODEC_WMADEC -DCFG_AUDIO_CODEC_G711_ALAW -DCFG_STC_ENABLE -DCFG_VIDEO_ENABLE -DCFG_VIDEO_MAX_WIDTH=1920 -DCFG_VIDEO_MAX_HEIGHT=1088 -DCFG_VIDEO_BUFFER_PITCH=2048 -DCFG_VIDEO_DECODE_MODE=1 -DTWO_WAY_AUDIORECORD -DCFG_BUILD_ITV -DCFG_I2C0_ENABLE -DCFG_CAPTURE_MODULE_ENABLE -DCFG_CAPTURE_MODULE=pr2000.c -DCFG_CAPTURE_MODULE_NAME="pr2000.c" -DCFG_CAPTURE_WIDTH=1280 -DCFG_CAPTURE_HEIGHT=720 -DCFG_SECOND_CAPTURE_MODULE= -DCFG_SECOND_CAPTURE_MODULE_NAME="" -DCFG_SECOND_CAPTURE_WIDTH= -DCFG_SECOND_CAPTURE_HEIGHT= -DCFG_TILING_MODE_OFF -DCFG_BUILD_ITU -DCFG_SD0_ENABLE -DCFG_MMC_ENABLE -DCFG_NOR_ENABLE -DCFG_NOR_RESERVED_SIZE=0x200000 -DCFG_NOR_CACHE_SIZE=0x200000 -DCFG_NOR_CACHE_FLUSH_INTERVAL=0 -DCFG_MSC_ENABLE -DCFG_FS_FAT -DCFG_PRIVATE_DRIVE="A" -DCFG_PUBLIC_DRIVE="B" -DCFG_TEMP_DRIVE="D" -DCFG_RTC_ENABLE -DCFG_RTC_REDUCE_IO_ACCESS_ENABLE -DCFG_RTC_SYNC_PERIOD=1800 -DCFG_RTC_DEFAULT_TIMESTAMP=1483228800 -DCFG_I2C0_ENABLE -DCFG_HW_I2C_ENABLE -DCFG_I2C1_ENABLE -DCFG_HW_I2C_ENABLE -DCFG_SPI0_ENABLE -DCFG_SPI0_MOSI_GPIO=18 -DCFG_SPI0_MISO_GPIO=19 -DCFG_SPI0_CLOCK_GPIO=20 -DCFG_SPI0_CHIP_SEL_GPIO=14 -DCFG_I2S_ENABLE -DCFG_I2S_OUTPUT_PIN_ENABLE -DCFG_DAC_port_I2C0 -DCFG_SPI_ENABLE -DCFG_UART0_ENABLE -DCFG_UART0_BAUDRATE=9600 -DCFG_UART1_ENABLE -DCFG_UART1_BAUDRATE=115200 -DCFG_UART_INTR -DCFG_UART_BUF_SIZE=16384 -DCFG_USB0_ENABLE -DCFG_TOUCH_ENABLE -DCFG_TOUCH_MODULE_COUNT=1 -DCFG_TOUCH_I2C0 -DCFG_TOUCH_CAPACITIVE -DCFG_TOUCH_INTR -DCFG_TOUCH_X_MAX_VALUE=0x3FF -DCFG_TOUCH_Y_MAX_VALUE=0x257 -DCFG_POWER_STANDBY -DCFG_POWER_STANDBY_CPU_FREQ_RATIO=15 -DCFG_POWER_STANDBY_BUS_FREQ_RATIO=30 -DCFG_GPIO_SD0_CARD_DETECT=15 -DCFG_GPIO_SD0_POWER_ENABLE=8 -DCFG_GPIO_SD0_WRITE_PROTECT=-1 "-DCFG_GPIO_SD0_IO=16, 17, 18, 19, 20, 21, -1, -1, -1, -1" -DCFG_GPIO_BACKLIGHT_PWM=64 -DCFG_GPIO_UART0_TX=91 -DCFG_GPIO_UART0_RX=90 -DCFG_GPIO_UART1_TX=4 -DCFG_GPIO_UART1_RX=-1 -DCFG_GPIO_UART2_TX=101 -DCFG_GPIO_UART2_RX=102 -DCFG_GPIO_TOUCH_INT=96 -DCFG_GPIO_TOUCH_WAKE=-1 -DCFG_GPIO_TOUCH_RESET=97 -DCFG_GPIO_ETHERNET_LINK=97 -DCFG_IIC0_GPIO_CONFIG_1=y -DCFG_IIC1_GPIO_CONFIG_1=y -DCFG_I2S_USE_GPIO_MODE_1=y -DCFG_NET_ETHERNET_PHY_ADDR=-1 -DCFG_NET_ETHERNET_COUNT=1 -DCFG_TASK_DRIVE_PROBE -DCFG_DBG_PRINTBUF_SIZE=0 -DCFG_DBG_UART1 -DCFG_DBG_STATS -DCFG_DBG_STATS_PERIOD=10 -DCFG_DBG_STATS_HEAP -DCFG_UPGRADE_FILENAME="ITEPKG03.PKG" -DCFG_UPGRADE_FILENAME_LIST="ITEPKG03.PKG" -DCFG_UPGRADE_ENC_KEY=0 -DCFG_UPGRADE_OPEN_FILE -DCFG_UPGRADE_IMAGE_NOR -DCFG_UPGRADE_IMAGE_POS=0x80000 -DCFG_UPGRADE_DELETE_PKGFILE_AFTER_FINISH -DCFG_UPGRADE_DELAY_AFTER_FINISH=10 -DCFG_UPGRADE_USB_DETECT_TIMEOUT=300 -DCFG_UPGRADE_USB_TIMEOUT=8000 -DCFG_COMPRESS_AUDIO_PLUGIN -DCFG_BUILD_AUDIO_MGR -DCFG_AUDIO_MGR_PARSING_MP3 -DCFG_NORMAL_BUFFER_MODE -DCFG_BUILD_MINSIZEREL -DCFG_VERSION_MAJOR=1 -DCFG_VERSION_MINOR=2 -DCFG_VERSION_PATCH=3 -DCFG_VERSION_CUSTOM=1 -DCFG_VERSION_TWEAK= -DCFG_VERSION_MAJOR_STR="1" -DCFG_VERSION_MINOR_STR="2" -DCFG_VERSION_PATCH_STR="3" -DCFG_VERSION_CUSTOM_STR="1" -DCFG_VERSION_TWEAK_STR="" -DCFG_SYSTEM_NAME="ITE Display Control Board" -DCFG_MANUFACTURER="www.ite.com.tw" -DCFG_PROJECT_NAME="COMMAX_7.0H" -D__DYNAMIC_REENT__ -D__OPENRTOS__=1 -D_POSIX_BARRIERS -D_POSIX_C_SOURCE=200809L -D_POSIX_MONOTONIC_CLOCK -D_POSIX_PRIORITY_SCHEDULING=1 -D_POSIX_THREADS -D_POSIX_TIMERS -D_UNIX98_THREAD_MUTEX_ATTRIBUTES -DOSIP_MT -DCFG_GCC_LTO -DMALLOC_ALIGNMENT=32 -DCFG_OPENRTOS_HEAP_SIZE=0 -DCFG_MMAP_SIZE=0 -DCFG_LCDC_HEIGHT=600 -DCFG_LCDC_PITCH=2048 -c -o D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/lib/fa626/argb2yuv.o D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/openrtos/boot/fa626/argb2yuv.s

argb2yuv.o: openrtos/boot/CMakeFiles/argb2yuv.o
argb2yuv.o: lib/fa626/argb2yuv.o
argb2yuv.o: openrtos/boot/CMakeFiles/argb2yuv.o.dir/build.make
.PHONY : argb2yuv.o

# Rule to build all files generated by this target.
openrtos/boot/CMakeFiles/argb2yuv.o.dir/build: argb2yuv.o
.PHONY : openrtos/boot/CMakeFiles/argb2yuv.o.dir/build

openrtos/boot/CMakeFiles/argb2yuv.o.dir/clean:
	cd D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/openrtos/boot && $(CMAKE_COMMAND) -P CMakeFiles/argb2yuv.o.dir/cmake_clean.cmake
.PHONY : openrtos/boot/CMakeFiles/argb2yuv.o.dir/clean

openrtos/boot/CMakeFiles/argb2yuv.o.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/openrtos/boot D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/openrtos/boot D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/COMMAX_7.0H/openrtos/boot/CMakeFiles/argb2yuv.o.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openrtos/boot/CMakeFiles/argb2yuv.o.dir/depend

