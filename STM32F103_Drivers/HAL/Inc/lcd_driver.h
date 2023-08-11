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
#include "systick_driver.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef enum{
	LCD_8BIT,
	LCD_4BIT
}LCD_MODE_t;

typedef enum{
	LCD_2ROWS,
	LCD_4ROWS
}LCD_ROWS_t;

typedef struct{
	LCD_MODE_t		Mode;
	LCD_ROWS_t		Rows;
	uint8			Display_Mode; // @ref LCD_COMMANDS_define
	uint8			Entry_Mode;   // @ref LCD_COMMANDS_define
	GPIO_TypeDef*	GPIO_PORT;
	uint16 			RS_PIN; // @ref GPIO_PINS_define
	uint16 			EN_PIN; // @ref GPIO_PINS_define
	uint16 			D0_PIN; // @ref GPIO_PINS_define
	uint16 			D1_PIN; // @ref GPIO_PINS_define
	uint16 			D2_PIN; // @ref GPIO_PINS_define
	uint16 			D3_PIN; // @ref GPIO_PINS_define
	uint16 			D4_PIN; // @ref GPIO_PINS_define
	uint16 			D5_PIN; // @ref GPIO_PINS_define
	uint16 			D6_PIN; // @ref GPIO_PINS_define
	uint16 			D7_PIN; // @ref GPIO_PINS_define
}LCD_t;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

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
#define LCD_THIRD_ROW								(0x94)
#define LCD_FOURTH_ROW								(0xD4)


/*
 * =============================================
 * APIs Supported by "LCD"
 * =============================================
 */

/**=============================================
  * @Fn				- LCD_Init
  * @brief 			- Initialized LCD based on user defined configurations
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @retval 		- None
  * Note			- User must set configurations @ref LCD_CONFIG_define
  */
void LCD_Init(LCD_t* LCD_cfg);

/**=============================================
  * @Fn				- LCD_Send_Command
  * @brief 			- Sends a command to the LCD to be executed
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @param [in] 	- command: command to be executed @ref LCD_COMMANDS_define
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Command(LCD_t* LCD_cfg, uint8 command);

/**=============================================
  * @Fn				- LCD_Send_Char
  * @brief 			- Sends a char to the LCD to be displayed
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @param [in] 	- Char: ASCII character to be displayed on screen
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Char(LCD_t* LCD_cfg, uint8 Char);

/**=============================================
  * @Fn				- LCD_Send_Char_Pos
  * @brief 			- Sends a char to the LCD to be displayed at a specific location
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @param [in] 	- Char: ASCII character to be displayed on screen
  * @param [in] 	- row: Selects the row number of the displayed character @ref LCD_ROWS_POS_define
  * @param [in] 	- column: Selects the column number of the displayed character (1...16)
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Char_Pos(LCD_t* LCD_cfg, uint8 Char, uint8 row, uint8 column);

/**=============================================
  * @Fn				- LCD_Send_String
  * @brief 			- Sends a string to the LCD to be displayed
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @param [in] 	- string: pointer to a string of characters to be displayed on LCD
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_String(LCD_t* LCD_cfg, uint8 *string);

/**=============================================
  * @Fn				- LCD_Send_string_Pos
  * @brief 			- Sends a string to the LCD to be displayed at a specific location
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @param [in] 	- string: pointer to a string of characters to be displayed on LCD
  * @param [in] 	- row: Selects the row number of the displayed character @ref LCD_ROWS_POS_define
  * @param [in] 	- column: Selects the column number of the displayed character (1...16)
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_string_Pos(LCD_t* LCD_cfg, uint8 *string, uint8 row, uint8 column);

/**=============================================
  * @Fn				- LCD_Send_Enable_Signal
  * @brief 			- Sends enable signal to the LCD
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Enable_Signal(LCD_t* LCD_cfg);

/**=============================================
  * @Fn				- LCD_Set_Cursor
  * @brief 			- Sets the location of the cursor
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @param [in] 	- row: Selects the row number of the displayed character @ref LCD_ROWS_POS_define
  * @param [in] 	- column: Selects the column number of the displayed character (1...16)
  * @retval 		- None
  * Note			- None
  */
void LCD_Set_Cursor(LCD_t* LCD_cfg, uint8 row, uint8 column);


#endif /* INCLCD_DRIVER_H_ */
