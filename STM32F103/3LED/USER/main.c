#include "sys.h"
#include "delay.h"
#include "led.h"


int main(void)
{	
	delay_init();  
	LED_Init();	
	while(1)
	{
		
		LED_ALL1();
		
		delay_ms(2700);
		
		LED_DL0();    //���Ϸ������������
		
		LED_DT1();    //���·�������������
		

	}
}

