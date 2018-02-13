add_executable(${CMAKE_PROJECT_NAME}
    test_$ENV{CFG_PLATFORM}.c
    )

if (DEFINED CFG_TEST_FAT)
    include_directories(
        ${PROJECT_SOURCE_DIR}/sdk/share/fat/common
        )
    add_executable(${CMAKE_PROJECT_NAME}
        fat/testdrv_f.c
        fat/testdrv_f.h
        fat/testport_f.c
        fat/test_f.c
        fat/test_f.h
        fat/test_fat.c
        )
elseif (DEFINED CFG_TEST_DRIVE)
    add_executable(${CMAKE_PROJECT_NAME}
        test_drive.c
        )
elseif (DEFINED CFG_TEST_FILESYSTEM)
    add_executable(${CMAKE_PROJECT_NAME}
        test_fs.c
        )
elseif (DEFINED CFG_TEST_NTFS)
    add_executable(${CMAKE_PROJECT_NAME}
        test_ntfs.c
        )
endif()

# build
include(${PROJECT_SOURCE_DIR}/sdk/build.cmake)
