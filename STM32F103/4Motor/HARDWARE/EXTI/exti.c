#include "exti.h"
#include "delay.h" 
#include "motor.h"
#include "graysensor.h"


//外部中断3服务程序
void EXTI3_IRQHandler(void)
{
	delay_ms(50);
	if(GRAYBIT == 0) 
	{
		MOTOR1 = 1;
		MOTOR2 = 0;
	}
  if(GRAYBIT == 1)
	{
	MOTOR1 = 0;
	MOTOR2 = 0;	
	}
		
	 EXTI_ClearITPendingBit(EXTI_Line3); //清除LINE3上的中断标志位
}	

//外部中断初始化程序
void EXTIX_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;
	
  GRAYSENSOR_Init();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource3);//PA0 连接到中断线3

  /* 配置EXTI_Line0 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line3;//LINE3
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断事件
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//使能LINE3
  EXTI_Init(&EXTI_InitStructure);
	
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;//外部中断3
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//抢占优先级
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; //优先级
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);

}












