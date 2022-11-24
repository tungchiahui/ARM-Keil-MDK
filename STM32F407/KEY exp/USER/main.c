#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"



int main(void)
{ 
 
  u8 key;           //保存键值
	delay_init(168);  //初始化延时函数
	LED_Init();				//初始化LED端口 
	BEEP_Init();      //初始化蜂鸣器端口
	KEY_Init();       //初始化与按键连接的硬件接口
	LED_B=1;
	
	while(1)
 {
		key=KEY_Scan(0);		//得到键值
	   	if(key)
			{
				LED_B=!LED_B;
				BEEP=!BEEP;
			}
		  else
				delay_ms(100);
 }
}
