/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : main.c 			                            		 */
/* Date          : Jul 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "RCC_driver.h"
#include "gpio_driver.h"
#include "EXTI_driver.h"

uint8 IRQ_Flag = 0;

void EXTI9_Callback(void){
	IRQ_Flag = 1;
}

int main(){
	MCAL_RCC_Enable_Peripheral(RCC_AFIO);
	MCAL_RCC_Enable_Peripheral(RCC_GPIOB);
	EXTI_PinConfig_t myEXTI9;
	myEXTI9.EXTI_PIN = EXTI9PB9;
	myEXTI9.IRQ_EN = EXTI_IRQ_ENABLE;
	myEXTI9.Trigger_Case = EXTI_TRIGGER_RISING;
	myEXTI9.P_IRQ_CallBack = EXTI9_Callback;
	MCAL_EXTI_GPIO_Init(&myEXTI9);
	while(1){
		if(IRQ_Flag)
			IRQ_Flag = 1;
	}
	return 0;
}


