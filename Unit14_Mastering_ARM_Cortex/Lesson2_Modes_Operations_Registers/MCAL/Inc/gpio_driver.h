/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : gpio_driver.h 			                             */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "STM32F103x8.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef struct{
	uint8 GPIO_MODE; 		 // Specifies the operating mode for the selected pins. This parameter can be a value of @ref GPIO_MODE_define
	uint8 GPIO_OUTPUT_SPEED; // Specifies the speed for the selected pins. This parameter can be a value of @ref GPIO_SPEED_define
	uint16 GPIO_PinNumber; 	 // Specifies the GPIO pins to be configured. This parameter can be a value of @ref GPIO_PINS_define
}GPIO_PinConfig_t;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

// @ref GPIO_PINS_define
#define GPIO_PIN_0	 	((uint16)0x0001)
#define GPIO_PIN_1 	 	((uint16)0x0002)
#define GPIO_PIN_2	 	((uint16)0x0004)
#define GPIO_PIN_3	 	((uint16)0x0008)
#define GPIO_PIN_4	 	((uint16)0x0010)
#define GPIO_PIN_5	 	((uint16)0x0020)
#define GPIO_PIN_6	 	((uint16)0x0040)
#define GPIO_PIN_7	 	((uint16)0x0080)
#define GPIO_PIN_8	 	((uint16)0x0100)
#define GPIO_PIN_9	 	((uint16)0x0200)
#define GPIO_PIN_10	 	((uint16)0x0400)
#define GPIO_PIN_11	 	((uint16)0x0800)
#define GPIO_PIN_12	 	((uint16)0x1000)
#define GPIO_PIN_13	 	((uint16)0x2000)
#define GPIO_PIN_14	 	((uint16)0x4000)
#define GPIO_PIN_15	 	((uint16)0x8000)
#define GPIO_PIN_ALL 	((uint16)0xFFFF)

// @ref GPIO_MODE_define
/*	0: Analog mode
	1: Floating input (reset state)
	2: Input with pull-up
	3: Input with pull-down
	4: General purpose output push-pull
	5: General purpose output Open-drain
	6: Alternate function output Push-pull
	7: Alternate function output Open-drain
	8: Alternate function input*/
#define GPIO_MODE_ANALOG		0x00000000U // Analog Mode
#define GPIO_MODE_INPUT_FLO		0x00000001U // Floating input
#define GPIO_MODE_INPUT_PU		0x00000002U // Input with pull-up
#define GPIO_MODE_INPUT_PD		0x00000003U // Input with pull-down
#define GPIO_MODE_OUTPUT_PP		0x00000004U // General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD		0x00000005U // General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP	0x00000006U // Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD	0x00000007U // Alternate function output Open-drain
#define GPIO_MODE_AF_INPUT		0x00000008U // Alternate function input

// @ref GPIO_SPEED_define
/*	1: Output mode, max speed 10 MHz.
	2: Output mode, max speed 2 MHz.
	3: Output mode, max speed 50 MHz.*/
#define GPIO_SPEED_10M		0x00000001U // Output mode, max speed 10 MHz.
#define GPIO_SPEED_2M		0x00000002U // Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M		0x00000003U // Output mode, max speed 50 MHz.

// @ref GPIO_PIN_STATE
#define GPIO_PIN_SET	1
#define GPIO_PIN_RESET	0

// @ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_OK			1
#define GPIO_RETURN_LOCK_ERROR		0

/*
 * =============================================
 * APIs Supported by "GPIO"
 * =============================================
 */

/**=============================================
  * @Fn				- MCAL_GPIO_Init
  * @brief 			- Initializes the GPIOx PINy according to the specified paramters in the PinConfig
  * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
  * @param [in] 	- PinConfig: Pointer to a GPIO_PinConfig_t structure that contains the configuration
  * 				  information for the specified GPIO PIN
  * @retval 		- None
  * Note			- STM32F103C8 MCU has GPIO A,B,C,D,E Modules, but LQFP48 package has only
  * 				  GPIO A,B and part of C/D exported as external PINS from the MCU
  * 				- It is mandatory to enable RCC clock for the corresponding GPIO PORT
  */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);

/**=============================================
  * @Fn				- MCAL_GPIO_DeInit
  * @brief 			- Resets the GPIO PORT
  * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
  * @retval 		- None
  * Note			- None
  */
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx);

/**=============================================
  * @Fn				- MCAL_GPIO_ReadPin
  * @brief 			- Reads Specific PIN
  * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
  * @param [in] 	- PinNumber: Set pin number according to @ref GPIO_PINS_define
  * @retval 		- the input pin value (two values based on @ref GPIO_PIN_STATE
  * Note			- None
  */
uint8 MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16 PinNumber);

/**=============================================
  * @Fn				- MCAL_GPIO_ReadPort
  * @brief 			- Reads Specific PORT
  * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
  * @retval 		- the input port value
  * Note			- None
  */
uint16 MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

/**=============================================
  * @Fn				- MCAL_GPIO_WritePin
  * @brief 			- Write on specific pin
  * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
  * @param [in] 	- PinNumber: Set pin number according to @ref GPIO_PINS_define
  * @param [in] 	- Value: Pin value to be written
  * @retval 		- None
  * Note			- None
  */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16 PinNumber, uint8 Value);

/**=============================================
  * @Fn				- MCAL_GPIO_WritePort
  * @brief 			- Write on specific port
  * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
  * @param [in] 	- Value: Port value to be written
  * @retval 		- None
  * Note			- None
  */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16 Value);

/**=============================================
  * @Fn				- MCAL_GPIO_TogglePin
  * @brief 			- Toggle a specific pin
  * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
  * @param [in] 	- PinNumber: Set pin number according to @ref GPIO_PINS_define
  * @retval 		- None
  * Note			- None
  */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16 PinNumber);

/**=============================================
  * @Fn				- MCAL_GPIO_LockPin
  * @brief 			- The locking mechanism allows the IO configuration to be frozen
  * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
  * @param [in] 	- PinNumber: Set pin number according to @ref GPIO_PINS_define
  * @retval 		- Ok if pin config is locked, or ERROR if pin is not locked @ref GPIO_RETURN_LOCK
  * Note			- None
  */
uint8 MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16 PinNumber);

#endif /* INC_GPIO_DRIVER_H_ */
