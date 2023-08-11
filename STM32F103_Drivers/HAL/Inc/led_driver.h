/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : led_driver.h 			                             */
/* Date          : Jun 18, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_LED_DRIVER_H_
#define INC_LED_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "gpio_driver.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------

typedef enum{
	LED_Active_High,
	LED_Active_Low,
	LED_Mode_max
}LED_Mode_t;

typedef struct{
	GPIO_TypeDef *LED_Port;
	GPIO_PinConfig_t LED_Pin;
	LED_Mode_t LED_Mode;
}LED_cfg_t;


/*
 * =============================================
 * APIs Supported by "LED"
 * =============================================
 */

/**=============================================
  * @Fn				- LED_Init
  * @brief 			- This function shall initialize the LED by setting the GPIO pin to the configuration provided in led_cfg
  * @param [in] 	- led_cfg: Pointer to the struct holding the LED configuration
  * @param [out] 	- 
  * @retval 		- 
  * Note			- LED is initially off
  */
void LED_Init(const LED_cfg_t *led_cfg);

/**=============================================
  * @Fn				- LED_TurnOn
  * @brief 			- This function shall turn on the LED
  * @param [in] 	- led_cfg: Pointer to the struct holding the LED configuration
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
void LED_TurnOn(const LED_cfg_t *led_cfg);

/**=============================================
  * @Fn				- LED_TurnOff
  * @brief 			- This function shall turn off the LED
  * @param [in] 	- led_cfg: Pointer to the struct holding the LED configuration
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
void LED_TurnOff(const LED_cfg_t *led_cfg);

/**=============================================
  * @Fn				- LED_Toggle
  * @brief 			- This function shall toggle the status of the LED
  * @param [in] 	- led_cfg: Pointer to the struct holding the LED configuration
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
void LED_Toggle(const LED_cfg_t *led_cfg);

#endif /* INC_LED_DRIVER_H_ */
