/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	I2C				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SendSlaveAddressWithWriteErr,
	SendSlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr	
}Error_Status;

void I2C_voidMasterInit(u8 Address);

void I2C_voidSlaveInit(u8 Address);

void I2C_u8SendStopCondition(void);

Error_Status I2C_u8SendStartCondition(void);

Error_Status I2C_u8SendReapeatedStart(void);

Error_Status I2C_u8SendSlaveAddressWithWrite(u8 Address);

Error_Status I2C_u8SendSlaveAddressWithRead(u8 Address);

Error_Status I2C_u8MasterWriteDataByte(u8 Data);

Error_Status I2C_u8MasterReadDataByte(u8* Data);

Error_Status I2C_u8SlaveReadDataByte(u8* Data);

void I2C_Slave_voidListen(void);
#endif