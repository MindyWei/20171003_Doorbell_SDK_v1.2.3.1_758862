#include <sys/ioctl.h>
#include <assert.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "ite/itp.h"

#define TEST_STACK_SIZE 10240

static void* drive_probe_task(void* arg)
{
    // init drives
    itpDriveInit();

    // mount/unmount cards when it's inserted/removed
    for (;;)
    {
#ifdef CFG_GPIO_CARD_DETECT_INTR
        // card detect by interrupt
        sem_wait(&itpCardDetectSemaphore);

#else
        // card detect by polling
        sleep(1);
#endif // CFG_GPIO_CARD_DETECT_INTR

        itpDriveProbe();
    }

    return NULL;
}

void* TestFunc(void* arg)
{
    pthread_t task;
    pthread_attr_t attr;
    
    // init pal
    itpInit();
    
    // create drive probe task
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, TEST_STACK_SIZE);

    pthread_create(&task, &attr, drive_probe_task, NULL);
    
    // init fat on this task
    ioctl(ITP_DEVICE_FAT, ITP_IOCTL_ENABLE, NULL);
    
    // do the test
    for (;;)
    {
        sleep(1);
    }
}
