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
#include "Timer0_private.h"
#include "Timer0_register.h"
#include "Timer0_config.h"
#include "Timer0_interface.h"


void (*Compare)(void) =NULL;
void (*Overflow)(void) =NULL;

void Timer0_voidInit(void)
{
	/*Choose Timer Mode*/
	#if Timer0_MODE == NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
	
	#elif Timer0_MODE == CTC
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	#elif Timer0_MODE == Fast_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	
	#elif Timer0_MODE == PWM_PhaseCorrect
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);	
	#endif
	
	/*Compare Match Fast PWM(Non-Inv)*/
	//SET_BIT(TCCR0,5);
	//CLR_BIT(TCCR0,4);
	
	/*Select Timer0 PreScaler*/
	TCCR0 &= Timer0_PRESCALER_MASK;
	TCCR0 |= Timer0_PRESCALLER;
	
	/*Clear Registers*/
	TCNT0 = 0;
	OCR0 = 0;
	
	/*Disable Interrupts*/
	CLR_BIT(TIMSK,TIMSK_TOIE0);
	CLR_BIT(TIMSK,TIMSK_OCIE0);
	
	/*Disable Flags*/
	CLR_BIT(TIFR,TIFR_OCF0);
	CLR_BIT(TIFR,TIFR_TOV0);
}

void Timer0_SetCompareMatchMode(void)
{
	#if COMPARE_MODE == NON_PWM_NORMAL
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == NON_PWM_TOGGLE
	SET_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == NON_PWM_SET
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == NON_PWM_CLEAR
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == FAST_PWM_NORMAL
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == FAST_PWM_TOGGLE
	SET_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == FAST_PWM_NONINV
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == FAST_PWM_INV
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == PHASE_CORRECT_NORMAL
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == PHASE_CORRECT_TOGGLE
	SET_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == PHASE_CORRECT_NONINV
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
	
	#elif COMPARE_MODE == PHASE_CORRECT_INV
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
	#endif
}

u8 Timer0_u8ReadTCNT0(void)
{
	return TCNT0;
}

void TImer0_voidEnableCMInterrupt(void)
{
	/*Enable Compare Match Interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
}

void TImer0_voidEnableOVFInterrupt(void)
{
	/*Enable OverFlow Interrupt*/
	SET_BIT(TIMSK,TIMSK_TOIE0);
}


void Timer0_voidSetPreload(u8 Value)
{
	/*PreLoad Normal mode*/
	TCNT0 = Value;
}


void Timer0_voidSetCompareMatchValue(u8 Value)
{
	/*Compare Match Value CTC mode*/
	OCR0 = Value;
}


void Timer0_voidCompareSetCallBack(void(*Copy_pf)(void))
{
	Compare = Copy_pf;
}

void Timer0_voidOverflowSetCallBack(void(*Copy_PF)(void))
{
	Overflow = Copy_PF;
}

/*CTC Vector*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	Compare();
}

/*Normal Vector*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	Overflow();
}

