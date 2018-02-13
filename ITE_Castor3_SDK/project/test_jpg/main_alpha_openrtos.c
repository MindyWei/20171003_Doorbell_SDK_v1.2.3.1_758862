﻿
#include <pthread.h>
#include "openrtos/FreeRTOS.h"
#include "openrtos/task.h"

//=============================================================================
//				  Constant Definition
//=============================================================================
#define TEST_STACK_SIZE 1024000

//=============================================================================
//				  Macro Definition
//=============================================================================


//=============================================================================
//				  Structure Definition
//=============================================================================


//=============================================================================
//				  Global Data Definition
//=============================================================================


//=============================================================================
//				  Private Function Definition
//=============================================================================

extern void Test_Proc(void);
//=============================================================================
//				  Public Function Definition
//=============================================================================
int main(void)
{
    pthread_t task;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    attr.stacksize = TEST_STACK_SIZE;

    pthread_create(&task, &attr, Test_Proc, NULL);

    /* Now all the tasks have been started - start the scheduler. */
    vTaskStartScheduler();

    /* Should never reach here! */
    return 0;
}

