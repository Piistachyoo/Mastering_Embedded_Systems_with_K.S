/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : EXTI_driver.c 			                             */
/* Date          : Jun 9, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "EXTI_driver.h"

#define AFIO_GPIO_EXTI_Selector(REG)	((REG==GPIOA)?0:(REG==GPIOB)?1:\
										(REG==GPIOC)?2:(REG==GPIOD)?3:0)

static void (*GP_IRQ_CallBack[15])(void);

static void Enable_NVIC(uint8 IRQn){
	switch(IRQn){
	case EXTI0:
		MCAL_NVIC_EnableIRQ(EXTI0_IRQ);
		break;
	case EXTI1:
		MCAL_NVIC_EnableIRQ(EXTI1_IRQ);
		break;
	case EXTI2:
		MCAL_NVIC_EnableIRQ(EXTI2_IRQ);
		break;
	case EXTI3:
		MCAL_NVIC_EnableIRQ(EXTI3_IRQ);
		break;
	case EXTI4:
		MCAL_NVIC_EnableIRQ(EXTI4_IRQ);
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		MCAL_NVIC_EnableIRQ(EXTI5_IRQ);
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		MCAL_NVIC_EnableIRQ(EXTI12_IRQ);
		break;
	default: /* Do Nothing */ break;
	}
}

static void Disable_NVIC(uint8 IRQn){
	switch(IRQn){
	case EXTI0:
		MCAL_NVIC_DisableIRQ(EXTI0_IRQ);
		break;
	case EXTI1:
		MCAL_NVIC_DisableIRQ(EXTI1_IRQ);
		break;
	case EXTI2:
		MCAL_NVIC_DisableIRQ(EXTI2_IRQ);
		break;
	case EXTI3:
		MCAL_NVIC_DisableIRQ(EXTI3_IRQ);
		break;
	case EXTI4:
		MCAL_NVIC_DisableIRQ(EXTI4_IRQ);
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		MCAL_NVIC_DisableIRQ(EXTI5_IRQ);
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		MCAL_NVIC_DisableIRQ(EXTI12_IRQ);
		break;
	default: /* Do Nothing */ break;
	}
}

static void Update_EXTI(EXTI_PinConfig_t *EXTI_Config){
	/* Configure GPIO to be AF -> Floating input */
	GPIO_PinConfig_t PinCfg;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	PinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &PinCfg);

	/* Configure AFIO to route between EXTI Line with Specified PORT */
	uint8 AFIO_EXTICR_index = (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) / 4;
	uint8 AFIO_EXTICR_position = ((EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) % 4) * 4;
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_position);
	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Selector(EXTI_Config->EXTI_PIN.GPIO_Port) & 0x0F) << AFIO_EXTICR_position);

	/* Configure trigger event */
	EXTI->RTSR &= EXTI_Config->EXTI_PIN.GPIO_PIN;
	EXTI->FTSR &= EXTI_Config->EXTI_PIN.GPIO_PIN;

	if(EXTI_TRIGGER_FALLING == EXTI_Config->Trigger_Case){
		EXTI->FTSR |= EXTI_Config->EXTI_PIN.GPIO_PIN;
	}
	else if(EXTI_TRIGGER_RISING == EXTI_Config->Trigger_Case){
		EXTI->RTSR |= EXTI_Config->EXTI_PIN.GPIO_PIN;
	}
	else if(EXTI_TRIGGER_BOTH == EXTI_Config->Trigger_Case){
		EXTI->FTSR |= EXTI_Config->EXTI_PIN.GPIO_PIN;
		EXTI->RTSR |= EXTI_Config->EXTI_PIN.GPIO_PIN;
	}
	else{ /* Do Nothing */ }

	/* Configure IRQ Handling CallBack */
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack;

	/* Enable/Disable IRQ EXTI & NVIC */
	if(EXTI_IRQ_ENABLE == EXTI_Config->IRQ_EN){
		EXTI->IMR |= EXTI_Config->EXTI_PIN.GPIO_PIN;
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_IRQ_DISABLE == EXTI_Config->IRQ_EN){
		EXTI->IMR &= ~(EXTI_Config->EXTI_PIN.GPIO_PIN);
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else{ /* Do Nothing */ }
}

/**=============================================
  * @Fn				- MCAL_EXTI_GPIO_Init
  * @brief 			- This is used to initialize EXTI from specific GPIO PIN and specify the Mask/Trigger condition and IRQ CallBack
  * @param [in] 	- EXTI_Config set by @ref EXTI_define, @ref EXTI_TRIGGER_define, @ref EXTI_IRQ_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- STM32F103C8 MCU has GPIO A,B,C,D,E Modules,
  * 				  But LQFP48 Package has only GPIO A,B, Part of C,D exported as external PINS from the MCU
  * 				- It is mandatory to enable RCC clock for AFIO and the corresponding GPIO
  */
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config){
	Update_EXTI(EXTI_Config);
}

/**=============================================
  * @Fn				- MCAL_EXTI_GPIO_DeInit
  * @brief 			- Resets EXTI registers and NVIC corresponding IRQ Mask
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- Disables all EXTI
  */
void MCAL_EXTI_GPIO_DeInit(void){
	/* Reset EXTI Registers */
	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR = 0xFFFFFFFF;

	/* Disable EXTI from NVIC */
	MCAL_NVIC_DisableIRQ(EXTI0_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI1_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI2_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI3_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI4_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI5_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI12_IRQ);
}

/**=============================================
  * @Fn				- MCAL_EXTI_GPIO_Update
  * @brief 			- This is used to initialize EXTI from specific GPIO PIN and specify the Mask/Trigger condition and IRQ CallBack
  * @param [in] 	- EXTI_Config set by @ref EXTI_define, @ref EXTI_TRIGGER_define, @ref EXTI_IRQ_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- STM32F103C8 MCU has GPIO A,B,C,D,E Modules,
  * 				  But LQFP48 Package has only GPIO A,B, Part of C,D exported as external PINS from the MCU
  * 				- It is mandatory to enable RCC clock for AFIO and the corresponding GPIO
  */
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config){
	Update_EXTI(EXTI_Config);
}

void EXTI0_IRQHandler(void){
	/* Clear Interrupt Flag */
	EXTI->PR |= (1<<0);
	GP_IRQ_CallBack[0]();
}

void EXTI1_IRQHandler(void){
	/* Clear Interrupt Flag */
		EXTI->PR |= (1<<1);
		GP_IRQ_CallBack[1]();
}

void EXTI2_IRQHandler(void){
	/* Clear Interrupt Flag */
		EXTI->PR |= (1<<2);
		GP_IRQ_CallBack[2]();
}

void EXTI3_IRQHandler(void){
	/* Clear Interrupt Flag */
		EXTI->PR |= (1<<3);
		GP_IRQ_CallBack[3]();
}

void EXTI4_IRQHandler(void){
	/* Clear Interrupt Flag */
		EXTI->PR |= (1<<4);
		GP_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler(void){
	if(EXTI->PR & (1<<5)){ EXTI->PR |= (1<<5); GP_IRQ_CallBack[5](); }
	if(EXTI->PR & (1<<6)){ EXTI->PR |= (1<<6); GP_IRQ_CallBack[6](); }
	if(EXTI->PR & (1<<7)){ EXTI->PR |= (1<<7); GP_IRQ_CallBack[7](); }
	if(EXTI->PR & (1<<8)){ EXTI->PR |= (1<<8); GP_IRQ_CallBack[8](); }
	if(EXTI->PR & (1<<9)){ EXTI->PR |= (1<<9); GP_IRQ_CallBack[9](); }
}

void EXTI15_10_IRQHandler(void){
	if(EXTI->PR & (1<<10)){ EXTI->PR |= (1<<10); GP_IRQ_CallBack[10](); }
	if(EXTI->PR & (1<<11)){ EXTI->PR |= (1<<11); GP_IRQ_CallBack[11](); }
	if(EXTI->PR & (1<<12)){ EXTI->PR |= (1<<12); GP_IRQ_CallBack[12](); }
	if(EXTI->PR & (1<<13)){ EXTI->PR |= (1<<13); GP_IRQ_CallBack[13](); }
	if(EXTI->PR & (1<<14)){ EXTI->PR |= (1<<14); GP_IRQ_CallBack[14](); }
	if(EXTI->PR & (1<<15)){ EXTI->PR |= (1<<15); GP_IRQ_CallBack[15](); }
}
