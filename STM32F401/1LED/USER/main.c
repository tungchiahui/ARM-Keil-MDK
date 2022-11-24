#include "stm32f4xx.h"
//#include "usart.h"
#include "delay.h"
#include "led.h"


int main(void)
{
  delay_init(84);
	LED_Init();
	
  while(1)
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_13);     //µ∆¡¡
			LED = 0;
			delay_ms(300);
			LED = 1;
			delay_ms(300);
	  }
}



