#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED20 PAout(0)
#define LED21 PAout(1)
#define LED22 PAout(2)
#define LED23 PAout(3)
#define LED24 PAout(4)
#define LED25 PAout(5)
#define LED26 PAout(6)
#define LED27 PAout(7)
#define LED4 PAout(8)
#define LED5 PAout(9)
#define LED6 PAout(10)
#define LED7 PAout(11)
#define LED8 PAout(12)
#define LED9 PAout(15)  //sha
#define LED28 PBout(0)
#define LED29 PBout(1)
#define LED10 PBout(3)
#define LED11 PBout(4)  //sha
#define LED12 PBout(5)
#define LED13 PBout(6)
#define LED14 PBout(7)
#define LED15 PBout(8)
#define LED16 PBout(9)
#define LED30 PBout(10)
#define LED31 PBout(11)
#define LED32 PBout(12)
#define LED1 PBout(13)
#define LED2 PBout(14)
#define LED3 PBout(15)
#define LED17 PCout(13)
#define LED18 PCout(14)
#define LED19 PCout(15)

static int LED[33];

void LED_Init(void);     //初始化LED
void LED_Ass(void);      //给Pxout(n)赋地址

void LED_ALL1(void);     //全亮
void LED_ALL0(void);     //全灭

void LED_DL1(void);      //从上方往下依次亮灯
void LED_DL0(void);      //从上方往下依次灭灯

void LED_DT1(void);      //从下方往上依次亮灯
void LED_DT0(void);      //从下方往上依次灭灯

#endif

