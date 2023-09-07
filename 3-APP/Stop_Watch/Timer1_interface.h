/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	Timer1			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef		TIMER_INTERFACE_H
#define		TIMER_INTERFACE_H

void Timer1_voidInit(void);

void Timer1_voidSetOCR1AValue(u16 Value);

void Timer1_voidCompareSetCallBack(void(*Copy_pf)(void));

#endif