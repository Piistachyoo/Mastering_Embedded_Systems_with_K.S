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

uint32 CONTROL_REG_CLONE = 0xFFFFFFFF;
uint32 IPSR_REG_CLONE = 0xFFFFFFFF;
uint8 IRQ_Flag = 0;

void EXTI9_Callback(void){
	IRQ_Flag = 1;
	__asm ("nop \n\t nop \n\t nop");
	// copy IPSR register to variable in handler mode
	__asm("MRS %[IPSR_REG_CLONE], IPSR"
			: [IPSR_REG_CLONE] "=r" (IPSR_REG_CLONE));	// first: output parameters
	__asm ("nop \n\t nop \n\t nop");
}

int main(){
	__asm ("nop \n\t nop \n\t nop");
	// copy control register to variable in thread mode
	__asm("MRS %[CONTROL_REG_CLONE], CONTROL"
			: [CONTROL_REG_CLONE] "=r" (CONTROL_REG_CLONE));	// first: output parameters
	__asm ("nop \n\t nop \n\t nop");
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
			IRQ_Flag = 0;
	}
	return 0;
}


