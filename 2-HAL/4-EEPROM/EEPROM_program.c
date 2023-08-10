/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	HAL				***************/
/***************	SWC: 	EEPROM			***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"
#include "EEPROM_register.h"
#include "I2C_interface.h"


u8 EEPROM_u8SendData(u16 Address , u8 Data)
{
	u8 Local_StateErr =0;
	
	/*Send Start Condition*/
	Local_StateErr=	I2C_u8SendStartCondition();

	
	/*Send Slave Address with Write for 24C04*/
	/*A2 for device Address , the 2MSB of Address for block number*/
	Local_StateErr=I2C_u8SendSlaveAddressWithWrite(EEPROM_ADD | A2<<2 | A1<<1 | Address>>8);

	
	/*Master Send Location Address*/
	Local_StateErr=	I2C_u8MasterWriteDataByte((u8) Address);

	
	/*Master Send Data*/
	Local_StateErr=	I2C_u8MasterWriteDataByte(Data);

	
	/*Send Stop Condition*/
	I2C_u8SendStopCondition();
	
	return Local_StateErr;
}

u8 EEPROM_u8ReadData(u16 Address , u8* Data)
{
	u8 Local_StateErr =0;
	
	/*Send Start Condition*/
	Local_StateErr=I2C_u8SendStartCondition();

		
	/*Send Slave Address with Write*/
	/*A2 for device Address , the 2MSB of Address for block number*/
	Local_StateErr=I2C_u8SendSlaveAddressWithWrite(EEPROM_ADD | A2<<2 | A1<<1 | Address>>8);

	
	/*Master Send Location Address*/
	Local_StateErr=I2C_u8MasterWriteDataByte((u8)Address);

	
	/*Send Repeated Start To Read the data Form previous Address*/
	Local_StateErr=I2C_u8SendReapeatedStart();

	/*Send Slave Address with Read*/
	/*A2 for device Address , the 2MSB of Address for block number*/
	Local_StateErr=	I2C_u8SendSlaveAddressWithRead(EEPROM_ADD | A2<<2 | A1<<1 | Address>>8);
	

	/* Master Read Data */
	Local_StateErr=	I2C_u8MasterReadDataByte(Data);

		
	/*Send Stop Condition*/
	I2C_u8SendStopCondition();

	return Local_StateErr;
}