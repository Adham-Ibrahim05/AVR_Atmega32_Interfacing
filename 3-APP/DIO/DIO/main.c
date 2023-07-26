#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"DIO_config.h"
#include <avr/delay.h>
#define pressed	0
void main(void)
{
	/*Set PinA0 as output*/
	/*DIO_voidSetPinDirection(DIO_PORTB,PIN7,PIN_OUTPUT);
	
	//PinA0 is high//
	//DIO_voidSetPinValue(DIO_PORTB,PIN7,PIN_HIGH);
	//u8 value = PIN5;
    while(1)
    {
		DIO_voidSetPinValue(DIO_PORTB,PIN7,PIN_HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(DIO_PORTB,PIN7,PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTA,PIN4,PIN_HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(DIO_PORTA,PIN4,PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTA,PIN5,PIN_HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(DIO_PORTA,PIN5,PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTA,PIN6,PIN_HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(DIO_PORTA,PIN6,PIN_LOW);
		
        //TODO:: Please write your application code 
    }*/
	DIO_voidSetPinDirection(DIO_PORTB,PIN6,PORT_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN0,PORT_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN1,PORT_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN2,PORT_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN4,PORT_OUTPUT);
	u8 ssd[9] = {0b00000000,0b00000001,0b00000010,0b00000100,0b00000101,0b00000110,0b00000111,0b00001000,0b00001001}; // array for the numbers 0 to 9
	u8 number =2 ;
	while(1)
	{
		DIO_voidSetPortValue(DIO_PORTB,ssd[number]);
	}
	
	
	
}