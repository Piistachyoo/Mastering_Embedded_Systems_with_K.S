/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : gpio_driver.c                           				 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "gpio_driver.h"

static uint8 Get_CRLH_Position(uint16 PinNumber){
	switch(PinNumber){
	case GPIO_PIN_0:
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_1:
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_2:
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_3:
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_4:
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_5:
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_6:
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_7:
	case GPIO_PIN_15:
		return 28;
		break;
	default: return 55;
	}
}

/**=============================================
  * @Fn				- MCAL_GPIO_Init
  * @brief 			- Initializes the GPIOx PINy according to the specified paramters in the PinConfig
  * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
  * @param [in] 	- PinConfig: Pointer to a GPIO_PinConfig_t structure that contains the configuration
  * 				  information for the specified GPIO PIN
  * @retval 		- None
  * Note			- STM32F103C8 MCU has GPIO A,B,C,D,E Modules, but LQFP48 package has only
  * 				  GPIO A,B and part of C/D exported as external PINS from the MCU
  * 				- It is mandatory to enable RCC clock for the corresponding GPIO PORT
  */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig){
	// Port configuration register low (GPIOx_CRL) for pins 0 -> 7
	// Port configuration register high (GPIOx_CRH) for pins 8 -> 15
	vuint32_t *ConfigReg = NULL;
	ConfigReg = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? (&GPIOx->CRL) : (&GPIOx->CRH);
	uint8 Pin_Pos = Get_CRLH_Position(PinConfig->GPIO_PinNumber); // Get pin position in CR register
	(*ConfigReg) &= ~(0xF << Pin_Pos);
	uint8 Temp_PinConfig = 0;
	/* Check if pin is input or output */
	switch(PinConfig->GPIO_MODE){
	case GPIO_MODE_OUTPUT_PP:
	case GPIO_MODE_OUTPUT_OD:
	case GPIO_MODE_OUTPUT_AF_PP:
	case GPIO_MODE_OUTPUT_AF_OD:
		Temp_PinConfig = ((((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_OUTPUT_SPEED)) & 0x0F);
		break;
	case GPIO_MODE_ANALOG:
	case GPIO_MODE_INPUT_FLO:
		Temp_PinConfig = ((PinConfig->GPIO_MODE << 2) & 0x0F);
		break;
	case GPIO_MODE_INPUT_PU:
		Temp_PinConfig = 0x08;
		GPIOx->ODR |= PinConfig->GPIO_PinNumber;
		break;
	case GPIO_MODE_INPUT_PD:
		Temp_PinConfig = 0x08;
		GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
		break;
	case GPIO_MODE_AF_INPUT:
		Temp_PinConfig = ((GPIO_MODE_INPUT_FLO << 2) & 0x0F);
		break;
	}
	(*ConfigReg) |= (Temp_PinConfig << Pin_Pos);
}

/**=============================================
 * @Fn			- MCAL_GPIO_DeInit
 * @brief 		- Resets the GPIO PORT
 * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @retval 		- None
 * Note			- None
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx){
	if(GPIOx == GPIOA){
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB){
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC){
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD){
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE){
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}
}

/**=============================================
 * @Fn			- MCAL_GPIO_ReadPin
 * @brief 		- Reads Specific PIN
 * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] 	- PinNumber: Set pin number according to @ref GPIO_PINS_define
 * @retval 		- the input pin value (two values based on @ref GPIO_PIN_STATE
 * Note			- None
 */
uint8 MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16 PinNumber){
	uint8 bit_status;
	if((GPIOx->IDR & PinNumber) != (uint32)GPIO_PIN_RESET){
		bit_status = GPIO_PIN_SET;
	}
	else{
		bit_status = GPIO_PIN_RESET;
	}
	return bit_status;
}

/**=============================================
 * @Fn			- MCAL_GPIO_ReadPort
 * @brief 		- Reads Specific PORT
 * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @retval 		- the input port value
 * Note			- None
 */
uint16 MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx){
	uint16 port_value = (uint16)GPIOx->IDR;
	return port_value;
}

/**=============================================
 * @Fn			- MCAL_GPIO_WritePin
 * @brief 		- Write on specific pin
 * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] 	- PinNumber: Set pin number according to @ref GPIO_PINS_define
 * @param [in] 	- Value: Pin value to be written
 * @retval 		- None
 * Note			- None
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16 PinNumber, uint8 Value){

	if(Value != GPIO_PIN_RESET){
/*		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Set the corresponding ODRx bit*/
		GPIOx->BSRR = (uint32)PinNumber;
	}
	else{
/*		Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Reset the corresponding ODRx bit*/
		GPIOx->BRR = (uint32)PinNumber;
	}
}

/**=============================================
 * @Fn			- MCAL_GPIO_WritePort
 * @brief 		- Write on specific port
 * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] 	- Value: Port value to be written
 * @retval 		- None
 * Note			- None
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16 Value){
	GPIOx->ODR = (uint32)Value;
}

/**=============================================
 * @Fn			- MCAL_GPIO_TogglePin
 * @brief 		- Toggle a specific pin
 * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] 	- PinNumber: Set pin number according to @ref GPIO_PINS_define
 * @retval 		- None
 * Note			- None
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16 PinNumber){
	GPIOx->ODR ^= (uint32)PinNumber;
}

/**=============================================
 * @Fn			- MCAL_GPIO_LockPin
 * @brief 		- The locking mechanism allows the IO configuration to be frozen
 * @param [in] 	- GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] 	- PinNumber: Set pin number according to @ref GPIO_PINS_define
 * @retval 		- Ok if pin config is locked, or ERROR if pin is not locked @ref GPIO_RETURN_LOCK
 * Note			- None
 */
uint8 MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16 PinNumber){
/*	Bit 16 LCKK[16]: Lock key
	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	0: Port configuration lock key not active
	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	Any error in the lock sequence will abort the lock.
	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	These bits are read write but can only be written when the LCKK bit is 0.
	0: Port configuration not locked
	1: Port configuration locked.*/

	volatile uint32 temp = (1<<16) | PinNumber;

//	Write 1
	GPIOx->LCKR = temp;

//	Write 0
	GPIOx->LCKR = PinNumber;

//	Write 1
	GPIOx->LCKR = temp;

//	Read 0
	temp = GPIOx->LCKR;

//	Read 1 (this read is optional but confirms that the lock is active)
	if((uint32)(GPIOx->LCKR & (1<<16))){
		return GPIO_RETURN_LOCK_OK;
	}
	else{
		return GPIO_RETURN_LOCK_ERROR;
	}
}
