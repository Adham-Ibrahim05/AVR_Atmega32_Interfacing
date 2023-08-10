#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"DIO_config.h"
#include <avr/delay.h>
void main(void)
{
	/*Set PinA0 as output*/
	DIO_voidSetPinDirection(DIO_PORTB,PIN7,PIN_OUTPUT);

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
    }
}