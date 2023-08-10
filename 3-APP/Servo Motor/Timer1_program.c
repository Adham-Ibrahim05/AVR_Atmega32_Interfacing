/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	Timer			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//#include "Timer_private.h"
#include "Timer1_register.h"
//#include "Timer_config.h"
#include "Timer1_interface.h"

void(*INT)(void) = NULL; 

void Timer1_voidInit(void)
{
	/*Choose Timer Mode (FAST PWM)*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	
	
	/*Compare Match Fast PWM(Non-Inv)*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	
	/*Select PreScaler /8 */
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
	
	/*Clear Registers*/
	TCNT1 = 0;
	OCR1A = 0;
	ICR1 = 0;
	
	/*Disable Interrupts*/
	CLR_BIT(TIMSK,TIMSK_TOIE1);
	CLR_BIT(TIMSK,TIMSK_OCIE1A);
	CLR_BIT(TIMSK,TIMSK_OCIE1B);
	CLR_BIT(TIMSK,TIMSK_TICIE1);
	
	/*Disable Flags*/
	CLR_BIT(TIFR,TIFR_TOV1);
	CLR_BIT(TIFR,TIFR_OCF1B);
	CLR_BIT(TIFR,TIFR_OCF1A);
	CLR_BIT(TIFR,TIFR_ICF1);	
}

void Timer1_ICUInit(void)
{
	/*Rising Edge*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	/*enable icu interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void Timer1_ICUSenseMode (u8 sense)
{
	/*Falling Edge*/
	if (sense == 0)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(sense ==1)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
}

u16 Timer1_ICRRead(void)
{
	return ICR1;
}

void Timer1_voidSetOCRValue(u16 Value)
{
	OCR1A = Value;
}

void Timer1_voidSetICRValue(u16 Value)
{
	ICR1 = Value;
}

void Timer1_VoidICUSetCallBack(void (*Copy_pf) (void))
{
	INT = Copy_pf;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	INT();
}