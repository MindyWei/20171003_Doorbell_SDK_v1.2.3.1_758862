#include <assert.h>
#include "function_user.h"

static ITUBackground* setup_menu_bg_1;
static ITUBackground* setup_menu_bg_2;
static ITUBackground* setup_menu_bg_3;
static ITUBackground* setup_menu_bg_4;
	
static ITUIcon* setup_main_icon_1;
static ITUIcon* setup_main_icon_2;
static ITUIcon* setup_main_icon_3;
static ITUIcon* setup_main_icon_4;

bool page_setup_init(ITUWidget* widget, char* param)
{
	if (!setup_menu_bg_1)
	{
		ITUWidget* widget;

		setup_menu_bg_1 = ituSceneFindWidget(&theScene, "setup_menu_bg_1");
		assert(setup_menu_bg_1);
		setup_menu_bg_2 = ituSceneFindWidget(&theScene, "setup_menu_bg_2");
		assert(setup_menu_bg_2);
		setup_menu_bg_3 = ituSceneFindWidget(&theScene, "setup_menu_bg_3");
		assert(setup_menu_bg_3);
		setup_menu_bg_4 = ituSceneFindWidget(&theScene, "setup_menu_bg_4");
		assert(setup_menu_bg_4);
		
		setup_main_icon_1 = ituSceneFindWidget(&theScene, "setup_main_icon_1");
		assert(setup_main_icon_1);
		setup_main_icon_2 = ituSceneFindWidget(&theScene, "setup_main_icon_2");
		assert(setup_main_icon_2);
		setup_main_icon_3 = ituSceneFindWidget(&theScene, "setup_main_icon_3");
		assert(setup_main_icon_3);
		setup_main_icon_4 = ituSceneFindWidget(&theScene, "setup_main_icon_4");
		assert(setup_main_icon_4);

	}
    return true;
}

bool page_setup_timer(ITUWidget* widget, char* param)
{
    return true;
}

bool page_setup_leave(ITUWidget* widget, char* param)
{
    return true;
}

bool setup_main_button(ITUWidget* widget, char* param)
{
	ituWidgetSetVisible(setup_menu_bg_1,false);
	ituWidgetSetVisible(setup_menu_bg_2,false);
	ituWidgetSetVisible(setup_menu_bg_3,false);
	ituWidgetSetVisible(setup_menu_bg_4,false);
	
	ituWidgetSetVisible(setup_main_icon_1,false);
	ituWidgetSetVisible(setup_main_icon_2,false);
	ituWidgetSetVisible(setup_main_icon_3,false);
	ituWidgetSetVisible(setup_main_icon_4,false);
	switch(param[0])
	{
	case '1':
		ituWidgetSetVisible(setup_menu_bg_1,true);
		ituWidgetSetVisible(setup_main_icon_1,true);
		break;
	case '2':
		ituWidgetSetVisible(setup_menu_bg_2,true);
		ituWidgetSetVisible(setup_main_icon_2,true);
		break;
	case '3':
		ituWidgetSetVisible(setup_menu_bg_3,true);
		ituWidgetSetVisible(setup_main_icon_3,true);
		break;
	case '4':
		ituWidgetSetVisible(setup_menu_bg_4,true);
		ituWidgetSetVisible(setup_main_icon_4,true);
		break;
	}
    return true;
}

