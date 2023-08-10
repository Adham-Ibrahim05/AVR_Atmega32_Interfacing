/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	I2C				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "I2C_config.h"
#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_register.h"

void I2C_voidMasterInit(u8 Address)
{
	/*Set Clock Frequency 400Kbps*/
	/*1-Set register TWBR = 2*/
	TWBR = 2;
	/*2-Clear TWPS PreScalar*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	
	TWAR = Address<<1;
	
	/*Enable TWI Interrupt*/
	SET_BIT(TWCR,TWCR_TWEN);
	
	/* Set ACknowlege*/
	SET_BIT(TWCR,TWCR_TWEA);
}

void I2C_voidSlaveInit(u8 Address)
{
	TWAR = Address<<1;
	
	/*Enable TWI Interrupt*/
	SET_BIT(TWCR,TWCR_TWEN);
	
	/*Set ACknowlege*/
	SET_BIT(TWCR,TWCR_TWEA);
}

Error_Status I2C_u8SendStartCondition(void)
{
	Error_Status Local_State_Error = NoError;
	
	/*Set Start Condition*/
	SET_BIT(TWCR,TWCR_TWSTA);
	
	/*Clear flag to do the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*Wait for flag to be set and the previous operation finished*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/*Check if there is no error in operation*/
	if ((TWSR & 0XF8) !=START_ACK)
	{
		Local_State_Error = StartConditionErr;
	}
	else
	{/*do nothing*/}
		
	return Local_State_Error;	
		
}

void I2C_u8SendStopCondition(void)
{
	/*Enable Stop Bit*/
	SET_BIT(TWCR,TWCR_TWSTO);
	/*Clear flag to do the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
}

Error_Status I2C_u8SendReapeatedStart(void)
{
	Error_Status Local_State_Error = NoError;
	
	/*Set Start Condition*/
	SET_BIT(TWCR,TWCR_TWSTA);
	
	/*Clear flag to do the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*Wait for flag to be set and the previous operation finished*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/*Check if there is no error in operation*/
	if ((TWSR & 0XF8) !=REP_START_ACK)
	{
		Local_State_Error = RepeatedStartErr;
	}
	else
	{/*Do Nothing*/}
	
	return Local_State_Error;
}

Error_Status I2C_u8SendSlaveAddressWithWrite(u8 Address)
{
	Error_Status Local_State_Error = NoError;
	
	/*Send slave Address*/
	/*1-Set Slave Address in 7MSB*/
	TWDR = Address<<1;
	/*2-Write Request*/
	CLR_BIT(TWDR,TWDR_TWD0);
			
	/*Clear Start Condition*/
	CLR_BIT(TWCR,TWCR_TWSTA);
		
	/*Clear flag to do the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*Wait for flag to be set and the previous operation finished*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/*Check if there is no error in operation*/
	if ((TWSR & 0XF8) !=SLAVE_ADD_AND_WR_ACK)
	{
		Local_State_Error = SendSlaveAddressWithWriteErr;
	}
	else
	{/*Do Nothing*/}
	
	return Local_State_Error;
}

Error_Status I2C_u8SendSlaveAddressWithRead(u8 Address)
{
	Error_Status Local_State_Error = NoError;
	
	/*Send slave Address*/
	/*1-Set Slave Address in 7MSB*/
	TWDR = Address<<1;
	/*2-Read Request*/
	SET_BIT(TWDR,TWDR_TWD0);
	
	/*Clear Start Condition*/
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	/*Clear flag to do the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*Wait for flag to be set and the previous operation finished*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/*Check if there is no error in operation*/
	if ((TWSR & 0XF8) !=SLAVE_ADD_AND_RD_ACK)
	{
		Local_State_Error = SendSlaveAddressWithReadErr;
	}
	else
	{/*Do Nothing*/}
	
	return Local_State_Error;
}

Error_Status I2C_u8MasterWriteDataByte(u8 Data)
{
	Error_Status Local_State_Error = NoError;
	
	/*Write Data Byte*/
	TWDR = Data;
	
	/*Clear flag to do the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*Wait for flag to be set and the previous operation finished*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/*Check if there is no error in operation*/
	if ((TWSR & 0XF8) !=MSTR_WR_BYTE_ACK)
	{
		Local_State_Error = MasterWriteByteErr;
	}
	else
	{/*Do Nothing*/}
	
	return Local_State_Error;
}

Error_Status I2C_u8MasterReadDataByte(u8* Data)
{
	Error_Status Local_State_Error = NoError;
	
	/*Enable Master To Generate ACK After Receiving Data*/
	SET_BIT(TWCR,TWCR_TWEA);
	
	/*Clear flag to do the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*Wait for flag to be set and the previous operation finished*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/*Check if there is no error in operation*/
	if ((TWSR & 0XF8) !=MSTR_RD_BYTE_WITH_ACK)
	{
		Local_State_Error = MasterReadByteErr;
	}
	else
	{
		/*Read Data Byte*/
		*Data = TWDR;
	}
	
	return Local_State_Error;
}

Error_Status I2C_u8SlaveReadDataByte(u8* Data)
{
	Error_Status Local_State_Error = NoError;
	
	/*Enable Master To Generate ACK After Receiving Data*/
	SET_BIT(TWCR,TWCR_TWEA);
	
	/*Clear flag to do the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*Wait for flag to be set and the previous operation finished*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/*Check if there is no error in operation*/
	if ((TWSR & 0XF8) !=SLAVE_DATA_RECEIVED)
	{
		Local_State_Error = MasterReadByteErr;
	}
	else
	{
		/*Read Data Byte*/
		*Data = TWDR;
	}
	
	return Local_State_Error;
}

void I2C_Slave_voidListen(void)
{
	/*Wait on flag*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
}

