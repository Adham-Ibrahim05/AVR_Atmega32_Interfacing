/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	HAL				***************/
/***************	SWC: 	KPD				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_register.h"
#include "KPD_private.h"

void KPD_u8Init()
{
	DIO_voidSetPinDirection(COLOUMN_PORT,COLOUMN1,PIN_OUTPUT);
	DIO_voidSetPinDirection(COLOUMN_PORT,COLOUMN2,PIN_OUTPUT);
	DIO_voidSetPinDirection(COLOUMN_PORT,COLOUMN3,PIN_OUTPUT);
	DIO_voidSetPinDirection(COLOUMN_PORT,COLOUMN4,PIN_OUTPUT);
	/*Set Column pin as initially high*/
	DIO_voidSetPinValue(COLOUMN_PORT,COLOUMN1,PIN_HIGH);
	DIO_voidSetPinValue(COLOUMN_PORT,COLOUMN2,PIN_HIGH);
	DIO_voidSetPinValue(COLOUMN_PORT,COLOUMN3,PIN_HIGH);
	DIO_voidSetPinValue(COLOUMN_PORT,COLOUMN4,PIN_HIGH);
	
	DIO_voidSetPinDirection(ROW_PORT,ROW1,PIN_INPUT);
	DIO_voidSetPinDirection(ROW_PORT,ROW2,PIN_INPUT);
	DIO_voidSetPinDirection(ROW_PORT,ROW3,PIN_INPUT);
	DIO_voidSetPinDirection(ROW_PORT,ROW4,PIN_INPUT);
	/*Set Row pin as initially high*/
	DIO_voidSetPinValue(ROW_PORT,ROW1,PIN_HIGH);
	DIO_voidSetPinValue(ROW_PORT,ROW2,PIN_HIGH);
	DIO_voidSetPinValue(ROW_PORT,ROW3,PIN_HIGH);
	DIO_voidSetPinValue(ROW_PORT,ROW4,PIN_HIGH);
}

u8 KPD_u8GetPressedKey()
{
	u8 Pressed_Key = KEY_NOT_PRESSED, Key_Status, Coloumn_Idx, Row_Idx;

	static u8 KPD_Arr[ROW_NUM][COLOUMN_NUM] = KPD_ARR_VAL;
	static u8 Coloumn_Arr [COLOUMN_NUM] = {COLOUMN1,COLOUMN2,COLOUMN3,COLOUMN4};
	static u8 Row_Arr [ROW_NUM] = {ROW1,ROW2,ROW3,ROW4};
	
	for(u8 Coloumn_Idx=0 ; Coloumn_Idx<COLOUMN_NUM ; Coloumn_Idx++)
	{
		/*Activate Current Column*/
		DIO_voidSetPinValue(COLOUMN_PORT,Coloumn_Arr[Coloumn_Idx],PIN_LOW);
		for(u8 Row_Idx=0 ; Row_Idx<ROW_NUM ; Row_Idx++)
		{
			/*Read Current Row*/
			DIO_u8GetPinValue(ROW_PORT,Row_Arr[Row_Idx],&Key_Status);
			/*Check for status of the switch*/
			if(Key_Status==PIN_LOW)
			{
				Pressed_Key = KPD_Arr[Row_Idx][Coloumn_Idx];
				/*Polling for the Switch until released*/
				while(Key_Status==PIN_LOW)
				{
					DIO_u8GetPinValue(ROW_PORT,Row_Arr[Row_Idx],&Key_Status);
				}
				return Pressed_Key;
			}
		}
		/*Deactivate Current Column*/
		DIO_voidSetPinValue(COLOUMN_PORT,Coloumn_Arr[Coloumn_Idx],PIN_HIGH);
	}
	return Pressed_Key;
}