#include "exti.h"
#include "delay.h" 
#include "motor.h"
#include "graysensor.h"


//�ⲿ�ж�3�������
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
		
	 EXTI_ClearITPendingBit(EXTI_Line3); //���LINE3�ϵ��жϱ�־λ
}	

//�ⲿ�жϳ�ʼ������
void EXTIX_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;
	
  GRAYSENSOR_Init();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource3);//PA0 ���ӵ��ж���3

  /* ����EXTI_Line0 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line3;//LINE3
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж��¼�
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½��ش���
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//ʹ��LINE3
  EXTI_Init(&EXTI_InitStructure);
	
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;//�ⲿ�ж�3
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//��ռ���ȼ�
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; //���ȼ�
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);

}












