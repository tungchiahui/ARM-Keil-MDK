#ifndef TIMER_H
#define TIMER_H

#include "can.h"
#include "pid_user.h"
#include "usart.h"
#include "math.h"
#include "sys.h"
#include "main.h"



extern float Speed_Motor_Target_1,Position_Motor_Target_1,Target_1;


void TIM2_Int_Init(u16 arr,u16 psc);


#endif
