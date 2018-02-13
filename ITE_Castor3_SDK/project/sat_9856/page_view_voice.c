#include <assert.h>
#include "function_user.h"

static ITUScrollMediaFileListBox* view_voice_file_list;
static ITUButton* view_voice_Button_play;
static ITUButton* view_voice_Button_pause;
static ITUText* view_voice_cur_time;
 ITUText* view_voice_total_time;
static ITUTrackBar* view_voice_TrackBar_1;

static int AudioPlayerPlayCallback(int state)
{
#if 1
	 switch (state)
    {
    case 0://AUDIOMGR_STATE_CALLBACK_PLAYING_FINISH:
		voice_play_status = P_S_END;
		/*
        item = ituMediaFileListNext((ITUMediaFileListBox*)audioPlayerScrollMediaFileListBox);
        if (item)
        {
            char* filepath = (char*)ituWidgetGetCustomData(item);

            //LinphonePauseKeySound();
            AudioPlay(filepath, AudioPlayerPlayCallback);
        }
        else
        {
            //LinphoneResumeKeySound();
            ituCheckBoxSetChecked(audioPlayerPlayCheckBox, false);
            audioPlayerPlaying = false;
        }
        ituTextSetString(audioPlayerTimeText, NULL);
        */
        break;
    }
#endif
    return 0;
}
bool page_view_voice_init(ITUWidget* widget, char* param)
{
	view_voice_file_list = ituSceneFindWidget(&theScene, "view_voice_file_list");
	assert(view_voice_file_list);
	view_voice_Button_play = ituSceneFindWidget(&theScene, "view_voice_Button_play");
	assert(view_voice_Button_play);
	view_voice_Button_pause = ituSceneFindWidget(&theScene, "view_voice_Button_pause");
	assert(view_voice_Button_pause);
	view_voice_cur_time = ituSceneFindWidget(&theScene, "view_voice_cur_time");
	assert(view_voice_cur_time);
	view_voice_total_time = ituSceneFindWidget(&theScene, "view_voice_total_time");
	assert(view_voice_total_time);
	view_voice_TrackBar_1 = ituSceneFindWidget(&theScene, "view_voice_TrackBar_1");
	assert(view_voice_TrackBar_1);


	
	AudioPauseKeySound();
    return true;
}

int prv_vo_s = 0;

void voice_play_total_time(void)
{
	int h, m, s = 0;
	char buf[32];
	int ret;
	
	s = total_time_voice;
	m = s / 60;
	s %= 60;
	h = m / 60;
	m %= 60;

	if (h > 0)
		sprintf(buf, "%02d:%02d:%02d", h, m, s);
	else
		sprintf(buf, "%02d:%02d", m, s);
	ituTextSetString(view_voice_total_time, buf);

}
voice_play_update_time()
{
	int h, m, s = 0;
	char buf[32];
	int ret;
	uint32_t  time;
		s = smtkAudioMgrGetTime();
		s = s / 1000;
	#if 1
	if(s != prv_vo_s)
	{
		prv_vo_s = s;
		ituTrackBarSetValue(view_voice_TrackBar_1,s*480/total_time_voice);
		m = s / 60;
		s %= 60;
		h = m / 60;
		m %= 60;

		if (h > 0)
			sprintf(buf, "%02d:%02d:%02d", h, m, s);
		else
			sprintf(buf, "%02d:%02d", m, s);
		ituTextSetString(view_voice_cur_time, buf);
		//printf("cur_time is ----->%s",buf);
	} 
#endif 



}
bool page_view_voice_timer(ITUWidget* widget, char* param)
{
	if(voice_play_status == P_S_END)
	{
		char buf[32] = "00:00";
		voice_play_status = P_S_READY;
		ituWidgetHide(view_voice_Button_pause, 0, 0);
		ituWidgetShow(view_voice_Button_play, 0, 0);
		ituTrackBarSetValue(view_voice_TrackBar_1,0);
		ituTextSetString(view_voice_cur_time, buf);
		ituTextSetString(view_voice_total_time, buf);
	}
	if (voice_play_status == P_S_PLAYING)
		voice_play_update_time();
    return true;
}

bool page_view_voice_leave(ITUWidget* widget, char* param)
{

	AudioStop();
	AudioResumeKeySound();
    return true;
}

bool view_voice_menu(ITUWidget* widget, char* param)
{ 
    return true;
}

bool view_voice(ITUWidget* widget, char* param)
{
	ITUScrollText* item = ituMediaFileListPlay((ITUMediaFileListBox*)view_voice_file_list);
	if (item)
	{
		char* filepath = (char*)ituWidgetGetCustomData(item);
		printf("filename-------->%s---->%d\n",filepath,AudioGetVolume());
		//AudioSetVolume(20);
		printf("11111111111111111");
		AudioStop();
		printf("222222222222222222");
		AudioPlay(filepath, AudioPlayerPlayCallback);
		printf("3333333333333333333");
		voice_play_status = P_S_PLAYING;
		printf("44444444444444444444");
		//ituWidgetHide(view_voice_Button_play, 0, 0);
		//ituWidgetShow(view_voice_Button_pause, 0, 0);
		ituWidgetSetVisible(view_voice_Button_play, false);
		ituWidgetSetVisible(view_voice_Button_pause, true);
		voice_play_total_time();
		printf("55555555555555555555");

	}
    return true;
}

bool view_voice_next(ITUWidget* widget, char* param)
{
	ITUScrollText* item = ituMediaFileListNext((ITUMediaFileListBox*)view_voice_file_list);
	if (item)
	{
		char* filepath = (char*)ituWidgetGetCustomData(item);
		printf("filename-------->%s---->%d\n",filepath,AudioGetVolume());
		//AudioSetVolume(20);
		AudioStop();
		AudioPlay(filepath, AudioPlayerPlayCallback);
		voice_play_status = P_S_PLAYING;
		ituWidgetHide(view_voice_Button_play, 0, 0);
		ituWidgetShow(view_voice_Button_pause, 0, 0);
		voice_play_total_time();

	}
    return true;
}

bool view_voice_play_stop(ITUWidget* widget, char* param)
{
#if 1
	if(voice_play_status == P_S_READY)
	{
		view_voice(widget,param);
		ituWidgetHide(view_voice_Button_play, 0, 0);
		ituWidgetShow(view_voice_Button_pause, 0, 0);
	}
	else if(voice_play_status == P_S_PLAYING)
	{   
		AudioPause();
		voice_play_status = P_S_PAUSE;
		ituWidgetHide(view_voice_Button_pause, 0, 0);
		ituWidgetShow(view_voice_Button_play, 0, 0);
	}
	else if(voice_play_status == P_S_PAUSE)
	{   
		AudioContinue();
		voice_play_status = P_S_PLAYING;
		ituWidgetHide(view_voice_Button_play, 0, 0);
		ituWidgetShow(view_voice_Button_pause, 0, 0);
	}
	#endif
    return true;
}

bool view_voice_prev(ITUWidget* widget, char* param)
{
	ITUScrollText* item = ituMediaFileListPrev((ITUMediaFileListBox*)view_voice_file_list);
	if (item)
	{
		char* filepath = (char*)ituWidgetGetCustomData(item);
		printf("filename-------->%s---->%d\n",filepath,AudioGetVolume());
		//AudioSetVolume(20);
		AudioStop();
		AudioPlay(filepath, AudioPlayerPlayCallback);
		voice_play_status = P_S_PLAYING;
		ituWidgetHide(view_voice_Button_play, 0, 0);
		ituWidgetShow(view_voice_Button_pause, 0, 0);
		voice_play_total_time();

	}
    return true;
}

bool view_voice_vol(ITUWidget* widget, char* param)
{
    return true;
}

bool view_voice_Button_fun_delete_no(ITUWidget* widget, char* param)
{
    return true;
}

bool view_voice_Button_fun_delete_yes(ITUWidget* widget, char* param)
{
    return true;
}

bool view_voice_Button_fun(ITUWidget* widget, char* param)
{
	switch(*param)
	{
		case '1':
			AudioPlay("E:/123.wma",AudioPlayerPlayCallback);
			break;
		case '2':
			AudioPlay("E:/123.wav",AudioPlayerPlayCallback);
			break;
		case '3':
			AudioPlay("E:/123.mp3",AudioPlayerPlayCallback);
			break;

	}
    return true;
}


