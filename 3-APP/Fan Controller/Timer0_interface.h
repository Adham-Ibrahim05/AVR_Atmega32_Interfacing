/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	Timer			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef		TIMER_INTERFACE_H
#define		TIMER_INTERFACE_H

void Timer0_voidInit(void);

void Timer0_SetCompareMatchMode(void);

u8 Timer0_u8ReadTCNT0(void);

void TImer0_voidEnableOVFInterrupt(void);

void TImer0_voidEnableCMInterrupt(void);

void Timer0_voidSetPreload(u8 Value);

void Timer0_voidSetCompareMatchValue(u8 Value);

void Timer0_voidCompareSetCallBack(void(*Copy_pf)(void));

void Timer0_voidOverflowSetCallBack(void(*Copy_PF)(void));

#endif