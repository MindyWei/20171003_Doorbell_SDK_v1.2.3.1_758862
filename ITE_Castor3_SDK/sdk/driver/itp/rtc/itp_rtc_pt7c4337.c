/*
 * Copyright (c) 2011 ITE Tech. Inc. All Rights Reserved.
 */
/** @file
 * PAL RTC software functions.
 *
 * @author Joseph Chang
 * @version 1.0
 */
#include <time.h>
#include "../itp_cfg.h"

//#define ENABLE_DBG_MSG
/********************************************
 * MACRO defination
 ********************************************/
#define IIC_RTC_ID          (0xD0>>1)
 
/* the defination of tm structure ***********
struct tm
{
	int tm_sec;		//0-59
	int tm_min;		//0-59
	int tm_hour;	//0-23
	int tm_mday;	//1-31
	int tm_mon;		//0-11
	int tm_year;	//00-99(from 1900)
	int tm_wday;	//0-6(0:sun 1:mon 2:...)
}
*********************************************/

/* the defination of pt7c4337's register *****
REG[0] : Seconds (00-59)
REG[1] : Minutes (00-59)
REG[2] : Hours (00-23)
REG[3] : week (1-7, 1:sun 2:mon 3:...)
REG[4] : Dates (1-31)
REG[5] : Months (1-12)
REG[6] : Years (00-99)
REG[7~15] : ...
*********************************************/

/********************************************
 * global variable
 ********************************************/
static struct tm tInfo;
static int	gRtcFd=-1;
static bool rtc_reset = false;

static long	gLastSyncSec = 0;

#ifdef	ENABLE_DBG_MSG
static int	gEnMsgCnt=0;
#endif

/********************************************
 * Private function protocol
 ********************************************/
static long _extRtcGetTime();

/********************************************
 * Private function 
 ********************************************/
static uint8_t pt7c4337_i2c_read(uint8_t slaveAddr,uint8_t regAddr)
{
	uint8_t val;
	mmpIicReceiveData(0, 1, slaveAddr>>1, &regAddr, 1,&val, 1);
	usleep(10);
	return val;
}
static void pt7c4337_i2c_write(uint8_t slaveAddr,uint8_t regAddr,uint8_t val)
{
	//printf("%x------------>%x\n",regAddr,val);
	mmpIicSendData(0, 1, slaveAddr>>1, regAddr, &val,1);
	usleep(10);
	return;
}

static uint8_t RTC_ITE(uint8_t byte)
{
	uint8_t B1 = (byte>>4);
	uint8_t B2 = (byte&0xF);

	return (B1*10) + B2;
}

static uint8_t ITE_RTC(uint8_t dec)
{
	uint8_t B1 = dec/10;
	uint8_t B2 = dec%10;

	return (B1<<4) | B2;
}

static long _extRtcGetTime(void)
{
	uint8_t data[7];
	long rtcSec=0;
	int i;
	for(i = 0; i < 0x7; i++)
	{
		data[i] = pt7c4337_i2c_read(0xD0,0x00+i);
		//printf("----------------------->0x%x\n",data[i]);
	}

	tInfo.tm_sec = RTC_ITE(data[0] & 0x7F);	//sec:0~59
	tInfo.tm_min = RTC_ITE(data[1] & 0x7F);	//min:0~59
	tInfo.tm_hour = RTC_ITE(data[2] & 0x3F);	//hour:0~23
	tInfo.tm_wday = (data[3] & 0x07) - 1;			//week:1~7 (1:sun, 2:mon, 3:tue,..., 7:sat)(but linux week define is 0~6)
	tInfo.tm_mday = RTC_ITE(data[4] & 0x3F);	//day:1~31 (without 0)
	tInfo.tm_mon = RTC_ITE(data[5] & 0x1F) - 1;//mon:1~12 (1:jan, 2:feb, 3:mar..., 12:Dec)(without 0, but linux month define is 0~11)
	tInfo.tm_year = RTC_ITE(data[6])+100;	//year:2000~2099
/*	
	printf("yrear----------------------->%d\n",tInfo.tm_year);
	printf("yrear----------------------->%d\n",tInfo.tm_mon);
	printf("yrear----------------------->%d\n",tInfo.tm_mday);
	printf("yrear----------------------->%d\n",tInfo.tm_hour);
	printf("yrear----------------------->%d\n",tInfo.tm_min);
	printf("yrear----------------------->%d\n",tInfo.tm_sec);
	*/
#if 0
	if (data[5] & 0x80)
	{
		tInfo.tm_year += 100;					//reg05 bit7 0&1 (0:year=19XX, 1:year=20XX)
	}
#endif
	rtcSec = mktime((struct tm*)&tInfo);
	return rtcSec;
}


/********************************************
 * Public function 
 ********************************************/
//I don't know if PT7C4337 needs to use the "CFG_RTC_DEFAULT_TIMESTAMP"
//I think(guess) external RTC maybe not need this "time stamp"
//I think(guess) external RTC can get correct time at any-time without S/W initialization. 
void itpRtcInit(void)
{
	int year;
	LOG_INFO "RTC PT7C4337 INITIAL~~~\n" LOG_END
	year = pt7c4337_i2c_read(0xD0,0x06);
	if(!year)
		rtc_reset = true;
}
 
bool get_rtc_reset()
{
	return rtc_reset;
}

void clear_rtc_reset()
{
	rtc_reset = false;
}
/*
 * At present, I skip the information of micro-second level 
 * Becouse this RTC can't handle this job(micro second)
 * maybe need to combine the information of IT9079's timer...
 * However, this solution needs to consider the IIC timing issue.
 * (IIC needs several decades ms to get RTC info, 
 * and it's hard to handle(sync) these two timers in us-level)
 */
long itpRtcGetTime(long* usec)
{
    uint8_t data[8];
    long rtcSec=0;
        
    ithEnterCritical();

   	rtcSec = _extRtcGetTime();
    *usec = 0;   	

    ithExitCritical();

    return rtcSec;
}

void itpRtcSetTime(long sec, long usec)
{
	uint8_t data[7];
	int     i;
	struct  tm *t = localtime(&sec);

	//printf(" current time-------------------->%d-%d-%d  %d:%d:%d\n",t->tm_year,t->tm_mon,t->tm_mday,t->tm_hour,t->tm_min, t->tm_sec);
	ithEnterCritical();
	memset(data, 0, sizeof(data));

	data[0] = ITE_RTC(t->tm_sec);
	data[1] = ITE_RTC(t->tm_min);
	data[2] = ITE_RTC(t->tm_hour);
	data[3] = t->tm_wday%7 + 1;
	data[4] = ITE_RTC(t->tm_mday);
	data[5] = ITE_RTC(t->tm_mon + 1);
	data[6] = ITE_RTC(t->tm_year % 100);
#if 0	
	if(t->tm_year > 199)
		data[5] |= 0x80;
	else
		data[5] &= 0x7F;
#endif
	for(i = 0; i < 7; i++)
		pt7c4337_i2c_write(0xD0,0x00+i,data[i]);
	ithExitCritical();
}