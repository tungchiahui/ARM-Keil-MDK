#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "exti.h"
#include "beep.h"


int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);    //��ʼ����ʱ����
	uart_init(115200); 	//���ڳ�ʼ�� 
	LED_Init();				  //��ʼ��LED�˿�  
	BEEP_Init();
	EXTIX_Init();       //��ʼ���ⲿ�ж����� 
	LED_B=1;//�ȵ����̵�
	BEEP=1;
	
	while(1)
	{
		
	}

}
