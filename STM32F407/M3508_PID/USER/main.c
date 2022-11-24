#include "main.h"

extern struct 
 {
 int16_t ch0;
 int16_t ch1;
 int16_t ch2;
 int16_t ch3;
 int16_t ch4; 
 int8_t s1;
 int8_t s2;
 }rc;
int main(void)

{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);	
	CAN1_mode_init(CAN_SJW_1tq,CAN_BS2_6tq,CAN_BS1_7tq,3,CAN_Mode_Normal);
	pid_chassis_init();
	uart_init(115200);
	TIM2_Int_Init(50,8400-1);
  delay_ms(100);
	
  while(1)
	{
		
	}
		
}
	












