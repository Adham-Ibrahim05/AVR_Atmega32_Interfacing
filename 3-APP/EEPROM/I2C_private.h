/**********************************************************/
/**********************************************************/
/***************	Author: Adham Ibrahim	***************/
/***************	Layer: 	MCAL			***************/
/***************	SWC: 	I2C				***************/
/***************	Version:1.00			***************/
/**********************************************************/
/**********************************************************/
#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define	START_ACK				0X08		//start has been sent
#define	REP_START_ACK			0X10		// Repeated Start                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
#define	SLAVE_ADD_AND_WR_ACK	0X18		//Master Transmit (SLA+Write)/ACK
#define	SLAVE_ADD_AND_RD_ACK	0X40		//Master Transmit (SLA+Read)/ACK
#define	MSTR_WR_BYTE_ACK		0X28		//Master transmit data ACK
#define	MSTR_RD_BYTE_WITH_ACK	0X50		// Master Received Data ACK
#define	MSTR_RD_BYTE_WITH_NACK	0X58		// Master Received Data NACK
#define	SLAVE_ADD_RCVD_RD_REQ	0XA8		//Slave Address Received with read Request
#define	SLAVE_ADD_RCVD_WR_REQ	0X60		//Slave Address Received with Write Request
#define	SLAVE_DATA_RECEIVED		0X80		// Byte Received 
#define	SLAVE_DATA_TRANSMITTED	0XB8		//Byte Transmitted

#endif