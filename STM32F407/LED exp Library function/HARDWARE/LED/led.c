#include "sys.h"
#include "led.h"

void LED_Init(void)
{
	
 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH,ENABLE);
	
		GPIO_InitTypeDef GPIO_InitStructure;
	
	//PH10,PH11,PH12
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 ;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
 GPIO_Init(GPIOH,&GPIO_InitStructure);
 GPIO_ResetBits(GPIOH,GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12);
	
	
}

