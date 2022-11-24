#include "sys.h"
#include "delay.h"
#include "led.h"


 int main(void)
 {	
	delay_init();  
	LED_Init();	
	while(1)
	{
		delay_ms(300);
		LED1 = !LED1;
		LED32 = !LED32;
		delay_ms(300);
		LED2 = !LED2;
		LED31 = !LED31;
		delay_ms(300);
		LED3 = !LED3;
		LED30 = !LED30;
		delay_ms(300);
		LED4 = !LED4;
		LED29 = !LED29;
		delay_ms(300);
		LED5 = !LED5;
		LED28 = !LED28;
		delay_ms(300);
		LED6 = !LED6;
		LED27 = !LED27;
		delay_ms(300);
		LED7 = !LED7;
		LED26 = !LED26;
		delay_ms(300);
		LED8 = !LED8;
		LED25 = !LED25;
		delay_ms(300);
		LED9 = !LED9;
		LED24 = !LED24;
		delay_ms(300);
		LED10 = !LED10;
		LED23 = !LED23;
		delay_ms(300);
		LED11 = !LED11;
		LED22 = !LED22;
		delay_ms(300);
		LED12 = !LED12;
		LED21 = !LED21;
		delay_ms(300);
		LED13 = !LED13;
		LED20 = !LED20;
		delay_ms(300);
		LED14 = !LED14;
		LED19 = !LED19;
		delay_ms(300);
		LED15 = !LED15;
		LED18 = !LED18;
		delay_ms(300);
		LED16 = !LED16;
		LED17 = !LED17;
		delay_ms(300);
	}
 }

