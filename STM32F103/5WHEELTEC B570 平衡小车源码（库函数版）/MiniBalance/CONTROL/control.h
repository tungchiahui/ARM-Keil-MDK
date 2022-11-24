#ifndef __CONTROL_H
#define __CONTROL_H
#include "sys.h"

#define PI 3.14159265							//PIԲ����
#define Control_Frequency  200.0	//��������ȡƵ��
#define Diameter_67  67.0 				//����ֱ��67mm 
#define EncoderMultiples   4.0 		//��������Ƶ��
#define Encoder_precision  13.0 	//���������� 13��
#define Reduction_Ratio  30.0			//���ٱ�30
#define Perimeter  210.4867 			//�ܳ�����λmm
#define Middle_angle -4
#define DIFFERENCE 100

struct PID
{
 int kp;
 float ki;
 int kd;
};


int speed_control_left(int encoder,int setspeed);
int speed_control_right(int encoder,int setspeed);
int Position_control_left(int Encoder,int Target);
int Position_control_right(int Encoder,int Target);
int EXTI15_10_IRQHandler(void);
int Balance(float angle,float gyro);
void Velocity(int encoder_left,int encoder_right);
void xunji_pid(void);
int Turn_ways(int yaw);
void Set_Pwm(int motor_left,int motor_right);
void Key(void);
void Limit_Pwm(void);
int PWM_Limit(int IN,int max,int min);
u8 Turn_Off(float angle, int voltage);
void Get_Angle(u8 way);
int myabs(int a);
int Pick_Up(float Acceleration,float Angle,int encoder_left,int encoder_right);
int Put_Down(float Angle,int encoder_left,int encoder_right);
void Get_Velocity_Form_Encoder(int encoder_left,int encoder_right);
void Choose(int encoder_left,int encoder_right);

#endif
