#include "stm32f10x.h"
#include "motor.h"
#include "delay.h"
#include "exti.h"
#include "graysensor.h"



 int main(void)
 {	
	 delay_init();
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	 MOTOR_Init();
	 EXTIX_Init();
	 
  while(1)
	{
	
	}
 }
