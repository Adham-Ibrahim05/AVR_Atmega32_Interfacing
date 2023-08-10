/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	EXTI			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_register.h"

/*Global Pointer to function to hold INT ISR address*/
void(*EXT_INT0_pf)(void) = NULL;
void(*EXT_INT1_pf)(void) = NULL;
void(*EXT_INT2_pf)(void) = NULL;

void EXTI_voidINT1Init(void)
{
	/*Sense Control*/
	MCUCR&= SENSE_CONTROL_MASK;
	MCUCR|= SENSE_MODE;
	
	///*Rising Edge*/
	//#if SENSE_MODE == EXTI_RISING
	//SET_BIT(MCUCR,3);
	//SET_BIT(MCUCR,2);
	//
	///*Falling Edge*/
	//#elif SENSE_MODE == EXTI_FALLING
	//SET_BIT(MCUCR,3);
	//CLR_BIT(MCUCR,2);
	//
	///*Logic change*/
	//#elif SENSE_MODE == EXTI_IOC
	//SET_BIT(MCUCR,2);
	//CLR_BIT(MCUCR,3);
	//
	///*Low Level*/
	//#elif SENSE_MODE == EXTI_LOW
	//CLR_BIT(MCUCR,3);
	//CLR_BIT(MCUCR,2);
	//#endif
	
	/*Disable External Interrupt(PIE)*/
	CLR_BIT(GICR,GICR_INT1);
	
	/*Clear Flag(PIF)*/
	SET_BIT(GIFR,GIFR_INTF1);
	 
}
void EXTI_voidINT1Enable(void)
{
	/*INT1 Enable*/
	SET_BIT(GICR,GICR_INT1);
}
void EXTI_voidINT1Disable(void)
{
	/*INT1 Disable*/
	CLR_BIT(GICR,GICR_INT1);
}

void EXTI_voidINT0Init(void)
{	
	/*Sense Control*/
	MCUCR&= SENSE_CONTROL_MASK;
	MCUCR|= SENSE_MODE;
	
	///*Rising Edge*/
	//#if SENSE_MODE == EXTI_RISING
	//SET_BIT(MCUCR,1);
	//SET_BIT(MCUCR,0);
	//
	///*Falling Edge*/
	//#elif SENSE_MODE == EXTI_FALLING
	//SET_BIT(MCUCR,1);
	//CLR_BIT(MCUCR,0);
	//
	///*Logic change*/
	//#elif SENSE_MODE == EXTI_IOC
	//SET_BIT(MCUCR,0);
	//CLR_BIT(MCUCR,1);
	//
	///*Low Level*/
	//#elif SENSE_MODE == EXTI_LOW
	//CLR_BIT(MCUCR,1);
	//CLR_BIT(MCUCR,0);
	//#endif
	
	/*Disable External Interrupt(PIE)*/
	CLR_BIT(GICR,GICR_INT0);
	
	/*Clear Flag(PIF)*/
	SET_BIT(GIFR,GIFR_INTF0);
	 
}
void EXTI_voidINT0Enable(void)
{
	/*INT0 Enable*/
	SET_BIT(GICR,GICR_INT0);
}
void EXTI_voidINT0Disable(void)
{
	/*INT0 Disable*/
	CLR_BIT(GICR,GICR_INT0);
}

void EXTI_voidINT2Init(void)
{
	/*Sense Control*/
	
	/*Rising Edge*/
	#if SENSE_MODE == EXTI_RISING
	SET_BIT(MCUCSR,MCUCSR_ISC2);
	/*Falling Edge*/
	#elif SENSE_MODE == EXTI_FALLING
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
	#endif
	
	/*Disable External Interrupt(PIE)*/
	CLR_BIT(GICR,GICR_INT2);
	
	/*Clear Flag*/
	SET_BIT(GIFR,GIFR_INTF2);
	 
}
void EXTI_voidINT2Enable(void)
{
	/*INT2 Enable*/
	SET_BIT(GICR,GICR_INT2);
}
void EXTI_voidINT2Disable(void)
{
	/*INT2 Disable*/
	CLR_BIT(GICR,GICR_INT2);
}


void EXTINT0_VoidSetCallBack(void (*Copy_pf) (void))
{
	EXT_INT0_pf = Copy_pf;
}

/*ISR of INT0*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXT_INT0_pf();
}


void EXTINT1_VoidSetCallBack(void (*Copy_pf) (void))
{
	EXT_INT1_pf = Copy_pf;
}

/*ISR of INT1*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	EXT_INT1_pf();
}



void EXTINT2_VoidSetCallBack(void (*Copy_pf) (void))
{
	EXT_INT2_pf = Copy_pf;
}

/*ISR of INT2*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	EXT_INT2_pf();
}