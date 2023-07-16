/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : USART_driver.c 			                             */
/* Date          : Jul 4, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "USART_driver.h"

/* BaudRate macros */
#define USARTDIV(_PCLK_, _BAUD_)            (uint32)(_PCLK_/(16 * _BAUD_))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)     (uint32)((25 * _PCLK_) / (4 * _BAUD_))
#define MANTISSA(_PCLK_, _BAUD_)            (uint32)(USARTDIV(_PCLK_, _BAUD_))
#define MANTISSA_MUL100(_PCLK_, _BAUD_)     (uint32)(USARTDIV(_PCLK_, _BAUD_) * 100)
#define DIV_FRACTION(_PCLK_, _BAUD_)        (uint32)(((USARTDIV_MUL100(_PCLK_, _BAUD_) - MANTISSA_MUL100(_PCLK_, _BAUD_)) * 16) / 100)
#define UART_BRR_REGISTER(_PCLK_, _BAUD_)   (uint32)((MANTISSA(_PCLK_, _BAUD_) << 4)|(DIV_FRACTION(_PCLK_, _BAUD_)&0xF))

/* Variables */
USART_cfg_t* Global_USART_cfg[3];

/**=============================================
  * @Fn				- MCAL_USART_Init
  * @brief 			- Initializes UART (Supported feature Asynchronous only)
  * @param [in] 	- USARTx: Pointer to the USART peripheral instance, where x can be (1..3 depending on device used)
  * @param [in] 	- USART_cfg: Pointer to the UART configuration
  * @retval 		- None
  * Note			- Support for now asynchronous mode and clock 8MHZ
  */
void MCAL_USART_Init(USART_TypeDef* USARTx, USART_cfg_t* USART_cfg){
	uint32 BRR, pclk;

	/* Enable clock for given USART peripheral */
	if(USART1 == USARTx){
		MCAL_RCC_Enable_Peripheral(RCC_USART1);
		MCAL_RCC_Enable_Peripheral(RCC_GPIOA);
		Global_USART_cfg[0] = USART_cfg;
	}
	else if(USART2 == USARTx){
		MCAL_RCC_Enable_Peripheral(RCC_USART2);
		MCAL_RCC_Enable_Peripheral(RCC_GPIOA);
		Global_USART_cfg[1] = USART_cfg;
	}
	else if(USART3 == USARTx){
		MCAL_RCC_Enable_Peripheral(RCC_USART3);
		MCAL_RCC_Enable_Peripheral(RCC_GPIOB);
		Global_USART_cfg[2] = USART_cfg;
	}
	else{ /* Do Nothing */ }

	/* Enable UART */
	USARTx->CR1 |= (1U<<13);

	/* Enable USART TX and RX according to USART_Mode configuration item */
	USARTx->CR1 |= USART_cfg->USART_Mode;

	/* Payload Width */
	USARTx->CR1 |= USART_cfg->Payload_Length;

	/* Configuration of parity control bit fields */
	USARTx->CR1 |= USART_cfg->Parity;

	/* Configure the number of stop bits */
	USARTx->CR2 |= USART_cfg->StopBits;

	/* USART Hardware Flow Control */
	USARTx->CR3 |= USART_cfg->HwFlowCtl;

	/* Configuration of BRR(BaudRate Register)
	 * PCLK1 for USART2, 3
	 * PCLK2 for USART1
	 */
	  if(USART1 == USARTx){
		  pclk = MCAL_RCC_GetPCLK2Freq();
	  }
	  else{
		  pclk = MCAL_RCC_GetPCLK1Freq();
	  }
	  BRR = UART_BRR_REGISTER(pclk, USART_cfg->BaudRate);
	  USARTx->BRR = BRR;

	  /* Configure interrupts */
	  if(UART_IRQ_Enable_NONE != USART_cfg->IRQ_Enable){
		  USARTx->CR1 |= (USART_cfg->IRQ_Enable);

		  /* Enable NVIC for USARTx IRQ */
		  if(USART1 == USARTx){
			  MCAL_NVIC_EnableIRQ(USART1_IRQ);
		  }
		  else if(USART2 == USARTx){
			  MCAL_NVIC_EnableIRQ(USART2_IRQ);
		  }
		  else if(USART3 == USARTx){
			  MCAL_NVIC_EnableIRQ(USART3_IRQ);
		  }
		  else{ /* Do Nothing */ }
	  }
	  else{ /* Do Nothing */ }

	  MCAL_USART_GPIO_Set_Pins(USARTx);
}

/**=============================================
  * @Fn				- MCAL_USART_DeInit
  * @brief 			- DeInitializes UART (Supported feature Asynchronous only)
  * @param [in] 	- USARTx: Pointer to the USART peripheral instance, where x can be (1..3 depending on device used)
  * @retval 		- None
  * Note			- Reset the model by RCC
  */
void MCAL_USART_DeInit(USART_TypeDef* USARTx){

	if(USART1 == USARTx){
		MCAL_RCC_Reset_Peripheral(RCC_USART1);
		MCAL_NVIC_DisableIRQ(USART1_IRQ);
	}
	else if(USART2 == USARTx){
		MCAL_RCC_Reset_Peripheral(RCC_USART2);
		MCAL_NVIC_DisableIRQ(USART2_IRQ);
	}
	else if(USART3 == USARTx){
		MCAL_RCC_Reset_Peripheral(RCC_USART3);
		MCAL_NVIC_DisableIRQ(USART3_IRQ);
	}
	else{ /* Do Nothing */ }

}

/**=============================================
  * @Fn				- MCAL_USART_GPIO_Set_Pins
  * @brief 			- Initializes GPIO pins
  * @param [in] 	- USARTx: Pointer to the USART peripheral instance, where x can be (1..3 depending on device used)
  * @retval 		- None
  * Note			- Should enable the corresponding ALT & GPIO in RCC clock, called after MCAL_UART_Init()
  */
void MCAL_USART_GPIO_Set_Pins(USART_TypeDef* USARTx){

	GPIO_PinConfig_t PinCfg;

	if(USART1 == USARTx){
		/*
		 * PA9 TX
		 * PA10 RX
		 * PA11 CTS
		 * PA12 RTS
		 */

		// PA9 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_9;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		// PA10 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		if((UART_HwFlowCtl_CTS == Global_USART_cfg[0]->HwFlowCtl) || (UART_HwFlowCtl_RTS_CTS == Global_USART_cfg[0]->HwFlowCtl)){
			// PA11 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_11;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
		else{ /* Do Nothing */ }

		if((UART_HwFlowCtl_RTS == Global_USART_cfg[0]->HwFlowCtl) || (UART_HwFlowCtl_RTS_CTS == Global_USART_cfg[0]->HwFlowCtl)){
			// PA12 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_12;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
		else{ /* Do Nothing */ }
	}
	else if(USART2 == USARTx){
		/*
		 * PA2 TX
		 * PA3 RX
		 * PA0 CTS
		 * PA1 RTS
		 */

		// PA2 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_2;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		// PA3 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_3;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		if((UART_HwFlowCtl_CTS == Global_USART_cfg[1]->HwFlowCtl) || (UART_HwFlowCtl_RTS_CTS == Global_USART_cfg[1]->HwFlowCtl)){
			// PA0 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_0;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
		else{ /* Do Nothing */ }

		if((UART_HwFlowCtl_RTS == Global_USART_cfg[1]->HwFlowCtl) || (UART_HwFlowCtl_RTS_CTS == Global_USART_cfg[1]->HwFlowCtl)){
			// PA1 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_1;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
		else{ /* Do Nothing */ }
	}
	else if(USART3 == USARTx){
		/*
		 * PB10 TX
		 * PB11 RX
		 * PB13 CTS
		 * PB14 RTS
		 */

		// PB10 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		// PB11 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_11;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		if((UART_HwFlowCtl_CTS == Global_USART_cfg[2]->HwFlowCtl) || (UART_HwFlowCtl_RTS_CTS == Global_USART_cfg[2]->HwFlowCtl)){
			// PB13 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}
		else{ /* Do Nothing */ }

		if((UART_HwFlowCtl_RTS == Global_USART_cfg[2]->HwFlowCtl) || (UART_HwFlowCtl_RTS_CTS == Global_USART_cfg[2]->HwFlowCtl)){
			// PB14 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}
		else{ /* Do Nothing */ }
	}
}

/**=============================================
  * @Fn				- MCAL_USART_SendData
  * @brief 			- Send buffer on UART
  * @param [in] 	- USARTx	: Pointer to the USART peripheral instance, where x can be (1..3 depending on device used)
  * @param [in] 	- pTxBuffer	: Buffer to be transmitted
  * @param [in] 	- PollingEn	: Enable or disable polling
  * @retval 		- None
  * Note			- Should initialize UART first
  * 				When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
  * 				the value written in the MSB(bit 7 or bit 8 depending on the data length) has no effect
  * 				because it is replaced by the parity.
  * 				When receiving with the parity enabled, the value read in the MSB bit is the received parity bit
  */
void MCAL_USART_SendData(USART_TypeDef* USARTx, uint16 *pTxBuffer, Polling_Mechanism PollingEn){
	if(enable == PollingEn){
		/* Wait until transmission buffer is empty */
		while(! (USARTx->SR & (1<<7)));
	}
	else{ /* Do Nothing */ }

	/*This bit selects the hardware parity control (generation and detection). When the parity
	control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
	if M=0) and parity is checked on the received data. This bit is set and cleared by software.
	Once it is set, PCE is active after the current byte (in reception and in transmission).*/

	if(USART1 == USARTx){
		if(UART_Payload_Length_9B == Global_USART_cfg[0]->Payload_Length){
			USARTx->DR = (*pTxBuffer & (uint16)0x01FF);
		}
		else{
			USARTx->DR = (*pTxBuffer & (uint16)0xFF);
		}
	}
	else if(USART2 == USARTx){
		if(UART_Payload_Length_9B == Global_USART_cfg[1]->Payload_Length){
			USARTx->DR = (*pTxBuffer & (uint16)0x01FF);
		}
		else{
			USARTx->DR = (*pTxBuffer & (uint16)0xFF);
		}
	}
	else if(USART3 == USARTx){
		if(UART_Payload_Length_9B == Global_USART_cfg[2]->Payload_Length){
			USARTx->DR = (*pTxBuffer & (uint16)0x01FF);
		}
		else{
			USARTx->DR = (*pTxBuffer & (uint16)0xFF);
		}
	}
	else{ /* Do Nothing */ }
}

/**=============================================
  * @Fn				- MCAL_USART_ReceiveData
  * @brief 			- Receive buffer from UART
  * @param [in] 	- USARTx	: Pointer to the USART peripheral instance, where x can be (1..3 depending on device used)
  * @param [in] 	- pRxBuffer	: Buffer to be received
  * @param [in] 	- PollingEn	: Enable or disable polling
  * @retval 		- None
  * Note			- Should initialize UART first
  * 				When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
  * 				the value written in the MSB(bit 7 or bit 8 depending on the data length) has no effect
  * 				because it is replaced by the parity.
  * 				When receiving with the parity enabled, the value read in the MSB bit is the received parity bit
  */
void MCAL_USART_ReceiveData(USART_TypeDef* USARTx, uint16 *pRxBuffer, Polling_Mechanism PollingEn){
	if(enable == PollingEn){
		/* Wait until data is received */
		while(! (USARTx->SR & (1<<5)));
	}
	else{ /* Do Nothing */ }

	/* Check the word length is 9bit or 8bit */
	if(USART1 == USARTx){
		if(UART_Payload_Length_9B == Global_USART_cfg[0]->Payload_Length){
			if(UART_Parity_NONE == Global_USART_cfg[0]->Parity){
				/* No parity so all 9 bit are considered data */
				*pRxBuffer = USARTx->DR;
			}
			else{
				/* Parity is used so 8 bits will be data and 1 MSB bit will be parity bit */
				*pRxBuffer = (USARTx->DR & 0xFF);
			}
		}
		else{
			if(UART_Parity_NONE == Global_USART_cfg[0]->Parity){
				/* No parity so all 8 bit are considered data */
				*pRxBuffer = (USARTx->DR & 0xFF);
			}
			else{
				/* Parity is used so 7 bits will be data and 1 MSB bit will be parity bit */
				*pRxBuffer = (USARTx->DR & 0x7F);
			}
		}
	}
	else if(USART2 == USARTx){
		if(UART_Payload_Length_9B == Global_USART_cfg[1]->Payload_Length){
			if(UART_Parity_NONE == Global_USART_cfg[1]->Parity){
				/* No parity so all 9 bit are considered data */
				*pRxBuffer = USARTx->DR;
			}
			else{
				/* Parity is used so 8 bits will be data and 1 MSB bit will be parity bit */
				*pRxBuffer = (USARTx->DR & 0xFF);
			}
		}
		else{
			if(UART_Parity_NONE == Global_USART_cfg[1]->Parity){
				/* No parity so all 8 bit are considered data */
				*pRxBuffer = (USARTx->DR & 0xFF);
			}
			else{
				/* Parity is used so 7 bits will be data and 1 MSB bit will be parity bit */
				*pRxBuffer = (USARTx->DR & 0x7F);
			}
		}
	}
	else if(USART3 == USARTx){
		if(UART_Payload_Length_9B == Global_USART_cfg[2]->Payload_Length){
			if(UART_Parity_NONE == Global_USART_cfg[2]->Parity){
				/* No parity so all 9 bit are considered data */
				*pRxBuffer = USARTx->DR;
			}
			else{
				/* Parity is used so 8 bits will be data and 1 MSB bit will be parity bit */
				*pRxBuffer = (USARTx->DR & 0xFF);
			}
		}
		else{
			if(UART_Parity_NONE == Global_USART_cfg[2]->Parity){
				/* No parity so all 8 bit are considered data */
				*pRxBuffer = (USARTx->DR & 0xFF);
			}
			else{
				/* Parity is used so 7 bits will be data and 1 MSB bit will be parity bit */
				*pRxBuffer = (USARTx->DR & 0x7F);
			}
		}
	}
	else{ /* Do Nothing */ }



}

/**=============================================
  * @Fn				- MCAL_USART_Wait_TC
  * @brief 			- Waits until transmission is completed by polling on TC flag
  * @param [in] 	- USARTx: Pointer to the USART peripheral instance, where x can be (1..3 depending on device used)
  * @retval 		- None
  * Note			- None
  */
void MCAL_USART_Wait_TC(USART_TypeDef* USARTx){
	/* Wait until TC flag is set in the SR */
	while(! (USARTx->SR & (1<<6)));
}

/* ISRs */
void USART1_IRQHandler(void){
	MCAL_NVIC_ClearPendingIRQ(USART1_IRQ);

	if(Global_USART_cfg[0]->P_IRQ_CallBack){
		Global_USART_cfg[0]->P_IRQ_CallBack();
	}
	else{ /* Do Nothing */ }
}

void USART2_IRQHandler(void){
	MCAL_NVIC_ClearPendingIRQ(USART2_IRQ);

	if(Global_USART_cfg[1]->P_IRQ_CallBack){
		Global_USART_cfg[1]->P_IRQ_CallBack();
	}
	else{ /* Do Nothing */ }
}

void USART3_IRQHandler(void){
	MCAL_NVIC_ClearPendingIRQ(USART3_IRQ);

	if(Global_USART_cfg[2]->P_IRQ_CallBack){
		Global_USART_cfg[2]->P_IRQ_CallBack();
	}
	else{ /* Do Nothing */ }
}
