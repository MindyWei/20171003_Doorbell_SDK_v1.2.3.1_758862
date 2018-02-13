#include <assert.h>
#include "function_user.h"

static ITUIcon* auto_view_windows;

char imagePlayerPath[1024];
bool imagePlayerLoading, imagePlayerLoaded;
static uint8_t* imagePlayerData;
static int imagePlayerDataSize;

int num = 1;

int  on_auto_view_page	= 0;				//是否在监控界面

bool auto_view_photo()
{
#if 1
	char filepath[30] = "E:/auto/auto (";
	char str[4];
	//100).jpg
	/*
	num = (int)rand%100;
	while(!num)
	{
		num = (int)rand%100;
	};
	*/
	if(num>354)
		num = 1;
	if(num<10)
	{
		str[0] = '0'+num;
		str[1] = '\0';
		strcat(filepath,str);
	}
	else if(num<100)
	{
		str[0] = '0'+num/10;
		str[1] = '0'+num%10;
		str[2] = '\0';

		strcat(filepath,str);

	}
	else
	{
		str[0] = '0'+num/100;
		str[1] = '0'+(num%100)/10;
		str[2] = '0'+num%10;
		str[3] = '\0';

		strcat(filepath,str);

	}
	strcat(filepath,").jpg");
	strncpy(imagePlayerPath, filepath, PATH_MAX);
	printf("---------------->%s\n",filepath);
	imagePlayerLoading = true;
	num ++;
#endif
	return true;
}

static void imagePlayerLoadCallback(uint8_t* data, int size)
{
	if (data && size > 0)
	{
		if (imagePlayerDataSize > 0)
		{
			free(imagePlayerData);
			imagePlayerData = NULL;
			imagePlayerDataSize = 0;
		}
		imagePlayerData = data;
		imagePlayerDataSize = size;
		imagePlayerLoaded = true;
	}
}



bool page_auto_view_init(ITUWidget* widget, char* param)
{
	printf("page_auto_view_init....................\n");
	auto_view_windows = ituSceneFindWidget(&theScene, "auto_view_windows");
	assert(auto_view_windows);

	on_auto_view_page = 1;

//	srand((unsigned)time(NULL));
	auto_view_photo();
	auto_view_start();
	//backlight_open();
	return true;
}

bool page_auto_view_timer(ITUWidget* widget, char* param)
{
	//imageplay
	if (imagePlayerLoading && !imagePlayerLoaded)
	{
		int ret = PhotoLoad(imagePlayerPath, imagePlayerLoadCallback);
		if (ret == 0)
			imagePlayerLoading = false;

	}
	else if (imagePlayerLoaded)
	{
		ituIconLoadJpegData(auto_view_windows, imagePlayerData, imagePlayerDataSize);
		ituWidgetSetVisible(auto_view_windows, true);
		ituWidgetSetVisible(auto_view_windows, true);
		free(imagePlayerData);
		imagePlayerData = NULL;
		imagePlayerDataSize = 0;
		imagePlayerLoaded = false;
		backlight_open();
	}

	//swtich_control

	return true;
}

bool page_auto_view_leave(ITUWidget* widget, char* param)
{
	on_auto_view_page = 0;
	return true;
}

