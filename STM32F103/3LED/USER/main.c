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
		
		LED_DL0();    //从上方往下依次灭灯
		
		LED_DT1();    //从下方往上依次亮灯
		

	}
}

