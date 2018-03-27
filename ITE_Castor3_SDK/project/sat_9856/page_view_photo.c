#include <assert.h>
#include "function_user.h"

static ITUScrollMediaFileListBox* view_photo_file_list;
static ITUText* view_photo_Text_file_name;
static ITUIcon* view_photo_windos;
static ITUBackgroundButton* view_photo_bg_button_switch;
static ITUBackgroundButton* view_photo_bg_button_back;
static ITUBackground* view_photo_menu;
static ITUBackground* view_photo_title;

char imagePlayerPath[1024];
bool imagePlayerLoading, imagePlayerLoaded;
static uint8_t* imagePlayerData;
static int imagePlayerDataSize;

bool view_photo(ITUWidget* widget, char* param);


bool page_view_photo_init(ITUWidget* widget, char* param)
{
	StorageType storageType;
	view_photo_file_list = ituSceneFindWidget(&theScene, "view_photo_file_list");
	assert(view_photo_file_list);
	view_photo_Text_file_name = ituSceneFindWidget(&theScene, "view_photo_Text_file_name");
	assert(view_photo_Text_file_name);
	view_photo_windos = ituSceneFindWidget(&theScene, "view_photo_windos");
	assert(view_photo_windos);
	view_photo_bg_button_switch = ituSceneFindWidget(&theScene, "view_photo_bg_button_switch");
	assert(view_photo_bg_button_switch);
	view_photo_bg_button_back = ituSceneFindWidget(&theScene, "view_photo_bg_button_back");
	assert(view_photo_bg_button_back);
	view_photo_menu = ituSceneFindWidget(&theScene, "view_photo_menu");
	assert(view_photo_menu);
	view_photo_title = ituSceneFindWidget(&theScene, "view_photo_title");
	assert(view_photo_title);

	switch_init();
	printf("focusIndex----------->%d\n",view_photo_file_list->mflistbox.listbox.focusIndex);
	printf("pageIndex----------->%d\n",view_photo_file_list->mflistbox.listbox.pageIndex);
	view_photo_file_list->mflistbox.listbox.focusIndex = 0;
	view_photo_file_list->mflistbox.listbox.pageIndex = 1;
	ituScrollMediaFileListBoxGetCurrPageItem(view_photo_file_list);
	view_photo(widget,param);
	ituWidgetEnable(view_photo_bg_button_switch);
	ituWidgetDisable(view_photo_bg_button_back);
	storageType = StorageGetCurrType();
	 ituMediaFileListSetPath(&view_photo_file_list->mflistbox, StorageGetDrivePath(storageType));
	
	ituWidgetSetVisible(view_photo_windos, false);
        imagePlayerLoading = imagePlayerLoaded = false;
        if (imagePlayerDataSize > 0)
        {
            free(imagePlayerData);
            imagePlayerData = NULL;
            imagePlayerDataSize = 0;
        }
	view_photo(widget,param);
	return true;
}

bool view_photo_Button_fun(ITUWidget* widget, char* param)
{
	switch(param[0])
	{
		case '1':			//menu
			return (switch_on_off(VIEW_PHOTO_S_MENU));
		case '2':			//delete
			return(switch_on_off(VIEW_PHOTO_S_DELETE));
		case '3':			//yes
			break;
	}
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
bool view_photo(ITUWidget* widget, char* param)
{
	printf("focusIndex----------->%d\n",view_photo_file_list->mflistbox.listbox.focusIndex);
	printf("pageIndex----------->%d\n",view_photo_file_list->mflistbox.listbox.pageIndex);
	printf("pageCount----------->%d\n",view_photo_file_list->mflistbox.listbox.pageCount);
	printf("itemCount----------->%d\n",view_photo_file_list->mflistbox.listbox.itemCount);
	//printf("pageIndexText----------->%s\n",view_photo_file_list->mflistbox.listbox.pageIndexText->string);
	//printf("pageCountText----------->%s\n",view_photo_file_list->mflistbox.listbox.pageCountText->string);
	  if (((ITUListBox*)view_photo_file_list)->focusIndex >= 0 && !imagePlayerLoaded  &&  !imagePlayerDataSize && !imagePlayerLoading)
    {
        ITUScrollText* item = ituMediaFileListPlay((ITUMediaFileListBox*)view_photo_file_list);
        if (item)
        {
            char* filepath = (char*)ituWidgetGetCustomData(item);

            printf("Try to load %s\n", filepath);
		char *cur_filename = &filepath[9];
		ituTextSetString(view_photo_Text_file_name, cur_filename);
            strncpy(imagePlayerPath, filepath, PATH_MAX);

            imagePlayerLoading = true;
        }
    }
    return true;
}

bool view_photo_prv(ITUWidget* widget, char* param)
{
	  if (((ITUListBox*)view_photo_file_list)->focusIndex >= 0 && !imagePlayerLoaded  &&  !imagePlayerDataSize && !imagePlayerLoading)
    {
        ITUScrollText* item = ituMediaFileListPrev((ITUMediaFileListBox*)view_photo_file_list);
        if (item)
        {
            char* filepath = (char*)ituWidgetGetCustomData(item);

            printf("Try to load %s\n", filepath);
		char *cur_filename = &filepath[3];
		ituTextSetString(view_photo_Text_file_name, cur_filename);
            strncpy(imagePlayerPath, filepath, PATH_MAX);

            imagePlayerLoading = true;
                        AudioPlayKeySound();
        }
    }
    return false;
}

bool view_photo_next(ITUWidget* widget, char* param)
{
	  if (((ITUListBox*)view_photo_file_list)->focusIndex >= 0 && !imagePlayerLoaded  &&  !imagePlayerDataSize && !imagePlayerLoading)
    {
        ITUScrollText* item = ituMediaFileListNext((ITUMediaFileListBox*)view_photo_file_list);
        if (item)
        {
            char* filepath = (char*)ituWidgetGetCustomData(item);

            printf("Try to load %s\n", filepath);
		char *cur_filename = &filepath[3];
		ituTextSetString(view_photo_Text_file_name, cur_filename);
            strncpy(imagePlayerPath, filepath, PATH_MAX);

            imagePlayerLoading = true;
                        AudioPlayKeySound();
        }
    }
    return false;
}

bool view_photo_back(ITUWidget* widget, char* param)
{
	if(switch_state[VIEW_PHOTO_S_DELETE])
	{
		switch_state[VIEW_PHOTO_S_DELETE] = false;
		ituWidgetHide(view_photo_title, ITU_EFFECT_NONE, 0);
			
	}
	else if(switch_state[VIEW_PHOTO_S_MENU])
	{
		switch_state[VIEW_PHOTO_S_MENU] = false;
		ituWidgetHide(view_photo_menu, ITU_EFFECT_SCROLL_RIGHT, 0);
		ituWidgetDisable(view_photo_bg_button_back);
		ituWidgetEnable(view_photo_bg_button_switch);
	}
		
    return true;
}
bool view_photo_timer(ITUWidget* widget, char* param)
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
        ituIconLoadJpegData(view_photo_windos, imagePlayerData, imagePlayerDataSize);
        ituWidgetSetVisible(view_photo_windos, true);
        ituWidgetSetVisible(view_photo_windos, true);
        free(imagePlayerData);
        imagePlayerData = NULL;
        imagePlayerDataSize = 0;
        imagePlayerLoaded = false;
    }

	//swtich_control
	
    return true;
}

bool view_photo_full(ITUWidget* widget, char* param)
{
	if(switch_on_off(VIEW_PHOTO_S_FULL))
		return false;
	else
		return true;
	//return(!switch_on_off(VIEW_PHOTO_S_FULL));
}

bool view_photo_Button_delete_file(ITUWidget* widget, char* param)
{
    return true;
}

