/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	Timer			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef		TIMER_PRIVATE_H
#define		TIMER_PRIVATE_H

#define NORMAL					0
#define PWM_PhaseCorrect		1
#define CTC						2
#define Fast_PWM				3

#define Timer0_PRESCALER_MASK	0b11111000

#define NO_CLOCK				0
#define NO_PRESCALE				1
#define DIV_BY8					2
#define DIV_BY64				3
#define DIV_BY256				4
#define DIV_BY1024				5
#define FALLING_EDGE			6
#define RISING_EDGE				7

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