/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : ss_driver.c 			                            	 */
/* Date          : Jun 18, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "ss_driver.h"

/**=============================================
  * @Fn				- SS_Init
  * @brief 			- Initializes the seven segment's GPIO pins
  * @param [in] 	- mySS: Pointer to the struct holding the seven segment configuration
  * @param [out] 	- None
  * @retval 		- None
  * Note			- Seven segment initially shows no number
  */
void SS_Init(const SS_cfg_t *mySS){
	uint8 index, SS_initial_state;
	/* Validate that led_cfg is not a NULL pointer */
	if(NULL != mySS){
		/* Let initial state be OFF */
		if(SS_Common_Anode == mySS->Active_Mode){
			SS_initial_state = GPIO_PIN_SET;
		}
		else if(SS_Common_Cathode == mySS->Active_Mode){
			SS_initial_state = GPIO_PIN_RESET;
		}
		else{
			/* Default is common cathode */
			SS_initial_state = GPIO_PIN_RESET;
		}
		/* Initialize GPIO PINS */
		for(index = 0; index < 8; index++){
			MCAL_GPIO_Init(mySS->PINS[index].PORT, (GPIO_PinConfig_t*)&(mySS->PINS[index].PIN));
			MCAL_GPIO_WritePin(mySS->PINS[index].PORT, mySS->PINS[index].PIN.GPIO_PinNumber, SS_initial_state);
		}
	}
	else{ /* Do Nothing */ }
}

/**=============================================
  * @Fn				- SS_Display_Number
  * @brief 			- Shows corresponding number on
  * @param [in] 	- mySS: Pointer to the struct holding the seven segment configuration
  * @param [in] 	- number: The number that will be displayed on the seven segment @ref SS_Numbers_define
  * @param [in] 	- dot_status: Defins the dot status if on or off @ref SS_Dot_Status_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- Seven segment initially shows no number
  */
void SS_Display_Number(const SS_cfg_t *mySS, uint8 number, uint8 dot_status){
	uint8 index, SS_ON_mode, SS_OFF_mode;
	number |= dot_status; // Turn dot on or off depending on sent configuration
	/* Validate that led_cfg is not a NULL pointer */
	if(NULL != mySS){
		/* Check seven segment type */
		if(SS_Common_Anode == mySS->Active_Mode){
			SS_ON_mode = GPIO_PIN_RESET;
			SS_OFF_mode = GPIO_PIN_SET;
		}
		else if(SS_Common_Cathode == mySS->Active_Mode){
			SS_ON_mode = GPIO_PIN_SET;
			SS_OFF_mode = GPIO_PIN_RESET;
		}
		else{
			/* Default is common cathode */
			SS_ON_mode = GPIO_PIN_SET;
			SS_OFF_mode = GPIO_PIN_RESET;
		}

		/* Loop on number code */
		for(index = 0; index < 8; index++){
			if((number>>index)&0x01){
				MCAL_GPIO_WritePin(mySS->PINS[index].PORT, mySS->PINS[index].PIN.GPIO_PinNumber, SS_ON_mode);
			}
			else{
				MCAL_GPIO_WritePin(mySS->PINS[index].PORT, mySS->PINS[index].PIN.GPIO_PinNumber, SS_OFF_mode);
			}
		}
	}
	else{ /* Do Nothing */ }
}
