#include <assert.h>
#include "function_user.h"
#include "ite/itp.h"

static ITUBackground* page_phone_bg;
static ITUTextBox* phone_display_num;
static ITUBackground* phone_back_1;
static ITUBackground* phone_back_2;
static ITUBackground* phone_back_3;
static ITUBackground* phone_back_4;
static ITUBackground* page_phone_call_bg;
static ITUBackground* page_phone_ans_bg;
static ITUText* phone_text_call_num;
static ITUText* phone_text_call_time;

bool page_phone_init(ITUWidget* widget, char* param)
{
	if (!page_phone_bg)
	{
		page_phone_bg = ituSceneFindWidget(&theScene, "page_phone_bg");
		assert(page_phone_bg);
		phone_display_num = ituSceneFindWidget(&theScene, "phone_display_num");
		assert(phone_display_num);
		phone_back_1 = ituSceneFindWidget(&theScene, "phone_back_1");
		assert(phone_back_1);
		phone_back_2 = ituSceneFindWidget(&theScene, "phone_back_2");
		assert(phone_back_2);
		phone_back_3 = ituSceneFindWidget(&theScene, "phone_back_3");
		assert(phone_back_3);
		phone_back_4 = ituSceneFindWidget(&theScene, "phone_back_4");
		assert(phone_back_4);
		page_phone_call_bg = ituSceneFindWidget(&theScene, "page_phone_call_bg");
		assert(page_phone_call_bg);
		page_phone_ans_bg = ituSceneFindWidget(&theScene, "page_phone_ans_bg");
		assert(page_phone_ans_bg);
		phone_text_call_num = ituSceneFindWidget(&theScene, "phone_text_call_num");
		assert(phone_text_call_num);
		phone_text_call_time = ituSceneFindWidget(&theScene, "phone_text_call_time");
		assert(phone_text_call_time);
	}

	//if()


	int i;
	char getstr[256];
	char sendtr[256];
	char rent;
	int len = 0;

	printf("Start uart test!\n");
    ioctl(ITP_DEVICE_UART2, ITP_IOCTL_INIT, NULL);
#ifdef CFG_UART2_ENABLE
    ioctl(ITP_DEVICE_UART2, ITP_IOCTL_RESET, CFG_UART2_BAUDRATE);
#endif

	while(1)
	{
		len = read(ITP_DEVICE_UART2,&getstr,256);

		if(len > 0)
		{
			printf("uart read->%s\n",getstr);
		
		/*
			printf("uart read: %s\n",getstr);
			sprintf(sendtr,"uart write: read str = %s",getstr);
			write(ITP_DEVICE_UART2,sendtr,256);
			*/
		}
	}
	return true;
}

bool page_phone_timer(ITUWidget* widget, char* param)
{
	return true;
}

bool page_phone_leave(ITUWidget* widget, char* param)
{
	return true;
}

bool page_phone_refuse(ITUWidget* widget, char* param)
{
	return true;
}

bool page_phone_answer(ITUWidget* widget, char* param)
{
	return true;
}

bool page_phone_call(ITUWidget* widget, char* param)
{
	return true;
}

