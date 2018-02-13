#ifndef _FUNCTION_USER_H_
#define _FUNCTION_USER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "scene.h"
#include "project.h"
#include "sw_i2c.h"
/*
#include <pthread.h>

#include "ite/itv.h"
#include "ite/ith_video.h"
#include "ite/audio.h"
*/
#include "audio_fun.h"
#include "user_call.h"
//#include "sysdep.h"


extern ITUText* view_voice_total_time;


//extern	SEND_STATE          gState;

typedef enum
{
	P_S_READY = 0,
	P_S_PLAYING,
	P_S_PAUSE,
	P_S_END,
} PlaybackStatus;
extern int video_play_status;	//视频播放的状态
extern int voice_play_status;	//声音播放的状态

typedef enum
{
    STORAGE_NONE = -1,
    STORAGE_USB,
    STORAGE_SD,

    STORAGE_MAX_COUNT
} StorageType;

typedef enum
{
    STORAGE_UNKNOWN,
    STORAGE_SD_INSERTED,
    STORAGE_SD_REMOVED,
    STORAGE_USB_INSERTED,
    STORAGE_USB_REMOVED
} StorageAction;


enum {
	MONITOR_S_CAM= 0,
	MONITOR_S_MENU,		
	VIEW_PHOTO_S_MENU ,
	VIEW_PHOTO_S_DELETE,
	VIEW_PHOTO_S_FULL,
	VIEW_VIDEO_S_MENU ,
	VIEW_VIDEO_S_DELETE,
	VIEW_VIDEO_S_VOLUME,
	VIEW_VIDEO_S_FULL,
	SWITCH_TOTAL
};


typedef enum SEND_STATE_TAG
{
    SEND_BEGIN,
    SEND_START,
    SEND_STOP,
    SEND_TERMINATE,
    SEND_IDLE,
} SEND_STATE;

extern bool switch_state[SWITCH_TOTAL];
extern bool switch_on_off(int num);

void param_cmd(char *param,int *but_cmd);

unsigned long str_to_num(const char *p);

extern uint8_t	show_snap_rec;	//snap_rec_show_icon

extern bool PlayerStop;

extern  bool      g_videoPlayerIsFileEOF;

extern bool pr2000_signal_lock;


extern timer_t door_open_TimerId;
extern int  on_auto_view_page;				//是否在监控界面


extern int temp_rec_time;
 
	extern SEND_STATE  gState;
void StorageInit(void);
StorageAction StorageCheck(void);

typedef void (*PhotoLoadCallback)(uint8_t* data, int size);
extern int PhotoLoad(char* filename, PhotoLoadCallback func);

extern void PhotoInit(void);

//user_fun
extern void switch_init();

extern void UserPlayVideo();	//播放函数

extern char Tfile[];						//播放的文件名

extern void user_gpio_init();


#endif //_FUNCTION_USER_H_