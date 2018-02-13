#
# Automatically generated file; DO NOT EDIT.
# Project Configuration
# Wed Jan 31 14:07:54 2018
#
#
set(CFG_TEST_ITU y)
set(CFG_LCD_ENABLE y)
set(CFG_I2S_ENABLE y)
# CFG_I2S_SPDIF_ENABLE is not set
set(CFG_AUDIO_ENABLE y)
set(CFG_VIDEO_ENABLE y)
set(CFG_FFMPEG_H264_SW y)
set(CFG_ITU_UCL_ENABLE y)
set(CFG_WIN32_SIMULATOR y)
set(CFG_ITU_FT_CACHE_ENABLE y)
set(CFG_BUILD_AUDIO_MGR y)
set(CFG_BUILD_ITU y)
set(CFG_BUILD_SDL y)
set(CFG_HAVE_LCD y)
set(CFG_HAVE_GRAPHICS y)
set(CFG_HAVE_AUDIO y)
set(CFG_HAVE_VIDEO y)

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
# Win32
#
# CFG_WIN32_FS_HW is not set
set(CFG_TEMP_DRIVE "T")

#
# System
#
set(CFG_CPU_FA626 y)
# CFG_CPU_SM32 is not set
set(CFG_CHIP_PKG_IT9079 y)
# CFG_CHIP_PKG_IT9852 is not set
# CFG_CHIP_PKG_IT9854 is not set
# CFG_CHIP_PKG_IT9856 is not set
# CFG_CHIP_PKG_IT9910 is not set
# CFG_CHIP_PKG_IT9920 is not set
set(CFG_RAM_SIZE "0x4000000")
set(CFG_RAM_INIT_SCRIPT "IT9079A1_Initial_DDR2_Mem_tiling_pitch2048_320MHZ.scr")
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
# CFG_XCPU_MSGQ is not set

#
# Screen
#
# CFG_ENABLE_ROTATE is not set
set(CFG_LCD_WIDTH "800")
set(CFG_LCD_HEIGHT "600")
set(CFG_LCD_PITCH "1600")
set(CFG_LCD_BPP "2")
set(CFG_LCD_INIT_SCRIPT "IT9850_LCD_800_480_innolux_7inch_565.txt.in")
set(CFG_LCD_TRIPLE_BUFFER y)
# CFG_HDMI_OUT_ENABLE is not set
# CFG_BL_SHOW_LOGO is not set
# CFG_BACKLIGHT_ENABLE is not set
# CFG_STNLCD_ENABLE is not set

#
# Internal Setting
#
# CFG_TVOUT_ENABLE is not set

#
# Graphics
#
# CFG_CMDQ_ENABLE is not set
# CFG_JPEG_HW_ENABLE is not set

#
# Audio
#
set(CFG_AUDIO_DAC_MODULE "itp_dac_null.c")
# CFG_DIALOGUE_PARAMETER_SET is not set
# CFG_AUDIO_CODEC_AACDEC is not set
# CFG_AUDIO_CODEC_AC3DEC is not set
# CFG_AUDIO_CODEC_AC3SPDIF is not set
# CFG_AUDIO_CODEC_AMR is not set
# CFG_AUDIO_CODEC_EAC3DEC is not set
# CFG_AUDIO_CODEC_MP3DEC is not set
# CFG_AUDIO_CODEC_MP2DEC is not set
# CFG_AUDIO_CODEC_WAV is not set
# CFG_AUDIO_CODEC_WMADEC is not set
# CFG_AUDIO_CODEC_FLACDEC is not set
# CFG_AUDIO_CODEC_G711_ALAW is not set
# CFG_AUDIO_CODEC_G711_ULAW is not set
# CFG_RISC_TS_DEMUX_PLUGIN is not set
# CFG_COMPRESS_AUDIO_PLUGIN is not set
# CFG_AUDIO_MGR_M4A is not set
# CFG_AUDIO_MGR_WAV_HD is not set
# CFG_AUDIO_MGR_LRC is not set
# CFG_AUDIO_MGR_RESAMPLE is not set
# CFG_AUDIO_MGR_PARSING_MP3 is not set

#
# Video
#
# CFG_TS_MODULE_ENABLE is not set
# CFG_MJPEG_DEC_ENABLE is not set

#
# Storage
#
# CFG_NAND_ENABLE is not set
# CFG_NOR_ENABLE is not set
# CFG_NOR_SHARE_GPIO is not set
# CFG_SD0_ENABLE is not set
# CFG_SD1_ENABLE is not set
# CFG_RAMDISK_ENABLE is not set

#
# File System
#
set(CFG_PRIVATE_DRIVE "A")
set(CFG_PUBLIC_DRIVE "B")

#
# Peripheral
#
# CFG_RTC_ENABLE is not set
set(CFG_RTC_DEFAULT_TIMESTAMP "1325376000")
# CFG_I2C0_ENABLE is not set
set(CFG_I2S_OUTPUT_PIN_ENABLE y)
set(CFG_SPI_ENABLE y)
set(CFG_SPI0_ENABLE y)
# CFG_SPI0_40MHZ_ENABLE is not set
# CFG_SPI1_ENABLE is not set
# CFG_RGBTOMIPI_ENABLE is not set
# CFG_WIEGAND_ENABLE is not set
# CFG_TV_ENCODER_ENABLE is not set
# CFG_CAPTURE_MODULE_ENABLE is not set
# CFG_IOEX_ENABLE is not set
# CFG_GPIO_EXPANDER_ENABLE is not set
# CFG_UART0_ENABLE is not set
# CFG_UART1_ENABLE is not set
# CFG_UART2_ENABLE is not set
# CFG_UART3_ENABLE is not set
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
set(CFG_DBG_PRINTBUF y)
# CFG_DBG_SWUART_CODEC is not set
# CFG_DBG_LCDCONSOLE is not set
# CFG_DBG_OSDCONSOLE is not set
set(CFG_DBG_INIT_SCRIPT "IT9079A1_Initial_DDR2_Mem_tiling_pitch2048_320MHZ.txt")
set(CFG_DBG_ICE_SCRIPT "IT9070A1_Initial_DDR2_Mem_tiling_pitch2048_320MHZ.csf")
set(CFG_DBG_PRINTBUF_SIZE "0x10000")
# CFG_DBG_BLUESCREEN is not set
# CFG_DBG_MEMLEAK is not set
# CFG_DBG_RMALLOC is not set
# CFG_DBG_STATS is not set
# CFG_DBG_TRACE_ANALYZER is not set
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
set(CFG_BUILD_ITC y)
set(CFG_BUILD_ZLIB y)

#
# ffmpeg
#
# CFG_FFMPEG_ENC is not set

#
# (unvisible)
#

#
# itc
#
set(CFG_ITC_ERR y)
set(CFG_ITC_WARN y)
set(CFG_ITC_INFO y)
# CFG_ITC_DBG is not set

#
# (unvisible)
#

#
# itu
#
set(CFG_ITU_ERR y)
set(CFG_ITU_WARN y)
set(CFG_ITU_INFO y)
# CFG_ITU_DBG is not set
# CFG_ITU_LOAD is not set
# CFG_ITU_UPDATE is not set
# CFG_ITU_DRAW is not set
set(CFG_ITU_FT_CACHE_SIZE "0x7D000")
# CFG_ITU_ASSERT_THREAD is not set
set(CFG_BUILD_FFMPEG y)
set(CFG_BUILD_FREETYPE y)
set(CFG_BUILD_JPEG y)
set(CFG_BUILD_PNG y)
set(CFG_BUILD_REDBLACK y)
set(CFG_BUILD_UCL y)

#
# (unvisible)
#

#
# upgrade (unvisible)
#

#
# ITU Test
#
# CFG_TEST_SDL is not set
# CFG_TEST_STNLCD is not set
# CFG_TEST_HELLOWORLD is not set
# CFG_TEST_BUTTON is not set
set(CFG_TEST_LANGUAGE y)
# CFG_TEST_CURSOR is not set
# CFG_TEST_PROGRESSBAR is not set
# CFG_TEST_LISTBOX is not set
# CFG_TEST_TRACKBAR is not set
# CFG_TEST_ARRAY is not set
# CFG_TEST_JPEG is not set
# CFG_TEST_MULTILINE is not set
# CFG_TEST_COMPRESS is not set
# CFG_TEST_FUNCTION is not set
# CFG_TEST_LISTBOX2 is not set
# CFG_TEST_CUSTOM is not set
# CFG_TEST_ICONLISTBOX is not set
# CFG_TEST_CIRCLEPROGRESSBAR is not set
# CFG_TEST_DRAW is not set
# CFG_TEST_SCROLLBAR is not set
# CFG_TEST_WHEEL is not set
# CFG_TEST_COVERFLOW is not set
# CFG_TEST_SCROLLLISTBOX is not set
# CFG_TEST_METER is not set
# CFG_TEST_VIDEO is not set
# CFG_TEST_COLORPICKER is not set
# CFG_TEST_IMAGECOVERFLOW is not set
# CFG_TEST_CURVE is not set
# CFG_TEST_TABLELISTBOX is not set
# CFG_TEST_PNG is not set
# CFG_TEST_TABLEICONLISTBOX is not set
# CFG_TEST_MULTIFONT is not set
# CFG_TEST_CLONE is not set
# CFG_TEST_TABLELISTBOX2 is not set
# CFG_TEST_ANIMPAGE is not set
# CFG_TEST_BITBLT is not set
# CFG_TEST_FILESLIDESHOW is not set
# CFG_TEST_SHOWLOGO is not set
