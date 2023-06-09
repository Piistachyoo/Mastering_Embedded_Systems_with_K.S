/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : lcd_driver.h 			                             */
/* Date          : Jun 9, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INCLCD_DRIVER_H_
#define INCLCD_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "gpio_driver.h"

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

// @ref LCD_DATA_MODE_define

#define LCD_8BIT_MODE								8
#define LCD_4BIT_MODE								4

// @ref LCD_COMMANDS_define

#define LCD_CLEAR_DISPLAY              				(0x01)
#define LCD_RETURN_HOME                				(0x02)
#define LCD_ENTRY_MODE_DEC_SHIFT_OFF   				(0x04)
#define LCD_ENTRY_MODE_DEC_SHIFT_ON    				(0x05)
#define LCD_ENTRY_MODE_INC_SHIFT_OFF   				(0x06)
#define LCD_ENTRY_MODE_INC_SHIFT_ON    				(0x07)
#define LCD_CURSOR_MOVE_SHIFT_LEFT     				(0x10)
#define LCD_CURSOR_MOVE_SHIFT_RIGHT    				(0x14)
#define LCD_DISPLAY_SHIFT_LEFT         				(0x18)
#define LCD_DISPLAY_SHIFT_RIGHT        				(0x1C)
#define LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF    	(0x0C)
#define LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON     	(0x0D)
#define LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF     	(0x0E)
#define LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON      	(0x0F)
#define LCD_DISPLAY_OFF_CURSOR_OFF                 	(0x08)
#define LCD_8BIT_MODE_2_LINE           				(0x38)
#define LCD_4BIT_MODE_2_LINE           				(0x28)

// @ref LCD_ROWS_POS_define

#define LCD_FIRST_ROW								(0x80)
#define LCD_SECOND_ROW								(0xC0)

//----------------------------------------------
// Section: User Configurations
//----------------------------------------------

#define LCD_MODE 			LCD_4BIT_MODE // @ref LCD_DATA_MODE_define


// @ref LCD_CONFIG_define

#define LCD_PORT			GPIOA
#define RS_PIN				GPIO_PIN_8  // @ref GPIO_PINS_define
#define RW_PIN				GPIO_PIN_9  // @ref GPIO_PINS_define
#define EN_PIN				GPIO_PIN_10 // @ref GPIO_PINS_define
#if LCD_MODE == LCD_8BIT_MODE
#define D0_PIN				GPIO_PIN_0  // @ref GPIO_PINS_define
#define D1_PIN				GPIO_PIN_1  // @ref GPIO_PINS_define
#define D2_PIN				GPIO_PIN_2  // @ref GPIO_PINS_define
#define D3_PIN				GPIO_PIN_3  // @ref GPIO_PINS_define
#endif
#define D4_PIN				GPIO_PIN_4  // @ref GPIO_PINS_define
#define D5_PIN				GPIO_PIN_5  // @ref GPIO_PINS_define
#define D6_PIN				GPIO_PIN_6  // @ref GPIO_PINS_define
#define D7_PIN				GPIO_PIN_7  // @ref GPIO_PINS_define

#define DISPLAY_MODE		LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF
#define ENTRY_MODE			LCD_ENTRY_MODE_INC_SHIFT_OFF


/*
 * =============================================
 * APIs Supported by "LCD"
 * =============================================
 */

/**=============================================
  * @Fn				- LCD_Init
  * @brief 			- Initialized LCD based on user defined configurations
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- User must set configurations @ref LCD_CONFIG_define
  */
void LCD_Init();

/**=============================================
  * @Fn				- LCD_Send_Command
  * @brief 			- Sends a command to the LCD to be executed
  * @param [in] 	- command: command to be executed @ref LCD_COMMANDS_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Command(uint8 command);

/**=============================================
  * @Fn				- LCD_Send_Char
  * @brief 			- Sends a char to the LCD to be displayed
  * @param [in] 	- Char: ASCII character to be displayed on screen
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Char(uint8 Char);

/**=============================================
  * @Fn				- LCD_Send_Char_Pos
  * @brief 			- Sends a char to the LCD to be displayed at a specific location
  * @param [in] 	- Char: ASCII character to be displayed on screen
  * @param [in] 	- row: Selects the row number of the displayed character @ref LCD_ROWS_POS_define
  * @param [in] 	- column: Selects the column number of the displayed character (1...16)
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Char_Pos(uint8 Char, uint8 row, uint8 column);

/**=============================================
  * @Fn				- LCD_Send_String
  * @brief 			- Sends a string to the LCD to be displayed
  * @param [in] 	- string: pointer to a string of characters to be displayed on LCD
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_String(uint8 *string);

/**=============================================
  * @Fn				- LCD_Send_string_Pos
  * @brief 			- Sends a string to the LCD to be displayed at a specific location
  * @param [in] 	- string: pointer to a string of characters to be displayed on LCD
  * @param [in] 	- row: Selects the row number of the displayed character @ref LCD_ROWS_POS_define
  * @param [in] 	- column: Selects the column number of the displayed character (1...16)
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_string_Pos(uint8 *string, uint8 row, uint8 column);

/**=============================================
  * @Fn				- LCD_Send_Enable_Signal
  * @brief 			- Sends enable signal to the LCD
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Enable_Signal();

/**=============================================
  * @Fn				- LCD_Set_Cursor
  * @brief 			- Sets the location of the cursor
  * @param [in] 	- row: Selects the row number of the displayed character @ref LCD_ROWS_POS_define
  * @param [in] 	- column: Selects the column number of the displayed character (1...16)
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Set_Cursor(uint8 row, uint8 column);


#endif /* INCLCD_DRIVER_H_ */
