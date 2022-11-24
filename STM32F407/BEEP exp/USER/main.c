#include "beep.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

int main(void)
{
	delay_init(168);
	
	BEEP_Init();
	
	while(1)
	{
//    GPIO_SetBits(GPIOH,GPIO_Pin_12);
//    GPIO_SetBits(GPIOD,GPIO_Pin_14); 
//		delay_ms(300);
//		GPIO_ResetBits(GPIOH,GPIO_Pin_12);
//    GPIO_ResetBits(GPIOD,GPIO_Pin_14);		
//		delay_ms(300);
//		
//		GPIO_SetBits(GPIOH,GPIO_Pin_11);  
//		GPIO_SetBits(GPIOD,GPIO_Pin_14);
//		delay_ms(300);
//		GPIO_ResetBits(GPIOH,GPIO_Pin_11);
//		GPIO_ResetBits(GPIOD,GPIO_Pin_14);
//		delay_ms(300);
//		
//		GPIO_SetBits(GPIOH,GPIO_Pin_10); 
//		GPIO_SetBits(GPIOD,GPIO_Pin_14);
//		delay_ms(300);
//		GPIO_ResetBits(GPIOH,GPIO_Pin_10);
//		GPIO_ResetBits(GPIOD,GPIO_Pin_14);
//		delay_ms(300);
//	
//   GPIO_ResetBits(GPIOD,GPIO_Pin_14);
	}
}
