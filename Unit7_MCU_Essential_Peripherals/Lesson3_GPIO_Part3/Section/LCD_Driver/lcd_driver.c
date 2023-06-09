/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : lcd_driver.c 			                             */
/* Date          : Jun 9, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "lcd_driver.h"

static void LCD_GPIO_Init(){
	GPIO_PinConfig_t PIN_CFG;
	PIN_CFG.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PIN_CFG.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;

	PIN_CFG.GPIO_PinNumber = RS_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = RW_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = EN_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);

#if LCD_MODE == LCD_8BIT_MODE
	PIN_CFG.GPIO_PinNumber = D0_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = D1_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = D2_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = D3_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);
#endif

	PIN_CFG.GPIO_PinNumber = D4_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = D5_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = D6_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = D7_PIN;
	MCAL_GPIO_Init(LCD_PORT, &PIN_CFG);
}

static void delay(uint32 time) {
	uint32 i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}

/**=============================================
  * @Fn				- LCD_Init
  * @brief 			- Initialized LCD based on user defined configurations
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- User must set configurations @ref LCD_CONFIG_define
  */
void LCD_Init(){
	// Initialize GPIO Pins
	LCD_GPIO_Init();
	delay(5);
#if LCD_MODE == LCD_8BIT_MODE
	// Send Function Set
	LCD_Send_Command(LCD_8BIT_MODE_2_LINE);
	delay(1);

	// Set Display Settings
	LCD_Send_Command(DISPLAY_MODE);
	delay(1);

	// Send clear display command
	LCD_Send_Command(LCD_CLEAR_DISPLAY);
	delay(1);

	// Set Entry Mode Settings
	LCD_Send_Command(ENTRY_MODE);

#elif LCD_MODE == LCD_4BIT_MODE
	// Send Function Set
	MCAL_GPIO_WritePin(LCD_PORT, D4_PIN, (LCD_4BIT_MODE_2_LINE&0x10));
	MCAL_GPIO_WritePin(LCD_PORT, D5_PIN, (LCD_4BIT_MODE_2_LINE&0x20));
	MCAL_GPIO_WritePin(LCD_PORT, D6_PIN, (LCD_4BIT_MODE_2_LINE&0x40));
	MCAL_GPIO_WritePin(LCD_PORT, D7_PIN, (LCD_4BIT_MODE_2_LINE&0x80));
	LCD_Send_Enable_Signal();
	delay(3);
	LCD_Send_Command(LCD_4BIT_MODE_2_LINE);
	delay(3);

	// Set Display Settings
	LCD_Send_Command(DISPLAY_MODE);
	delay(3);

	// Send clear display command
	LCD_Send_Command(LCD_CLEAR_DISPLAY);
	delay(3);

	// Set Entry Mode Settings
	LCD_Send_Command(ENTRY_MODE);
#endif
}

/**=============================================
  * @Fn				- LCD_Send_Command
  * @brief 			- Sends a command to the LCD to be executed
  * @param [in] 	- command: command to be executed @ref LCD_COMMANDS_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Command(uint8 command){
	MCAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RW_PIN, GPIO_PIN_RESET);
	delay(1);
#if LCD_MODE == LCD_8BIT_MODE
	MCAL_GPIO_WritePin(LCD_PORT, D0_PIN, (command&0x01));
	MCAL_GPIO_WritePin(LCD_PORT, D1_PIN, (command&0x02));
	MCAL_GPIO_WritePin(LCD_PORT, D2_PIN, (command&0x04));
	MCAL_GPIO_WritePin(LCD_PORT, D3_PIN, (command&0x08));
	MCAL_GPIO_WritePin(LCD_PORT, D4_PIN, (command&0x10));
	MCAL_GPIO_WritePin(LCD_PORT, D5_PIN, (command&0x20));
	MCAL_GPIO_WritePin(LCD_PORT, D6_PIN, (command&0x40));
	MCAL_GPIO_WritePin(LCD_PORT, D7_PIN, (command&0x80));
#elif LCD_MODE == LCD_4BIT_MODE
	MCAL_GPIO_WritePin(LCD_PORT, D4_PIN, (command&0x10));
	MCAL_GPIO_WritePin(LCD_PORT, D5_PIN, (command&0x20));
	MCAL_GPIO_WritePin(LCD_PORT, D6_PIN, (command&0x40));
	MCAL_GPIO_WritePin(LCD_PORT, D7_PIN, (command&0x80));
	LCD_Send_Enable_Signal();
	delay(1);
	MCAL_GPIO_WritePin(LCD_PORT, D4_PIN, (command&0x01));
	MCAL_GPIO_WritePin(LCD_PORT, D5_PIN, (command&0x02));
	MCAL_GPIO_WritePin(LCD_PORT, D6_PIN, (command&0x04));
	MCAL_GPIO_WritePin(LCD_PORT, D7_PIN, (command&0x08));
#endif
	LCD_Send_Enable_Signal();
	delay(1);
}

/**=============================================
  * @Fn				- LCD_Send_Char
  * @brief 			- Sends a char to the LCD to be displayed
  * @param [in] 	- Char: ASCII character to be displayed on screen
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Char(uint8 Char){
	MCAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_PORT, RW_PIN, GPIO_PIN_RESET);
	delay(1);
#if LCD_MODE == LCD_8BIT_MODE
	MCAL_GPIO_WritePin(LCD_PORT, D0_PIN, (Char&0x01));
	MCAL_GPIO_WritePin(LCD_PORT, D1_PIN, (Char&0x02));
	MCAL_GPIO_WritePin(LCD_PORT, D2_PIN, (Char&0x04));
	MCAL_GPIO_WritePin(LCD_PORT, D3_PIN, (Char&0x08));
	MCAL_GPIO_WritePin(LCD_PORT, D4_PIN, (Char&0x10));
	MCAL_GPIO_WritePin(LCD_PORT, D5_PIN, (Char&0x20));
	MCAL_GPIO_WritePin(LCD_PORT, D6_PIN, (Char&0x40));
	MCAL_GPIO_WritePin(LCD_PORT, D7_PIN, (Char&0x80));
#elif LCD_MODE == LCD_4BIT_MODE
	MCAL_GPIO_WritePin(LCD_PORT, D4_PIN, (Char&0x10));
	MCAL_GPIO_WritePin(LCD_PORT, D5_PIN, (Char&0x20));
	MCAL_GPIO_WritePin(LCD_PORT, D6_PIN, (Char&0x40));
	MCAL_GPIO_WritePin(LCD_PORT, D7_PIN, (Char&0x80));
	LCD_Send_Enable_Signal();
	delay(1);
	MCAL_GPIO_WritePin(LCD_PORT, D4_PIN, (Char&0x01));
	MCAL_GPIO_WritePin(LCD_PORT, D5_PIN, (Char&0x02));
	MCAL_GPIO_WritePin(LCD_PORT, D6_PIN, (Char&0x04));
	MCAL_GPIO_WritePin(LCD_PORT, D7_PIN, (Char&0x08));
#endif
	LCD_Send_Enable_Signal();
	delay(1);
}

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
void LCD_Send_Char_Pos(uint8 Char, uint8 row, uint8 column){
	LCD_Set_Cursor(row, column);
	LCD_Send_Char(Char);
}

/**=============================================
  * @Fn				- LCD_Send_String
  * @brief 			- Sends a string to the LCD to be displayed
  * @param [in] 	- string: pointer to a string of characters to be displayed on LCD
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_String(uint8 *string){
	int count = 0;
	for(; string[count] != '\0'; count++){
		LCD_Send_Char(string[count]);
	}
}

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
void LCD_Send_string_Pos(uint8 *string, uint8 row, uint8 column){
	LCD_Set_Cursor(row, column);
	LCD_Send_String(string);
}

/**=============================================
  * @Fn				- LCD_Send_Enable_Signal
  * @brief 			- Sends enable signal to the LCD
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Enable_Signal(){
	MCAL_GPIO_WritePin(LCD_PORT, EN_PIN, GPIO_PIN_SET);
	delay(2);
	MCAL_GPIO_WritePin(LCD_PORT, EN_PIN, GPIO_PIN_RESET);
}

/**=============================================
  * @Fn				- LCD_Set_Cursor
  * @brief 			- Sets the location of the cursor
  * @param [in] 	- row: Selects the row number of the displayed character @ref LCD_ROWS_POS_define
  * @param [in] 	- column: Selects the column number of the displayed character (1...16)
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void LCD_Set_Cursor(uint8 row, uint8 column){
	column--;
	LCD_Send_Command(row + column);
}
