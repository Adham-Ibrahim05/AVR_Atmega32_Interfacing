#define F_CPU	8000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_register.h"
#include "I2C_interface.h"
#include "I2C_private.h"
#include "LCD_interface.h"
#include "util/delay.h"

void main()
{	
	Error_Status Error=NoError;
	DIO_VoidInit();
	LCD_voidInit();
	I2C_voidMasterInit(0);
	
	Error =I2C_u8SendStartCondition();
	if (Error == NoError)
	{
		LCD_voidGoToXY(0,0);
		LCD_voidSendString("Start OK");
		_delay_ms(1000);
	}
	
	Error=I2C_u8SendSlaveAddressWithWrite(2);
	if (Error == NoError)
	{
		LCD_voidGoToXY(1,0);
		LCD_voidSendString("SLA OK");
		_delay_ms(500);
	}
	
	if((Error==NoError) && (GET_BIT(PINA,DIO_PIN0)==0))
	{
		Error=I2C_u8MasterWriteDataByte(5);
		LCD_voidGoToXY(2,0);
		LCD_voidSendString("Data OK");
		_delay_ms(500);
	}
	
	I2C_u8SendStopCondition();
	LCD_voidGoToXY(3,0);
	LCD_voidSendString("Stop OK");
	while (1)
	{}
}