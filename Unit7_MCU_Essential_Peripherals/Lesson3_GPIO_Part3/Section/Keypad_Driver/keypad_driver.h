/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : keypad_driver.h 			                             */
/* Date          : Jun 9, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_KEYPAD_DRIVER_H_
#define INC_KEYPAD_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "gpio_driver.h"

//----------------------------------------------
// Section: User Configurations
//----------------------------------------------


//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------
// @ref Keypad_PINS_define
#define KEYPAD_PORT	GPIOB
#define KEYPAD_ROWS	4
#define ROW0		GPIO_PIN_0
#define ROW1		GPIO_PIN_1
#define ROW2		GPIO_PIN_12
#define ROW3		GPIO_PIN_13
#define KEYPAD_COLS	4
#define COL0		GPIO_PIN_5
#define COL1		GPIO_PIN_6
#define COL2		GPIO_PIN_7
#define COL3		GPIO_PIN_8

/*
 * =============================================
 * APIs Supported by "Driver Name"
 * =============================================
 */

/**=============================================
  * @Fn				- keypad_init
  * @brief 			- Initializes the keypad
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- User must define GPIO pins for rows and columns in @ref Keypad_PINS_define
  */
void keypad_init();

/**=============================================
  * @Fn				- keypad_Get_Pressed_Key
  * @brief 			- Checks for any pressed key and returns the value of it
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Value of the pressed key, or F if no key is pressed
  * Note			- None
  */
uint8 keypad_Get_Pressed_Key();

#endif /* INC_KEYPAD_DRIVER_H_ */
