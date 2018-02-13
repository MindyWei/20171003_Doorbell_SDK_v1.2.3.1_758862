#include "ite/itu.h"

extern bool page_monitor_init(ITUWidget* widget, char* param);
extern bool page_monitor_timer(ITUWidget* widget, char* param);
extern bool page_monitor_leave(ITUWidget* widget, char* param);
extern bool monitor_cam_switch_fun(ITUWidget* widget, char* param);
extern bool monitor_open_fun(ITUWidget* widget, char* param);
extern bool monitor_menu_fun(ITUWidget* widget, char* param);
extern bool monitor_rec_fun(ITUWidget* widget, char* param);
extern bool monitor_snap_fun(ITUWidget* widget, char* param);
extern bool page_phone_init(ITUWidget* widget, char* param);
extern bool page_phone_timer(ITUWidget* widget, char* param);
extern bool page_phone_leave(ITUWidget* widget, char* param);
extern bool page_phone_refuse(ITUWidget* widget, char* param);
extern bool page_phone_answer(ITUWidget* widget, char* param);
extern bool page_phone_call(ITUWidget* widget, char* param);
extern bool page_view_photo_init(ITUWidget* widget, char* param);
extern bool view_photo_timer(ITUWidget* widget, char* param);
extern bool view_photo_Button_delete_file(ITUWidget* widget, char* param);
extern bool view_photo(ITUWidget* widget, char* param);
extern bool view_photo_Button_fun(ITUWidget* widget, char* param);
extern bool view_photo_back(ITUWidget* widget, char* param);
extern bool view_photo_prv(ITUWidget* widget, char* param);
extern bool view_photo_next(ITUWidget* widget, char* param);
extern bool view_photo_full(ITUWidget* widget, char* param);
extern bool page_view_video_init(ITUWidget* widget, char* param);
extern bool page_view_video_timer(ITUWidget* widget, char* param);
extern bool page_view_video_leave(ITUWidget* widget, char* param);
extern bool view_video_Button_fun_full_close(ITUWidget* widget, char* param);
extern bool view_video_Button_fun_delete_no(ITUWidget* widget, char* param);
extern bool view_video_Button_fun_delete_yes(ITUWidget* widget, char* param);
extern bool view_video_play_stop(ITUWidget* widget, char* param);
extern bool view_video_Button_fun_full(ITUWidget* widget, char* param);
extern bool view_video_Button_fun_vol(ITUWidget* widget, char* param);
extern bool view_video_prev(ITUWidget* widget, char* param);
extern bool view_video_next(ITUWidget* widget, char* param);
extern bool view_video_vol_progress(ITUWidget* widget, char* param);
extern bool view_video_time_progress(ITUWidget* widget, char* param);
extern bool view_video_Button_fun_menu(ITUWidget* widget, char* param);
extern bool view_video(ITUWidget* widget, char* param);
extern bool view_video_Button_fun_delete(ITUWidget* widget, char* param);
extern bool view_video_back(ITUWidget* widget, char* param);
extern bool view_video_full(ITUWidget* widget, char* param);
extern bool page_view_voice_init(ITUWidget* widget, char* param);
extern bool page_view_voice_timer(ITUWidget* widget, char* param);
extern bool page_view_voice_leave(ITUWidget* widget, char* param);
extern bool view_voice_play_stop(ITUWidget* widget, char* param);
extern bool view_voice_menu(ITUWidget* widget, char* param);
extern bool view_voice(ITUWidget* widget, char* param);
extern bool view_voice_next(ITUWidget* widget, char* param);
extern bool view_voice_prev(ITUWidget* widget, char* param);
extern bool view_voice_vol(ITUWidget* widget, char* param);
extern bool page_setup_init(ITUWidget* widget, char* param);
extern bool page_setup_timer(ITUWidget* widget, char* param);
extern bool page_setup_leave(ITUWidget* widget, char* param);
extern bool setup_main_button(ITUWidget* widget, char* param);
extern bool page_auto_view_init(ITUWidget* widget, char* param);
extern bool page_auto_view_timer(ITUWidget* widget, char* param);
extern bool page_auto_view_leave(ITUWidget* widget, char* param);

ITUActionFunction actionFunctions[] =
{
    "page_monitor_init", page_monitor_init,
    "page_monitor_timer", page_monitor_timer,
    "page_monitor_leave", page_monitor_leave,
    "monitor_cam_switch_fun", monitor_cam_switch_fun,
    "monitor_open_fun", monitor_open_fun,
    "monitor_menu_fun", monitor_menu_fun,
    "monitor_rec_fun", monitor_rec_fun,
    "monitor_snap_fun", monitor_snap_fun,
    "page_phone_init", page_phone_init,
    "page_phone_timer", page_phone_timer,
    "page_phone_leave", page_phone_leave,
    "page_phone_refuse", page_phone_refuse,
    "page_phone_answer", page_phone_answer,
    "page_phone_call", page_phone_call,
    "page_view_photo_init", page_view_photo_init,
    "view_photo_timer", view_photo_timer,
    "view_photo_Button_delete_file", view_photo_Button_delete_file,
    "view_photo", view_photo,
    "view_photo_Button_fun", view_photo_Button_fun,
    "view_photo_back", view_photo_back,
    "view_photo_prv", view_photo_prv,
    "view_photo_next", view_photo_next,
    "view_photo_full", view_photo_full,
    "page_view_video_init", page_view_video_init,
    "page_view_video_timer", page_view_video_timer,
    "page_view_video_leave", page_view_video_leave,
    "view_video_Button_fun_full_close", view_video_Button_fun_full_close,
    "view_video_Button_fun_delete_no", view_video_Button_fun_delete_no,
    "view_video_Button_fun_delete_yes", view_video_Button_fun_delete_yes,
    "view_video_play_stop", view_video_play_stop,
    "view_video_Button_fun_full", view_video_Button_fun_full,
    "view_video_Button_fun_vol", view_video_Button_fun_vol,
    "view_video_prev", view_video_prev,
    "view_video_next", view_video_next,
    "view_video_vol_progress", view_video_vol_progress,
    "view_video_time_progress", view_video_time_progress,
    "view_video_Button_fun_menu", view_video_Button_fun_menu,
    "view_video", view_video,
    "view_video_Button_fun_delete", view_video_Button_fun_delete,
    "view_video_back", view_video_back,
    "view_video_full", view_video_full,
    "page_view_voice_init", page_view_voice_init,
    "page_view_voice_timer", page_view_voice_timer,
    "page_view_voice_leave", page_view_voice_leave,
    "view_voice_play_stop", view_voice_play_stop,
    "view_voice_menu", view_voice_menu,
    "view_voice", view_voice,
    "view_voice_next", view_voice_next,
    "view_voice_prev", view_voice_prev,
    "view_voice_vol", view_voice_vol,
    "page_setup_init", page_setup_init,
    "page_setup_timer", page_setup_timer,
    "page_setup_leave", page_setup_leave,
    "setup_main_button", setup_main_button,
    "page_auto_view_init", page_auto_view_init,
    "page_auto_view_timer", page_auto_view_timer,
    "page_auto_view_leave", page_auto_view_leave,
    NULL, NULL
};
