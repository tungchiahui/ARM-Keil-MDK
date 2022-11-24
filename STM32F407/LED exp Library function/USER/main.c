#include "sys.h"
#include "led.h"
#include "delay.h"

int main(void)
{
	delay_init(168);
	
	LED_Init();
	
	while(1)
	{
		GPIO_SetBits(GPIOH,GPIO_Pin_12); 		//��ɫ
		GPIO_ResetBits(GPIOH,GPIO_Pin_12); 	
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_11);    //��ɫ
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_11);
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_10); 		//��ɫ
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_10);
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_11 | GPIO_Pin_12);    //��ɫ
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_11 | GPIO_Pin_12);
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_12);    //��ɫ
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_12);
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_11);    //ǳ��ɫ
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_11);
		delay_ms(300);
		
		GPIO_SetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12);    //��ɫ
		delay_ms(300);
		GPIO_ResetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12);
		delay_ms(300);
	}
}

