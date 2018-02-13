#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scene.h"
#include "doorbell.h"

extern ITUBackgroundButton* phoneResidentRoomBackgroundButton;
extern ITUTextBox* phoneAreaTextBox;
extern ITUTextBox* phoneBuildingTextBox;
extern ITUTextBox* phoneUnitTextBox;
extern ITUTextBox* phoneFloorTextBox;
extern ITUTextBox* phoneRoomTextBox;

extern ITUBackground* phoneResidentIPBackground;
extern ITUTextBox* phoneIPTextBox;

static ITULayer* phoneResidentLayer;
static ITULayer* phoneAdminLayer;
static ITULayer* phoneContactLayer;
static ITULayer* phoneMiscLayer;
static ITUScrollListBox* phoneAdminScrollListBox;
static ITUScrollListBox* phoneMiscScrollListBox;

static ITUBackground* phoneContactAddBackground;
static ITUTextBox* phoneContactAddAreaTextBox;
static ITUTextBox* phoneContactAddBuildingTextBox;
static ITUTextBox* phoneContactAddUnitTextBox;
static ITUTextBox* phoneContactAddFloorTextBox;
static ITUTextBox* phoneContactAddRoomTextBox;

// status
extern ITUTextBox* activePhoneDialTextBox;
extern ITUTextBox* activePhoneContactAddTextBox;

bool PhoneNumberButtonOnPress(ITUWidget* widget, char* param)
{
    if (!phoneResidentLayer)
    {
        phoneResidentLayer = ituSceneFindWidget(&theScene, "phoneResidentLayer");
        assert(phoneResidentLayer);

        phoneContactLayer = ituSceneFindWidget(&theScene, "phoneContactLayer");
        assert(phoneContactLayer);

        phoneMiscLayer = ituSceneFindWidget(&theScene, "phoneMiscLayer");
        assert(phoneMiscLayer);

        phoneContactAddBackground = ituSceneFindWidget(&theScene, "phoneContactAddBackground");
        assert(phoneContactAddBackground);

        phoneContactAddAreaTextBox = ituSceneFindWidget(&theScene, "phoneContactAddAreaTextBox");
        assert(phoneContactAddAreaTextBox);

        phoneContactAddBuildingTextBox = ituSceneFindWidget(&theScene, "phoneContactAddBuildingTextBox");
        assert(phoneContactAddBuildingTextBox);

        phoneContactAddUnitTextBox = ituSceneFindWidget(&theScene, "phoneContactAddUnitTextBox");
        assert(phoneContactAddUnitTextBox);

        phoneContactAddFloorTextBox = ituSceneFindWidget(&theScene, "phoneContactAddFloorTextBox");
        assert(phoneContactAddFloorTextBox);

        phoneContactAddRoomTextBox = ituSceneFindWidget(&theScene, "phoneContactAddRoomTextBox");
        assert(phoneContactAddRoomTextBox);

        activePhoneContactAddTextBox = phoneContactAddAreaTextBox;
    }

    if (ituWidgetIsVisible(phoneResidentLayer))
    {
        ITUButton* btn = (ITUButton*) widget;
        char* input = ituTextGetString(&btn->text);

        if (activePhoneDialTextBox == phoneIPTextBox)
        {
            if (*input == '*')
                *input = '.';
        }
        else
        {
            char* str = ituTextGetString(activePhoneDialTextBox);
            int count = str ? strlen(str) : 0;

            if (activePhoneDialTextBox == phoneAreaTextBox)
            {
                if (count == 0 && input[0] == '#')
                {
                    ituWidgetSetVisible(phoneResidentRoomBackgroundButton, false);
                    ituWidgetSetVisible(phoneResidentIPBackground, true);
                    activePhoneDialTextBox = phoneIPTextBox;
                    ituTextBoxInput(activePhoneDialTextBox, input);
                    return true;
                }
            }

            if (count >= activePhoneDialTextBox->maxLen)
            {
                if (activePhoneDialTextBox == phoneAreaTextBox)
                    activePhoneDialTextBox = phoneBuildingTextBox;
                else if (activePhoneDialTextBox == phoneBuildingTextBox)
                    activePhoneDialTextBox = phoneUnitTextBox;
                else if (activePhoneDialTextBox == phoneUnitTextBox)
                    activePhoneDialTextBox = phoneFloorTextBox;
                else if (activePhoneDialTextBox == phoneFloorTextBox)
                    activePhoneDialTextBox = phoneRoomTextBox;
            }
        }
        ituTextBoxInput(activePhoneDialTextBox, input);
    }
    else if (ituWidgetIsVisible(phoneContactLayer) && ituWidgetIsVisible(phoneContactAddBackground))
    {
        ITUButton* btn = (ITUButton*) widget;
        char* input = ituTextGetString(&btn->text);
        char* str = ituTextGetString(activePhoneContactAddTextBox);
        int count = str ? strlen(str) : 0;

        if (count >= activePhoneContactAddTextBox->maxLen)
        {
            if (activePhoneContactAddTextBox == phoneContactAddAreaTextBox)
                activePhoneContactAddTextBox = phoneContactAddBuildingTextBox;
            else if (activePhoneContactAddTextBox == phoneContactAddBuildingTextBox)
                activePhoneContactAddTextBox = phoneContactAddUnitTextBox;
            else if (activePhoneContactAddTextBox == phoneContactAddUnitTextBox)
                activePhoneContactAddTextBox = phoneContactAddFloorTextBox;
            else if (activePhoneContactAddTextBox == phoneContactAddFloorTextBox)
                activePhoneContactAddTextBox = phoneContactAddRoomTextBox;
        }
        ituTextBoxInput(activePhoneContactAddTextBox, input);
    }
    else
    {
        ituLayerGoto(phoneResidentLayer);
    }
	return true;
}

bool PhoneCallButtonOnPress(ITUWidget* widget, char* param)
{
    if (!phoneAdminLayer)
    {
        if (!phoneResidentLayer)
        {
            phoneResidentLayer = ituSceneFindWidget(&theScene, "phoneResidentLayer");
            assert(phoneResidentLayer);

            phoneContactLayer = ituSceneFindWidget(&theScene, "phoneContactLayer");
            assert(phoneContactLayer);

            phoneMiscLayer = ituSceneFindWidget(&theScene, "phoneMiscLayer");
            assert(phoneMiscLayer);

            phoneContactAddBackground = ituSceneFindWidget(&theScene, "phoneContactAddBackground");
            assert(phoneContactAddBackground);

            phoneContactAddAreaTextBox = ituSceneFindWidget(&theScene, "phoneContactAddAreaTextBox");
            assert(phoneContactAddAreaTextBox);

            phoneContactAddBuildingTextBox = ituSceneFindWidget(&theScene, "phoneContactAddBuildingTextBox");
            assert(phoneContactAddBuildingTextBox);

            phoneContactAddUnitTextBox = ituSceneFindWidget(&theScene, "phoneContactAddUnitTextBox");
            assert(phoneContactAddUnitTextBox);

            phoneContactAddFloorTextBox = ituSceneFindWidget(&theScene, "phoneContactAddFloorTextBox");
            assert(phoneContactAddFloorTextBox);

            phoneContactAddRoomTextBox = ituSceneFindWidget(&theScene, "phoneContactAddRoomTextBox");
            assert(phoneContactAddRoomTextBox);

            activePhoneContactAddTextBox = phoneContactAddAreaTextBox;
        }
        phoneAdminLayer = ituSceneFindWidget(&theScene, "phoneAdminLayer");
        assert(phoneAdminLayer);

        phoneAdminScrollListBox = ituSceneFindWidget(&theScene, "phoneAdminScrollListBox");
        assert(phoneAdminScrollListBox);

        phoneMiscScrollListBox = ituSceneFindWidget(&theScene, "phoneMiscScrollListBox");
        assert(phoneMiscScrollListBox);
    }

    if (ituWidgetIsVisible(phoneResidentLayer))
    {
        if (ituTextGetString(activePhoneDialTextBox))
        {
            if (activePhoneDialTextBox == phoneIPTextBox)
            {
                char* ip = ituTextGetString(phoneIPTextBox);

                if (CallingCallByIP(&ip[1]) == 0)
				    return true; //goto callingLayer
            }
            else if (activePhoneDialTextBox == phoneRoomTextBox)
            {
                if (CallingCall(
                    ituTextGetString(phoneAreaTextBox),
                    ituTextGetString(phoneBuildingTextBox),
                    ituTextGetString(phoneUnitTextBox),
                    ituTextGetString(phoneFloorTextBox),
                    ituTextGetString(phoneRoomTextBox),
                    NULL) == 0)
				    return true; // goto callingLayer
            }
        }
    }
    else if (ituWidgetIsVisible(phoneAdminLayer))
    {
        ITUWidget* item = ituListBoxGetFocusItem(&phoneAdminScrollListBox->listbox);
        if (item)
        {
            DeviceInfo* info = (DeviceInfo*) ituWidgetGetCustomData(item);

		    if (CallingCallManager(info->ip) == 0)
            {
			    return true; // goto callingLayer
		    }
        }
    }
    else if (ituWidgetIsVisible(phoneMiscLayer))
    {
        ITUWidget* item = ituListBoxGetFocusItem(&phoneMiscScrollListBox->listbox);
        if (item)
        {
            DeviceInfo* info = (DeviceInfo*) ituWidgetGetCustomData(item);

		    if (CallingCallByIP(info->ip) == 0)
            {
			    return true; // goto callingLayer
		    }
        }
    }
	return false;
}

void PhoneReset(void)
{
    phoneResidentLayer = NULL;
    phoneAdminLayer = NULL;
}

