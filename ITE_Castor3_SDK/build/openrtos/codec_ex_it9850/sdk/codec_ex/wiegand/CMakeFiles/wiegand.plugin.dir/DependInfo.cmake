# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "C"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_C
  "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec_ex/wiegand/ith_clock.c" "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_ex_it9850/sdk/codec_ex/wiegand/CMakeFiles/wiegand.plugin.dir/ith_clock.c.obj"
  "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec_ex/wiegand/main.c" "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_ex_it9850/sdk/codec_ex/wiegand/CMakeFiles/wiegand.plugin.dir/main.c.obj"
  "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec_ex/wiegand/swuart.c" "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_ex_it9850/sdk/codec_ex/wiegand/CMakeFiles/wiegand.plugin.dir/swuart.c.obj"
  "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec_ex/wiegand/treadmill.c" "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_ex_it9850/sdk/codec_ex/wiegand/CMakeFiles/wiegand.plugin.dir/treadmill.c.obj"
  "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/sdk/codec_ex/wiegand/wiegand.c" "D:/Project/Doorbell/20171003_Doorbell_SDK_v1.2.3.1_758862/ITE_Castor3_SDK/build/openrtos/codec_ex_it9850/sdk/codec_ex/wiegand/CMakeFiles/wiegand.plugin.dir/wiegand.c.obj"
  )
set(CMAKE_C_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS
  "AUDIO_PLUGIN_MESSAGE_QUEUE"
  "CFG_AEC_DELAY_MS=60"
  "CFG_AUDIO_CODEC_AACDEC"
  "CFG_AUDIO_CODEC_AMR"
  "CFG_AUDIO_CODEC_EAC3DEC"
  "CFG_AUDIO_CODEC_FLACDEC"
  "CFG_AUDIO_CODEC_MP3DEC"
  "CFG_AUDIO_CODEC_SBC"
  "CFG_AUDIO_CODEC_WAV"
  "CFG_AUDIO_CODEC_WMADEC"
  "CFG_AUDIO_ENABLE"
  "CFG_AUDIO_SAMPLING_RATE=8000"
  "CFG_BUILD_RELEASE"
  "CFG_CHIP_FAMILY=9070"
  "CFG_CHIP_PKG_IT9078"
  "CFG_CHIP_REV_A1"
  "CFG_CMDQ_SIZE=0"
  "CFG_DBG_PRINTBUF"
  "CFG_DBG_PRINTBUF_SIZE=0x1000"
  "CFG_EQUALIZER_MICGAIN_SET=NULL"
  "CFG_EQUALIZER_SPKGAIN_SET=NULL"
  "CFG_GPIO_ETHERNET_LINK=-1"
  "CFG_LCD_BPP=0"
  "CFG_LCD_HEIGHT=0"
  "CFG_LCD_PITCH=0"
  "CFG_LCD_WIDTH=0"
  "CFG_MANUFACTURER=\"\""
  "CFG_MIC_GAIN=0"
  "CFG_NET_ETHERNET_COUNT=1"
  "CFG_NET_ETHERNET_PHY_ADDR=-1"
  "CFG_NOISE_GATE_THRESHOLD=0.3"
  "CFG_NORMAL_BUFFER_MODE"
  "CFG_OPENRTOS_HEAP_SIZE="
  "CFG_OSC_CLK=30000000"
  "CFG_PRIVATE_DRIVE=\"A\""
  "CFG_PROJECT_NAME=\"codec_ex_it9850\""
  "CFG_PUBLIC_DRIVE=\"B\""
  "CFG_RAM_SIZE=0x4000000"
  "CFG_RISC_TS_DEMUX_PLUGIN"
  "CFG_RTC_DEFAULT_TIMESTAMP=1325376000"
  "CFG_RTC_EXTCLK=32768"
  "CFG_SPEAKER_GAIN=0"
  "CFG_SYSTEM_NAME=\"ITE Castor3\""
  "CFG_TEMP_DRIVE=\"\""
  "CFG_UPGRADE_ENC_KEY=0"
  "CFG_UPGRADE_FILENAME=\"ITEPKG03.PKG\""
  "CFG_UPGRADE_FILENAME_LIST=\"\""
  "CFG_VERSION_CUSTOM=0"
  "CFG_VERSION_CUSTOM_STR=\"0\""
  "CFG_VERSION_MAJOR=0"
  "CFG_VERSION_MAJOR_STR=\"0\""
  "CFG_VERSION_MINOR=1"
  "CFG_VERSION_MINOR_STR=\"1\""
  "CFG_VERSION_PATCH=0"
  "CFG_VERSION_PATCH_STR=\"0\""
  "CFG_VERSION_TWEAK="
  "CFG_VERSION_TWEAK_STR=\"\""
  "CFG_WT_SIZE=0"
  "CONFIG_ITADRIVER"
  "ENABLE_CODECS_PLUGIN"
  "ENABLE_WIEGAND_PLUGIN=1"
  "HAVE_CONFIG_H"
  "ORTP_BIGENDIAN"
  "OSIP_MT"
  "_POSIX_BARRIERS"
  "_POSIX_C_SOURCE=200809L"
  "_POSIX_MONOTONIC_CLOCK"
  "_POSIX_PRIORITY_SCHEDULING=1"
  "_POSIX_THREADS"
  "_POSIX_TIMERS"
  "_UNIX98_THREAD_MUTEX_ATTRIBUTES"
  "__DYNAMIC_REENT__"
  "__OPENRTOS__=1"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# The include file search paths:
set(CMAKE_C_TARGET_INCLUDE_PATH
  "../../../openrtos/include"
  "../../../sdk/include"
  )
set(CMAKE_CXX_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_Fortran_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_ASM_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
