/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	HAL				***************/
/***************	SWC: 	LCD				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit();
void LCD_voidSendCommand(u8 Command);
void LCD_voidSendData(u8 Data);
void LCD_voidSendString(const char *String);
void LCD_voidGoToXY(u8 X_Pos, u8 Y_Pos);
void LCD_voidWriteNumber(u8 Number);
void LCD_voidWriteSpecialCharacter(u8 *Array_Of_Pattern, u8 Block_No, u8 X_pos, u8 Y_pos);

#endif