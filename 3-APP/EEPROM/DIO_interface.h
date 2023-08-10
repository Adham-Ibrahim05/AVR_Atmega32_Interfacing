/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	DIO				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_VoidInit(void);

void DIO_voidSetPinValue(u8 PORT_ID,u8 PIN_ID,u8 Value);

void DIO_voidSetPortValue(u8 PORT_ID,u8 Value);

u8 DIO_u8GetPinValue(u8 PORT_ID,u8 PIN_ID,u8* Value);

#endif