#ifndef _USER_CALL_H_
#define _USER_CALL_H_

extern int EVENT_CALL;					//CALL���¼�
extern int EVENT_CALL_S;					//CALL���¼�
extern int EVENT_OPEN;					//OPEN�¼�
extern int EVENT_BACKL;					//���ⳬʱ�¼�
extern int EVENT_AUTO_V;					//��������¼�
extern int EVENT_QUTI_A;					//�˳���������¼�

extern int EVENT_RING;					// �����¼� 
extern int EVENT_UPDATE_REC_TIME;					// ����¼��ʱ���¼�
extern int EVENT_REC_STATE;					// �ж�¼���¼�

extern int EVENT_PHONE;					// intcom�¼�
extern int EVENT_PHONE_HOST;					// ��������

extern unsigned long EVENT_REC_LAST_TICK;
extern int EVENT_REC_STOP;					// �ж�¼���¼�

extern int on_monitor_page;				//�Ƿ��ڼ�ؽ���
extern int door_gpio[2][2];
extern int cur_cvbs_channel;

extern void user_call_init();








#endif //_USER_CALL_H_