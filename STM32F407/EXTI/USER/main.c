#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "exti.h"
#include "beep.h"


int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);    //初始化延时函数
	uart_init(115200); 	//串口初始化 
	LED_Init();				  //初始化LED端口  
	BEEP_Init();
	EXTIX_Init();       //初始化外部中断输入 
	LED_B=1;//先点亮绿灯
	BEEP=1;
	
	while(1)
	{
		
	}

}
