#include "sys.h"

#ifndef __KEY_H
#define __KEY_H	 


/*����ķ�ʽ��ͨ��ֱ�Ӳ����⺯����ʽ��ȡIO*/
#define  KEY  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)	//PA0


/*���淽ʽ��ͨ��λ��������ʽ��ȡIO*/
/*
#define KEY 	PAin(0)		//PA0
*/


#define KEY_PRES 1

void KEY_Init(void);	//IO��ʼ��
u8 KEY_Scan(u8); //����ɨ�躯��	

#endif
