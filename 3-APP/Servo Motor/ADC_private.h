/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	ADC				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/

#ifndef _ADC_PRIVATE_H
#define _ADC_PRIVATE_H

#define	ADC_PRESCALER_MASK	0b11111000

#define DIV_BY_2			1
#define DIV_BY_4			2
#define DIV_BY_8			3
#define DIV_BY_16			4
#define DIV_BY_32			5
#define DIV_BY_64			6
#define DIV_BY_128			7

#define	ADC_CHANNEL_MASK	0b11100000

#define	ADC0				0
#define	ADC1				1
#define	ADC2				2
#define	ADC3				3
#define	ADC4				4
#define	ADC5				5
#define	ADC6				6
#define	ADC7				7

#define	AVCC					5		
#define	AREF					4
#define	INTERNAL				2.56

#define	RIGHT_ADJUSTMENT		0
#define	LEFT_ADJUSTMENT			1

#endif