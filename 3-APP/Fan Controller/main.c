#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "Timer0_interface.h"
#include "util/delay.h"

int main(void)
{
	DIO_VoidInit();
	LCD_voidInit();
	Timer0_voidInit();
	Timer0_SetCompareMatchMode();
	ADC_voidInit();
	ADC_voidEnable();
	
	u16 Digital=0, mv=0;
	u8 Tempeature=0, Speed=0;
	
	while(1)
	{
		ADC_Channel();
		ADC_voidStartConversion();
		Digital = ADC_u16GetChannelReading();
		mv = ((u32) Digital*5000UL)/1024UL; 
		Tempeature = mv/10;
		
		LCD_voidGoToXY(0,0);
		LCD_voidSendString("Temp = ");
		LCD_voidGoToXY(0,7);
		LCD_voidWriteNumber(Tempeature);
		
		if (Tempeature < 30)
		{
			Speed=0;
			LCD_voidGoToXY(1,0);
			LCD_voidSendString("Speed = ");
			LCD_voidGoToXY(1,7);
			LCD_voidWriteNumber(Speed);
			
			/*Fan Stop*/
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_LOW);
			Timer0_voidSetCompareMatchValue(Speed);	
		}
		else if (Tempeature >=30 &&  Tempeature < 60)
		{
			Speed = 25;
			LCD_voidGoToXY(1,0);
			LCD_voidSendString("Speed = ");
			LCD_voidGoToXY(1,7);
			LCD_voidWriteNumber(Speed);
			
			/*Fan Rotate CW*/
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_LOW);
			/* Set Speed/Duty Cycle by 25%*/
			Timer0_voidSetCompareMatchValue(Speed);
		}
		else if (Tempeature >=60 &&  Tempeature < 90)
		{
			Speed = 50;
			LCD_voidGoToXY(1,0);
			LCD_voidSendString("Speed = ");
			LCD_voidGoToXY(1,7);
			LCD_voidWriteNumber(Speed);
			
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_LOW);
			/* Set Speed/Duty Cycle by 50%*/
			Timer0_voidSetCompareMatchValue(Speed);		
		}
		else if (Tempeature >=90 &&  Tempeature < 120)
		{
			Speed = 75;
			LCD_voidGoToXY(1,0);
			LCD_voidSendString("Speed = ");
			LCD_voidGoToXY(1,7);
			LCD_voidWriteNumber(Speed);
			
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_LOW);
			/* Set Speed/Duty Cycle by 75%*/
			Timer0_voidSetCompareMatchValue(Speed);
		}
		else if (Tempeature >=120)
		{
			Speed =100;
			LCD_voidGoToXY(1,0);
			LCD_voidSendString("Speed = ");
			LCD_voidGoToXY(1,7);
			LCD_voidWriteNumber(Speed);
			
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN0,PIN_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN1,PIN_LOW);
			/* Set Speed/Duty Cycle by 100%*/
			Timer0_voidSetCompareMatchValue(Speed);
		}
	}
}