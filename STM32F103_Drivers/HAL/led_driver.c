/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : led_driver.c 			                             */
/* Date          : Jun 18, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "led_driver.h"

/**=============================================
  * @Fn				- LED_Init
  * @brief 			- This function shall initialize the LED by setting the GPIO pin to the configuration provided in led_cfg
  * @param [in] 	- led_cfg: Pointer to the struct holding the LED configuration
  * @param [out] 	- None
  * @retval 		- None
  * Note			- LED is initially off
  */
void LED_Init(const LED_cfg_t *led_cfg){
	/* Validate that led_cfg is not a NULL pointer */
	if(NULL != led_cfg){
		MCAL_GPIO_Init(led_cfg->LED_Port, (GPIO_PinConfig_t*)&(led_cfg->LED_Pin));
		/* Set LED initial state */
		if(led_cfg->LED_Mode == LED_Active_High){
			MCAL_GPIO_WritePin(led_cfg->LED_Port, led_cfg->LED_Pin.GPIO_PinNumber, GPIO_PIN_RESET);
		}
		else if(led_cfg->LED_Mode == LED_Active_Low){
			MCAL_GPIO_WritePin(led_cfg->LED_Port, led_cfg->LED_Pin.GPIO_PinNumber, GPIO_PIN_SET);
		}
		else{ /* Do Nothing */ }
	}
	else{ /* Do Nothing */ }
}

/**=============================================
  * @Fn				- LED_TurnOn
  * @brief 			- This function shall turn on the LED
  * @param [in] 	- led_cfg: Pointer to the struct holding the LED configuration
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
void LED_TurnOn(const LED_cfg_t *led_cfg){
	/* Validate that led_cfg is not a NULL pointer */
	if(NULL != led_cfg){
		if(led_cfg->LED_Mode == LED_Active_High){
			MCAL_GPIO_WritePin(led_cfg->LED_Port, led_cfg->LED_Pin.GPIO_PinNumber, GPIO_PIN_SET);
		}
		else if(led_cfg->LED_Mode == LED_Active_Low){
			MCAL_GPIO_WritePin(led_cfg->LED_Port, led_cfg->LED_Pin.GPIO_PinNumber, GPIO_PIN_RESET);
		}
		else{ /* Do Nothing */ }
	}
	else{ /* Do Nothing */ }
}

/**=============================================
  * @Fn				- LED_TurnOff
  * @brief 			- This function shall turn off the LED
  * @param [in] 	- led_cfg: Pointer to the struct holding the LED configuration
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LED_TurnOff(const LED_cfg_t *led_cfg){
	/* Validate that led_cfg is not a NULL pointer */
	if(NULL != led_cfg){
		if(led_cfg->LED_Mode == LED_Active_High){
			MCAL_GPIO_WritePin(led_cfg->LED_Port, led_cfg->LED_Pin.GPIO_PinNumber, GPIO_PIN_RESET);
		}
		else if(led_cfg->LED_Mode == LED_Active_Low){
			MCAL_GPIO_WritePin(led_cfg->LED_Port, led_cfg->LED_Pin.GPIO_PinNumber, GPIO_PIN_SET);
		}
		else{ /* Do Nothing */ }
	}
	else{ /* Do Nothing */ }
}

/**=============================================
  * @Fn				- LED_Toggle
  * @brief 			- This function shall toggle the status of the LED
  * @param [in] 	- led_cfg: Pointer to the struct holding the LED configuration
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LED_Toggle(const LED_cfg_t *led_cfg){
	/* Validate that led_cfg is not a NULL pointer */
	if(NULL != led_cfg){
		MCAL_GPIO_TogglePin(led_cfg->LED_Port, led_cfg->LED_Pin.GPIO_PinNumber);
	}
	else{ /* Do Nothing */ }
}
