#define F_CPU 8000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "I2C_interface.h"
#include "EEPROM_interface.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "LCD_interface.h"
#include "util/delay.h"

void main(void)
{	
	u8 Return_Data = 0;
	I2C_voidMasterInit(0);
	DIO_VoidInit();
	LCD_voidInit();

	EEPROM_u8SendData(0 , 0X55);
	_delay_ms(10);	
	EEPROM_u8ReadData(0 , &Return_Data);
	LCD_voidGoToXY(0,0);
	LCD_voidWriteNumber(Return_Data);
	DIO_voidSetPortValue(DIO_PORTD,Return_Data);
	while(1)
	{}
}
