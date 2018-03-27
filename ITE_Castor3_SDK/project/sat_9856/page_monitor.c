#include <assert.h>
#include "function_user.h"
#include "iic/mmp_iic.h"
#include "castor3player.h"

static ITUBackground* cvbs_windos;
static ITUBackground* monitor_bg;
static ITUBackground*   monitor_bg2;
static ITUBackground* monitor_menu_cam;
static ITUBackground* monitor_menu_dis;
static ITUText* monitor_cam;
static ITUText* monitor_text_rec;


static MTAL_SPEC mtal_spec = {0};

int change_cam_state = 0;
int cur_cam_num = 0;
int monitor_menu_state = 0;
static void VideoPlayerViewBackgroundDraw(ITUWidget* widget, ITUSurface* dest, int x, int y, uint8_t alpha)
{
	//printf("VideoPlayerViewBackgroundDraw......................\n");
	int destx, desty;
	ITURectangle* rect = (ITURectangle*) &widget->rect;

	destx = rect->x + x;
	desty = rect->y + y;

	ituDrawVideoSurface(dest, destx, desty, rect->width, rect->height);
}
static void UserEventHandler(PLAYER_EVENT nEventID, void *arg)
{
	//printf("EventHandler......................\n");
	switch(nEventID)
	{
	case PLAYER_EVENT_EOF:
		printf("File EOF\n");
		video_play_status = P_S_END;
		break;
	case PLAYER_EVENT_OPEN_FILE_FAIL:
		printf("Open file fail\n");
		video_play_status = P_S_READY;
		break;
	case PLAYER_EVENT_UNSUPPORT_FILE:
		printf("File not support\n");
		video_play_status = P_S_READY;
		break;
	default:
		break;
	}
}
#define DOOR_1_ON			31		//户外机1 供电GPIO
bool page_monitor_init(ITUWidget* widget, char* param)
{
	printf("page_monitor_init...........\n");

	if (!monitor_bg)
	{
		ITUWidget* widget;

		monitor_bg = ituSceneFindWidget(&theScene, "monitor_bg");
		assert(monitor_bg);
		monitor_cam = ituSceneFindWidget(&theScene, "monitor_cam");
		assert(monitor_cam);
		cvbs_windos = ituSceneFindWidget(&theScene, "cvbs_windos");
		assert(cvbs_windos);
		ituWidgetSetDraw(cvbs_windos, VideoPlayerViewBackgroundDraw);
		monitor_menu_cam = ituSceneFindWidget(&theScene, "monitor_menu_cam");
		assert(monitor_menu_cam);
		monitor_menu_dis = ituSceneFindWidget(&theScene, "monitor_menu_dis");
		assert(monitor_menu_dis);
		monitor_text_rec = ituSceneFindWidget(&theScene, "monitor_text_rec");
		assert(monitor_text_rec);

	}
	switch_init();
	on_monitor_page = 1;
	AudioPauseKeySound();
	SceneEnterVideoState();
	
	if(cur_cvbs_channel)
	{		
		cur_cam_num = cur_cvbs_channel;
		switch_cam_fun(cur_cvbs_channel);
		switch_cam_power(cur_cvbs_channel);
		cur_cvbs_channel = 0;
		AudioStop();
		AudioPlay("A:/sounds/call.wav", NULL);
	}
	else
	{
		cur_cam_num = 1;
		ithGpioSet(31);
		switch_cam_fun(1);
	}
	usleep(100*1000);
	gState = SEND_BEGIN;
	//else
		backlight_open();
#if 0	
	mtal_pb_init(UserEventHandler);
	char* filepath = "CapDev";
	strcpy(mtal_spec.srcname, filepath);
	AudioStop();
	mtal_pb_stop();
	mtal_pb_select_file(&mtal_spec);
	mtal_pb_play();
#endif
	return true;
}

void HW_v6502_switch(int offset)
{
	uint8_t addr = 0x00;
	uint8_t val = 0x01<<(offset-1);

	mmpIicSendData(IIC_PORT_1, IIC_MASTER_MODE, 0x06>>1, addr, &val, 2);
}
void switch_cam_fun( uint8_t val)
{
	char buf_1[6][10] = {"DOOR 1","DOOR 2","CCTV 1","CCTV 2","CCTV 3","CCTV4"};

	ituTextSetString(monitor_cam,buf_1[val-1]);
	HW_v6502_switch(val);		
}

int temp_rec_time = 0;
void update_rec_time_process()
{
	printf("update_rec_time_process------------->%d\n",temp_rec_time);
	char str[3] = {'\0'};
	temp_rec_time++;
	if(temp_rec_time<10)
	{
		str[0] = '0';
		str[1] = '0'+temp_rec_time;
		str[2] = '\0';
	}
	else
	{
		str[0] = '0'+temp_rec_time/10;
		str[1] = '0'+temp_rec_time%10;
		str[2] = '\0';
	}
	ituTextSetString(monitor_text_rec, str);
}
bool page_monitor_timer(ITUWidget* widget, char* param)
{
#if 1
	if(cur_cvbs_channel)
	{
		if (!monitor_cam )
		{
			monitor_cam = ituSceneFindWidget(&theScene, "monitor_cam");
			assert(monitor_cam);
		}
		cur_cam_num = cur_cvbs_channel;
		switch_cam_fun(cur_cvbs_channel);
		switch_cam_power(cur_cvbs_channel);
		cur_cvbs_channel = 0;
		AudioStop();
		AudioPlay("A:/sounds/call.wav", NULL);
		usleep(100*1000);
		gState = SEND_BEGIN;
	}  
#if 1
	if (EVENT_REC_LAST_TICK)
	{
		uint32_t tick = SDL_GetTicks();
		uint32_t diff = tick - EVENT_REC_LAST_TICK;
		if (diff >= 1000)
		{
			EVENT_REC_LAST_TICK = tick;
			update_rec_time_process();
		}
	}
#endif 
#endif
	return true;
}

bool page_monitor_leave(ITUWidget* widget, char* param)
{
	printf("page_monitor_leave.............................\n");
	on_monitor_page = 0;
#if 0
	AudioStop();
	mtal_pb_stop();
	mtal_pb_exit();
	usleep(100*1000);
#endif
	gState = SEND_STOP;
	AudioStop();
	exit_monitor();
	AudioResumeKeySound();
	return true;
}

bool monitor_cam_switch_fun(ITUWidget* widget, char* param)
{
	uint8_t addr = 0x00;
	uint8_t val = 0x01;
	switch(param[0])
	{
	case '0':
		printf("change cam...........\n");
		if(switch_state[MONITOR_S_CAM] == false)
		{
			switch_state[MONITOR_S_CAM] = true;
			ituWidgetShow(monitor_menu_cam, ITU_EFFECT_SCROLL_UP, 10);

			switch_state[MONITOR_S_MENU] = false;
			ituWidgetHide(monitor_menu_dis, ITU_EFFECT_SCROLL_DOWN, 5);
		}
		else
		{
			switch_state[MONITOR_S_CAM] = false;
			ituWidgetHide(monitor_menu_cam, ITU_EFFECT_SCROLL_DOWN, 5);
		}

		break;
#if 0
	case '1':
	case '2':
		cur_cvbs_channel = (param[0] - '0');
		break;
	case '3':
	case '4':
	case '5':
	case '6':
		//switch_cam_fun(param[0] - '0');
		//switch_cam_power(param[0] - '0');
		break;
#else
	case '1':
	case '2':
	case '3':
		
		gState = SEND_STOP;
		ithGpioClear(30);	
		ithGpioSet(31);
		mmpIicSendData(IIC_PORT_1, IIC_MASTER_MODE, 0x06>>1, addr, &val, 2);
		while(gState != SEND_IDLE)// || pr2000_signal_lock)
		{
			usleep(100*1000);
		}
		gState = SEND_BEGIN;
		break;
	case '4':
	case '5':
	case '6':
		gState = SEND_STOP;
		val = val<<1;
		ithGpioClear(31);	
		ithGpioSet(30);
		mmpIicSendData(IIC_PORT_1, IIC_MASTER_MODE, 0x06>>1, addr, &val, 2);
		while(gState != SEND_IDLE)// || pr2000_signal_lock)
		{
			usleep(100*1000);
		}
		gState = SEND_BEGIN;
		break;
#endif
	}
	return true;
}

static int AudioPlayerPlayCallback(int state)
{
    return 0;
}
bool monitor_open_fun(ITUWidget* widget, char* param)
{ 
	AudioStop();
	AudioPlay("A:/sounds/open.wav", NULL);
	user_open_door();
	return true;
}

bool monitor_menu_fun(ITUWidget* widget, char* param)
{
	if(switch_state[MONITOR_S_MENU] == false)
	{
		switch_state[MONITOR_S_MENU] = true;
		ituWidgetShow(monitor_menu_dis, ITU_EFFECT_SCROLL_UP, 10);

		switch_state[MONITOR_S_CAM] = false;
		ituWidgetHide(monitor_menu_cam, ITU_EFFECT_SCROLL_DOWN, 5);
	}

	else
	{
		switch_state[MONITOR_S_MENU] = false;
		ituWidgetHide(monitor_menu_dis, ITU_EFFECT_SCROLL_DOWN, 5);
	}


	return true;
}

bool monitor_rec_fun(ITUWidget* widget, char* param)
{
	printf("monitor_rec_fun.............................\n");
	user_snap(2);
	
	return true;
}

bool monitor_snap_fun(ITUWidget* widget, char* param)
{
	printf("monitor_snap_fun.............................\n");
		user_snap(1);
	
	return true;
}

void HW_v6502_test(void)
{
	uint8_t addr = 0x00;
	uint8_t val = 0x01;

	printf("v6502_start.............\n");
	mmpIicSendData(IIC_PORT_1, IIC_MASTER_MODE, 0x06>>1, addr, &val, 2);
}

