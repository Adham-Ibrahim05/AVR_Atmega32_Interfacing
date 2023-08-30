/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	DIO				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#define PIN_HIGH	1
#define PIN_LOW		0

#define PORT_HIGH	0xff
#define PORT_LOW	0

#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

/*choose: 0 for input
		  1 for output*/
		  
#define PORTA_PIN0_DIR				1
#define PORTA_PIN1_DIR				0
#define PORTA_PIN2_DIR				1
#define PORTA_PIN3_DIR				1
#define PORTA_PIN4_DIR				0
#define PORTA_PIN5_DIR				0
#define PORTA_PIN6_DIR				0
#define PORTA_PIN7_DIR				0

#define PORTB_PIN0_DIR				1
#define PORTB_PIN1_DIR				1
#define PORTB_PIN2_DIR				1
#define PORTB_PIN3_DIR				1
#define PORTB_PIN4_DIR				1
#define PORTB_PIN5_DIR				0
#define PORTB_PIN6_DIR				0
#define PORTB_PIN7_DIR				0
		
#define PORTC_PIN0_DIR				0
#define PORTC_PIN1_DIR				0
#define PORTC_PIN2_DIR				0
#define PORTC_PIN3_DIR				0
#define PORTC_PIN4_DIR				0
#define PORTC_PIN5_DIR				0
#define PORTC_PIN6_DIR				0
#define PORTC_PIN7_DIR				0

#define PORTD_PIN0_DIR				1
#define PORTD_PIN1_DIR				1
#define PORTD_PIN2_DIR				0
#define PORTD_PIN3_DIR				0
#define PORTD_PIN4_DIR				0
#define PORTD_PIN5_DIR				1
#define PORTD_PIN6_DIR				0
#define PORTD_PIN7_DIR				0

/*choose: 0 for floating if input , low if output
		  1 for pulledup if input , high if output*/
		  	
#define PORTA_PIN0_INITIAL_VALUE	0
#define PORTA_PIN1_INITIAL_VALUE	0
#define PORTA_PIN2_INITIAL_VALUE	0
#define PORTA_PIN3_INITIAL_VALUE	0
#define PORTA_PIN4_INITIAL_VALUE	0
#define PORTA_PIN5_INITIAL_VALUE	0
#define PORTA_PIN6_INITIAL_VALUE	0
#define PORTA_PIN7_INITIAL_VALUE	0

#define PORTB_PIN0_INITIAL_VALUE	0
#define PORTB_PIN1_INITIAL_VALUE	0
#define PORTB_PIN2_INITIAL_VALUE	0
#define PORTB_PIN3_INITIAL_VALUE	1
#define PORTB_PIN4_INITIAL_VALUE	0
#define PORTB_PIN5_INITIAL_VALUE	0
#define PORTB_PIN6_INITIAL_VALUE	0
#define PORTB_PIN7_INITIAL_VALUE	0

#define PORTC_PIN0_INITIAL_VALUE	0
#define PORTC_PIN1_INITIAL_VALUE	0
#define PORTC_PIN2_INITIAL_VALUE	0
#define PORTC_PIN3_INITIAL_VALUE	0
#define PORTC_PIN4_INITIAL_VALUE	0
#define PORTC_PIN5_INITIAL_VALUE	0
#define PORTC_PIN6_INITIAL_VALUE	0
#define PORTC_PIN7_INITIAL_VALUE	0

#define PORTD_PIN0_INITIAL_VALUE	0
#define PORTD_PIN1_INITIAL_VALUE	0
#define PORTD_PIN2_INITIAL_VALUE	0
#define PORTD_PIN3_INITIAL_VALUE	0
#define PORTD_PIN4_INITIAL_VALUE	0
#define PORTD_PIN5_INITIAL_VALUE	0
#define PORTD_PIN6_INITIAL_VALUE	0
#define PORTD_PIN7_INITIAL_VALUE	0

#endif