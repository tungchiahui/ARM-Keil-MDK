#include "sys.h"
#include "led.h"
#include "delay.h"

int main(void)
{
	delay_init(168);
	
	LED_Init();
	
	while(1)
	{
		GPIO_SetBits(GPIOH,GPIO_Pin_12); 		//红色
		GPIO_ResetBits(GPIOH,GPIO_Pin_12); 	
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_11);    //绿色
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_11);
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_10); 		//蓝色
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_10);
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_11 | GPIO_Pin_12);    //黄色
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_11 | GPIO_Pin_12);
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_12);    //紫色
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_12);
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_11);    //浅蓝色
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_11);
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12);    //白色
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12);
		delay_ms(300);
	}
}

