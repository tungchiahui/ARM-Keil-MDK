#include "key.h"
#include "delay.h" 

//按键初始化函数
void KEY_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟
 
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0; //KEY对应引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
	
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}


//u8 KEY_Scan(u8 mode)
//{	 
//	static u8 key_up=1;//按键按松开标志
//	if(mode)key_up=1;  //支持连按		  当其按下，就会
//	if(key_up&&KEY==1)
//	{
//		delay_ms(10);//去抖动 
//		key_up=0;  //按下的标志
//		if(KEY==1)
//			return 1;
//	}
//	else
//	if(KEY==0)
//		key_up=1;
// 	return 0;// 无按键按下
//}




















