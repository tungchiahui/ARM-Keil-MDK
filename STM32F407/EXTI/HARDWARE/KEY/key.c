#include "key.h"
#include "delay.h" 

//������ʼ������
void KEY_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//ʹ��GPIOAʱ��
 
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0; //KEY��Ӧ����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
	
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}


//u8 KEY_Scan(u8 mode)
//{	 
//	static u8 key_up=1;//�������ɿ���־
//	if(mode)key_up=1;  //֧������		  ���䰴�£��ͻ�
//	if(key_up&&KEY==1)
//	{
//		delay_ms(10);//ȥ���� 
//		key_up=0;  //���µı�־
//		if(KEY==1)
//			return 1;
//	}
//	else
//	if(KEY==0)
//		key_up=1;
// 	return 0;// �ް�������
//}




















