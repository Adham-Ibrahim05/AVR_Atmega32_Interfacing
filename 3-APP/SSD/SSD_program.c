#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SSD_config.h"
#include "SSD_interface.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_config.h"
#include<util/delay.h>

void SSD_Init()
{
	DIO_voidSetPinDirection(DIO_PORTA, PIN3,PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, PIN2,PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN6,PIN_OUTPUT);
	
	DIO_voidSetPinDirection(DIO_PORTB, PIN0,PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN1,PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN2,PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN4,PIN_OUTPUT);
}

/*void SSD_voidDisplayOn(u8 SSD_ID,u8 Number)
{
	switch(SSD_ID)
	{
		case SSD1: 
		DIO_voidSetPinDirection(DIO_PORTA, PIN3,PORT_OUTPUT); 
		DIO_voidSetPinValue(DIO_PORTA, PIN3,PIN_LOW);
		DIO_voidSetPinDirection(DIO_PORTB, PIN0,PORT_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB, PIN1,PORT_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB, PIN2,PORT_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB, PIN4,PORT_OUTPUT);
		break;
		
		case SSD2:
		DIO_voidSetPinDirection(DIO_PORTA, PIN2,PORT_OUTPUT); 
		DIO_voidSetPinValue(DIO_PORTA, PIN2,PIN_LOW);
		DIO_voidSetPinDirection(DIO_PORTB, PIN0,PORT_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB, PIN1,PORT_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB, PIN2,PORT_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB, PIN4,PORT_OUTPUT);
		break;
		
		case SSD3: 
		 DIO_voidSetPinDirection(DIO_PORTB, PIN5,PORT_OUTPUT);
		 DIO_voidSetPinValue(DIO_PORTB, PIN5,PIN_LOW);
		 DIO_voidSetPinDirection(DIO_PORTB, PIN0,PORT_OUTPUT);
		 DIO_voidSetPinDirection(DIO_PORTB, PIN1,PORT_OUTPUT);
		 DIO_voidSetPinDirection(DIO_PORTB, PIN2,PORT_OUTPUT);
		 DIO_voidSetPinDirection(DIO_PORTB, PIN4,PORT_OUTPUT);
		 break;
		 
		case SSD4: 
		DIO_voidSetPinDirection(DIO_PORTB, PIN6,PORT_OUTPUT); 
		DIO_voidSetPinValue(DIO_PORTB, PIN6,PIN_LOW);
		DIO_voidSetPinDirection(DIO_PORTB, PIN0,PORT_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB, PIN1,PORT_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB, PIN2,PORT_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB, PIN4,PORT_OUTPUT);
		break;
	}
		
		
		switch(Number)
		{
			case 0:
			DIO_voidSetPinValue(DIO_PORTB, PIN0,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN1,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN2,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN4,PIN_LOW);
			break;
			
			case 1:
			DIO_voidSetPinValue(DIO_PORTB, PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN1,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN2,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN4,PIN_LOW);
			break;
			
			case 2:
			DIO_voidSetPinValue(DIO_PORTB, PIN0,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN1,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN2,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN4,PIN_LOW);
			break;
			
			case 3:
			DIO_voidSetPinValue(DIO_PORTB, PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN1,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN2,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN4,PIN_LOW);
			break;
						
			case 4:
			DIO_voidSetPinValue(DIO_PORTB, PIN0,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN1,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN2,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN4,PIN_LOW);
			break;
			
									
			case 5:
			DIO_voidSetPinValue(DIO_PORTB, PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN1,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN2,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN4,PIN_LOW);
			break;
			
									
			case 6:
			DIO_voidSetPinValue(DIO_PORTB, PIN0,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN1,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN2,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN4,PIN_LOW);
			break;

									
			case 7:
			DIO_voidSetPinValue(DIO_PORTB, PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN1,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN2,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN4,PIN_LOW);
			break;
									
																		
			case 8:
			DIO_voidSetPinValue(DIO_PORTB, PIN0,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN1,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN2,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN4,PIN_HIGH);
			break;									
					
			case 9:
			DIO_voidSetPinValue(DIO_PORTB, PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTB, PIN1,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN2,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, PIN4,PIN_HIGH);
			break;	
		}
}*/

void SSD_voidDisplayOff(u8 SSD_ID)
{
	switch (SSD_ID)
	{
		case SSD1:DIO_voidSetPinValue(DIO_PORTA, PIN3,PIN_HIGH);break;
		case SSD2:DIO_voidSetPinValue(DIO_PORTA, PIN2,PIN_HIGH);break;
		case SSD3:DIO_voidSetPinValue(DIO_PORTB, PIN5,PIN_HIGH);break;
		case SSD4:DIO_voidSetPinValue(DIO_PORTB, PIN6,PIN_HIGH);break;
	}
	
}

void SSD_voidDisplayNumbers(u16 Number)
{
	u16 Temp= Number%10;
	DIO_voidSetPinValue(DIO_PORTB,PIN0,GET_BIT(Temp,0));
	DIO_voidSetPinValue(DIO_PORTB,PIN1,GET_BIT(Temp,1));
	DIO_voidSetPinValue(DIO_PORTB,PIN2,GET_BIT(Temp,2));
	DIO_voidSetPinValue(DIO_PORTB,PIN4,GET_BIT(Temp,3));
	
	DIO_voidSetPinValue(DIO_PORTA,PIN3,PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTA,PIN2,PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTB,PIN5,PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTB,PIN6,PIN_HIGH);
	_delay_ms(5);
	
	Number/=10;
	Temp= Number%10;
	DIO_voidSetPinValue(DIO_PORTB,PIN0,GET_BIT(Temp,0));
	DIO_voidSetPinValue(DIO_PORTB,PIN1,GET_BIT(Temp,1));
	DIO_voidSetPinValue(DIO_PORTB,PIN2,GET_BIT(Temp,2));
	DIO_voidSetPinValue(DIO_PORTB,PIN4,GET_BIT(Temp,3));
	
	DIO_voidSetPinValue(DIO_PORTA,PIN3,PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTA,PIN2,PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTB,PIN5,PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTB,PIN6,PIN_HIGH);
	_delay_ms(5);
	
	Number/=10;
	Temp= Number%10;
	DIO_voidSetPinValue(DIO_PORTB,PIN0,GET_BIT(Temp,0));
	DIO_voidSetPinValue(DIO_PORTB,PIN1,GET_BIT(Temp,1));
	DIO_voidSetPinValue(DIO_PORTB,PIN2,GET_BIT(Temp,2));
	DIO_voidSetPinValue(DIO_PORTB,PIN4,GET_BIT(Temp,3));
	
	DIO_voidSetPinValue(DIO_PORTA,PIN3,PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTA,PIN2,PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTB,PIN5,PIN_LOW);
	DIO_voidSetPinValue(DIO_PORTB,PIN6,PIN_HIGH);
	_delay_ms(5);
	
	Number/=10;
	Temp= Number%10;
	DIO_voidSetPinValue(DIO_PORTB,PIN0,GET_BIT(Number,0));
	DIO_voidSetPinValue(DIO_PORTB,PIN1,GET_BIT(Number,1));
	DIO_voidSetPinValue(DIO_PORTB,PIN2,GET_BIT(Number,2));
	DIO_voidSetPinValue(DIO_PORTB,PIN4,GET_BIT(Number,3));
	
	DIO_voidSetPinValue(DIO_PORTA,PIN3,PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTA,PIN2,PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTB,PIN5,PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTB,PIN6,PIN_LOW);
	_delay_ms(5);
}