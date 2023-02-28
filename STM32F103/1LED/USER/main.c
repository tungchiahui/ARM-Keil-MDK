#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"


 int main(void)
 {	
	delay_init();	    //��ʱ������ʼ��	  
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	LED = 0;
	while(1)
	{
		LED = ~LED;
		delay_ms(300);	 //��ʱ300ms
	}
 }


 /**
 *****************����ע�ӵĴ�����ͨ�����ÿ⺯����ʵ��IO���Ƶķ���*****************************************
int main(void)
{ 
 
	delay_init();		  //��ʼ����ʱ����
	LED_Init();		        //��ʼ��LED�˿�
	while(1)
	{
			GPIO_SetBits(GPIOC,GPIO_Pin_5); 
			delay_ms(300);  		   //��ʱ300ms
			GPIO_ResetBits(GPIOC,GPIO_Pin_5);  
			delay_ms(300);  		   //��ʱ300ms
	}
} 
 
 ****************************************************************************************************
 ***/
