#include "usart.h"
#include "delay.h"
#include "pwm.h"
#include "servo.h"



int main(void)
{
	
	uart_init(115200);
	delay_init(168);
	SERVO_Init();
	TIM1_PWM_Init(20000-1,168-1);	//(arr+1)(psc+1)/tclk      tick = 20ms    tclk = 168MHz         //红色正极，黑色褐色负极，黄色白色信号。
	
	
  while(1)
	{	
		TIM_SetCompare1(TIM1,500);
		delay_ms(200);
		
	}
}



