/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	HAL				***************/
/***************	SWC: 	KPD				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KEY_NOT_PRESSED	0XFF

#define	ROW_PORT		DIO_PORTC
#define	COLOUMN_PORT	DIO_PORTD

#define	ROW1			PIN5
#define	ROW2			PIN4
#define	ROW3			PIN3
#define	ROW4			PIN2

#define	COLOUMN1		PIN7
#define	COLOUMN2		PIN6
#define	COLOUMN3		PIN5
#define	COLOUMN4		PIN3

#define KPD_ARR_VAL		{{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'c',0,'=','+'}}
						 
						 
						 

#endif