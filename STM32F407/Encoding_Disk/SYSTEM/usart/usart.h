#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 

void USART6_Init(u32 bound);
void USART6_IRQHandler(void);
void Data_Analyse(uint8_t rec);
#endif


