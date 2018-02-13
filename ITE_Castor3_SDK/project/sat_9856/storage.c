﻿#include <sys/ioctl.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ite/itp.h"
//#include "doorbell.h"
#include "scene.h"
#include "function_user.h"

static ITPDriveStatus* storageTable[STORAGE_MAX_COUNT];
static StorageType storageCurrType;

void StorageInit(void)
{
    int i;

    for (i = 0; i < STORAGE_MAX_COUNT; i++)
        storageTable[i] = NULL;

    storageCurrType = STORAGE_NONE;
}

StorageAction StorageCheck(void)
{
    ITPDriveStatus* driveStatusTable;
    ITPDriveStatus* driveStatus = NULL;
    int i;

    // try to find the package drive
    ioctl(ITP_DEVICE_DRIVE, ITP_IOCTL_GET_TABLE, &driveStatusTable);

    for (i = 0; i < ITP_MAX_DRIVE; i++)
    {
        driveStatus = &driveStatusTable[i];
        if (driveStatus->disk >= ITP_DISK_SD0 && driveStatus->disk <= ITP_DISK_SD1)
        {
            if (driveStatus->avail && !storageTable[STORAGE_SD])
            {
                printf("SD #%d inserted: %s\n", driveStatus->disk - ITP_DISK_SD0, driveStatus->name);

                storageTable[STORAGE_SD] = driveStatus;

                if (storageCurrType == STORAGE_NONE)
                    storageCurrType = STORAGE_SD;

                return STORAGE_SD_INSERTED;
            }
            else if (!driveStatus->avail && storageTable[STORAGE_SD] == driveStatus)
            {
                printf("SD #%d removed: %s\n", driveStatus->disk - ITP_DISK_SD0, driveStatus->name);

                storageTable[STORAGE_SD] = NULL;

                if (storageCurrType == STORAGE_SD)
                {
                    if (storageTable[STORAGE_USB])
                        storageCurrType = STORAGE_USB;
                    else
                        storageCurrType = STORAGE_NONE;
                }
                return STORAGE_SD_REMOVED;
            }
        }
        else if (driveStatus->disk >= ITP_DISK_MSC00 && driveStatus->disk <= ITP_DISK_MSC17)
        {
            if (driveStatus->avail && !storageTable[STORAGE_USB])
            {
                printf("USB #%d inserted: %s\n", driveStatus->disk - ITP_DISK_MSC00, driveStatus->name);

                storageTable[STORAGE_USB] = driveStatus;

                if (storageCurrType == STORAGE_NONE)
                    storageCurrType = STORAGE_USB;

                return STORAGE_USB_INSERTED;
            }
            else if (!driveStatus->avail && storageTable[STORAGE_USB] == driveStatus)
            {
                printf("USB #%d removed: %s\n", driveStatus->disk - ITP_DISK_MSC00, driveStatus->name);

                storageTable[STORAGE_USB] = NULL;

                if (storageCurrType == STORAGE_USB)
                {
                    if (storageTable[STORAGE_SD])
                        storageCurrType = STORAGE_SD;
                    else
                        storageCurrType = STORAGE_NONE;
                }
                return STORAGE_USB_REMOVED;
            }
        }
    }
    return STORAGE_UNKNOWN;
}

StorageType StorageGetCurrType(void)
{
    return storageCurrType;
}

void StorageSetCurrType(StorageType type)
{
    storageCurrType = type;
}

char* StorageGetDrivePath(StorageType type)
{
    ITPDriveStatus* driveStatus;

    if (type == STORAGE_NONE)
        return NULL;

    driveStatus = storageTable[type];

    if (driveStatus)
        return driveStatus->name;

    return NULL;
}