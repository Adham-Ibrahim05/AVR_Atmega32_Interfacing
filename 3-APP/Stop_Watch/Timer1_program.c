/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	Timer1			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer1_private.h"
#include "Timer1_register.h"
#include "Timer1_config.h"
#include "Timer1_interface.h"

void (*Compare)(void) =NULL;

void Timer1_voidInit(void)
{
	/*Choose Timer Mode*/
	#if Timer1_MODE == NORMAL
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
	
	#elif Timer1_MODE == CTC_OCR1A
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
	#endif
		
	/*Select PreScaler*/
	TCCR1B &= Timer1_PRESCALER_MASK;
	TCCR1B |= Timer1_PRESCALLER;
	
	/*Clear Registers*/
	TCNT1 = 0;
	OCR1A = 0;
	ICR1 = 0;
	
	/*Disable Interrupts*/
	CLR_BIT(TIMSK,TIMSK_TOIE1);
	CLR_BIT(TIMSK,TIMSK_OCIE1B);
	CLR_BIT(TIMSK,TIMSK_TICIE1);
	
	/*Enable CM Interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE1A);
	
	
	/*Disable Flags*/
	SET_BIT(TIFR,TIFR_TOV1);
	SET_BIT(TIFR,TIFR_OCF1B);
	SET_BIT(TIFR,TIFR_OCF1A);
	SET_BIT(TIFR,TIFR_ICF1);	
}

void Timer1_voidSetOCR1AValue(u16 Value)
{
	OCR1A = Value;
}

void Timer1_voidCompareSetCallBack(void(*Copy_pf)(void))
{
	Compare = Copy_pf;
}

/*CTC Vector*/
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	Compare();
}