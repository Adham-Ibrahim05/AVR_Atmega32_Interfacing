/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	DIO				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_register.h"
#include "DIO_private.h"

void DIO_VoidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	PORTA = PORTA_INITIAL_VALUE;
	PORTB = PORTB_INITIAL_VALUE;
	PORTC = PORTC_INITIAL_VALUE;
	PORTD = PORTD_INITIAL_VALUE;
}


void DIO_voidSetPinValue(u8 PORT_ID,u8 PIN_ID,u8 Value)
{
	if(PIN_ID <= DIO_PIN7)
	{
		if(Value == PIN_LOW)
		{
			switch(PORT_ID)
			{
				case DIO_PORTA: CLR_BIT(PORTA,PIN_ID);break;
				case DIO_PORTB: CLR_BIT(PORTB,PIN_ID);break;
				case DIO_PORTC: CLR_BIT(PORTC,PIN_ID);break;
				case DIO_PORTD: CLR_BIT(PORTD,PIN_ID);break;
			}
		}
		else if(Value == PIN_HIGH)
		{
			switch(PORT_ID)
			{
				case DIO_PORTA: SET_BIT(PORTA,PIN_ID);break;
				case DIO_PORTB: SET_BIT(PORTB,PIN_ID);break;
				case DIO_PORTC: SET_BIT(PORTC,PIN_ID);break;
				case DIO_PORTD: SET_BIT(PORTD,PIN_ID);break;
			}
		}
	}
}


void DIO_voidSetPortValue(u8 PORT_ID,u8 Value)
{
	switch(PORT_ID)
	{
		case DIO_PORTA: PORTA= Value;break;
		case DIO_PORTB: PORTB= Value;break;
		case DIO_PORTC: PORTC= Value;break;
		case DIO_PORTD: PORTD= Value;break;
	}
}

u8 DIO_u8GetPinValue(u8 PORT_ID,u8 PIN_ID,u8* Value)
{
	u8 NULL_PtrErrorState = 0;
	if(Value!=NULL && PIN_ID<=DIO_PIN7)
	{
		switch(PORT_ID)
		{
			case DIO_PORTA: *Value = GET_BIT(PINA,PIN_ID); break;
			case DIO_PORTB: *Value = GET_BIT(PINB,PIN_ID); break;
			case DIO_PORTC: *Value = GET_BIT(PINC,PIN_ID); break;
			case DIO_PORTD: *Value = GET_BIT(PIND,PIN_ID); break;
		}
	}
	else
	{
		NULL_PtrErrorState = 1;
	}
	return NULL_PtrErrorState;
}

