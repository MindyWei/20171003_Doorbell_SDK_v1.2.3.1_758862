#include <assert.h>
#include "user_call.h"
#include "function_user.h"

#define DETECT_TYPE			0		//call机检测方式 0:中断	1:线程
#define DOOR_MAX			2		//户外机数量

#define DOOR_1_ON			31		//户外机1 供电GPIO
#define DOOR_2_ON			30		//户外机2 供电GPIO
#define DOOR_3_ON			0		//户外机3 供电GPIO
#define DOOR_4_ON			0		//户外机4 供电GPIO

#define DOOR_1_CALL			27		//户外机1 检测GPIO
#define DOOR_2_CALL			28		//户外机2 检测GPIO
#define DOOR_3_CALL			0		//户外机3 检测GPIO
#define DOOR_4_CALL			0		//户外机4检测GPIO

#define DOOR_OPEN			100		//户外机开锁GPIO	

#define DOOR_1_OPEN		71	
#define DOOR_2_OPEN		70

#define DOOR_HOOK			90


#define ON		0
#define CALL		1

int EVENT_CALL = 0;					//CALL机事件
int EVENT_CALL_S= 0;					//CALL机事件
int EVENT_OPEN = 0;					//OPEN事件
int EVENT_BACKL= 0;					//背光超时事件
int EVENT_AUTO_V= 0;					//电子相框事件
int EVENT_QUTI_A= 0;					//退出电子相框事件
int EVENT_RING= 0;					// 响铃事件

int EVENT_UPDATE_REC_TIME= 0;					// 更新录像时间事件
int EVENT_REC_STATE= 0;					// 中断录像事件
unsigned long EVENT_REC_LAST_TICK;
int EVENT_REC_STOP= 0;					// 中断录像事件

int EVENT_PHONE= 0;					// intcom事件
int EVENT_PHONE_HOST= 0;					// 主机号码

int cur_cvbs_channel = 0;

int  on_monitor_page	= 0;				//是否在监控界面
static ITULayer* page_monitor;			//监控界面Layer

int door_gpio[DOOR_MAX][2] =  {{DOOR_1_ON,DOOR_1_CALL},
								{DOOR_2_ON,DOOR_2_CALL},
								{DOOR_3_ON,DOOR_3_CALL},
								{DOOR_4_ON,DOOR_4_CALL}};

pthread_t call_p[4];			//线程ID
pthread_attr_t call_pat[4];


#define CD4051_A				91
#define CD4051_B				92

void switch_cam_power( uint8_t val)
{
	if(val == 1)
	{	
		ithGpioClear(door_gpio[1][ON]);	
		ithGpioSet(door_gpio[0][ON]);
		ithGpioSet(CD4051_A);
		ithGpioClear(CD4051_B);	
	}
	else if(val == 2)
	{
		ithGpioClear(door_gpio[0][ON]);	
		ithGpioSet(door_gpio[1][ON]);
		ithGpioSet(CD4051_B);
		ithGpioClear(CD4051_A);	
	}
}
void *_call_int(int  val)	//中断事件
{
	int i;
	/*中斷 ISR 裡如有印訊息的需求，
	不能使用 printf，
	必須改用 ithPrintf，
	ithPrintf 才是 reentrant function。 */
	//ithPrintf("call_int----------------->%d\n",val);
	#if 0
	ithGpioSet(door_gpio[(val - 1)][ON]);
	
	if(val == 1)
	{	
		ithGpioSet(CD4051_A);
		ithGpioClear(CD4051_B);	
	}
	else if(val == 2)
	{
		ithGpioSet(CD4051_B);
		ithGpioClear(CD4051_A);	
	}
	for(i = 0;i < DOOR_MAX;i++)			//户外机上电
	{
		if(i != (val - 1))
			ithGpioClear(door_gpio[i][ON]);	
	}
	#endif
	EVENT_CALL = val;					//事件标志
	gState = SEND_STOP;
	g_videoPlayerIsFileEOF = true;

	//ithPrintf("call_int----------------->over\n");
}

void *_call_thread(int  val)	//线程事件
{
	printf("_call_thread...............................%d\n",val);
	int i;
	bool cur_gpio_rc = 1;
	bool prv_gpio_rc = 1;
	
	while(1)
	{
		usleep(1000);
		cur_gpio_rc = ithGpioGet(door_gpio[val-1][CALL]);
		if(prv_gpio_rc != cur_gpio_rc)
		{
			prv_gpio_rc = cur_gpio_rc; 
			if(!cur_gpio_rc)
			{
				for(i = 0;i < DOOR_MAX;i++)			//户外机上电
				{
					if(i == val - 1)
						ithGpioSet(door_gpio[i][ON]);	
					else
						ithGpioClear(door_gpio[i][ON]);	
				}	
				EVENT_CALL = val;
				if(on_monitor_page == 0)
				{
					if (!page_monitor)
				       {
				           page_monitor = ituSceneFindWidget(&theScene, "page_monitor");
				           assert(page_monitor);
				       }
					ituLayerGoto(page_monitor);
					on_monitor_page = 1;
				}
			}
		}
	}
}
void call_event_1(void *val)
{
	if(!DETECT_TYPE)
		_call_int(1);
	else
		_call_thread(1);
}
void call_event_2()
{
	if(!DETECT_TYPE)
		_call_int(2);
	else
		_call_thread(2);
}
void call_event_3()
{
	if(!DETECT_TYPE)
		_call_int(3);
	else
		_call_thread(3);
}
void call_event_4()
{
	if(!DETECT_TYPE)
		_call_int(4);
	else
		_call_thread(4);
}
	
void user_call_init()
{
	int i = 0 ;
#if 0
		ithGpioSetMode(DOOR_1_CALL, ITH_GPIO_MODE0);					//设置GPIO模式
		ithGpioSetIn(DOOR_1_CALL);									//输入检测口		
		ithGpioCtrlEnable(DOOR_1_CALL, ITH_GPIO_PULL_ENABLE);			//内部上拉(下拉)使能
		ithGpioCtrlEnable(DOOR_1_CALL, ITH_GPIO_PULL_UP);				//内部上拉
		ithGpioEnable(DOOR_1_CALL);									//使能GPIO	

		//ithEnterCritical();
		ithGpioClearIntr(DOOR_1_CALL); 											//清除先前的中斷事件
		ithGpioRegisterIntrHandler(DOOR_1_CALL, call_event_1, NULL); 	//註冊此 GPIO pin 的 ISR
		ithGpioCtrlDisable(DOOR_1_CALL, ITH_GPIO_INTR_LEVELTRIGGER);				//設定中斷 trigger 方式是使用 edge trigger
		ithGpioCtrlDisable(DOOR_1_CALL, ITH_GPIO_INTR_BOTHEDGE); 					//設定中斷 edge trigger 方式是使用 both edge
		ithGpioCtrlEnable(DOOR_1_CALL, ITH_GPIO_INTR_TRIGGERFALLING);	
		//ithGpioCtrlEnable(DOOR_1_CALL, ITH_GPIO_INTR_TRIGGERLOW);					//
		ithIntrEnableIrq(ITH_INTR_GPIO); 											//啟動 GPIO 的中斷功能(中斷控制器)
		ithGpioEnableIntr(DOOR_1_CALL); 											//啟動此 GPIO pin 的中斷功能
		//ithExitCritical(); 	
#else
	for(i = 0;i<DOOR_MAX;i++)		//户外机CALL机检测GPIO初始化
	{
		ithGpioSetMode(door_gpio[i][CALL], ITH_GPIO_MODE0);				//设置GPIO模式
		ithGpioSetIn(door_gpio[i][CALL]);									//输入检测口		
		ithGpioCtrlEnable(door_gpio[i][CALL], ITH_GPIO_PULL_ENABLE);			//内部上拉(下拉)使能
		ithGpioCtrlEnable(door_gpio[i][CALL], ITH_GPIO_PULL_UP);				//内部上拉
		ithGpioEnable(door_gpio[i][CALL]);									//使能GPIO	

		
		ithIntrEnableIrq(ITH_INTR_GPIO); 												//啟動 GPIO 的中斷功能(中斷控制器)

#if DETECT_TYPE
		pthread_attr_init(&call_p[i]);
		pthread_attr_setdetachstate(&call_pat[i], PTHREAD_CREATE_DETACHED);
		if(i == 0)
			pthread_create(&call_p[i],NULL, call_event_1, NULL);
		else if(i == 1)
			pthread_create(&call_p[i],NULL, call_event_2, NULL);
		else if(i == 2)
			pthread_create(&call_p[i],NULL, call_event_3, NULL);
		else if(i == 3)
			pthread_create(&call_p[i],NULL, call_event_4, NULL);
#else
		ithEnterCritical();
		ithGpioClearIntr(door_gpio[i][CALL]); 											//清除先前的中斷事件
		if(i == 0)
			ithGpioRegisterIntrHandler(door_gpio[i][CALL], call_event_1, (void*)door_gpio[i][CALL]); 	//註冊此 GPIO pin 的 ISR
		else if(i == 1)
			ithGpioRegisterIntrHandler(door_gpio[i][CALL], call_event_2, (void*)door_gpio[i][CALL]); 	
		else if(i == 2)
			ithGpioRegisterIntrHandler(door_gpio[i][CALL], call_event_3, (void*)door_gpio[i][CALL]); 	
		else if(i == 3)
			ithGpioRegisterIntrHandler(door_gpio[i][CALL], call_event_4, (void*)door_gpio[i][CALL]); 	
		
		ithGpioCtrlDisable(door_gpio[i][CALL], ITH_GPIO_INTR_LEVELTRIGGER);				//設定中斷 trigger 方式是使用 edge trigger
		ithGpioCtrlDisable(door_gpio[i][CALL], ITH_GPIO_INTR_BOTHEDGE); 					//設定中斷 edge trigger 方式是使用 both edge
		ithGpioCtrlEnable(door_gpio[i][CALL], ITH_GPIO_INTR_TRIGGERFALLING);				//
		ithIntrEnableIrq(ITH_INTR_GPIO); 												//啟動 GPIO 的中斷功能(中斷控制器)
		ithGpioEnableIntr(door_gpio[i][CALL]); 											//啟動此 GPIO pin 的中斷功能
		ithExitCritical(); 	
#endif
	}	
#endif 	
	for(i = 0;i<DOOR_MAX;i++)		//户外机供电GPIO初始化
	{
		ithGpioSetMode(door_gpio[i][ON], ITH_GPIO_MODE0);
		ithGpioSetOut(door_gpio[i][ON]);	
		ithGpioClear(door_gpio[i][ON]);	
		ithGpioEnable(door_gpio[i][ON]);	
	}

	//户外机开锁GPIO初始化
	ithGpioSetMode(DOOR_OPEN, ITH_GPIO_MODE0);
	ithGpioSetOut(DOOR_OPEN);	
	ithGpioClear(DOOR_OPEN);	
	ithGpioEnable(DOOR_OPEN);
	
	ithGpioSetMode(DOOR_1_OPEN, ITH_GPIO_MODE0);
	ithGpioSetOut(DOOR_1_OPEN);	
	ithGpioClear(DOOR_1_OPEN);	
	ithGpioEnable(DOOR_1_OPEN);	
	
	ithGpioSetMode(DOOR_2_OPEN, ITH_GPIO_MODE0);
	ithGpioSetOut(DOOR_2_OPEN);
	ithGpioClear(DOOR_2_OPEN);	
	ithGpioEnable(DOOR_2_OPEN);
}

void exit_monitor()
{
	int i;
	for(i = 0;i < DOOR_MAX;i++)			//户外机上电
	{
		ithGpioClear(door_gpio[i][ON]);	
	}
}

void user_open_door()
{
	EVENT_OPEN = 1;
	ithGpioSet(DOOR_OPEN);
	door_open_start();
	
}
void HOOK_ON_init()
{
	ithGpioSetMode(DOOR_HOOK, ITH_GPIO_MODE0);				//设置GPIO模式
	ithGpioSetIn(DOOR_HOOK);									//输入检测口		
	ithGpioCtrlEnable(DOOR_HOOK, ITH_GPIO_PULL_ENABLE);		//内部上拉(下拉)使能
	ithGpioCtrlEnable(DOOR_HOOK, ITH_GPIO_PULL_UP);			//内部上拉
	ithGpioEnable(DOOR_HOOK);								//使能GPIO	


/*
	ithEnterCritical();
	ithGpioClearIntr(door_gpio[i][CALL]); 											//清除先前的中斷事件
	ithGpioRegisterIntrHandler(door_gpio[i][CALL], call_event_1, (void*)door_gpio[i][CALL]); 	//註冊此 GPIO pin 的 ISR
	ithGpioCtrlDisable(door_gpio[i][CALL], ITH_GPIO_INTR_LEVELTRIGGER);				//設定中斷 trigger 方式是使用 edge trigger
	ithGpioCtrlDisable(door_gpio[i][CALL], ITH_GPIO_INTR_BOTHEDGE); 					//設定中斷 edge trigger 方式是使用 both edge
	ithGpioCtrlEnable(door_gpio[i][CALL], ITH_GPIO_INTR_TRIGGERFALLING);				//
	ithIntrEnableIrq(ITH_INTR_GPIO); 												//啟動 GPIO 的中斷功能(中斷控制器)
	ithGpioEnableIntr(door_gpio[i][CALL]); 											//啟動此 GPIO pin 的中斷功能
	ithExitCritical(); 	
	*/
}
/*
void xxxx_uart()
{
	char getstr[256]; 
	char sendtr[256]= "get success...............";
	int len = 0;
	len = read(ITP_DEVICE_UART2,getstr,256);
	if( len)
		write(ITP_DEVICE_UART2,sendtr,256); 
}
*/



