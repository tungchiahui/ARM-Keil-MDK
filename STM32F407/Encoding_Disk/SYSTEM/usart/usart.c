#include "sys.h"
#include "usart.h"	
#include "math.h"
////////////////////////////////////////////////////////////////////////////////// 	 
//如果使用ucos,则包括下面的头文件即可.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos 使用	  
#endif

void USART6_Init(u32 bound)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG,ENABLE); //使能GPIOG时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6,ENABLE);//使能USART6时钟
	
	GPIO_PinAFConfig(GPIOG,GPIO_PinSource14,GPIO_AF_USART6); //GPIOG14复用为USART6
	GPIO_PinAFConfig(GPIOG,GPIO_PinSource9,GPIO_AF_USART6); //GPIOG9复用为USART6
	
	//USART6端口配置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_9; //GPIOG14与GPIOG9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_Init(GPIOG,&GPIO_InitStructure); //初始化PG14，PG9
	
	//USART6 初始化设置
	USART_InitStructure.USART_BaudRate = bound;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
  USART_Init(USART6, &USART_InitStructure); //初始化串口6
	
	USART_Cmd(USART6, ENABLE);  //使能串口6
	
	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);//开启相关中断
	
		//USART6 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;//串口1中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x02;//抢占优先级2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0x02;		//子优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
}



float pos_x=0;
float pos_y=0;
float xangle=0;
float yangle=0;
float zangle=0;
float w_z=0;
//u8 USART6_RxBuffer[20] = {0};
//float ac;
//float ab;
//float len_back,len_right;
//float len_back_last,len_right_last;
//float LPF_XS = 0.4f;
//float PI = 3.14159f;
//float yaw;
//void USART6_IRQHandler(void)
//{
//	static uint8_t ch;
//	static union
//	{
//		u8 data[24];
//		float ActVal[6];
//	}posture;
//	
//	static uint8_t count=0;
//	static uint8_t i=0;
//	if(USART_GetITStatus(USART6,USART_IT_RXNE)==SET)
//	{
//		USART_ClearITPendingBit(USART6,USART_IT_RXNE);
//		ch=USART_ReceiveData(USART6);
//		switch(count)
//		{
//			case 0:
//			if(ch==0x0d)
//				count++;
//			else
//				count=0;
//			break;
//			case 1:
//			if(ch==0x0a)
//			{ 
//				i=0;
//				count++;
//			}
//			else if(ch==0x0d);
//			else 
//				count=0;
//			break;
//			case 2:
//				posture.data[i]=ch;
//				i++;
//			if(i>=24)
//			{
//				i=0;
//				count++;
//			}
//			break;
//			case 3:
//				if(ch==0x0a)
//			count++;
//			else
//				count=0;
//			break;
//			case 4:
//				if(ch==0x0d)
//			{
//				zangle=posture.ActVal[0];
//				xangle=posture.ActVal[1];
//				yangle=posture.ActVal[2];
//				pos_x=-posture.ActVal[3];
//				pos_y=-posture.ActVal[4];
//				w_z=posture.ActVal[5];		
//			}
//			count=0;
//			break;
//			default:
//				count=0;
//			break;
//			
//		}
//	}
//}



void USART6_IRQHandler(void)  
{
  u8 r;
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
	{
		r =USART_ReceiveData(USART3);
		Data_Analyse(r);
	}
}




void Data_Analyse(uint8_t rec)
{
	static uint8_t ch;
	static union
	{
		uint8_t date[24];
		float ActVal[6];
	}posture;
	static uint8_t count=0;
	static uint8_t i=0;

	ch=rec;
	switch(count)
	{
		case 0:
			if(ch==0x0d)
				count++;
			else
				count=0;
			break;
		case 1:
			if(ch==0x0a)
			{
				i=0;
				count++;
			}
			else if(ch==0x0d);
			else
				count=0;
			break;
		case 2:
			posture.date[i]=ch;
			i++;
			if(i>=24)
			{
				i=0;
				count++;
			}
			break;
		case 3:
			if(ch==0x0a)
				count++;
			else
				count=0;
			break;
		case 4:
			if(ch==0x0d)
			{
				zangle=posture.ActVal[0];
				xangle=posture.ActVal[1];
				yangle=posture.ActVal[2];
				pos_x=posture.ActVal[3];
				pos_y=posture.ActVal[4];
				w_z=posture.ActVal[5];
			}
			count=0;
			break;
		default:
			count=0;
		break;
	}
}
