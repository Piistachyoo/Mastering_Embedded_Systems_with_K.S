/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : main.c                           				 	 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "gpio_driver.h"
#include "EXTI_driver.h"
#include "lcd_driver.h"

uint8 IRQ_Flag;

void clock_init();
void MyISR_EXTIB9(void);
void my_wait(int x){
	uint16 i, j;
	for(i = 0; i < x; i++){
		for(j = 0; j < 255; j++);
	}
}

int main(void)
{
	clock_init();
	LCD_Init();
	EXTI_PinConfig_t myEXTI;
	myEXTI.EXTI_PIN = EXTI9PB9;
	myEXTI.Trigger_Case = EXTI_TRIGGER_FALLING;
	myEXTI.IRQ_EN = EXTI_IRQ_ENABLE;
	myEXTI.P_IRQ_CallBack = MyISR_EXTIB9;
	MCAL_EXTI_GPIO_Init(&myEXTI);
	LCD_Send_string_Pos((uint8*)"Waiting EXTI!", LCD_FIRST_ROW, 1);
	while(1){
		if(IRQ_Flag){
			LCD_Send_string_Pos((uint8*)"                ", LCD_SECOND_ROW, 1);
			IRQ_Flag--;
		}

//		my_wait(350);
	}
}

void clock_init(){
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

void MyISR_EXTIB9(void){
	LCD_Send_string_Pos((uint8*)"EXTI PB9 Occured", LCD_SECOND_ROW, 1);
	IRQ_Flag++;
	my_wait(2000);

}
