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

void Timer1_voidSetOCRValue(u16 Value);

void Timer1_voidSetICRValue(u16 Value);

void Timer1_ICUInit(void);

void Timer1_ICUSenseMode (u8 sense);

u16 Timer1_ICRRead(void);

#endif