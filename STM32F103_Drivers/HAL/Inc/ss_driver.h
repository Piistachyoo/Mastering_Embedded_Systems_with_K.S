/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : ss_driver.h 			                            	 */
/* Date          : Jun 18, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_SS_DRIVER_H_
#define INC_SS_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "gpio_driver.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef enum{
	SS_Common_Anode,
	SS_Common_Cathode,
	SS_Active_Mode_max
}SS_Active_Mode_t;

typedef struct{
	GPIO_TypeDef *PORT;
	GPIO_PinConfig_t PIN;
}SS_PIN_t;

typedef struct{
	SS_PIN_t PINS[8];
	SS_Active_Mode_t Active_Mode;
}SS_cfg_t;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

// @ref SS_Dot_Status_define
#define SS_DOT_ON	0x80U
#define SS_DOT_OFF	0x00U

// @ref SS_Numbers_define
/* hexadecimal representation for common cathode seven segment */
#define SS_ZERO		0x3FU
#define SS_ONE		0x06U
#define SS_TWO		0x5BU
#define SS_THREE	0x4FU
#define SS_FOUR		0x66U
#define SS_FIVE		0x6DU
#define SS_SIX		0x7DU
#define SS_SEVEN	0x07U
#define SS_EIGHT	0x7FU
#define SS_NINE		0x6FU

/*
 * =============================================
 * APIs Supported by "Seven Segment"
 * =============================================
 */

/**=============================================
  * @Fn				- SS_Init
  * @brief 			- Initializes the seven segment's GPIO pins
  * @param [in] 	- mySS: Pointer to the struct holding the seven segment configuration
  * @param [out] 	- None
  * @retval 		- None
  * Note			- Seven segment initially shows no number
  */
void SS_Init(const SS_cfg_t *mySS);

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
void SS_Display_Number(const SS_cfg_t *mySS, uint8 number, uint8 dot_status);

#endif /* INC_SS_DRIVER_H_ */
