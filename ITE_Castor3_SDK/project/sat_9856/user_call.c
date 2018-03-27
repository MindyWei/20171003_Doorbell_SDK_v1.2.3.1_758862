#include <assert.h>
#include "user_call.h"
#include "function_user.h"

#define DETECT_TYPE			0		//call����ⷽʽ 0:�ж�	1:�߳�
#define DOOR_MAX			2		//���������

#define DOOR_1_ON			31		//�����1 ����GPIO
#define DOOR_2_ON			30		//�����2 ����GPIO
#define DOOR_3_ON			0		//�����3 ����GPIO
#define DOOR_4_ON			0		//�����4 ����GPIO

#define DOOR_1_CALL			27		//�����1 ���GPIO
#define DOOR_2_CALL			28		//�����2 ���GPIO
#define DOOR_3_CALL			0		//�����3 ���GPIO
#define DOOR_4_CALL			0		//�����4���GPIO

#define DOOR_OPEN			100		//���������GPIO	

#define DOOR_1_OPEN		71	
#define DOOR_2_OPEN		70

#define DOOR_HOOK			90


#define ON		0
#define CALL		1

int EVENT_CALL = 0;					//CALL���¼�
int EVENT_CALL_S= 0;					//CALL���¼�
int EVENT_OPEN = 0;					//OPEN�¼�
int EVENT_BACKL= 0;					//���ⳬʱ�¼�
int EVENT_AUTO_V= 0;					//��������¼�
int EVENT_QUTI_A= 0;					//�˳���������¼�
int EVENT_RING= 0;					// �����¼�

int EVENT_UPDATE_REC_TIME= 0;					// ����¼��ʱ���¼�
int EVENT_REC_STATE= 0;					// �ж�¼���¼�
unsigned long EVENT_REC_LAST_TICK;
int EVENT_REC_STOP= 0;					// �ж�¼���¼�

int EVENT_PHONE= 0;					// intcom�¼�
int EVENT_PHONE_HOST= 0;					// ��������

int cur_cvbs_channel = 0;

int  on_monitor_page	= 0;				//�Ƿ��ڼ�ؽ���
static ITULayer* page_monitor;			//��ؽ���Layer

int door_gpio[DOOR_MAX][2] =  {{DOOR_1_ON,DOOR_1_CALL},
								{DOOR_2_ON,DOOR_2_CALL},
								{DOOR_3_ON,DOOR_3_CALL},
								{DOOR_4_ON,DOOR_4_CALL}};

pthread_t call_p[4];			//�߳�ID
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
void *_call_int(int  val)	//�ж��¼�
{
	int i;
	/*�Д� ISR �e����ӡӍϢ������
	����ʹ�� printf��
	��횸��� ithPrintf��
	ithPrintf ���� reentrant function�� */
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
	for(i = 0;i < DOOR_MAX;i++)			//������ϵ�
	{
		if(i != (val - 1))
			ithGpioClear(door_gpio[i][ON]);	
	}
	#endif
	EVENT_CALL = val;					//�¼���־
	gState = SEND_STOP;
	g_videoPlayerIsFileEOF = true;

	//ithPrintf("call_int----------------->over\n");
}

void *_call_thread(int  val)	//�߳��¼�
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
				for(i = 0;i < DOOR_MAX;i++)			//������ϵ�
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
		ithGpioSetMode(DOOR_1_CALL, ITH_GPIO_MODE0);					//����GPIOģʽ
		ithGpioSetIn(DOOR_1_CALL);									//�������		
		ithGpioCtrlEnable(DOOR_1_CALL, ITH_GPIO_PULL_ENABLE);			//�ڲ�����(����)ʹ��
		ithGpioCtrlEnable(DOOR_1_CALL, ITH_GPIO_PULL_UP);				//�ڲ�����
		ithGpioEnable(DOOR_1_CALL);									//ʹ��GPIO	

		//ithEnterCritical();
		ithGpioClearIntr(DOOR_1_CALL); 											//�����ǰ���Д��¼�
		ithGpioRegisterIntrHandler(DOOR_1_CALL, call_event_1, NULL); 	//�]�Դ� GPIO pin �� ISR
		ithGpioCtrlDisable(DOOR_1_CALL, ITH_GPIO_INTR_LEVELTRIGGER);				//�O���Д� trigger ��ʽ��ʹ�� edge trigger
		ithGpioCtrlDisable(DOOR_1_CALL, ITH_GPIO_INTR_BOTHEDGE); 					//�O���Д� edge trigger ��ʽ��ʹ�� both edge
		ithGpioCtrlEnable(DOOR_1_CALL, ITH_GPIO_INTR_TRIGGERFALLING);	
		//ithGpioCtrlEnable(DOOR_1_CALL, ITH_GPIO_INTR_TRIGGERLOW);					//
		ithIntrEnableIrq(ITH_INTR_GPIO); 											//���� GPIO ���Д๦��(�Д������)
		ithGpioEnableIntr(DOOR_1_CALL); 											//���Ӵ� GPIO pin ���Д๦��
		//ithExitCritical(); 	
#else
	for(i = 0;i<DOOR_MAX;i++)		//�����CALL�����GPIO��ʼ��
	{
		ithGpioSetMode(door_gpio[i][CALL], ITH_GPIO_MODE0);				//����GPIOģʽ
		ithGpioSetIn(door_gpio[i][CALL]);									//�������		
		ithGpioCtrlEnable(door_gpio[i][CALL], ITH_GPIO_PULL_ENABLE);			//�ڲ�����(����)ʹ��
		ithGpioCtrlEnable(door_gpio[i][CALL], ITH_GPIO_PULL_UP);				//�ڲ�����
		ithGpioEnable(door_gpio[i][CALL]);									//ʹ��GPIO	

		
		ithIntrEnableIrq(ITH_INTR_GPIO); 												//���� GPIO ���Д๦��(�Д������)

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
		ithGpioClearIntr(door_gpio[i][CALL]); 											//�����ǰ���Д��¼�
		if(i == 0)
			ithGpioRegisterIntrHandler(door_gpio[i][CALL], call_event_1, (void*)door_gpio[i][CALL]); 	//�]�Դ� GPIO pin �� ISR
		else if(i == 1)
			ithGpioRegisterIntrHandler(door_gpio[i][CALL], call_event_2, (void*)door_gpio[i][CALL]); 	
		else if(i == 2)
			ithGpioRegisterIntrHandler(door_gpio[i][CALL], call_event_3, (void*)door_gpio[i][CALL]); 	
		else if(i == 3)
			ithGpioRegisterIntrHandler(door_gpio[i][CALL], call_event_4, (void*)door_gpio[i][CALL]); 	
		
		ithGpioCtrlDisable(door_gpio[i][CALL], ITH_GPIO_INTR_LEVELTRIGGER);				//�O���Д� trigger ��ʽ��ʹ�� edge trigger
		ithGpioCtrlDisable(door_gpio[i][CALL], ITH_GPIO_INTR_BOTHEDGE); 					//�O���Д� edge trigger ��ʽ��ʹ�� both edge
		ithGpioCtrlEnable(door_gpio[i][CALL], ITH_GPIO_INTR_TRIGGERFALLING);				//
		ithIntrEnableIrq(ITH_INTR_GPIO); 												//���� GPIO ���Д๦��(�Д������)
		ithGpioEnableIntr(door_gpio[i][CALL]); 											//���Ӵ� GPIO pin ���Д๦��
		ithExitCritical(); 	
#endif
	}	
#endif 	
	for(i = 0;i<DOOR_MAX;i++)		//���������GPIO��ʼ��
	{
		ithGpioSetMode(door_gpio[i][ON], ITH_GPIO_MODE0);
		ithGpioSetOut(door_gpio[i][ON]);	
		ithGpioClear(door_gpio[i][ON]);	
		ithGpioEnable(door_gpio[i][ON]);	
	}

	//���������GPIO��ʼ��
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
	for(i = 0;i < DOOR_MAX;i++)			//������ϵ�
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
	ithGpioSetMode(DOOR_HOOK, ITH_GPIO_MODE0);				//����GPIOģʽ
	ithGpioSetIn(DOOR_HOOK);									//�������		
	ithGpioCtrlEnable(DOOR_HOOK, ITH_GPIO_PULL_ENABLE);		//�ڲ�����(����)ʹ��
	ithGpioCtrlEnable(DOOR_HOOK, ITH_GPIO_PULL_UP);			//�ڲ�����
	ithGpioEnable(DOOR_HOOK);								//ʹ��GPIO	


/*
	ithEnterCritical();
	ithGpioClearIntr(door_gpio[i][CALL]); 											//�����ǰ���Д��¼�
	ithGpioRegisterIntrHandler(door_gpio[i][CALL], call_event_1, (void*)door_gpio[i][CALL]); 	//�]�Դ� GPIO pin �� ISR
	ithGpioCtrlDisable(door_gpio[i][CALL], ITH_GPIO_INTR_LEVELTRIGGER);				//�O���Д� trigger ��ʽ��ʹ�� edge trigger
	ithGpioCtrlDisable(door_gpio[i][CALL], ITH_GPIO_INTR_BOTHEDGE); 					//�O���Д� edge trigger ��ʽ��ʹ�� both edge
	ithGpioCtrlEnable(door_gpio[i][CALL], ITH_GPIO_INTR_TRIGGERFALLING);				//
	ithIntrEnableIrq(ITH_INTR_GPIO); 												//���� GPIO ���Д๦��(�Д������)
	ithGpioEnableIntr(door_gpio[i][CALL]); 											//���Ӵ� GPIO pin ���Д๦��
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



