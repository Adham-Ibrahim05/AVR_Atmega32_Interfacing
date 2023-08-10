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

void Timer1_SetCompareMatchMode(void);

void Timer1_voidSetOCR1AValue(u16 Value);

void Timer1_voidSetICR1Value(u16 Value);

void Timer1_ICUInterruptEnable(void);

void Timer1_ICUInterruptDisable(void);

void Timer1_ICUSenseMode (u8 Mode);

u16 Timer1_ICR1Read(void);

#endif