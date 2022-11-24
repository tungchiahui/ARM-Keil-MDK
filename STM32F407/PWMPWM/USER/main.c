#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#include "stm32f4xx.h"

int main(void)
{ 



	u16 led0pwmval=0;
	u8 dir=1;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	TIM4_PWM_Init(65535,1000);
	TIM5_PWM_Init(65535,1000);
	delay_init(168);  	
	uart_init(115200);

   while(1)
	{
 		delay_ms(10);
		if(dir)
			led0pwmval++;
		else
			led0pwmval--;
 		if(led0pwmval>800)
			dir=0;
		if(led0pwmval==0)
			dir=1;
 
		TIM_SetCompare1(TIM5,led0pwmval);
	}
}
