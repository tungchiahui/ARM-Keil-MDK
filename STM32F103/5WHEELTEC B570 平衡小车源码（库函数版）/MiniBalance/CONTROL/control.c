#include "control.h"	
#include "timer.h"
#include "key.h"
/**************************************************************************
�������ܣ����еĿ��ƴ��붼��������
         5ms�ⲿ�ж���MPU6050��INT���Ŵ���
         �ϸ�֤���������ݴ����ʱ��ͬ��			 
**************************************************************************/
float velocity1,velocity2;
extern int xunji_error;
extern float Roll,Pitch,Yaw; 
struct PID pid_speed={10,50,0};//10 40
struct PID pid_Position={10,0,300};//10 40
struct PID pid_Yaw_turn={3,0,35};//��Ϊ60����Ϊ�˲���10������Ϊ��ʹԭʼ���ݲ��䣬��10
struct PID pid_Yaw={50,0,0};
struct PID pid_gyro_turn={0,0,1};
struct PID pid_xunji_turn={130,0,0};
int dusu,Left_speed=0,right_speed=0,Turn_Pwm=0;
int Encoder_Left,Encoder_Right,Position_Left,Position_Right;  
int turn=0,medicine_flag=1;
int turn_cnt,turnleft_90=0,turnright_90=0,turnleft_180=0,turnleft90_flag=0,turnright90_flag=0,turnleft180_flag=0;
int xunji=1,stop_cnt=0,stopflag=1;
int EXTI15_10_IRQHandler(void) 
{    
	static int Voltage_Temp,Voltage_Count,Voltage_All;		//��ѹ������ر���
	static u8 Flag_Target;																//���ƺ�����ر������ṩ10ms��׼
	static int Flag_Yaw=0;
	           					//���ұ��������������
	int Balance_Pwm;		  					//ƽ�⻷PWM�������ٶȻ�PWM������ת��PWM��
	if(INT==0)		
	{   
		EXTI->PR=1<<12;                           					//����жϱ�־λ   
		Flag_Target=!Flag_Target;
		Get_Angle(Way_Angle);                     					//������̬��5msһ�Σ����ߵĲ���Ƶ�ʿ��Ը��ƿ������˲��ͻ����˲���Ч��
		Encoder_Left=-Read_Encoder(2);            					//��ȡ���ֱ�������ֵ��ǰ��Ϊ��������Ϊ��
		Encoder_Right=-Read_Encoder(4);           					//��ȡ���ֱ�������ֵ��ǰ��Ϊ��������Ϊ��
		if(delay_flag==1)
		{
			if(++delay_50==10)	 delay_50=0,delay_flag=0;  		//���������ṩ50ms�ľ�׼��ʱ��ʾ������Ҫ50ms�߾�����ʱ
		}
		Position_Left+=(-Encoder_Left); 
		Position_Right+=(-Encoder_Right); 
		dusu+=(int)Gyro_Turn/80;
		Key();                                    					//ɨ�谴��״̬ ����˫�����Ըı�С������״̬	
     //xunji_pid();	
		Yaw=Yaw+26;	
      if(Flag_Stop==0)
			{
         
			
				//Turn_Pwm=Turn_ways(xunji_error);
					Turn_Pwm=Turn_ways(Yaw);	
				Left_speed=speed_control_left(Encoder_Left,10);
	      right_speed=speed_control_right(Encoder_Right,10);	
//					Left_speed=Position_control_left(Position_Left,-1056*2);
//					right_speed=Position_control_right(Position_Right,1056*2);	
				Motor_Left=Left_speed+Turn_Pwm;                  //�������ֵ������PWM
	      Motor_Right=right_speed-Turn_Pwm;	
		   Set_Pwm(Motor_Left,Motor_Right);         					//��ֵ��PWM�Ĵ���  
	
				
//				if(0) 
//				{
////					turn_ways=2;
////					turnleft_90=1;

//				Turn_Pwm=Turn_ways(dusu);
//				Motor_Left=Turn_Pwm;                  //�������ֵ������PWM
//	   Motor_Right=-Turn_Pwm;
//		   Set_Pwm(Motor_Left,Motor_Right);  
//				}	
//				
				
//			 Motor_Left=Turn_Pwm;                  //�������ֵ������PWM
//		   Motor_Right=-Turn_Pwm;	
			}
			if(Flag_Stop==1) Set_Pwm(0,0);         					//��ֵ��PWM�Ĵ���  
			
			
	 }       	
	 return 0;	  
} 




int speed_control_left(int encoder,int setspeed)
{
   static int pwmout=0,last_error=0,error=0;
	error=setspeed-encoder;
  pwmout=pwmout+pid_speed.kp*(error-last_error)+pid_speed.ki*error;
  last_error=error;
	if(pwmout>6500)
		pwmout=6500;
  if(pwmout<-6500)
		pwmout=-6500;
   return pwmout;
}

int speed_control_right(int encoder,int setspeed)
{
   static int pwmout=0,last_error=0,error=0;
	error=setspeed-encoder;
  pwmout=pwmout+pid_speed.kp*(error-last_error)+pid_speed.ki*error;
  last_error=error;
	if(pwmout>6500)
		pwmout=6500;
  if(pwmout<-6500)
		pwmout=-6500;
   return pwmout;
}

int Position_control_left(int Encoder,int Target)
{ 	
	 static int Bias,Pwm,Integral_bias,Last_Bias;
	 Bias=Encoder-Target;                                  //����ƫ��
	 Integral_bias+=Bias;	                                 //���ƫ��Ļ���
	 if(Integral_bias>100000)Integral_bias=10000;
	 if(Integral_bias<-100000)Integral_bias=-10000;
	 Pwm=pid_Position.kp*Bias+pid_Position.ki*Integral_bias+pid_Position.kd*(Bias-Last_Bias);       //λ��ʽPID������
	 Last_Bias=Bias;                                       //������һ��ƫ�� 
	 return (int)Pwm;                                           //�������
}

int Position_control_right(int Encoder,int Target)
{ 	
	 static int Bias,Pwm,Integral_bias,Last_Bias;
	 Bias=Encoder-Target;                                  //����ƫ��
	 Integral_bias+=Bias;	                                 //���ƫ��Ļ���
	 if(Integral_bias>100000)Integral_bias=10000;
	 if(Integral_bias<-100000)Integral_bias=-10000;
	 Pwm=pid_Position.kp*Bias+pid_Position.ki*Integral_bias+pid_Position.kd*(Bias-Last_Bias);       //λ��ʽPID������
	 Last_Bias=Bias;                                       //������һ��ƫ�� 
	 return (int)Pwm;                                           //�������
}





int Turn_ways(int yaw)
{
   static int turn_pwm,bias,last_bias,Turn_Target=1;
	 int Kd;		
//	if(turn_ways==1)
//	{
//		turn_pwm=Turn_Target*yaw*pid_xunji_turn.kp;//���Z�������ǽ���PD����
//	}
//	if(turn_ways==2&&turnleft_90==1)
//	{
//		turn_pwm=Turn_Target*(yaw-3700)*pid_Yaw_turn.kp+pid_Yaw_turn.kd;//���Z�������ǽ���PD����
//	}
//	if(turn_ways==2&&turnright_90==1)
//	{
//		turn_pwm=Turn_Target*(yaw+3700)*pid_Yaw_turn.kp+pid_Yaw_turn.kd;//���Z�������ǽ���PD����
//	}
//	if(turn_ways==2&&turnleft_180==1)
//	{
//		turn_pwm=Turn_Target*(yaw-7000)*pid_Yaw_turn.kp+pid_Yaw_turn.kd;//���Z�������ǽ���PD����
//	}
//	bias=yaw-3700*0;
//	turn_pwm=Turn_Target*bias*pid_Yaw_turn.kp+pid_Yaw_turn.kd*(bias-last_bias);//���Z�������ǽ���PD����
//	last_bias=bias;
//	 return (int)turn_pwm;								

bias=yaw-0;
	turn_pwm=Turn_Target*bias*pid_Yaw.kp+pid_Yaw.kd*(bias-last_bias);//���Z�������ǽ���PD����
	last_bias=bias;
	 return (int)turn_pwm;	
}

/**************************************************************************
Function: Assign to PWM register
Input   : motor_left��Left wheel PWM��motor_right��Right wheel PWM
Output  : none
�������ܣ���ֵ��PWM�Ĵ���
��ڲ���������PWM������PWM
����  ֵ����
**************************************************************************/
void Set_Pwm(int motor_left,int motor_right)
{
  if(motor_left>0)	    BIN1=1,			BIN2=0; //ǰ�� 
	else           			  BIN1=0,			BIN2=1; //����
	PWMB=myabs(motor_left);	
  if(motor_right>0)			AIN2=1,			AIN1=0;	//ǰ��
	else 	        			  AIN2=0,			AIN1=1; //����
	PWMA=myabs(motor_right);
}

/**************************************************************************
Function: Press the key to modify the car running state
Input   : none
Output  : none
�������ܣ������޸�С������״̬ 
��ڲ�������
����  ֵ����
**************************************************************************/
void Key(void)
{	
	u8 tmp,tmp2;
	tmp=click_N_Double(50); 
	if(tmp==1)
	{ 
		Flag_Stop=!Flag_Stop;
	}		//��������С������ͣ
	tmp2=Long_Press();                   
  if(tmp2==1) Flag_Show=!Flag_Show;	//�������ƽ�����λ��ģʽ��С������ʾֹͣ

}
/**************************************************************************
Function: If abnormal, turn off the motor
Input   : angle��Car inclination��voltage��Voltage
Output  : 1��abnormal��0��normal
�������ܣ��쳣�رյ��		
��ڲ�����angle��С����ǣ�voltage����ѹ
����  ֵ��1���쳣  0������
**************************************************************************/	
u8 Turn_Off(float angle, int voltage)
{
	u8 temp;
	if(1==Flag_Stop||voltage<1110)//��ص�ѹ����11.1V�رյ��
	{	                                                 //��Ǵ���40�ȹرյ��
		temp=1;                                          //Flag_Stop��1�����������ƹرյ��
		AIN1=0;                                            
		AIN2=0;
		BIN1=0;
		BIN2=0;
	}
	else
		temp=0;
	return temp;			
}
	
/**************************************************************************
Function: Get angle
Input   : way��The algorithm of getting angle 1��DMP  2��kalman  3��Complementary filtering
Output  : none
�������ܣ���ȡ�Ƕ�	
��ڲ�����way����ȡ�Ƕȵ��㷨 1��DMP  2�������� 3�������˲�
����  ֵ����
**************************************************************************/	
void Get_Angle(u8 way)
{ 
	float Accel_Y,Accel_Z,Accel_X,Accel_Angle_x,Accel_Angle_y,Gyro_X,Gyro_Z,Gyro_Y;
	Temperature=Read_Temperature();      //��ȡMPU6050�����¶ȴ��������ݣ����Ʊ�ʾ�����¶ȡ�
	if(way==1)                           //DMP�Ķ�ȡ�����ݲɼ��ж϶�ȡ���ϸ���ѭʱ��Ҫ��
	{	
		Read_DMP();                      	 //��ȡ���ٶȡ����ٶȡ����
		Angle_Balance=Pitch;             	 //����ƽ�����,ǰ��Ϊ��������Ϊ��
		Gyro_Balance=gyro[0];              //����ƽ����ٶ�,ǰ��Ϊ��������Ϊ��
		Gyro_Turn=gyro[2];                 //����ת����ٶ�
		Acceleration_Z=accel[2];           //����Z����ٶȼ�
	}			
	else
	{
		Gyro_X=(I2C_ReadOneByte(devAddr,MPU6050_RA_GYRO_XOUT_H)<<8)+I2C_ReadOneByte(devAddr,MPU6050_RA_GYRO_XOUT_L);    //��ȡX��������
		Gyro_Y=(I2C_ReadOneByte(devAddr,MPU6050_RA_GYRO_YOUT_H)<<8)+I2C_ReadOneByte(devAddr,MPU6050_RA_GYRO_YOUT_L);    //��ȡY��������
		Gyro_Z=(I2C_ReadOneByte(devAddr,MPU6050_RA_GYRO_ZOUT_H)<<8)+I2C_ReadOneByte(devAddr,MPU6050_RA_GYRO_ZOUT_L);    //��ȡZ��������
		Accel_X=(I2C_ReadOneByte(devAddr,MPU6050_RA_ACCEL_XOUT_H)<<8)+I2C_ReadOneByte(devAddr,MPU6050_RA_ACCEL_XOUT_L); //��ȡX����ٶȼ�
		Accel_Y=(I2C_ReadOneByte(devAddr,MPU6050_RA_ACCEL_YOUT_H)<<8)+I2C_ReadOneByte(devAddr,MPU6050_RA_ACCEL_YOUT_L); //��ȡX����ٶȼ�
		Accel_Z=(I2C_ReadOneByte(devAddr,MPU6050_RA_ACCEL_ZOUT_H)<<8)+I2C_ReadOneByte(devAddr,MPU6050_RA_ACCEL_ZOUT_L); //��ȡZ����ٶȼ�
		if(Gyro_X>32768)  Gyro_X-=65536;                 //��������ת��  Ҳ��ͨ��shortǿ������ת��
		if(Gyro_Y>32768)  Gyro_Y-=65536;                 //��������ת��  Ҳ��ͨ��shortǿ������ת��
		if(Gyro_Z>32768)  Gyro_Z-=65536;                 //��������ת��
		if(Accel_X>32768) Accel_X-=65536;                //��������ת��
		if(Accel_Y>32768) Accel_Y-=65536;                //��������ת��
		if(Accel_Z>32768) Accel_Z-=65536;                //��������ת��
		Gyro_Balance=-Gyro_X;                            //����ƽ����ٶ�
		Accel_Angle_x=atan2(Accel_Y,Accel_Z)*180/PI;     //������ǣ�ת����λΪ��	
		Accel_Angle_y=atan2(Accel_X,Accel_Z)*180/PI;     //������ǣ�ת����λΪ��
		Gyro_X=Gyro_X/16.4;                              //����������ת�������̡�2000��/s��Ӧ������16.4���ɲ��ֲ�
		Gyro_Y=Gyro_Y/16.4;                              //����������ת��	
		if(Way_Angle==2)		  	
		{
			 Pitch = -Kalman_Filter_x(Accel_Angle_x,Gyro_X);//�������˲�
			 Roll = -Kalman_Filter_y(Accel_Angle_y,Gyro_Y);
		}
		else if(Way_Angle==3) 
		{  
			 Pitch = -Complementary_Filter_x(Accel_Angle_x,Gyro_X);//�����˲�
			 Roll = -Complementary_Filter_y(Accel_Angle_y,Gyro_Y);
		}
		Angle_Balance=Pitch;                              //����ƽ�����
		Gyro_Turn=Gyro_Z;                                 //����ת����ٶ�
		Acceleration_Z=Accel_Z;                           //����Z����ٶȼ�	
	}
}
/**************************************************************************
Function: Absolute value function
Input   : a��Number to be converted
Output  : unsigned int
�������ܣ�����ֵ����
��ڲ�����a����Ҫ�������ֵ����
����  ֵ���޷�������
**************************************************************************/	
int myabs(int a)
{ 		   
	int temp;
	if(a<0)  temp=-a;  
	else temp=a;
	return temp;
}
/**************************************************************************
Function: Check whether the car is picked up
Input   : Acceleration��Z-axis acceleration��Angle��The angle of balance��encoder_left��Left encoder count��encoder_right��Right encoder count
Output  : 1��picked up  0��No action
�������ܣ����С���Ƿ�����
��ڲ�����Acceleration��z����ٶȣ�Angle��ƽ��ĽǶȣ�encoder_left���������������encoder_right���ұ���������
����  ֵ��1:С��������  0��С��δ������
**************************************************************************/
int Pick_Up(float Acceleration,float Angle,int encoder_left,int encoder_right)
{ 		   
	 static u16 flag,count0,count1,count2;
	 if(flag==0)                                                      //��һ��
	 {
			if(myabs(encoder_left)+myabs(encoder_right)<30)               //����1��С���ӽ���ֹ
			count0++;
			else 
			count0=0;		
			if(count0>10)				
			flag=1,count0=0; 
	 } 
	 if(flag==1)                                                      //����ڶ���
	 {
			if(++count1>200)       count1=0,flag=0;                       //��ʱ���ٵȴ�2000ms�����ص�һ��
			if(Acceleration>26000&&(Angle>(-20+Middle_angle))&&(Angle<(20+Middle_angle)))   //����2��С������0�ȸ���������
			flag=2; 
	 } 
	 if(flag==2)                                                       //������
	 {
		  if(++count2>100)       count2=0,flag=0;                        //��ʱ���ٵȴ�1000ms
	    if(myabs(encoder_left+encoder_right)>70)                       //����3��С������̥��Ϊ�������ﵽ����ת��   
      {
				flag=0;                                                                                     
				return 1;                                                    //��⵽С��������
			}
	 }
	return 0;
}
/**************************************************************************
Function: Check whether the car is lowered
Input   : The angle of balance��Left encoder count��Right encoder count
Output  : 1��put down  0��No action
�������ܣ����С���Ƿ񱻷���
��ڲ�����ƽ��Ƕȣ���������������ұ���������
����  ֵ��1��С������   0��С��δ����
**************************************************************************/
int Put_Down(float Angle,int encoder_left,int encoder_right)
{ 		   
	 static u16 flag,count;	 
	 if(Flag_Stop==0)                     //��ֹ���      
			return 0;	                 
	 if(flag==0)                                               
	 {
			if(Angle>(-10+Middle_angle)&&Angle<(10+Middle_angle)&&encoder_left==0&&encoder_right==0) //����1��С������0�ȸ�����
			flag=1; 
	 } 
	 if(flag==1)                                               
	 {
		  if(++count>50)                     //��ʱ���ٵȴ� 500ms
		  {
				count=0;flag=0;
		  }
	    if(encoder_left>3&&encoder_right>3&&encoder_left<40&&encoder_right<40) //����2��С������̥��δ�ϵ��ʱ����Ϊת��  
      {
				flag=0;
				flag=0;
				return 1;                         //��⵽С��������
			}
	 }
	return 0;
}

/**************************************************************************
Function: Select car running mode
Input   : encoder_left��Left wheel encoder reading��encoder_right��Right wheel encoder reading
Output  : none
�������ܣ�ѡ��С������ģʽ
��ڲ�����encoder_left�������������  encoder_right���ұ���������
����  ֵ����
**************************************************************************/
void Choose(int encoder_left,int encoder_right)
{
	static int count;
	if(Flag_Stop==0)
		count = 0;
	if((Flag_Stop==1)&&(encoder_left<10))	//��ʱֹͣ�����ֲ���
	{
		count += myabs(encoder_right);
		if(count>6&&count<180)	//��ͨģʽ
		{
			Flag_follow = 0;
			Flag_avoid = 0;
		}
		if(count>180&&count<360)	//����ģʽ 
		{
			Flag_avoid = 1;
			Flag_follow = 0;
		}
		if(count>360&&count<540)	//����ģʽ
		{
			Flag_avoid = 0;
			Flag_follow = 1;
		}
		if(count>540)
			count = 0;
	}
}

void xunji_pid(void)
{

	static int i;
	if(xunji)
	{
		
									if(Left==0&&Right==0)		
									{
										xunji_error=0;
										turn_ways=1;
									
									}	 
	
									if(Left==1&&Right==0)	   
									{
									 xunji_error=40;
										turn_ways=1;
									}			
	
								 if(Left==0&&Right==1)	
								 {
									xunji_error=-40;
									 turn_ways=1;
								 
								 }		

								 if(Left==1&&Right==1&&medicine==0)
								 {
									dusu=0;
									 xunji=0;
									 turn=1;
									 turnleft90_flag=1;
								 
								 }		
		

								if(Left==1&&Right==1&&medicine==1)	
								{
								
									 dusu=0;
									 xunji=0;
									 turn=1;
									 turnright90_flag=1;
								}
//	
//	if(stop==0) 
//	{
//	stop_cnt++;
//	if(stop_cnt>50)
//	{
//	Flag_Stop=1;	
//	dusu=0;	
//		if(medicine==1)
//		{
//				xunji=0;
//			turn=1; 
//			turnleft180_flag=1;
//			Flag_Stop=0;	
////		stopflag=0;	
//	stop_cnt=0;
//		
//		}	
//	}

//	}	


	
	
	
	
	}

	
	
	
	
	//ת��ģʽ
	
	if(turn)
	{	
								i++;
								turn_ways=2;
								if(turnleft90_flag==1) turnleft_90=1;
								if(turnright90_flag==1) turnright_90=1;
								if(turnleft180_flag==1) turnleft_180=1;
	if(i>400)//ת�����
	{
	  turn=0;
		turnleft90_flag=0;
		turnright90_flag=0;
		turnleft180_flag=0;
		dusu=0;
		xunji=1;
		i=0;
	}	
	}
	 
}

