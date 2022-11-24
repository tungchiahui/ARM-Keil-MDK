#ifndef __LED_H
#define __LED_H
#include "sys.h"


//LED端口定义
#define LED_B PHout(10)
#define LED_G PHout(11)
#define LED_R PHout(12)

void LED_Init(void);//初始化		 				    
#endif
