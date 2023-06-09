/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : main.c                           				 	 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "STM32F103x8.h"
#include "gpio_driver.h"
#include "lcd_driver.h"
#include "keypad_driver.h"

void clock_init();
void gpio_init();

void my_wait(int x){
	uint8 i, j;
	for(i = 0; i < x; i++){
		for(j = 0; j < 255; j++);
	}
}

int main(void)
{
	clock_init();
	LCD_Init();
	keypad_init();
	uint8 temp;
	LCD_Send_string_Pos((char*)"Learn In Depth", LCD_FIRST_ROW, 2);
	LCD_Send_string_Pos((char*)"Keypad: ", LCD_SECOND_ROW, 1);
	while(1){
		temp = keypad_Get_Pressed_Key();
		if('F' != temp){
			if('C' == temp){
				LCD_Send_string_Pos("          ", LCD_SECOND_ROW, 9);
				LCD_Set_Cursor(LCD_SECOND_ROW, 9);
			}
			else{
				LCD_Send_Char(temp);
			}
		}
	}
}

void clock_init(){
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

void gpio_init(){

	GPIO_PinConfig_t PINA1 = {.GPIO_PinNumber = GPIO_PIN_1,
							  .GPIO_MODE = GPIO_MODE_INPUT_PU};

	GPIO_PinConfig_t PINA2 = {.GPIO_PinNumber = GPIO_PIN_2,
							   .GPIO_MODE = GPIO_MODE_INPUT_PD};

	GPIO_PinConfig_t PINB0 = {.GPIO_PinNumber = GPIO_PIN_0,
							  .GPIO_MODE = GPIO_MODE_OUTPUT_PP,
							  .GPIO_OUTPUT_SPEED = GPIO_SPEED_2M };

	GPIO_PinConfig_t PINB1 = {.GPIO_PinNumber = GPIO_PIN_1,
							   .GPIO_MODE = GPIO_MODE_OUTPUT_PP,
							   .GPIO_OUTPUT_SPEED = GPIO_SPEED_2M };


	MCAL_GPIO_Init(GPIOA, &PINA1);
	MCAL_GPIO_Init(GPIOA, &PINA2);
	MCAL_GPIO_Init(GPIOB, &PINB0);
	MCAL_GPIO_Init(GPIOB, &PINB1);

}
