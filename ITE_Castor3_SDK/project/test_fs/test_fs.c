#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "ite/itp.h"

#define BUF_SIZE 512

void* TestFunc(void* arg)
{
    int ret, i;
    FILE *f1, *f2;
    static unsigned char buf[BUF_SIZE];
    ITPDriveStatus* driveStatusTable;
        
    // init pal
    itpInit();

    ioctl(ITP_DEVICE_DRIVE, ITP_IOCTL_GET_TABLE, &driveStatusTable);
    
    while (1)
    {
        ITPDriveStatus* driveStatus = &driveStatusTable[0]; // 0 is A:, 1 is B:, ...
        printf("drive A: avail=%d\n", driveStatus->avail);
        if (driveStatus->avail)
            break;

        sleep(1);
    }
    
    f1 = fopen("A:/test.bin", "rb");
    printf("fopen()=0x%X\n", f1);
    ret = fread(buf, 1, BUF_SIZE, f1);
    printf("read %d bytes: %02X %02X %02X %02X %02X %02X %02X %02X ...\n", ret, buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);

    f2 = fopen("A:/write.bin", "wb");
    ret = fwrite(buf, 1, BUF_SIZE, f2);
    printf("write %d bytes\n", ret);

    ret = fclose(f2);
    if (ret)
        printf("fclose fail: %d\n", ret);

    ret = fclose(f1);
    if (ret)
        printf("fclose fail: %d\n", ret);

    return NULL;
}
