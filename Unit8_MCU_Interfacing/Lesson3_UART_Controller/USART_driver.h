/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : USART_driver.h 			                             */
/* Date          : Jul 4, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_USART_DRIVER_H_
#define INC_USART_DRIVER_H_

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
typedef struct{
	uint8	USART_Mode; 	// Specifies TX/RX Enable/Disable
							// this parameter must be set based on @ref UART_Mode_define
	uint32	BaudRate;		// This member configures the UART communication baud rate
							// this parameter must be set based on @ref UART_BaudRate_define
	uint8	Payload_Length; // Specifies the number of data bits transmitted or received in a frame
							// this parameter must be set based on @ref UART_Payload_Length_define
	uint8	Parity;			// Specifies the parity mode
							// this parameter must be set based on @ref UART_Parity_define
	uint8	StopBits;		// Specifies the number of stop bits transmitted
							// this parameter must be set based on @ref UART_StopBits_define
	uint8	HwFlowCtl;		// Specifies whether the hardware flow control mode is enabled or disabled
							// this parameter must be set based on @ref UART_HwFlowCtl_define
	uint8	IRQ_Enable;		// Enable or Disable UART IRQ TX/RX
							// @ref UART_IRQ_Enable_define, you can select two or three parameters
	void (*P_IRQ_CallBack)(void); // Set the C Function() which will be called once the IRQ happen
}USART_cfg_t;

typedef enum{
	enable,
	disable
}Polling_Mechanism;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

// @ref UART_Mode_define
#define UART_Mode_RX				((uint32)(1UL<<2))
#define UART_Mode_TX				((uint32)(1UL<<3))
#define UART_Mode_TX_RX				((uint32)(1UL<<2 | 1UL<<3))

// @ref UART_BaudRate_define
#define UART_BaudRate_2400			2400
#define UART_BaudRate_9600			9600
#define UART_BaudRate_19200			19200
#define UART_BaudRate_57600			57600
#define UART_BaudRate_115200		115200
#define UART_BaudRate_230400		230400
#define UART_BaudRate_460800		460800
#define UART_BaudRate_921600		921600
#define UART_BaudRate_2250000		2250000
#define UART_BaudRate_4500000		4500000

// @ref UART_Payload_Length_define
#define UART_Payload_Length_8B		((uint32)(0))
#define UART_Payload_Length_9B		((uint32)(1UL<<12))

// @ref UART_Parity_define
#define UART_Parity_NONE			((uint32)(0))
#define UART_Parity_EVEN			((uint32)(1UL<<10))
#define UART_Parity_ODD				((uint32)(1UL<<10) | (1UL<<9))

// @ref UART_StopBits_define
#define UART_StopBits_half			((uint32)(1<<12))
#define UART_StopBits_1				((uint32)(0))
#define UART_StopBits_1_half		((uint32)(3<<12))
#define UART_StopBits_2				((uint32)(2<<12))

// @ref UART_HwFlowCtl_define
#define UART_HwFlowCtl_NONE			((uint32)(0))
#define UART_HwFlowCtl_RTS			((uint32)(1UL<<8))
#define UART_HwFlowCtl_CTS			((uint32)(1UL<<9))
#define UART_HwFlowCtl_RTS_CTS		((uint32)(1UL<<8 | 1UL<<9))

// @ref UART_IRQ_Enable_define
#define UART_IRQ_Enable_NONE		((uint32)(0))
#define UART_IRQ_Enable_TXE			((uint32)(1UL<<7)) // Transmit data register empty
#define UART_IRQ_Enable_TC			((uint32)(1UL<<6)) // Transmission complete
#define UART_IRQ_Enable_RXNE		((uint32)(1UL<<5)) // Received data ready to be read & Overrun error detected
#define UART_IRQ_Enable_PE			((uint32)(1UL<<8)) // Parity error

/*
 * =============================================
 * APIs Supported by "USART"
 * =============================================
 */

/**=============================================
  * @Fn				- MCAL_USART_Init
  * @brief 			- Initializes UART (Supported feature Asynchronous only)
  * @param [in] 	- USARTx: Pointer to the USART peripheral instance, where x can be (1..3 depending on device used)
  * @param [in] 	- USART_cfg: Pointer to the UART configuration
  * @retval 		- None
  * Note			- Support for now asynchronous mode and clock 8MHZ
  */
void MCAL_USART_Init(USART_TypeDef* USARTx, USART_cfg_t* USART_cfg);

/**=============================================
  * @Fn				- MCAL_USART_DeInit
  * @brief 			- DeInitializes UART (Supported feature Asynchronous only)
  * @param [in] 	- USARTx: Pointer to the USART peripheral instance, where x can be (1..3 depending on device used)
  * @retval 		- None
  * Note			- Reset the model by RCC
  */
void MCAL_USART_DeInit(USART_TypeDef* USARTx);

/**=============================================
  * @Fn				- MCAL_USART_GPIO_Set_Pins
  * @brief 			- Initializes GPIO pins
  * @param [in] 	- USARTx: Pointer to the USART peripheral instance, where x can be (1..3 depending on device used)
  * @retval 		- None
  * Note			- Should enable the corresponding ALT & GPIO in RCC clock, called after MCAL_UART_Init()
  */
void MCAL_USART_GPIO_Set_Pins(USART_TypeDef* USARTx);

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
void MCAL_USART_SendData(USART_TypeDef* USARTx, uint16 *pTxBuffer, Polling_Mechanism PollingEn);

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
void MCAL_USART_ReceiveData(USART_TypeDef* USARTx, uint16 *pRxBuffer, Polling_Mechanism PollingEn);

/**=============================================
  * @Fn				- MCAL_USART_Wait_TC
  * @brief 			- Waits until transmission is completed by polling on TC flag
  * @param [in] 	- USARTx: Pointer to the USART peripheral instance, where x can be (1..3 depending on device used)
  * @retval 		- None
  * Note			- None
  */
void MCAL_USART_Wait_TC(USART_TypeDef* USARTx);

// TODO MCAL_USART_LIN_Init();
// TODO MCAL_USART_Init();
// TODO MCAL_USART_DMA_Init();

#endif /* INC_USART_DRIVER_H_ */
