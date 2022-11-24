#include "usart.h"
#include "delay.h"
#include "pwm.h"
#include "servo.h"



int main(void)
{
	
	uart_init(115200);
	delay_init(168);
	SERVO_Init();
	TIM1_PWM_Init(20000-1,168-1);	//(arr+1)(psc+1)/tclk      tick = 20ms    tclk = 168MHz         //��ɫ��������ɫ��ɫ��������ɫ��ɫ�źš�
	
	
  while(1)
	{	
		TIM_SetCompare1(TIM1,500);
		delay_ms(200);
		
	}
}



