#ifndef _USER_CALL_H_
#define _USER_CALL_H_

extern int EVENT_CALL;					//CALL机事件
extern int EVENT_CALL_S;					//CALL机事件
extern int EVENT_OPEN;					//OPEN事件
extern int EVENT_BACKL;					//背光超时事件
extern int EVENT_AUTO_V;					//电子相框事件
extern int EVENT_QUTI_A;					//退出电子相框事件

extern int EVENT_RING;					// 响铃事件 
extern int EVENT_UPDATE_REC_TIME;					// 更新录像时间事件
extern int EVENT_REC_STATE;					// 中断录像事件

extern int EVENT_PHONE;					// intcom事件
extern int EVENT_PHONE_HOST;					// 主机号码

extern unsigned long EVENT_REC_LAST_TICK;
extern int EVENT_REC_STOP;					// 中断录像事件

extern int on_monitor_page;				//是否在监控界面
extern int door_gpio[2][2];
extern int cur_cvbs_channel;

extern void user_call_init();








#endif //_USER_CALL_H_