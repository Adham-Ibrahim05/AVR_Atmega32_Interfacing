/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	HAL				***************/
/***************	SWC: 	LCD				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_register.h"
#include <util/delay.h>

void LCD_voidSendCommand(u8 Command)
{
	/*Set RS pin to low for command*/
	DIO_voidSetPinValue(CTRL_PORT,RS,PIN_LOW);
	
	/*Send Command to data pins*/
	DIO_voidSetPinValue(DATA_PORT,D4,GET_BIT(Command,4));
	DIO_voidSetPinValue(DATA_PORT,D5,GET_BIT(Command,5));
	DIO_voidSetPinValue(DATA_PORT,D6,GET_BIT(Command,6));
	DIO_voidSetPinValue(DATA_PORT,D7,GET_BIT(Command,7));
	
	/*Enable Trigger Pulses*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(1);
	
	DIO_voidSetPinValue(DATA_PORT,D4,GET_BIT(Command,0));
	DIO_voidSetPinValue(DATA_PORT,D5,GET_BIT(Command,1));
	DIO_voidSetPinValue(DATA_PORT,D6,GET_BIT(Command,2));
	DIO_voidSetPinValue(DATA_PORT,D7,GET_BIT(Command,3));
	
	/*Enable Trigger Pulses*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(2);
}

void LCD_voidInit()
{
	_delay_ms(31);	
	/*1/Function Set*/
	DIO_voidSetPinValue(DATA_PORT,D4,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D5,PIN_HIGH);
	DIO_voidSetPinValue(DATA_PORT,D6,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D7,PIN_LOW);
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(2);
	
	DIO_voidSetPinValue(DATA_PORT,D4,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D5,PIN_HIGH);
	DIO_voidSetPinValue(DATA_PORT,D6,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D7,PIN_LOW);
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(2);
	
	DIO_voidSetPinValue(DATA_PORT,D6,PIN_LOW);// fONT 5*8
	DIO_voidSetPinValue(DATA_PORT,D7,PIN_HIGH);// 2 lines
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,DIO_PIN2,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,DIO_PIN2,PIN_LOW);
	_delay_ms(2);
	
	/*2/Display on off control: display enable, disable cursor, no blink cursor*/
	DIO_voidSetPinValue(DATA_PORT,D4,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D5,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D6,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D7,PIN_LOW);
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(2);
	
	DIO_voidSetPinValue(DATA_PORT,D4,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D5,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D6,PIN_HIGH);
	DIO_voidSetPinValue(DATA_PORT,D7,PIN_HIGH);
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(2);
	
	/*3/Clear display*/
	DIO_voidSetPinValue(DATA_PORT,D4,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D5,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D6,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D7,PIN_LOW);
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(2);
	
	DIO_voidSetPinValue(DATA_PORT,D4,PIN_HIGH);
	DIO_voidSetPinValue(DATA_PORT,D5,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D6,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D7,PIN_LOW);
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(2);

	/*4/Entry Mode*/
	DIO_voidSetPinValue(DATA_PORT,D4,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D5,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D6,PIN_LOW);
	DIO_voidSetPinValue(DATA_PORT,D7,PIN_LOW);
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(2);
	
	DIO_voidSetPinValue(DATA_PORT,D4,PIN_HIGH);
	DIO_voidSetPinValue(DATA_PORT,D5,PIN_HIGH);
	DIO_voidSetPinValue(DATA_PORT,D6,PIN_HIGH);
	DIO_voidSetPinValue(DATA_PORT,D7,PIN_LOW);
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(2);
}

void LCD_voidSendData(u8 Data)
{
	/*Set RS pin to high for Data*/
	DIO_voidSetPinValue(CTRL_PORT,RS,PIN_HIGH);
	
	/*Send Data*/
	DIO_voidSetPinValue(DATA_PORT,D4,GET_BIT(Data,4));
	DIO_voidSetPinValue(DATA_PORT,D5,GET_BIT(Data,5));
	DIO_voidSetPinValue(DATA_PORT,D6,GET_BIT(Data,6));
	DIO_voidSetPinValue(DATA_PORT,D7,GET_BIT(Data,7));
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(1);
	DIO_voidSetPinValue(DATA_PORT,D4,GET_BIT(Data,0));
	DIO_voidSetPinValue(DATA_PORT,D5,GET_BIT(Data,1));
	DIO_voidSetPinValue(DATA_PORT,D6,GET_BIT(Data,2));
	DIO_voidSetPinValue(DATA_PORT,D7,GET_BIT(Data,3));
	
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(1);
}

void LCD_voidSendString(const char *String)
{
	u8 Counter=0;
	while(String[Counter]!='\0')
	{
		LCD_voidSendData(String[Counter]);
		Counter++;
	}
}

void LCD_voidGoToXY(u8 X_Pos, u8 Y_Pos)
{
	u8 Address=0;
	/*Location at First line*/
	if(X_Pos==0)
	{
		Address = Y_Pos + 0x80;
	}
	/*Location at Second line*/
	else if(X_Pos==1)
	{
		Address = Y_Pos + 0xC0;
	}
	/*Location at third line*/
	else if(X_Pos==2)
	{
		Address = Y_Pos + 0x94;
	}
	/*Location at fourth line*/
	else if(X_Pos==3)
	{
		Address = Y_Pos + 0xd4;
	}
	
	///Set DDRAM Address Command////
	
	/*Set RS pin to low for command*/
	DIO_voidSetPinValue(CTRL_PORT,RS,PIN_LOW);
	
	/*Send Address to Data pins*/
	DIO_voidSetPinValue(DATA_PORT,D4,GET_BIT(Address,4));
	DIO_voidSetPinValue(DATA_PORT,D5,GET_BIT(Address,5));
	DIO_voidSetPinValue(DATA_PORT,D6,GET_BIT(Address,6));
	/*Set D7 high*/
	DIO_voidSetPinValue(DATA_PORT,D7,PIN_HIGH);
	
	/*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(1);
	
	DIO_voidSetPinValue(DATA_PORT,D4,GET_BIT(Address,0));
	DIO_voidSetPinValue(DATA_PORT,D5,GET_BIT(Address,1));
	DIO_voidSetPinValue(DATA_PORT,D6,GET_BIT(Address,2));
	DIO_voidSetPinValue(DATA_PORT,D7,GET_BIT(Address,3));
	
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(1);
}

void LCD_voidWriteNumber(u8 Number)
{
	u16 temp;
	u8 Idx,Arr[SIZE_ARRAY_NUMBERS],Counter=0;
	if(Number==0)
	{
		LCD_voidSendData('0');
	}
	else
	{
	while(Number!=0)
	{
		temp = Number%10;
		Arr[Counter] = temp;
		Number/=10;
		Counter++;
	}
	
			for(Idx=Counter; Idx>0;Idx--)
			{
				LCD_voidSendData(Arr[Idx-1] + 48);//+ 48 for  represented integer for characters.
			}
	}	
}

void LCD_voidWriteSpecialCharacter(u8 *Array_Of_Pattern, u8 Block_No, u8 X_pos, u8 Y_pos)
{
	u8 Address=0,Idx;
	/*Calculate CGRAM Address*/
	Address = Block_No * 8;
	
	///Set CGRAM Address///
	
   /*Set RS pin to low for command*/
   DIO_voidSetPinValue(CTRL_PORT,RS,PIN_LOW);
   
   /*Send Address to Data pins*/
   DIO_voidSetPinValue(DATA_PORT,D4,GET_BIT(Address,4));
   DIO_voidSetPinValue(DATA_PORT,D5,GET_BIT(Address,5));
   /*Set D6 high ,D7 low*/
   DIO_voidSetPinValue(DATA_PORT,D6,PIN_HIGH);
   DIO_voidSetPinValue(DATA_PORT,D7,PIN_LOW);
   
   /*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(1);
	
    DIO_voidSetPinValue(DATA_PORT,D4,GET_BIT(Address,0));
    DIO_voidSetPinValue(DATA_PORT,D5,GET_BIT(Address,1));
    DIO_voidSetPinValue(DATA_PORT,D6,GET_BIT(Address,2));
    DIO_voidSetPinValue(DATA_PORT,D7,GET_BIT(Address,3));
   
   /*Enable Trigger high then after 2ms low*/
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT,EN,PIN_LOW);
	_delay_ms(1);
   
   /*Write Pattern To CGRAM*/
	for(Idx=0;Idx<8;Idx++)
	{
		LCD_voidSendData(Array_Of_Pattern[Idx]);
	}
   
   /*Go Back To DDRAM TO Display*/
   LCD_voidGoToXY(X_pos,Y_pos);
   
   /*Display the Pattern Written in CGRAM*/
   LCD_voidSendData(Block_No);
}