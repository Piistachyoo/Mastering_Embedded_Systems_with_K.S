/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : SPI_driver.h 			                             */
/* Date          : Jul 17, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "STM32F103x8.h"
#include "gpio_driver.h"
#include "RCC_driver.h"
#include "NVIC_driver.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------

struct S_IRQ_SRC{
	uint8 TXE:1; 	// TX buffer empty interrupt
	uint8 RXNE:1; 	// RX buffer not empty interrupt
	uint8 ERRI:1; 	// Error interrupt
	uint8 Reserved:5;
};

typedef struct{
	uint16 Device_Mode; 			// Specifies the SPI operating mode @ref SPI_Device_Mode_define
	uint16 Communication_Mode;		// Specifies the SPI bidirectional mode state @ref SPI_Communication_Mode_define
	uint16 Frame_Format;			// Specifies LSB or MSB to be sent first @ref SPI_Frame_Format_define
	uint16 DataSize;				// Specifies the size of the sent or received data @ref SPI_DataSize_define
	uint16 CLKPolarity;				// Specifies the clock polarity @ref SPI_CLKPolarity_define
	uint16 CLKPhase;				// Specifies the clock phase @ref SPI_CLKPhase_define
	uint16 NSS;						// Specifies whether the NSS signal is managed by hardware or software @ref SPI_NSS_define
	uint16 SPI_BAUDRATEPRESCALER;	/* Specifies the baud rate prescaler value which will be used to configure the transmit and receive
									   SCK clock. This parameter can be a value of @ref SPI_BAUDRATEPRESCALER_define*/
									/* @note The communication clock is derived from the master clock. the slave clock does not need
									 * to be set. You have to configure RCC to enter the correct clock to APB2 or APB1 bus */
	uint16 IRQ_Enable;				// @ref SPI_IRQ_Enable_define
	void (*P_IRQ_CallBack)(struct S_IRQ_SRC irq_src);		// Sets the C function() which will be called once the IRQ happens
}SPI_config;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

// @ref SPI_Device_Mode_define
#define SPI_DEVICE_MODE_SLAVE			(0x00000000U)
#define SPI_DEVICE_MODE_MASTER			(0x1U<<2)

// @ref SPI_Communication_Mode_define
#define SPI_DIRECTION_2LINES			(0x00000000U)
#define SPI_DIRECTION_2LINES_RXONLY		(0x1U<<10)
#define SPI_DIRECTION_1LINE_RXONLY		((0x1U<<15) | (0x1U<<14))
#define SPI_DIRECTION_1LINE_TXONLY

// @ref SPI_Frame_Format_define
#define SPI_Frame_Format_MSB_First		(0x00000000U)
#define SPI_Frame_Format_LSB_First		(0x1U<<7)

// @ref SPI_DataSize_define
#define SPI_DataSize_8BIT				(0x00000000U)
#define SPI_DataSize_16BIT				(0x1U<<11)

// @ref SPI_CLKPolarity_define
#define SPI_CLKPolarity_LOW_IDLE		(0x00000000U)
#define SPI_CLKPolarity_HIGH_IDLE		(0x1U<<1)

// @ref SPI_CLKPhase_define
#define SPI_CLKPhase_FIRST_EDGE			(0x00000000U)
#define SPI_CLKPhase_SECOND_EDGE		(0x1U<<0)

// @ref SPI_NSS_define
#define SPI_NSS_HARDWARE_SLAVE						(0x00000000U)
#define SPI_NSS_HARDWARE_MASTER_SS_OUTPUT_ENABLE	(0x1U<<2)
#define SPI_NSS_HARDWARE_MASTER_SS_OUTPUT_DISABLE	~(0x1U<<2)
#define SPI_NSS_SOFTWARE_NSSINTERNALSOFT_RESET		(0x1U<<9)
#define SPI_NSS_SOFTWARE_NSSINTERNALSOFT_SET		((0x1U<<9) | (0x1U<<8))

// @ref SPI_BAUDRATEPRESCALER_define
#define SPI_BAUDRATEPRESCALER_2			(0x00000000U)
#define SPI_BAUDRATEPRESCALER_4			(0b001U<<3)
#define SPI_BAUDRATEPRESCALER_8			(0b010U<<3)
#define SPI_BAUDRATEPRESCALER_16		(0b011U<<3)
#define SPI_BAUDRATEPRESCALER_32		(0b100U<<3)
#define SPI_BAUDRATEPRESCALER_64		(0b101U<<3)
#define SPI_BAUDRATEPRESCALER_128		(0b110U<<3)
#define SPI_BAUDRATEPRESCALER_256		(0b111U<<3)

// @ref SPI_IRQ_Enable_define
#define SPI_IRQ_ENABLE_NONE				(0x00000000U)
#define SPI_IRQ_ENABLE_TXEIE			(0x1U<<7)
#define SPI_IRQ_ENABLE_RXNEIE			(0x1U<<6)
#define SPI_IRQ_ENABLE_ERRIE			(0x1U<<5)

enum PollingMechanism{
	PollingEnable,
	PollingDisable
};

/*
 * =============================================
 * APIs Supported by "SPI"
 * =============================================
 */

/**=============================================
 * @Fn			- MCAL_SPI_Init
 * @brief 		- Initializes the SPI according to the specified parameters
 * @param [in] 	- SPIx: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
 * @param [in]  - SPI_cfg: All SPI configuration
 * @retval 		- None
 * Note			- Support for SPI full duplex Master/Slave only for now & NSS HW only for slave,
 * 					in case of master, you have to configure pin and drive it
 */
void MCAL_SPI_Init(SPI_TypeDef *SPIx, SPI_config *SPI_cfg);

/**=============================================
  * @Fn				- MCAL_SPI_DeInit
  * @brief 			- DeInitializes SPI
  * @param [in] 	- SPIx: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
  * @retval 		- None
  * Note			- Reset the model by RCC
  */
void MCAL_SPI_DeInit(SPI_TypeDef *SPIx);

/**=============================================
  * @Fn				- MCAL_SPI_GPIO_Set_Pins
  * @brief 			- Initializes GPIO pins
  * @param [in] 	- SPIx: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
  * @retval 		- None
  * Note			- Called automatically at the end of MCAL_SPI_Init()
  */
void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef *SPIx);

/**=============================================
  * @Fn				- MCAL_SPI_SendData
  * @brief 			- Send data from buffer on SPI
  * @param [in] 	- SPIx	: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
  * @param [in] 	- pTxBuffer	: Buffer to be transmitted
  * @param [in] 	- PollingEn	: Enable or disable polling
  * @retval 		- None
  * Note			- Should initialize SPI first
  */
void MCAL_SPI_SendData(SPI_TypeDef *SPIx, uint16 *pTxBuffer, enum PollingMechanism PollingEn);

/**=============================================
  * @Fn				- MCAL_SPI_ReceiveData
  * @brief 			- Receive data to buffer from SPI
  * @param [in] 	- SPIx: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
  * @param [in] 	- pRxBuffer: Buffer to be received
  * @param [in] 	- PollingEn: Enable or disable polling
  * @retval 		- None
  * Note			- Should initialize SPI first
  */
void MCAL_SPI_ReceiveData(SPI_TypeDef *SPIx, uint16 *pRxBuffer, enum PollingMechanism PollingEn);

/**=============================================
  * @Fn				- MCAL_SPI_TX_RX
  * @brief 			- Send and receive data from buffer with SPI
  * @param [in] 	- SPIx: Pointer to the SPI peripheral instance, where x can be (1..3 depending on device used)
  * @param [in] 	- pTxRxBuffer: Buffer with data to be send and data will be received into
  * @param [in] 	- PollingEn	: Enable or disable polling
  * @retval 		- None
  * Note			- Should initialize SPI first
  */
void MCAL_SPI_TX_RX(SPI_TypeDef *SPIx, uint16 *pTxRxBuffer, enum PollingMechanism PollingEn);

#endif /* INC_SPI_DRIVER_H_ */
