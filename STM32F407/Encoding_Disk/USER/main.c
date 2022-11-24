#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"


int main(void)
{
	USART6_Init(115200);
	delay_init(168);
	
  while(1)
	{
	}
}




