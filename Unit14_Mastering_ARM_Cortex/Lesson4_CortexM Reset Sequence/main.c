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

enum CPUAccessLevel{
	priviliged,
	unprivileged
};



void Switch_CPU_Access_Level(enum CPUAccessLevel level){
	switch(level){
	case priviliged:
		/* Clear Bit 0 CONTROL Register */
		__asm("mrs r3, CONTROL 		\n\t"
			  "lsr r3, r3, #0x1 	\n\t"
			  "lsl r3, r3, #0x1		\n\t"
			  "msr CONTROL, r3");
		break;
	case unprivileged:
		/* Set Bit 0 CONTROL Register */
		__asm("mrs r3, CONTROL 		\n\t"
			  "orr r3, r3, #0x1 	\n\t"
			  "msr CONTROL, r3");
		break;
	}
}

void EXTI9_Callback(void){
	IRQ_Flag = 1;
	Switch_CPU_Access_Level(priviliged);

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
	Switch_CPU_Access_Level(unprivileged);
	Switch_CPU_Access_Level(priviliged);
	while(1){
		if(IRQ_Flag)
			IRQ_Flag = 0;
	}
	return 0;
}


