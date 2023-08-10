/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	Timer1			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef		TIMER_PRIVATE_H
#define		TIMER_PRIVATE_H

#define NORMAL						0
#define PHASE_CORRECT8				1
#define PHASE_CORRECT9				2
#define PHASE_CORRECT10				3
#define CTC_OCR1A					4
#define FAST_PWM8					5
#define FAST_PWM9					6
#define FAST_PWM10					7
#define PHASE_CORRECT_ICR1			8
#define PHASE_CORRECT_OCR1A			9
#define CTC_ICR1					10
#define FAST_PWM_ICR1				11
#define FAST_PWM_OCR1A				12


#define Timer1_PRESCALER_MASK		0b11111000

#define NO_CLOCK					0
#define NO_PRESCALE					1
#define DIV_BY8						2
#define DIV_BY64					3
#define DIV_BY256					4
#define DIV_BY1024					5
#define FALLING_EDGE				6
#define RISING_EDGE					7

#define ICU_FALLING_EDGE			0
#define ICU_RISING_EDGE				1


#define NON_PWM_NORMAL				0
#define NON_PWM_TOGGLE				1
#define NON_PWM_CLEAR				2
#define NON_PWM_SET					3

#define FAST_PWM_NORMAL				0
#define FAST_PWM_TOGGLE				1
#define FAST_PWM_NONINV				2
#define FAST_PWM_INV				3

#define PHASE_CORRECT_NORMAL		0
#define PHASE_CORRECT_TOGGLE		1
#define PHASE_CORRECT_NONINV		2
#define PHASE_CORRECT_INV			3





#endif