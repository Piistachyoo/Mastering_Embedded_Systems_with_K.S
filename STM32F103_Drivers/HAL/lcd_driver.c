/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : lcd_driver.c 			                             */
/* Date          : Jun 9, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "lcd_driver.h"

static void LCD_GPIO_Init(LCD_t* LCD_cfg){
	GPIO_PinConfig_t PIN_CFG;
	PIN_CFG.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PIN_CFG.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;

	PIN_CFG.GPIO_PinNumber = LCD_cfg->RS_PIN;
	MCAL_GPIO_Init(LCD_cfg->GPIO_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = LCD_cfg->EN_PIN;
	MCAL_GPIO_Init(LCD_cfg->GPIO_PORT, &PIN_CFG);

	if(LCD_8BIT == LCD_cfg->Mode){
		PIN_CFG.GPIO_PinNumber = LCD_cfg->D0_PIN;
		MCAL_GPIO_Init(LCD_cfg->GPIO_PORT, &PIN_CFG);

		PIN_CFG.GPIO_PinNumber = LCD_cfg->D1_PIN;
		MCAL_GPIO_Init(LCD_cfg->GPIO_PORT, &PIN_CFG);

		PIN_CFG.GPIO_PinNumber = LCD_cfg->D2_PIN;
		MCAL_GPIO_Init(LCD_cfg->GPIO_PORT, &PIN_CFG);

		PIN_CFG.GPIO_PinNumber = LCD_cfg->D3_PIN;
		MCAL_GPIO_Init(LCD_cfg->GPIO_PORT, &PIN_CFG);
	}
	else{ /* Do Nothing */ }

	PIN_CFG.GPIO_PinNumber = LCD_cfg->D4_PIN;
	MCAL_GPIO_Init(LCD_cfg->GPIO_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = LCD_cfg->D5_PIN;
	MCAL_GPIO_Init(LCD_cfg->GPIO_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = LCD_cfg->D6_PIN;
	MCAL_GPIO_Init(LCD_cfg->GPIO_PORT, &PIN_CFG);

	PIN_CFG.GPIO_PinNumber = LCD_cfg->D7_PIN;
	MCAL_GPIO_Init(LCD_cfg->GPIO_PORT, &PIN_CFG);
}

/**=============================================
  * @Fn				- LCD_Init
  * @brief 			- Initialized LCD based on user defined configurations
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @retval 		- None
  * Note			- User must set configurations @ref LCD_CONFIG_define
  */
void LCD_Init(LCD_t* LCD_cfg){
	// Initialize GPIO Pins
	LCD_GPIO_Init(LCD_cfg);
	MCAL_STK_Delay1ms(2);
	if(LCD_8BIT == LCD_cfg->Mode){
		// Send Function Set
		LCD_Send_Command(LCD_cfg, LCD_8BIT_MODE_2_LINE);
		MCAL_STK_Delay1ms(1);

	}
	else if(LCD_4BIT == LCD_cfg->Mode){
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->RS_PIN, GPIO_PIN_RESET);
		MCAL_STK_Delay1ms(1);

		// Send Function Set
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D4_PIN, (LCD_4BIT_MODE_2_LINE&0x10));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D5_PIN, (LCD_4BIT_MODE_2_LINE&0x20));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D6_PIN, (LCD_4BIT_MODE_2_LINE&0x40));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D7_PIN, (LCD_4BIT_MODE_2_LINE&0x80));
		MCAL_STK_Delay1ms(1);
		LCD_Send_Enable_Signal(LCD_cfg);

		LCD_Send_Command(LCD_cfg, LCD_4BIT_MODE_2_LINE);
		MCAL_STK_Delay1ms(1);


	}
	else{ /* Do Nothing */ }

	// Set Display Settings
	LCD_Send_Command(LCD_cfg, LCD_cfg->Display_Mode);
	MCAL_STK_Delay1ms(1);

	// Send clear display command
	LCD_Send_Command(LCD_cfg, LCD_CLEAR_DISPLAY);
	MCAL_STK_Delay1ms(2);

	// Set Entry Mode Settings
	LCD_Send_Command(LCD_cfg, LCD_cfg->Entry_Mode);
	MCAL_STK_Delay1ms(1);
}

/**=============================================
  * @Fn				- LCD_Send_Command
  * @brief 			- Sends a command to the LCD to be executed
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @param [in] 	- command: command to be executed @ref LCD_COMMANDS_define
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Command(LCD_t* LCD_cfg, uint8 command){
	MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->RS_PIN, GPIO_PIN_RESET);
	MCAL_STK_Delay1ms(1);
	if(LCD_8BIT == LCD_cfg->Mode){
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D0_PIN, (command&0x01));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D1_PIN, (command&0x02));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D2_PIN, (command&0x04));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D3_PIN, (command&0x08));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D4_PIN, (command&0x10));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D5_PIN, (command&0x20));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D6_PIN, (command&0x40));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D7_PIN, (command&0x80));
	}
	else if(LCD_4BIT == LCD_cfg->Mode){
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D4_PIN, (command&0x10));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D5_PIN, (command&0x20));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D6_PIN, (command&0x40));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D7_PIN, (command&0x80));
		LCD_Send_Enable_Signal(LCD_cfg);
		MCAL_STK_Delay1ms(1);
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D4_PIN, (command&0x01));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D5_PIN, (command&0x02));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D6_PIN, (command&0x04));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D7_PIN, (command&0x08));
	}
	else{ /* Do Nothing */ }

	MCAL_STK_Delay1ms(1);
	LCD_Send_Enable_Signal(LCD_cfg);
}

/**=============================================
  * @Fn				- LCD_Send_Char
  * @brief 			- Sends a char to the LCD to be displayed
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @param [in] 	- Char: ASCII character to be displayed on screen
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Char(LCD_t* LCD_cfg, uint8 Char){
	MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->RS_PIN, GPIO_PIN_SET);
	MCAL_STK_Delay1ms(1);
	if(LCD_8BIT == LCD_cfg->Mode){
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D0_PIN, (Char&0x01));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D1_PIN, (Char&0x02));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D2_PIN, (Char&0x04));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D3_PIN, (Char&0x08));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D4_PIN, (Char&0x10));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D5_PIN, (Char&0x20));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D6_PIN, (Char&0x40));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D7_PIN, (Char&0x80));
	}
	else if(LCD_4BIT == LCD_cfg->Mode){
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D4_PIN, (Char&0x10));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D5_PIN, (Char&0x20));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D6_PIN, (Char&0x40));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D7_PIN, (Char&0x80));
		MCAL_STK_Delay1ms(1);
		LCD_Send_Enable_Signal(LCD_cfg);
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D4_PIN, (Char&0x01));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D5_PIN, (Char&0x02));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D6_PIN, (Char&0x04));
		MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->D7_PIN, (Char&0x08));
	}
	else{ /* Do Nothing */ }

	MCAL_STK_Delay1ms(1);
	LCD_Send_Enable_Signal(LCD_cfg);
}

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
void LCD_Send_Char_Pos(LCD_t* LCD_cfg, uint8 Char, uint8 row, uint8 column){
	LCD_Set_Cursor(LCD_cfg, row, column);
	LCD_Send_Char(LCD_cfg, Char);
}

/**=============================================
  * @Fn				- LCD_Send_String
  * @brief 			- Sends a string to the LCD to be displayed
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @param [in] 	- string: pointer to a string of characters to be displayed on LCD
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_String(LCD_t* LCD_cfg, uint8 *string){
	int count = 0;
	for(; string[count] != '\0'; count++){
		LCD_Send_Char(LCD_cfg, string[count]);
	}
}

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
void LCD_Send_string_Pos(LCD_t* LCD_cfg, uint8 *string, uint8 row, uint8 column){
	LCD_Set_Cursor(LCD_cfg, row, column);
	LCD_Send_String(LCD_cfg, string);
}

/**=============================================
  * @Fn				- LCD_Send_Enable_Signal
  * @brief 			- Sends enable signal to the LCD
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @retval 		- None
  * Note			- None
  */
void LCD_Send_Enable_Signal(LCD_t* LCD_cfg){
	MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->EN_PIN, GPIO_PIN_SET);
	MCAL_STK_Delay1ms(1);
	MCAL_GPIO_WritePin(LCD_cfg->GPIO_PORT, LCD_cfg->EN_PIN, GPIO_PIN_RESET);
	MCAL_STK_Delay1ms(1);
}

/**=============================================
  * @Fn				- LCD_Set_Cursor
  * @brief 			- Sets the location of the cursor
  * @param [in] 	- LCD_cfg: Pointer to the structure containing LCD configuration
  * @param [in] 	- row: Selects the row number of the displayed character @ref LCD_ROWS_POS_define
  * @param [in] 	- column: Selects the column number of the displayed character (1...16)
  * @retval 		- None
  * Note			- None
  */
void LCD_Set_Cursor(LCD_t* LCD_cfg, uint8 row, uint8 column){
	column--;
	LCD_Send_Command(LCD_cfg, row + column);
}
