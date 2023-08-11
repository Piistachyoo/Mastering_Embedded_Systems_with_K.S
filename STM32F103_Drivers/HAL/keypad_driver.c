/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : keypad_driver.c 			                             */
/* Date          : Jun 9, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "keypad_driver.h"

/* Keypad buttons definition */
static uint8 Keypad_Buttons [KEYPAD_ROWS][KEYPAD_COLS] = {
		{ 7 ,  8 ,  9 , '/'},
		{ 4 ,  5 ,  6 , 'x'},
		{ 1 ,  2 ,  3 , '-'},
		{'C',  0 , '=', '+'}
};

static uint16 Keypad_ROWS_GPIO [KEYPAD_ROWS] = {ROW0, ROW1, ROW2, ROW3};
static uint16 Keypad_COLS_GPIO [KEYPAD_COLS] = {COL0, COL1, COL2, COL3};

/**=============================================
  * @Fn				- keypad_init
  * @brief 			- Initializes the keypad
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- User must define GPIO pins for rows and columns in @ref Keypad_PINS_define
  */
void keypad_init(){
	GPIO_PinConfig_t Pin_Cfg;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;

	Pin_Cfg.GPIO_PinNumber = ROW0;
	MCAL_GPIO_Init(KEYPAD_PORT, &Pin_Cfg);
	MCAL_GPIO_WritePin(KEYPAD_PORT, ROW0, GPIO_PIN_SET);

	Pin_Cfg.GPIO_PinNumber = ROW1;
	MCAL_GPIO_Init(KEYPAD_PORT, &Pin_Cfg);
	MCAL_GPIO_WritePin(KEYPAD_PORT, ROW1, GPIO_PIN_SET);

	Pin_Cfg.GPIO_PinNumber = ROW2;
	MCAL_GPIO_Init(KEYPAD_PORT, &Pin_Cfg);
	MCAL_GPIO_WritePin(KEYPAD_PORT, ROW2, GPIO_PIN_SET);

	Pin_Cfg.GPIO_PinNumber = ROW3;
	MCAL_GPIO_Init(KEYPAD_PORT, &Pin_Cfg);
	MCAL_GPIO_WritePin(KEYPAD_PORT, ROW3, GPIO_PIN_SET);

	Pin_Cfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	Pin_Cfg.GPIO_PinNumber = COL0;
	MCAL_GPIO_Init(KEYPAD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = COL1;
	MCAL_GPIO_Init(KEYPAD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = COL2;
	MCAL_GPIO_Init(KEYPAD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = COL3;
	MCAL_GPIO_Init(KEYPAD_PORT, &Pin_Cfg);
}

/**=============================================
  * @Fn				- keypad_Get_Pressed_Key
  * @brief 			- Checks for any pressed key and returns the value of it
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Value of the pressed key, or F if no key is pressed
  * Note			- None
  */
uint8 keypad_Get_Pressed_Key(){
	uint8 return_char = 'F';
	uint8 row_index, col_index;
	for(row_index = 0; row_index < KEYPAD_ROWS; row_index++){
		MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_ROWS_GPIO[row_index], GPIO_PIN_RESET);
		for(col_index = 0; col_index < KEYPAD_COLS; col_index++){
			if(MCAL_GPIO_ReadPin(KEYPAD_PORT, Keypad_COLS_GPIO[col_index]) == GPIO_PIN_RESET){
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, Keypad_COLS_GPIO[col_index]) == GPIO_PIN_RESET);
				return_char = Keypad_Buttons[row_index][col_index];
				MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_ROWS_GPIO[row_index], GPIO_PIN_SET);
				return return_char;
			}
		}
		MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_ROWS_GPIO[row_index], GPIO_PIN_SET);
	}
	return return_char;
}
