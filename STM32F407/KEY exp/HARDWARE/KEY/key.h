#include "sys.h"

#ifndef __KEY_H
#define __KEY_H	 


/*下面的方式是通过直接操作库函数方式读取IO*/
#define  KEY  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)	//PA0


/*下面方式是通过位带操作方式读取IO*/
/*
#define KEY 	PAin(0)		//PA0
*/


#define KEY_PRES 1

void KEY_Init(void);	//IO初始化
u8 KEY_Scan(u8); //按键扫描函数	

#endif
