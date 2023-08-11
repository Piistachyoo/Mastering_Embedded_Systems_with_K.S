/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : I2C_EEPROM.h 			                             */
/* Date          : Jul 25, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_I2C_EEPROM_H_
#define INC_I2C_EEPROM_H_

// EEPROM is an I2C Slave
// IDLE Mode: device is in high-impedance state and waits for data
// Master Transmitter mode: the device transmits data to a slave receiver
// Master Receiver Mode: The device receives data from a slave transmitter

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "I2C_driver.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------
#define EEPROM_Slave_Address	0x2A
#define EEPROM_I2C				I2C1

/*
 * =============================================
 * APIs Supported by "I2C_EEPROM"
 * =============================================
 */

/**=============================================
 * @Fn			- 
 * @brief 		- 
 * @param [in] 	- 
 * @retval 		- 
 * Note			- 
 */
void EEPROM_Init(void);
void EEPROM_Write_nBytes(uint16 Memory_Address, uint8 *Data, uint8 Data_Length);
void EEPROM_Read_nBytes(uint16 Memory_Address, uint8 *DataOut, uint8 Data_Length);

#endif /* INC_I2C_EEPROM_H_ */
