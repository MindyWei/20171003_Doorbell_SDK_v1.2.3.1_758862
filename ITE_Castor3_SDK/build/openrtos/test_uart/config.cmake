#
# Automatically generated file; DO NOT EDIT.
# Project Configuration
# Tue Oct 31 14:11:50 2017
#
#
set(CFG_TEST_UART y)
set(CFG_DEF_CHIP_PKG_IT9856 y)
set(CFG_RAM_INIT_SCRIPT "IT9850A0_400MHz.scr")
# CFG_FS_FAT is not set
set(CFG_UART0_ENABLE y)
set(CFG_UART1_ENABLE y)
set(CFG_GPIO_UART1_TX "4")
set(CFG_GPIO_UART1_RX "-1")
set(CFG_NOR_ENABLE y)
set(CFG_SPI_ENABLE y)
set(CFG_SPI0_MOSI_GPIO "18")
set(CFG_SPI0_MISO_GPIO "19")
set(CFG_SPI0_CLOCK_GPIO "20")
set(CFG_SPI0_CHIP_SEL_GPIO "14")
set(CFG_DEF_DBG_UART1 y)
set(CFG_UART_INTR y)
set(CFG_DBG_INIT_SCRIPT "IT9850A0_400MHz.txt")

#
# (unvisible)
#
set(CFG_DEF_CFG_RELEASE y)

#
# (unvisible)
#

#
# Develop Environment
#
# CFG_DEV_DEVELOP is not set
set(CFG_DEV_RELEASE y)
# CFG_BOOTLOADER_ENABLE is not set

#
# OpenRTOS
#
set(CFG_GCC_LTO y)
set(CFG_OPENRTOS_HEAP_SIZE "0")
set(CFG_MMAP_SIZE "0")

#
# System
#
set(CFG_CPU_FA626 y)
# CFG_CPU_SM32 is not set
# CFG_CHIP_PKG_IT9079 is not set
# CFG_CHIP_PKG_IT9852 is not set
# CFG_CHIP_PKG_IT9854 is not set
set(CFG_CHIP_PKG_IT9856 y)
# CFG_CHIP_PKG_IT9910 is not set
# CFG_CHIP_PKG_IT9920 is not set
set(CFG_RAM_SIZE "0x4000000")
set(CFG_FONT_FILENAME "WenQuanYiMicroHeiMono.ttf")
# CFG_WATCHDOG_ENABLE is not set
# CFG_EXT_WATCHDOG_ENABLE is not set

#
# Internal Settings
#
set(CFG_MEMDBG_ENABLE y)
set(CFG_ROM_COMPRESS y)
# CFG_DCPS_ENABLE is not set
# CFG_DPU_ENABLE is not set
# CFG_SPREAD_SPECTRUM_PLL1_ENABLE is not set
# CFG_SPREAD_SPECTRUM_PLL2_ENABLE is not set
# CFG_SPREAD_SPECTRUM_PLL3_ENABLE is not set
set(CFG_CPU_WB y)
# CFG_XCPU_MSGQ is not set

#
# Screen (unvisible)
#

#
# Internal Setting (unvisible)
#

#
# Graphics (unvisible)
#

#
# Audio (unvisible)
#

#
# Video (unvisible)
#

#
# Storage
#
# CFG_NAND_ENABLE is not set
set(CFG_NOR_CACHE_SIZE "0")
set(CFG_NOR_CACHE_FLUSH_INTERVAL "0")
# CFG_NOR_SHARE_GPIO is not set
# CFG_SD0_ENABLE is not set
# CFG_SD1_ENABLE is not set
# CFG_RAMDISK_ENABLE is not set

#
# File System
#
# CFG_FS_NTFS is not set
set(CFG_NOR_RESERVED_SIZE "0")
# CFG_NOR_PARTITION0 is not set
set(CFG_PRIVATE_DRIVE "A")
set(CFG_PUBLIC_DRIVE "B")
set(CFG_TEMP_DRIVE "C")

#
# Peripheral
#
# CFG_RTC_ENABLE is not set
set(CFG_RTC_DEFAULT_TIMESTAMP "1325376000")
# CFG_I2C0_ENABLE is not set
# CFG_I2C1_ENABLE is not set
# CFG_I2S_ENABLE is not set
set(CFG_SPI0_ENABLE y)
# CFG_SPI0_40MHZ_ENABLE is not set
# CFG_SPI1_ENABLE is not set
# CFG_RGBTOMIPI_ENABLE is not set
# CFG_WIEGAND_ENABLE is not set
# CFG_SW_WIEGAND_ENABLE is not set
# CFG_TV_ENCODER_ENABLE is not set
# CFG_CAPTURE_MODULE_ENABLE is not set
# CFG_IOEX_ENABLE is not set
# CFG_GPIO_EXPANDER_ENABLE is not set
set(CFG_UART0_BAUDRATE "115200")
set(CFG_UART1_BAUDRATE "115200")
# CFG_UART2_ENABLE is not set
# CFG_UART3_ENABLE is not set
set(CFG_UART_BUF_SIZE "16384")
# CFG_UART_DMA is not set
set(CFG_UART_FORCE_FLUSH y)
# CFG_RS485_0_ENABLE is not set
# CFG_RS485_1_ENABLE is not set
# CFG_RS485_2_ENABLE is not set
# CFG_RS485_3_ENABLE is not set
# CFG_RS485_4_ENABLE is not set
# CFG_SWUART_CODEC_ENABLE is not set
# CFG_USB0_ENABLE is not set
# CFG_USB1_ENABLE is not set
# CFG_IRDA_ENABLE is not set
# CFG_IR_ENABLE is not set
# CFG_KEYPAD_ENABLE is not set
# CFG_TOUCH_ENABLE is not set
# CFG_BATTERY_ENABLE is not set
# CFG_GSENSOR_ENABLE is not set
# CFG_HEADSET_ENABLE is not set
# CFG_SPEAKER_ENABLE is not set
# CFG_AMPLIFIER_ENABLE is not set
# CFG_LED_ENABLE is not set
# CFG_SWITCH_ENABLE is not set
# CFG_TUNER_ENABLE is not set
# CFG_FM2018_ENABLE is not set
# CFG_AUDIOAMP_ENABLE is not set
# CFG_SENSOR_ENABLE is not set

#
# Power
#
# CFG_POWER_ON is not set
# CFG_POWER_SAVING_ENABLE is not set
# CFG_POWER_DOZE is not set
# CFG_POWER_TICKLESS_IDLE is not set

#
# GPIO
#
set(CFG_GPIO_UART0_TX "101")
set(CFG_GPIO_UART0_RX "102")
# CFG_PWM_GPIO_SET is not set

#
# Network
#
# CFG_NET_ENABLE is not set

#
# (unvisible)
#

#
# (unvisible)
#

#
# Task
#

#
# Debug
#
# CFG_DBG_NONE is not set
# CFG_DBG_PRINTBUF is not set
# CFG_DBG_SWUART_CODEC is not set
# CFG_DBG_UART0 is not set
set(CFG_DBG_UART1 y)
set(CFG_DBG_ICE_SCRIPT "IT9070A1_Initial_DDR2_Mem_tiling_pitch2048_320MHZ.csf")
# CFG_DBG_MEMLEAK is not set
# CFG_DBG_RMALLOC is not set
# CFG_DBG_STATS is not set
# CFG_DBG_TRACE_ANALYZER is not set
# CFG_DBG_CLI is not set
# CFG_ENABLE_UART_CLI is not set

#
# Upgrade
#
# CFG_UPGRADE_BOOTLOADER is not set
# CFG_UPGRADE_IMAGE is not set
# CFG_UPGRADE_DATA is not set
set(CFG_UPGRADE_ENC_KEY "0")
set(CFG_UPGRADE_FILENAME "ITEPKG03.PKG")
set(CFG_UPGRADE_FILENAME_LIST "ITEPKG03.PKG")

#
# SDK
#
# CFG_BUILD_DEBUG is not set
# CFG_BUILD_DEBUGREL is not set
set(CFG_BUILD_RELEASE y)
# CFG_BUILD_MINSIZEREL is not set
set(CFG_VERSION_MAJOR "1")
set(CFG_VERSION_MINOR "2")
set(CFG_VERSION_PATCH "3")
set(CFG_VERSION_CUSTOM "1")
set(CFG_SYSTEM_NAME "ITE Castor3")
set(CFG_MANUFACTURER "www.ite.com.tw")
# CFG_GENERATE_DOC is not set
# CFG_GENERATE_VERSION_TWEAK is not set

#
# Drivers
#

#
# ith
#
set(CFG_ITH_ERR y)
set(CFG_ITH_WARN y)
set(CFG_ITH_INFO y)
# CFG_ITH_DBG is not set
# CFG_ITH_FPGA is not set

#
# itp
#
set(CFG_ITP_ERR y)
set(CFG_ITP_WARN y)
set(CFG_ITP_INFO y)
# CFG_ITP_DBG is not set

#
# Libraries
#

#
# (unvisible)
#

#
# dhcps (unvisible)
#

#
# ffmpeg (unvisible)
#

#
# (unvisible)
#

#
# itc (unvisible)
#

#
# (unvisible)
#

#
# itu (unvisible)
#

#
# (unvisible)
#

#
# upgrade (unvisible)
#
