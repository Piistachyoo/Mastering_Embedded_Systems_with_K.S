/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : SPI_driver.c 			                             */
/* Date          : Jul 17, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "SPI_driver.h"

#define SPI1_INDEX	0
#define SPI2_INDEX	1

#define SPI_SR_TXE	((uint8)(0x02)) /* Transmit buffer empty */
#define SPI_SR_RXNE	((uint8)(0x01)) /* Transmit buffer empty */

SPI_config Global_SPI_Config[2];

/**=============================================
 * @Fn			- MCAL_SPI_Init
 * @brief 		- Initializes the SPI according to the specified parameters
 * @param [in] 	- SPIx: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
 * @param [in]  - SPI_cfg: All SPI configuration
 * @retval 		- None
 * Note			- Support for SPI full duplex Master/Slave only for now & NSS HW only for slave,
 * 					in case of master, you have to configure pin and drive it
 */
void MCAL_SPI_Init(SPI_TypeDef *SPIx, SPI_config *SPI_cfg){
	/* Temp clone of registers for safety */
	uint16 tmpreg_CR1 = 0;
	uint16 tmpreg_CR2 = 0;
	if(SPI1 == SPIx){
		MCAL_RCC_Enable_Peripheral(RCC_SPI1);
		Global_SPI_Config[SPI1_INDEX] = *SPI_cfg;
	}
	else if(SPI2 == SPIx){
		MCAL_RCC_Enable_Peripheral(RCC_SPI2);
		Global_SPI_Config[SPI2_INDEX] = *SPI_cfg;
	}
	else{ /* Do Nothing */ }

	/* Enable SPI */
	tmpreg_CR1 |= (1U<<6);

	/* Master or slave */
	tmpreg_CR1 |= SPI_cfg->Device_Mode;

	/* Communication mode */
	tmpreg_CR1 |= SPI_cfg->Communication_Mode;

	/* Frame Format */
	tmpreg_CR1 |= SPI_cfg->Frame_Format;

	/* Data Size */
	tmpreg_CR1 |= SPI_cfg->DataSize;

	/* Clock Polarity */
	tmpreg_CR1 |= SPI_cfg->CLKPolarity;

	/* Clock Phase */
	tmpreg_CR1 |= SPI_cfg->CLKPhase;

	/* NSS */
	if(SPI_NSS_HARDWARE_MASTER_SS_OUTPUT_ENABLE == SPI_cfg->NSS){
		tmpreg_CR2 |= SPI_cfg->NSS;
	}
	else if(SPI_NSS_HARDWARE_MASTER_SS_OUTPUT_DISABLE == SPI_cfg->NSS){
		tmpreg_CR2 &= SPI_cfg->NSS;
	}
	else{
		tmpreg_CR1 |= SPI_cfg->NSS;
	}

	/* Prescaler */
	tmpreg_CR1 |= SPI_cfg->SPI_BAUDRATEPRESCALER;

	if(SPI_IRQ_ENABLE_NONE != SPI_cfg->IRQ_Enable){
		tmpreg_CR2 |= SPI_cfg->IRQ_Enable;
		if(SPI1 == SPIx){
			MCAL_NVIC_EnableIRQ(SPI1_IRQ);
		}
		else if(SPI2 == SPIx){
			MCAL_NVIC_EnableIRQ(SPI2_IRQ);
		}
		else{ /* Do Nothing */ }
	}

	SPIx->CR1 = tmpreg_CR1;
	SPIx->CR2 = tmpreg_CR2;

	MCAL_SPI_GPIO_Set_Pins(SPIx);
}

/**=============================================
  * @Fn				- MCAL_SPI_DeInit
  * @brief 			- DeInitializes SPI
  * @param [in] 	- SPIx: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
  * @retval 		- None
  * Note			- Reset the model by RCC
  */
void MCAL_SPI_DeInit(SPI_TypeDef *SPIx){
	if(SPI1 == SPIx){
		MCAL_NVIC_DisableIRQ(SPI1_IRQ);
		MCAL_RCC_Reset_Peripheral(RCC_SPI1);
	}
	else if(SPI2 == SPIx){
		MCAL_NVIC_DisableIRQ(SPI2_IRQ);
		MCAL_RCC_Reset_Peripheral(RCC_SPI2);
	}
	else{ /* Do Nothing */ }
}

/**=============================================
  * @Fn				- MCAL_SPI_GPIO_Set_Pins
  * @brief 			- Initializes GPIO pins
  * @param [in] 	- SPIx: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
  * @retval 		- None
  * Note			- Called automatically at the end of MCAL_SPI_Init()
  */
void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef *SPIx){
	GPIO_PinConfig_t PinCfg;
	if(SPI1 == SPIx){
		/* PA4 NSS
		 * PA5 SCK
		 * PA6 MISO
		 * PA7 MOSI
		 */
		MCAL_RCC_Enable_Peripheral(RCC_GPIOA);
		MCAL_RCC_Enable_Peripheral(RCC_AFIO);
		if(SPI_DEVICE_MODE_MASTER == Global_SPI_Config[SPI1_INDEX].Device_Mode){
			// PA4 NSS
			switch(Global_SPI_Config[SPI1_INDEX].NSS){
			case SPI_NSS_HARDWARE_MASTER_SS_OUTPUT_DISABLE:
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;
			case SPI_NSS_HARDWARE_MASTER_SS_OUTPUT_ENABLE:
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;
			default: /* Do Nothing */ break;
			}

			// PA5 SCK
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			// PA6 MISO
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			// PA7 MOSI
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}
		else{ /* Slave Mode */
			// PA4 NSS
			if(SPI_NSS_HARDWARE_SLAVE == Global_SPI_Config[SPI1_INDEX].NSS){
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
			}
			else{ /* Do Nothing */ }

			// PA5 SCK
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			// PA6 MISO
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			// PA7 MOSI
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
	}
	else if(SPI2 == SPIx){
		/* PB12 NSS
		 * PB13 SCK
		 * PB14 MISO
		 * PB15 MOSI
		 */
		MCAL_RCC_Enable_Peripheral(RCC_GPIOB);
		MCAL_RCC_Enable_Peripheral(RCC_AFIO);
		if(SPI_DEVICE_MODE_MASTER == Global_SPI_Config[SPI2_INDEX].Device_Mode){
			// PB12 NSS
			switch(Global_SPI_Config[SPI2_INDEX].NSS){
			case SPI_NSS_HARDWARE_MASTER_SS_OUTPUT_DISABLE:
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;
			case SPI_NSS_HARDWARE_MASTER_SS_OUTPUT_ENABLE:
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;
			default: /* Do Nothing */ break;
			}

			// PB13 SCK
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			// PB14 MISO
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			// PB15 MOSI
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

		}
		else{ /* Slave Mode */
			// PB12 NSS
			if(SPI_NSS_HARDWARE_SLAVE == Global_SPI_Config[SPI2_INDEX].NSS){
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
			}
			else{ /* Do Nothing */ }

			// PB13 SCK
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			// PB14 MISO
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			// PB15 MOSI
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}
	}
	else{ /* Do Nothing */ }
}

/**=============================================
  * @Fn				- MCAL_SPI_SendData
  * @brief 			- Send data from buffer on SPI
  * @param [in] 	- SPIx	: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
  * @param [in] 	- pTxBuffer	: Buffer to be transmitted
  * @param [in] 	- PollingEn	: Enable or disable polling
  * @retval 		- None
  * Note			- Should initialize SPI first
  */
void MCAL_SPI_SendData(SPI_TypeDef *SPIx, uint16 *pTxBuffer, enum PollingMechanism PollingEn){
	/* TODO: should check communication mode first */

	if(PollingEnable == PollingEn){
		/* While transmission buffer is not empty */
		while(! (SPIx->SR & SPI_SR_TXE));
	}
	else{ /* Do Nothing */ }

	SPIx->DR = *pTxBuffer;
}

/**=============================================
  * @Fn				- MCAL_SPI_ReceiveData
  * @brief 			- Receive data to buffer from SPI
  * @param [in] 	- SPIx	: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
  * @param [in] 	- pRxBuffer	: Buffer to be received
  * @param [in] 	- PollingEn	: Enable or disable polling
  * @retval 		- None
  * Note			- Should initialize SPI first
  */
void MCAL_SPI_ReceiveData(SPI_TypeDef *SPIx, uint16 *pRxBuffer, enum PollingMechanism PollingEn){
	if(PollingEnable == PollingEn){
		/* While receive buffer is not empty */
		while(! (SPIx->SR & SPI_SR_RXNE));
	}
	else{ /* Do Nothing */ }

	*pRxBuffer = SPIx->DR;
}

/**=============================================
  * @Fn				- MCAL_SPI_TX_RX
  * @brief 			- Send and receive data from buffer with SPI
  * @param [in] 	- SPIx: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
  * @param [in] 	- pTxRxBuffer: Buffer with data to be send and data will be received into
  * @param [in] 	- PollingEn	: Enable or disable polling
  * @retval 		- None
  * Note			- Should initialize SPI first
  */
void MCAL_SPI_TX_RX(SPI_TypeDef *SPIx, uint16 *pTxRxBuffer, enum PollingMechanism PollingEn){
	if(PollingEnable == PollingEn){
		/* While transmission buffer is not empty */
		while(! (SPIx->SR & SPI_SR_TXE));
	}
	else{ /* Do Nothing */ }
	SPIx->DR = *pTxRxBuffer;

	if(PollingEnable == PollingEn){
		/* While receive buffer is not empty */
		while(! (SPIx->SR & SPI_SR_RXNE));
	}
	else{ /* Do Nothing */ }
	*pTxRxBuffer = SPIx->DR;
}

void SPI1_IRQHandler(void){
	MCAL_NVIC_ClearPendingIRQ(SPI1_IRQ);
	if(NULL != Global_SPI_Config[SPI1_INDEX].P_IRQ_CallBack){
		struct S_IRQ_SRC irq_src;
		irq_src.TXE = ((SPI1->SR & (1<<1))>>1);
		irq_src.RXNE = ((SPI1->SR & (1<<0))>>0);
		irq_src.ERRI = ((SPI1->SR & (1<<4))>>4);
		Global_SPI_Config[SPI1_INDEX].P_IRQ_CallBack(irq_src);
	}
	else{ /* Do Nothing */ }
}

void SPI2_IRQHandler(void){
	MCAL_NVIC_ClearPendingIRQ(SPI2_IRQ);
	if(NULL != Global_SPI_Config[SPI2_INDEX].P_IRQ_CallBack){
		struct S_IRQ_SRC irq_src;
		irq_src.TXE = ((SPI2->SR & (1<<1))>>1);
		irq_src.RXNE = ((SPI2->SR & (1<<0))>>0);
		irq_src.ERRI = ((SPI2->SR & (1<<4))>>4);
		Global_SPI_Config[SPI2_INDEX].P_IRQ_CallBack(irq_src);
	}
	else{ /* Do Nothing */ }
}
