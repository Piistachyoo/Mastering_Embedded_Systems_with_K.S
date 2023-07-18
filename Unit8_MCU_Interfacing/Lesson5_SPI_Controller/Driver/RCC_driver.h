/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : RCC_driver.h 			                             */
/* Date          : Jul 4, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_RCC_DRIVER_H_
#define INC_RCC_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "STM32F103x8.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

#define HSI_RC_CLK		8000000UL
#define HSE_CLK			8000000UL

// @ref RCC_CLOCK_SOURCE_define
#define RCC_SELECT_HSI	(uint8)0x00
#define RCC_SELECT_HSE	(uint8)0x01
#define RCC_SELECT_PLL	(uint8)0x02

// @ref RCC_PERIPHERALS_define
#define RCC_GPIOA		(uint8)0x00
#define RCC_GPIOB		(uint8)0x01
#define RCC_GPIOC		(uint8)0x02
#define RCC_GPIOD		(uint8)0x03
#define RCC_GPIOE		(uint8)0x04
#define RCC_GPIOF		(uint8)0x05
#define RCC_GPIOG		(uint8)0x06
#define RCC_AFIO		(uint8)0x07
#define RCC_USART1		(uint8)0x08
#define RCC_USART2		(uint8)0x09
#define RCC_USART3		(uint8)0x0A
#define RCC_SPI1		(uint8)0x0B
#define RCC_SPI2		(uint8)0x0C

/*
 * =============================================
 * APIs Supported by "RCC"
 * =============================================
 */

/**=============================================
  * @Fn				- MCAL_RCC_Select_Clock
  * @brief 			- Sets the clock source of the MCU
  * @param [in] 	- clock: Select the clock source from @ref RCC_CLOCK_SOURCE_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_RCC_Select_Clock(uint8 clock);

/**=============================================
  * @Fn				- MCAL_RCC_Enable_Peripheral
  * @brief 			- Enable the clock for a specific peripheral
  * @param [in] 	- peripheral: Select the peripheral from @ref RCC_PERIPHERALS_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_RCC_Enable_Peripheral(uint8 peripheral);

/**=============================================
  * @Fn				- MCAL_RCC_Reset_Peripheral
  * @brief 			- Resets a specific peripheral
  * @param [in] 	- peripheral: Select the peripheral from @ref RCC_PERIPHERALS_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_RCC_Reset_Peripheral(uint8 peripheral);

/**=============================================
  * @Fn				- MCAL_RCC_GetSYS_CLKFreq
  * @brief 			- Gets the frequency of the system clock in HZ
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Frequency of the system clock
  * Note			- None
  */
uint32 MCAL_RCC_GetSYS_CLKFreq(void);

/**=============================================
  * @Fn				- MCAL_RCC_GetHCLKFreq
  * @brief 			- Gets the frequency of the AHB bus clock in HZ
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Frequency of the AHB bus clock
  * Note			- None
  */
uint32 MCAL_RCC_GetHCLKFreq(void);

/**=============================================
  * @Fn				- MCAL_RCC_GetPCLK1Freq
  * @brief 			- Gets the frequency of the APB1 bus clock in HZ
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Frequency of the APB1 bus clock
  * Note			- None
  */
uint32 MCAL_RCC_GetPCLK1Freq(void);

/**=============================================
  * @Fn				- MCAL_RCC_GetPCLK1Freq
  * @brief 			- Gets the frequency of the APB2 bus clock in HZ
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Frequency of the APB2 bus clock
  * Note			- None
  */
uint32 MCAL_RCC_GetPCLK2Freq(void);

#endif /* INC_RCC_DRIVER_H_ */
