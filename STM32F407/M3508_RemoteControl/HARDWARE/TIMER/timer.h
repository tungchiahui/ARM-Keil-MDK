#ifndef TIMER_H
#define TIMER_H
#include "sys.h"


//  #include "main.h"



extern float Speed_Motor_Target_1,Speed_Motor_Target_2,Speed_Motor_Target_3,Speed_Motor_Target_4;




void TIM2_Int_Init(u16 arr,u16 psc);


#endif

