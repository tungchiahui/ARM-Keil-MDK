/**    ��ң�������ֿ��ơ�   
 *           _____                    _____                          
 *          /\    \                  /\    \         
 *         /::\    \                /::\    \        
 *        /::::\    \              /::::\    \       
 *       /::::::\    \            /::::::\    \      
 *      /:::/\:::\    \          /:::/\:::\    \     
 *     /:::/__\:::\    \        /:::/  \:::\    \    
 *    /::::\   \:::\    \      /:::/    \:::\    \   
 *   /::::::\   \:::\    \    /:::/    / \:::\    \  
 *  /:::/\:::\   \:::\____\  /:::/    /   \:::\    \ 
 * /:::/  \:::\   \:::|    |/:::/____/     \:::\____\
 * \::/   |::::\  /:::|____|\:::\    \      \::/    /
 *  \/____|:::::\/:::/    /  \:::\    \      \/____/ 
 *        |:::::::::/    /    \:::\    \    
 *        |::|\::::/    /      \:::\    \   
 *        |::| \::/____/        \:::\    \    
 *        |::|  ~|               \:::\    \    
 *        |::|   |                \:::\    \         
 *        \::|   |                 \:::\____\        
 *         \:|   |                  \::/    /        
 *          \|___|                   \/____/   
 */ 
#include "timer.h"



#define ABS(x)	((x>0) ? (x) : (-x)) //xֻ�������֣������Ǳ��ʽ

float Speed_Motor_Target_1,Position_Motor_Target_1,Target_1;

extern struct 
 {
 int16_t ch0;
 int16_t ch1;
 int16_t ch2;
 int16_t ch3;
 int16_t ch4; 
 int8_t s1;
 int8_t s2;
 }rc;



void TIM2_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  ///ʹ��TIM3ʱ��
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);//��ʼ��TIM3
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
	TIM_Cmd(TIM2,ENABLE); //ʹ�ܶ�ʱ��3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn; //��ʱ��3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x02; //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00; //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);	
}

void TIM2_IRQHandler(void)
	
{
   static u16 i = 0;
	 if (i>65534)
		 i = 0;
	
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET) //����ж�
		{
			TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //����жϱ�־λ
			  {	
/*------------------------------------------------------------------------------------------------------------------*/

//       if(rc.ch2 == 660)
//			 {
				Speed_Motor_Target_1 = 300;
				Target_1 = PID_velocity_realize_1(Speed_Motor_Target_1,1);
//			 }
//				if(rc.ch2 == -660)
//				{
//				Position_Motor_Target_1 = 8192 * 2 *19;
//				Target_1 = pid_call_1(Position_Motor_Target_1,1);
//				}
//				if(rc.ch2 == 0)
//				{
//				Target_1 = PID_velocity_realize_1(0,1);
//				}
				CAN_CMD_can1_1(Target_1,0,0,0);
			
				
		    }	
		
		}
				
}
		
		

 
	 
	 
	 

	 
	 
