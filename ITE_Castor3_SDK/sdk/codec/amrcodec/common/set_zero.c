﻿/*
********************************************************************************
*      GSM AMR-NB speech codec   R98   Version 7.6.0   December 12, 2001
*                                R99   Version 3.3.0
*                                REL-4 Version 4.1.0
*
********************************************************************************
*
*      File             : set_zero.h
*
********************************************************************************
*/
/*
********************************************************************************
*                         MODULE INCLUDE FILE AND VERSION ID
********************************************************************************
*/
#include "set_zero.h"
const char set_zero_id[] = "@(#)$Id $" set_zero_h;

/*
********************************************************************************
*                         INCLUDE FILES
********************************************************************************
*/
#include "typedef.h"
#include "basic_op.h"
//#include "count.h"

/*
********************************************************************************
*                         PUBLIC PROGRAM CODE
********************************************************************************
*/
void Set_zero (
    Word16 x[],         /* (o)    : vector to clear     */
    Word16 L            /* (i)    : length of vector    */
)
{
    Word32 i;

    for (i = 0; i < L; i++)
    {
        x[i] = 0;
    }

    return;
}
