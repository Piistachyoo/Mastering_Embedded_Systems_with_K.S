/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : DAC_driver.c 			                             */
/* Date          : Jul 30, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "DAC_driver.h"
#include "RCC_driver.h"
#include "gpio_driver.h"

void MCAL_DAC_Init(DAC_Channels Channel, DAC_config *cfg){
	uint32 temp_register = 0;

	// Enable clock for DAC
	MCAL_RCC_Enable_Peripheral(RCC_AFIO);
	MCAL_RCC_Enable_Peripheral(RCC_DAC);

	// Set buffer control
	temp_register |= cfg->Buffer_Control;

	// Set trigger control
	temp_register |= cfg->Trigger_Control;

	// Set DMA control
	temp_register |= cfg->DMA_Control;



	// Set configuration
	if(DAC_CHANNEL_DUAL != Channel){
		// Enable DAC
		temp_register |= (1UL<<0);

		DAC->CR = (temp_register << Channel);
	}
	else{
		// Enable DAC
		temp_register |= ((1UL<<0) | (1UL<<16));

		// Enable both channels
		DAC->CR = ((temp_register << DAC_CHANNEL_1) | (temp_register << DAC_CHANNEL_2));
	}

	// Set GPIO pins
	MCAL_DAC_GPIO_Set_Pins(Channel);
}

void MCAL_DAC_GPIO_Set_Pins(DAC_Channels Channel){
	MCAL_RCC_Enable_Peripheral(RCC_GPIOA);

	GPIO_PinConfig_t PinCfg;

	PinCfg.GPIO_MODE = GPIO_MODE_ANALOG;

	if(DAC_CHANNEL_1 == Channel){
		PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	}
	else if(DAC_CHANNEL_2 == Channel){
		PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	}
	else if(DAC_CHANNEL_DUAL == Channel){
		PinCfg.GPIO_PinNumber = GPIO_PIN_4;
		MCAL_GPIO_Init(GPIOA, &PinCfg);
		PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	}
	else{ /* Do Nothing */ }

	MCAL_GPIO_Init(GPIOA, &PinCfg);
}

void MCAL_DAC_DeInit(){
	MCAL_RCC_Reset_Peripheral(RCC_DAC);
}

void MCAL_DAC_Set_Value(DAC_Channels Channel, DAC_Data_Allignment Allignment, uint16 Value){
	if(DAC_CHANNEL_1 == Channel){
		switch(Allignment){
		case DAC_12bit_left:	DAC->DHR12L1 = (Value<<4); 	break;
		case DAC_12bit_right:	DAC->DHR12R1 = Value; 		break;
		case DAC_8bit_right:	DAC->DHR8R1 = Value; 		break;
		default: /* Do Nothing */ break;
		}
	}
	else if(DAC_CHANNEL_2 == Channel){
		switch(Allignment){
		case DAC_12bit_left:	DAC->DHR12L2 = (Value<<4); 	break;
		case DAC_12bit_right:	DAC->DHR12R2 = Value; 		break;
		case DAC_8bit_right:	DAC->DHR8R2 = Value; 		break;
		default: /* Do Nothing */ break;
		}
	}
	else if(DAC_CHANNEL_DUAL == Channel){
		switch(Allignment){
		case DAC_12bit_left:
			DAC->DHR12L1 = (Value<<4);
			DAC->DHR12L2 = (Value<<4);
			break;
		case DAC_12bit_right:
			DAC->DHR12R1 = Value;
			DAC->DHR12R2 = Value;
			break;
		case DAC_8bit_right:
			DAC->DHR8R1 = Value;
			DAC->DHR8R2 = Value;
			break;
		default: /* Do Nothing */ break;
		}
	}
	else{ /* Do Nothing */ }
}
