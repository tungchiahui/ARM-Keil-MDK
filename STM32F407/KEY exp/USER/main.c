#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"



int main(void)
{ 
 
  u8 key;           //�����ֵ
	delay_init(168);  //��ʼ����ʱ����
	LED_Init();				//��ʼ��LED�˿� 
	BEEP_Init();      //��ʼ���������˿�
	KEY_Init();       //��ʼ���밴�����ӵ�Ӳ���ӿ�
	LED_B=1;
	
	while(1)
 {
		key=KEY_Scan(0);		//�õ���ֵ
	   	if(key)
			{
				LED_B=!LED_B;
				BEEP=!BEEP;
			}
		  else
				delay_ms(100);
 }
}
