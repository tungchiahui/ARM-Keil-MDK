#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "main.h"


int main(void)
{
	uart_init(115200);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	CAN1_mode_init(CAN_SJW_1tq,CAN_BS2_6tq,CAN_BS1_7tq,3,CAN_Mode_Normal);
	pid_chassis_init();
	TIM2_Int_Init(50,8400-1);
  delay_ms(100);
	
  while(1)
	{
	
		
		
		
	}
}




