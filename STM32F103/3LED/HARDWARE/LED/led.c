#include "led.h"


void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_15;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);
 GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_15);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOB, &GPIO_InitStructure);
 GPIO_SetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_4 |GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);
 GPIO_SetBits(GPIOC, GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

}


void LED_Ass(void)  //给Pxout(n)赋地址
{

	LED[0] = 0;
	
	LED1 = LED[1];
	LED2 = LED[2];
	LED3 = LED[3];
	LED4 = LED[4];
	LED5 = LED[5];
	LED6 = LED[6];
	LED7 = LED[7];
	LED8 = LED[8];
	LED9 = LED[9];
	LED10 = LED[10];
	LED11 = LED[11];
	LED12 = LED[12];
	LED13 = LED[13];
	LED14 = LED[14];
	LED15 = LED[15];
	LED16 = LED[16];
	LED17 = LED[17];
	LED18 = LED[18];
	LED19 = LED[19];
	LED20 = LED[20];
	LED21 = LED[21];
	LED22 = LED[22];
	LED23 = LED[23];
	LED24 = LED[24];
	LED25 = LED[25];
	LED26 = LED[26];
	LED27 = LED[27];
	LED28 = LED[28];
	LED29 = LED[29];
	LED30 = LED[30];
	LED31 = LED[31];
	LED32 = LED[32];

}	



void LED_ALL1(void)    //全亮
{
	for(int i = 1 ; i <= 32 ; i++ )
		{
			LED[i] = 1;
		}
	LED_Ass();
	delay_ms(300);
}


void LED_ALL0(void)   //全灭
{
	for(int i = 1 ; i <= 32 ; i++ )
		{
			LED[i] = 0;
		}
	LED_Ass();
	delay_ms(300);
}

void LED_DL1(void)    //从上方往下依次亮灯
{
	int i = 1;
	int j = 32;
	while(i <= 16 && (j >= 17 && j <= 32))
	{
		LED[i] = 1;
		LED[j] = 1;
		LED_Ass();
		i++;
		j--;
		delay_ms(300);
	}
}


void LED_DL0(void)    //从上方往下依次灭灯
{
	int i = 1;
	int j = 32;
	while(i <= 16 && (j >= 17 && j <= 32))
	{
		LED[i] = 0;
		LED[j] = 0;
		LED_Ass();
		i++;
		j--;
		delay_ms(300);
	}
}


void LED_DT1(void)    //从下方往上依次亮灯
{
	int i = 16;
	int j = 17;
	while (i <= 16 && (j >= 17 && j <= 32))
	{
		LED[i] = 1;
		LED[j] = 1;
		LED_Ass();
		i--;
		j++;
		delay_ms(300);
	}
}


void LED_DT0(void)    //从下方往上依次灭灯
{
	int i = 16;
	int j = 17;
	while (i <= 16 && (j >= 17 && j <= 32))
	{
		LED[i] = 0;
		LED[j] = 0;
		LED_Ass();
		i--;
		j++;
		delay_ms(300);
	}
}



