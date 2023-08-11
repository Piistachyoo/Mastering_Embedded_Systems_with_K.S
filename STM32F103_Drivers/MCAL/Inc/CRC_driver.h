/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : CRC_driver.h 			                             */
/* Date          : Jul 31, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_CRC_DRIVER_H_
#define INC_CRC_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "STM32F103x8.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef enum{
	CRC_RESET,
	CRC_NO_RESET
}CRC_RESET_STATUS;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

#define CRC_RESET_VALUE		0x00000001UL

/*
 * =============================================
 * APIs Supported by "CRC"
 * =============================================
 */

/**=============================================
 * @Fn			- MCAL_CRC_Calculate
 * @brief 		- Calculates the 32-bit CRC value for a 32-bit data buffer
 * @param [in] 	- pBuffer	: Pointer to the buffer containing data
 * @param [in] 	- Buffer_Len: Length of 32-bit data in buffer
 * @param [in] 	- reset		: Choose to reset the data register or accumulate on a previous value
 * @retval 		- Calculated 32-bit CRC value
 * Note			- None
 */
uint32 MCAL_CRC_Calculate(uint32 *pBuffer, uint32 Buffer_Len, CRC_RESET_STATUS reset);

/**=============================================
 * @Fn			- MCAL_CRC_Reset
 * @brief 		- Resets the CRC Data Register
 * @param [in] 	- None
 * @retval 		- None
 * Note			- None
 */
void MCAL_CRC_Reset(void);

#endif /* INC_CRC_DRIVER_H_ */
