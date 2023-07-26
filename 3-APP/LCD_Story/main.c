#include "STD_TYPES.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void main(void)
{
	LCD_voidInit();
	u8 Normal_Pos [8] = {0X0E,0X0E,0X05,0X0E,0X14,0X04,0X0E,0X15};
	u8 Welcome_Pos [8] = {0X00,0X0E,0X0E,0X14,0X1F,0X05,0X0E,0X11};
	u8 Bye1 [8] = {0x0E,0x0E,0x05,0x06,0x1C,0x04,0x04,0x1B};
	u8 Bye2 [8] = {0x0E,0x0E,0x04,0x07,0x1C,0x04,0x04,0x1B};
	u8 Move_Forward1 [8] = {0x07,0x07,0x04,0x0F,0x14,0x04,0x0B,0x10};
	u8 Move_Forward2 [8] = {0x07,0x07,0x04,0x1E,0x05,0x04,0x1A,0x00};
		
	/*Animation Starting*/
	for(int i=0;i<17;i++)
	{
			LCD_voidWriteSpecialCharacter(Move_Forward1, 0, 0, i);
			_delay_ms(500);
			LCD_voidSendCommand(1);
			_delay_ms(10);
			i++;
			LCD_voidWriteSpecialCharacter(Move_Forward2, 1, 0, i);
			_delay_ms(500);
			LCD_voidSendCommand(1);
			_delay_ms(10);
	}
	
	/*Welcome*/
	LCD_voidWriteSpecialCharacter(Welcome_Pos, 2, 0, 17);
	_delay_ms(400);
	LCD_voidGoToXY(0,0);
	LCD_voidSendString("HI");
	_delay_ms(400);
	LCD_voidGoToXY(0,3);
	LCD_voidSendString("My Name");
	_delay_ms(400);
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("is Adham");
	_delay_ms(400);
	LCD_voidGoToXY(2,0);
	LCD_voidSendString("HOW are you ?!!");
	_delay_ms(1000);
	LCD_voidSendCommand(1);
	_delay_ms(10);
	
	/*The Story*/
	LCD_voidWriteSpecialCharacter(Normal_Pos,3,0,17);
	_delay_ms(700);
	LCD_voidGoToXY(0,0);
	LCD_voidSendString("Today i'm going");
	_delay_ms(700);
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("To tell you about");
	_delay_ms(700);
	LCD_voidGoToXY(2,0);
	LCD_voidSendString("My Traveling to");
	_delay_ms(700);
	LCD_voidGoToXY(3,6);
	LCD_voidSendString("KSA");
	_delay_ms(1000);
	LCD_voidSendCommand(1);
	_delay_ms(10);
	LCD_voidWriteSpecialCharacter(Normal_Pos,3,0,0);
	LCD_voidGoToXY(0,3);
	LCD_voidSendString("First time to");
	_delay_ms(700);
	LCD_voidGoToXY(1,3);
	LCD_voidSendString("Ride a plane");
	_delay_ms(700);
	LCD_voidGoToXY(2,3);
	LCD_voidSendString("I Visited Kaaba");
	_delay_ms(700);
	LCD_voidGoToXY(3,3);
	LCD_voidSendString("And did Umrah");
	_delay_ms(1000);
	LCD_voidSendCommand(1);
	_delay_ms(10);
	LCD_voidWriteSpecialCharacter(Normal_Pos,3,0,0);
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("!!Great Experience!!");
	_delay_ms(700);
	LCD_voidGoToXY(2,0);
	LCD_voidSendString("I'll visit it again");
	_delay_ms(700);
	LCD_voidGoToXY(3,8);
	LCD_voidSendString("SOON");
	_delay_ms(1000);
	LCD_voidSendCommand(1);
	_delay_ms(10);
	LCD_voidWriteSpecialCharacter(Normal_Pos,3,1,9);
	LCD_voidGoToXY(2,3);
	LCD_voidSendString("That's My Story");
	_delay_ms(700);
	LCD_voidGoToXY(3,3);
	LCD_voidSendString("Tell me yours");
	_delay_ms(1000);
	LCD_voidSendCommand(1);
	_delay_ms(10);
	
	/*End Story*/
	while(1)
	{
		LCD_voidGoToXY(2,3);
		LCD_voidSendString("!!THANK YOU!!");
		LCD_voidWriteSpecialCharacter(Bye1,4,2,17);
		_delay_ms(700);
		LCD_voidSendCommand(1);
		_delay_ms(10);
		LCD_voidGoToXY(2,3);
		LCD_voidSendString("!!THANK YOU!!");
		LCD_voidWriteSpecialCharacter(Bye2,5,2,17);
		_delay_ms(700);
		LCD_voidSendCommand(1);
		_delay_ms(10);
	}
}