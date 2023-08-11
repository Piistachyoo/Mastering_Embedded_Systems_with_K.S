/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : CRC_driver.c 			                             */
/* Date          : Jul 31, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "CRC_driver.h"

/**=============================================
 * @Fn			- MCAL_CRC_Calculate
 * @brief 		- Calculates the 32-bit CRC value for a 32-bit data buffer
 * @param [in] 	- pBuffer	: Pointer to the buffer containing data
 * @param [in] 	- Buffer_Len: Length of 32-bit data in buffer
 * @param [in] 	- reset		: Choose to reset the data register or accumulate on a previous value
 * @retval 		- Calculated 32-bit CRC value
 * Note			-
 */
uint32 MCAL_CRC_Calculate(uint32 *pBuffer, uint32 Buffer_Len, CRC_RESET_STATUS reset){
	uint32 iterator, result;
	if(CRC_RESET == reset){
		MCAL_CRC_Reset();
	}
	else{ /* Do Nothing */ }

	/* Calculate CRC for every 32-bit data in buffer */
	for(iterator = 0; iterator < Buffer_Len; iterator++){
		CRC->DR = pBuffer[iterator];
	}

	/* Extract calculated 32-bit CRC value and return it */
	result = CRC->DR;

	return result;
}

/**=============================================
 * @Fn			- MCAL_CRC_Reset
 * @brief 		- Resets the CRC Data Register
 * @param [in] 	- None
 * @retval 		- None
 * Note			- None
 */
void MCAL_CRC_Reset(void){
	CRC->CR = CRC_RESET_VALUE;
}
