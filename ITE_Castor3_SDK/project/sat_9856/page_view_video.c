#include <assert.h>
#include "function_user.h"
#include "castor3player.h"

static ITUBackground* view_video_windos;
static ITUBackground* view_video_menu;
static ITUBackground* view_video_title;
static ITUBackground* view_video_status;
static ITUBackground* view_video_play_status;
static ITUBackgroundButton* view_video_bg_button_back;
static ITUBackgroundButton* view_video_bg_button_P_S;
static ITUText* view_video_Text_file_name;
static ITUButton* view_video_Button_full_close;
static ITUButton* view_video_Button_play;
static ITUButton* view_video_Button_pause;
static ITUText* view_video_cur_time;
static ITUText* view_video_total_time;
static ITUProgressBar* view_video_ProgressBar;
static ITUTrackBar* view_video_TrackBar;
static ITUTrackBar* view_video_TrackBar_2;
static ITUScrollMediaFileListBox* view_video_file_list;
static ITUText* view_video_Text_vol;

#define CFG_VIDEO_ENABLE      1
static int x, y, width, height = 0;
static MTAL_SPEC mtal_spec = {0};
int LastMediaPlayerVoice = 0;
bool videoPlayerIsFileEOF = false;
bool videoPlayerIsPlaying = false;
int videoPlayerPercentage = 0;
int totaltime = 0;
int prv_s = 0;
int def_vol = 30;
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

int CalVideoPlayerProgressBarPercentage(void)
{
    int percentage_value;
    int totaltime = 0;
    int currenttime = 0;
    int ret;
#ifdef CFG_VIDEO_ENABLE        
    ret = mtal_pb_get_total_duration(&totaltime);
    if(ret < 0)
        return -1;
    ret = mtal_pb_get_current_time(&currenttime);
    if(ret < 0)
        return -1;
#endif        
    if(totaltime > 0)
    {
        percentage_value = currenttime*100/totaltime;
        if(percentage_value > 100)
            percentage_value = 100;
    }
    else
        percentage_value = 0;

    return percentage_value;
}
static void VideoPlayerViewBackgroundDraw(ITUWidget* widget, ITUSurface* dest, int x, int y, uint8_t alpha)
{
	//printf("VideoPlayerViewBackgroundDraw......................\n");
    int destx, desty;
    ITURectangle* rect = (ITURectangle*) &widget->rect;

    destx = rect->x + x;
    desty = rect->y + y;
    
    ituDrawVideoSurface(dest, destx, desty, rect->width, rect->height);
    ituWidgetDrawImpl(widget, dest, x, y, alpha);
}

bool page_view_video_init(ITUWidget* widget, char* param)
{
	//printf("page_view_video_init......................\n");
	view_video_windos = ituSceneFindWidget(&theScene, "view_video_windos");
	assert(view_video_windos);
	ituWidgetSetDraw(view_video_windos, VideoPlayerViewBackgroundDraw);
	
	view_video_menu = ituSceneFindWidget(&theScene, "view_video_menu");
	assert(view_video_menu);
	view_video_title = ituSceneFindWidget(&theScene, "view_video_title");
	assert(view_video_title);
	view_video_status = ituSceneFindWidget(&theScene, "view_video_status");
	assert(view_video_status);
	view_video_play_status = ituSceneFindWidget(&theScene, "view_video_play_status");
	assert(view_video_play_status);
	view_video_bg_button_back = ituSceneFindWidget(&theScene, "view_video_bg_button_back");
	assert(view_video_bg_button_back);
	view_video_bg_button_P_S = ituSceneFindWidget(&theScene, "view_video_bg_button_P_S");
	assert(view_video_bg_button_P_S);
	view_video_Text_file_name = ituSceneFindWidget(&theScene, "view_video_Text_file_name");
	assert(view_video_Text_file_name);
	view_video_Button_full_close = ituSceneFindWidget(&theScene, "view_video_Button_full_close");
	assert(view_video_Button_full_close);
	view_video_Button_play = ituSceneFindWidget(&theScene, "view_video_Button_play");
	assert(view_video_Button_play);
	view_video_Button_pause = ituSceneFindWidget(&theScene, "view_video_Button_pause");
	assert(view_video_Button_pause);
	view_video_cur_time = ituSceneFindWidget(&theScene, "view_video_cur_time");
	assert(view_video_cur_time);
	view_video_total_time = ituSceneFindWidget(&theScene, "view_video_total_time");
	assert(view_video_total_time);
	view_video_ProgressBar = ituSceneFindWidget(&theScene, "view_video_ProgressBar");
	assert(view_video_ProgressBar);
	view_video_TrackBar = ituSceneFindWidget(&theScene, "view_video_TrackBar");
	assert(view_video_TrackBar);
	view_video_TrackBar_2 = ituSceneFindWidget(&theScene, "view_video_TrackBar_2");
	assert(view_video_TrackBar_2);
	view_video_file_list = ituSceneFindWidget(&theScene, "view_video_file_list");
	assert(view_video_file_list);
	view_video_Text_vol = ituSceneFindWidget(&theScene, "view_video_Text_vol");
	assert(view_video_Text_vol);
	
	SceneEnterVideoState();

	ituWidgetGetGlobalPosition(view_video_windos, &x, &y);
	width = ituWidgetGetWidth(view_video_windos);
	height = ituWidgetGetHeight(view_video_windos);
	itv_set_video_window(x, y, width, height);

	ituWidgetHide(view_video_play_status, 0, 0);
	switch_init();
	ituWidgetHide(view_video_Button_pause, 0, 0);
	ituWidgetShow(view_video_Button_play, 0, 0);
	ituWidgetDisable(view_video_bg_button_back);
	ituWidgetDisable(view_video_bg_button_P_S);
	ituWidgetHide(view_video_Button_full_close, ITU_EFFECT_NONE, 0);
	mtal_pb_init(UserEventHandler);
	AudioPauseKeySound();
    return true;
}

void video_play_total_time(char *filepath)
{
	int h, m, s = 0;
	char buf[32];
	int ret;

	mtal_pb_get_total_duration_ext(&totaltime,filepath);
	{
		//printf("total time.....................%d\n",totaltime);
		prv_s = 0;
		s = totaltime;
		m = s / 60;
		s %= 60;
		h = m / 60;
		m %= 60;

		if (h > 0)
			sprintf(buf, "%02d:%02d:%02d", h, m, s);
		else
			sprintf(buf, "%02d:%02d", m, s);
		ituTextSetString(view_video_total_time, buf);
	}
}
void video_play_update_time()
{
	int h, m, s = 0;
	char buf[32];
	int ret;

	if((mtal_pb_get_current_time(&s) == 0 )&& (s != prv_s))
	{
		prv_s = s;
		ituTrackBarSetValue(view_video_TrackBar,s*480/totaltime);
		m = s / 60;
		s %= 60;
		h = m / 60;
		m %= 60;

		if (h > 0)
			sprintf(buf, "%02d:%02d:%02d", h, m, s);
		else
			sprintf(buf, "%02d:%02d", m, s);
		ituTextSetString(view_video_cur_time, buf);
		//printf("cur_time is ----->%s",buf);
	} 
}

bool page_view_video_timer(ITUWidget* widget, char* param)
{
	//printf("page_view_video_timer......................\n");
#if 1
	if(video_play_status == P_S_END)
	{
		char buf[32] = "00:00";
		mtal_pb_stop();
		video_play_status = P_S_READY;
		ituWidgetHide(view_video_Button_pause, 0, 0);
		ituWidgetShow(view_video_Button_play, 0, 0);
		ituTrackBarSetValue(view_video_TrackBar,0);
		ituTextSetString(view_video_cur_time, buf);
		ituTextSetString(view_video_total_time, buf);
		return true;
	}

	if (video_play_status == P_S_PLAYING)
	{
		video_play_update_time();
		return true;
	}
#endif 	
	return true;
}

bool page_view_video_leave(ITUWidget* widget, char* param)
{
	printf("-------->page_view_video_leave\n");
	__WaitPlayMjpegFinish();
	AudioResumeKeySound();
	SceneLeaveVideoState();
    return true;
}


bool view_video_prev(ITUWidget* widget, char* param)
{
	ITUScrollText* item = ituMediaFileListPrev((ITUMediaFileListBox*)view_video_file_list);
	if (item)
	{
		video_play_status = P_S_PLAYING;
		ituWidgetHide(view_video_Button_play, 0, 0);
		ituWidgetShow(view_video_Button_pause, 0, 0);
		char* filepath = (char*)ituWidgetGetCustomData(item);
		strcpy(mtal_spec.srcname, filepath);
		char *cur_filename = &filepath[9];
		ituTextSetString(view_video_Text_file_name, cur_filename);
		
		mtal_spec.vol_level = def_vol;
		//video_play_total_time(filepath);
		AudioStop();
		mtal_pb_stop();
		mtal_pb_select_file(&mtal_spec);
		//video_play_total_time(filepath);
		mtal_pb_play();
		video_play_total_time(filepath);
	}
	
    return true;
}

bool view_video_play_stop(ITUWidget* widget, char* param)
{
	if(video_play_status == P_S_READY)
	{
	#if 1
		//user_PlayMjpeg(0, 0, ithLcdGetWidth(), ithLcdGetHeight(), CFG_BOOT_VIDEO_BGCOLOR, 0);
	g_videoPlayerIsFileEOF = false;
		user_video_play();
	#else
		ITUScrollText* item = ituMediaFileListPlay((ITUMediaFileListBox*)view_video_file_list);
		//if (item)
		{
			printf("play video.............................\n");
			video_play_status = P_S_PLAYING;
			ituWidgetHide(view_video_Button_play, 0, 0);
			ituWidgetShow(view_video_Button_pause, 0, 0);
			char* filepath = (char*)ituWidgetGetCustomData(item);
			strcpy(mtal_spec.srcname, filepath);
			char *cur_filename = &filepath[9];
			ituTextSetString(view_video_Text_file_name, cur_filename);
			
			mtal_spec.vol_level = def_vol;
			//video_play_total_time(filepath);
			AudioStop();
			mtal_pb_stop();
			mtal_pb_select_file(&mtal_spec);
			//video_play_total_time(filepath);
			mtal_pb_play();
			video_play_total_time(filepath);
		}
		#endif
	}
	else if(video_play_status == P_S_PLAYING)
	{   
		mtal_pb_pause();
		video_play_status = P_S_PAUSE;
		ituWidgetHide(view_video_Button_pause, 0, 0);
		ituWidgetShow(view_video_Button_play, 0, 0);
	}
	else if(video_play_status == P_S_PAUSE)
	{   
		AudioStop();
		mtal_pb_play();
		video_play_status = P_S_PLAYING;
		ituWidgetHide(view_video_Button_play, 0, 0);
		ituWidgetShow(view_video_Button_pause, 0, 0);
	}
	return true;
}


bool view_video_next(ITUWidget* widget, char* param)
{
	ITUScrollText* item = ituMediaFileListNext((ITUMediaFileListBox*)view_video_file_list);
	if (item)
	{
		video_play_status = P_S_PLAYING;
		ituWidgetHide(view_video_Button_play, 0, 0);
		ituWidgetShow(view_video_Button_pause, 0, 0);
		char* filepath = (char*)ituWidgetGetCustomData(item);
		strcpy(mtal_spec.srcname, filepath);
		char *cur_filename = &filepath[9];
		ituTextSetString(view_video_Text_file_name, cur_filename);
		
		mtal_spec.vol_level = def_vol;
		//video_play_total_time(filepath);
		AudioStop();
		mtal_pb_stop();
		mtal_pb_select_file(&mtal_spec);
		//video_play_total_time(filepath);
		mtal_pb_play();
		video_play_total_time(filepath);
	}
	return true;
}
bool view_video_Button_fun_vol(ITUWidget* widget, char* param)
{
	if(switch_state[VIEW_VIDEO_S_VOLUME] == false)
	{
		switch_state[VIEW_VIDEO_S_VOLUME] = true;
		ituWidgetShow(view_video_TrackBar_2, 0, 0);
		ituWidgetShow(view_video_Text_vol, 0, 0);
		ituTrackBarSetValue(view_video_TrackBar_2,def_vol*20/100);
	}
	else
	{
		switch_state[VIEW_VIDEO_S_VOLUME] = false;
		ituWidgetHide(view_video_TrackBar_2, 0, 0);
		ituWidgetHide(view_video_Text_vol, 0, 0);

	}
    return true;
}


bool view_video_Button_fun_menu(ITUWidget* widget, char* param)
{
	//printf("view_video_Button_fun_menu......%d....\n",(int)switch_state[VIEW_VIDEO_S_MENU]);
	if(switch_state[VIEW_VIDEO_S_MENU] == false)
	{
		switch_state[VIEW_VIDEO_S_MENU] = true;
		ituWidgetShow(view_video_menu, ITU_EFFECT_SCROLL_LEFT, 10);
		ituWidgetHide(view_video_play_status, ITU_EFFECT_SCROLL_DOWN, 5);
		ituWidgetEnable(view_video_menu);
		ituWidgetEnable(view_video_bg_button_back);
	}
	else
	{
		switch_state[VIEW_VIDEO_S_MENU] = false;
		ituWidgetHide(view_video_menu, ITU_EFFECT_SCROLL_RIGHT, 5);
		//ituWidgetShow(view_video_play_status,ITU_EFFECT_SCROLL_UP , 10);
		ituWidgetDisable(view_video_bg_button_back);
		
		switch_state[VIEW_VIDEO_S_DELETE] = false;
		ituWidgetHide(view_video_title, ITU_EFFECT_NONE, 0);
		//ituWidgetEnable(view_video_menu);
		//ituWidgetEnable(view_video_bg_button_back);
		
		switch_state[VIEW_VIDEO_S_MENU] = false;
	}
		
    return true;
}

bool view_video(ITUWidget* widget, char* param)
{
	mtal_pb_stop();
	video_play_status = P_S_READY;
	view_video_play_stop(widget,param);
    	return true;
}

bool view_video_Button_fun_delete(ITUWidget* widget, char* param)
{
	switch_state[VIEW_VIDEO_S_DELETE] = true;
	ituWidgetShow(view_video_title, ITU_EFFECT_NONE, 0);
	ituWidgetDisable(view_video_menu);
	ituWidgetDisable(view_video_bg_button_back);
	
   	return true;
}

bool view_video_Button_fun_delete_no(ITUWidget* widget, char* param)
{
	switch_state[VIEW_VIDEO_S_DELETE] = false;
	ituWidgetHide(view_video_title, ITU_EFFECT_NONE, 0);
	ituWidgetEnable(view_video_menu);
	ituWidgetEnable(view_video_bg_button_back);
    return true;
}

bool view_video_Button_fun_delete_yes(ITUWidget* widget, char* param)
{
	switch_state[VIEW_VIDEO_S_DELETE] = false;
	ituWidgetHide(view_video_title, ITU_EFFECT_NONE, 0);
	ituWidgetEnable(view_video_menu);
	ituWidgetEnable(view_video_bg_button_back);
    return true;
}

bool view_video_back(ITUWidget* widget, char* param)
{
	switch_state[VIEW_VIDEO_S_MENU] = false;
	ituWidgetHide(view_video_menu, ITU_EFFECT_SCROLL_RIGHT, 5);
	ituWidgetShow(view_video_play_status, ITU_EFFECT_SCROLL_UP, 10);
	ituWidgetDisable(view_video_bg_button_back);
    return true;
}

bool view_video_Button_fun_full(ITUWidget* widget, char* param)
{
	//
	//printf("view_video_Button_fun_full..........\n");
	//switch_state[VIEW_VIDEO_S_FULL] = true;
	//ituWidgetEnable(view_video_full_close);
	ituWidgetShow(view_video_Button_full_close, ITU_EFFECT_NONE, 0);
	ituWidgetHide(view_video_status, ITU_EFFECT_SCROLL_UP, 10);
	ituWidgetHide(view_video_play_status, ITU_EFFECT_SCROLL_DOWN,10);
    return true;
}

bool view_video_Button_fun_full_close(ITUWidget* widget, char* param)
{
	//printf("view_video_Button_fun_full_close..........\n");
	//switch_state[VIEW_VIDEO_S_FULL] = false;
	//ituWidgetDisable(view_video_full_close);
	ituWidgetHide(view_video_Button_full_close, ITU_EFFECT_NONE, 0);
	ituWidgetShow(view_video_status, ITU_EFFECT_SCROLL_DOWN, 10);
	ituWidgetShow(view_video_play_status, ITU_EFFECT_SCROLL_UP,10);
    return true;
}

bool view_video_full(ITUWidget* widget, char* param)
{
	return true;
}

bool view_video_vol_progress(ITUWidget* widget, char* param)
{
	//ithMediaPlayer_volume_up();
    return true;
}

bool view_video_time_progress(ITUWidget* widget, char* param)
{
    return true;
}