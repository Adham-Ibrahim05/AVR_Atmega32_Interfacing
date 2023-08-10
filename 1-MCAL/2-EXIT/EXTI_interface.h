/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	EXTI			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef		EXTI_INTERFACE_H
#define		EXTI_INTERFACE_H

void EXTI_voidINT0Init(void);
void EXTI_voidINT0Enable(void);
void EXTI_voidINT0Disable(void);

void EXTI_voidINT1Init(void);
void EXTI_voidINT1Enable(void);
void EXTI_voidINT1Disable(void);

void EXTI_voidINT2Init(void);
void EXTI_voidINT2Enable(void);
void EXTI_voidINT2Disable(void);

void EXTINT0_VoidSetCallBack(void (*Copy_pf) (void));
void EXTINT1_VoidSetCallBack(void (*Copy_pf) (void));
void EXTINT2_VoidSetCallBack(void (*Copy_pf) (void));


#endif