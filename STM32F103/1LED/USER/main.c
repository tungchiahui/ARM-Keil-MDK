#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"


 int main(void)
 {	
	delay_init();	    //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
	LED = 0;
	while(1)
	{
		LED = ~LED;
		delay_ms(300);	 //延时300ms
	}
 }


 /**
 *****************下面注视的代码是通过调用库函数来实现IO控制的方法*****************************************
int main(void)
{ 
 
	delay_init();		  //初始化延时函数
	LED_Init();		        //初始化LED端口
	while(1)
	{
			GPIO_SetBits(GPIOC,GPIO_Pin_5); 
			delay_ms(300);  		   //延时300ms
			GPIO_ResetBits(GPIOC,GPIO_Pin_5);  
			delay_ms(300);  		   //延时300ms
	}
} 
 
 ****************************************************************************************************
 ***/
