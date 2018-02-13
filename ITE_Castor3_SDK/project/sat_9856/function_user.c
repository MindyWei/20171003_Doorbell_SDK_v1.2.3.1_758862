#include "function_user.h"
int video_play_status = P_S_READY;
int voice_play_status = P_S_READY;


bool switch_state[SWITCH_TOTAL] ={false};

bool PlayerStop = false;
 
bool switch_on_off(int num)
{
	if(switch_state[num])
	{
		switch_state[num] = false;
		return true;
	}
	else
	{
		switch_state[num] = true;
		return false;
	}
}

void switch_init()
{
	int i;
	
	for(i = 0; i < SWITCH_TOTAL; i++)
	{
		switch_state[i] = false;
	}
}
int test_num = 0;

char Tfile[] = "D:/video/1.avi";	//播放的文件名

#define DVDD_COUNT			63
#define BL_EN_PWM			64
#define LCD_LD_EN			65

#define CD4051_A				91
#define CD4051_B				92



void user_gpio_init()
{
	
	ithGpioSetMode(DVDD_COUNT, ITH_GPIO_MODE0);
	ithGpioSetOut(DVDD_COUNT);	
	ithGpioSet(DVDD_COUNT);	
	ithGpioEnable(DVDD_COUNT);	
	
	ithGpioSetMode(BL_EN_PWM, ITH_GPIO_MODE0);
	ithGpioSetOut(BL_EN_PWM);
	ithGpioSet(BL_EN_PWM);	
	ithGpioEnable(BL_EN_PWM);	


	ithGpioSetMode(CD4051_A, ITH_GPIO_MODE0);
	ithGpioSetOut(CD4051_A);	
	ithGpioSet(CD4051_A);	
	ithGpioEnable(CD4051_A);	

	ithGpioSetMode(CD4051_B, ITH_GPIO_MODE0);
	ithGpioSetOut(CD4051_B);	
	ithGpioSet(CD4051_B);	
	ithGpioEnable(CD4051_B);
		
}

void backlight_open()
{
	ithGpioSet(DVDD_COUNT);	
	ithGpioSet(BL_EN_PWM);
}

void backlight_close()
{
	ithGpioClear(DVDD_COUNT);	
	ithGpioClear(BL_EN_PWM);
}

 timer_t door_open_TimerId;		//开锁定时器	1S
 #define	 door_open_Time		1
 timer_t back_light_TimerId;		//背光定时器	60S
 #define	 back_light_Time		60
 timer_t auto_start_TimerId;		//相框启动定时器	10S
 #define	 auto_start_Time		10
 timer_t auto_view_TimerId;		//相框切换定时器	5S
 #define	 auto_view_Time		10


void auto_start_start()
{
    struct itimerspec value;

    value.it_value.tv_sec   = auto_start_Time;
    value.it_value.tv_nsec  = 0;
    value.it_interval.tv_sec = value.it_interval.tv_nsec = 0;
	
    timer_settime(auto_start_TimerId, 0, &value, NULL);
}

void auto_start_over(timer_t timerid, int arg)
{
	EVENT_AUTO_V = 1;
}

void auto_view_start()
{
    struct itimerspec value;

    value.it_value.tv_sec   = auto_view_Time;
    value.it_value.tv_nsec  = 0;
    value.it_interval.tv_sec = value.it_interval.tv_nsec = 0;
	
    timer_settime(auto_view_TimerId, 0, &value, NULL);
}


void auto_view_over(timer_t timerid, int arg)
{
	if(on_auto_view_page)
	{
		auto_view_photo();
		 auto_view_start();
	}
}

void door_open_start()
{
    struct itimerspec value;

    value.it_value.tv_sec   = door_open_Time;
    value.it_value.tv_nsec  = 0;
    value.it_interval.tv_sec = value.it_interval.tv_nsec = 0;
	
    timer_settime(door_open_TimerId, 0, &value, NULL);
}


void door_open_over(timer_t timerid, int arg)
{
	EVENT_OPEN = 0;
	//ithGpioClear(DOOR_OPEN);	
	ithGpioClear(100);	
}

void back_light_start()
{
	struct itimerspec value;

	value.it_value.tv_sec   = back_light_Time;
	value.it_value.tv_nsec  = 0;
	value.it_interval.tv_sec = value.it_interval.tv_nsec = 0;

	timer_settime(back_light_TimerId, 0, &value, NULL);
	timer_delete(auto_start_TimerId);
	timer_create(CLOCK_REALTIME, NULL, &auto_start_TimerId);
	timer_connect(auto_start_TimerId, auto_start_over, 0);
}

void back_light_over(timer_t timerid, int arg)
{
	#if 0
	EVENT_BACKL = 1;
	//home_event_process();
	#else
	#endif
}

void user_timer_init()
{
    timer_create(CLOCK_REALTIME, NULL, &door_open_TimerId);
    timer_connect(door_open_TimerId, door_open_over, 0);
	
    timer_create(CLOCK_REALTIME, NULL, &back_light_TimerId);
    timer_connect(back_light_TimerId, back_light_over, 0);
	
    timer_create(CLOCK_REALTIME, NULL, &auto_start_TimerId);
    timer_connect(auto_start_TimerId, auto_start_over, 0);
	
    timer_create(CLOCK_REALTIME, NULL, &auto_view_TimerId);
    timer_connect(auto_view_TimerId, auto_view_over, 0);



}
static int AudioPlayerPlayCallback(int state)
{
    return 0;
}
void _user_ring_init()
{
	while(1)
	{
		usleep(10);
		switch(EVENT_RING)
		{
			case 1:
				printf("ring------------------------>1\n");
				AudioSetVolume(40);
				AudioStop();
				AudioPlay("A:/sounds/call.mp3", AudioPlayerPlayCallback);
				
				break;
			case 2:
				printf("ring------------------------>2\n");
				AudioSetVolume(40);
				AudioStop();
				AudioPlay("A:/sounds/open.mp3", AudioPlayerPlayCallback);
				break;
			case 3:
				break;
		}
		EVENT_RING = 0;
	}
}
		
void user_ring_init()
{
#if 1
	pthread_t user_ring_p;			//线程ID
	pthread_attr_t user_ring_pat;
	pthread_attr_init(&user_ring_p);
	pthread_attr_setdetachstate(&user_ring_pat, PTHREAD_CREATE_DETACHED);
	pthread_create(&user_ring_p,NULL, _user_ring_init, NULL);
#endif
}

void SAT_BOARD_INIT()
{
	uint8_t addr = 0x00;
	uint8_t val = 0x01;

	//CVBS 控制开关初始化
	mmpIicSendData(1, 1, 0x06>>1, addr, &val, 2);

	//户外机power 初始化
	ithGpioSetMode(31, ITH_GPIO_MODE0);
	ithGpioSetOut(31);	
	ithGpioSet(31);	
	ithGpioEnable(31);	

	ithGpioSetMode(100, ITH_GPIO_MODE0);
	ithGpioSetOut(100);	
	ithGpioClear(100);	
	ithGpioEnable(100);

	ithGpioSetMode(71, ITH_GPIO_MODE0);
	ithGpioSetOut(71);	
	ithGpioClear(71);	
	ithGpioEnable(71);	

	ithGpioSetMode(70, ITH_GPIO_MODE0);
	ithGpioSetOut(70);
	ithGpioClear(70);	
	ithGpioEnable(70);
	
	//PR2000 上电复位
	ithGpioSetMode(70 , ITH_GPIO_MODE0);
	ithGpioSetOut(70);
	ithGpioEnable(70);
	ithGpioSet(70);
	usleep(10*1000);
	ithGpioClear(70);
	usleep(10*1000);
	ithGpioSet(70);
}


