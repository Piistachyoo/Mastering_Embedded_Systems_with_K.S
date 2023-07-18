/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : RCC_driver.c 			                             */
/* Date          : Jul 4, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "RCC_driver.h"

/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB low-speed clock
(PCLK1).
Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16*/
static const uint8 APBPrescTable[8] = {0, 0, 0, 0, 1, 2, 3, 4}; // Shift 1 right = 4, shift 2 right = 5, shift 3 right = 6, shift 4 right = 7

/*Bits 7:4 HPRE: AHB prescaler
Set and cleared by software to control the division factor of the AHB clock.
0xxx: SYSCLK not divided
1000: SYSCLK divided by 2
1001: SYSCLK divided by 4
1010: SYSCLK divided by 8
1011: SYSCLK divided by 16
1100: SYSCLK divided by 64
1101: SYSCLK divided by 128
1110: SYSCLK divided by 256
1111: SYSCLK divided by 512*/
static const uint8 AHBPrescTable[16U] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

/**=============================================
  * @Fn				- MCAL_RCC_Select_Clock
  * @brief 			- Sets the clock source of the MCU
  * @param [in] 	- clock: Select the clock source from @ref RCC_CLOCK_SOURCE_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_RCC_Select_Clock(uint8 clock){
	switch(clock){
	case RCC_SELECT_HSI:
		RCC->CR |= (1<<0); 				  			// internal 8 MHz RC oscillator ON
		while(!((RCC->CR >> 1) & 0x01U)); 			// wait until internal clock is ready
		RCC->CFGR &= ~(0b11UL);			  			// 00: HSI selected as system clock
		while(0x00 != ((RCC->CFGR >> 2) & 0x03UL)); // Wait until HSI is the clock source
		RCC->CR &= ~(1UL<<16);						// 0: HSE oscillator OFF
		RCC->CR &= ~(1UL<<24);						// 0: PLL OFF
		break;
	case RCC_SELECT_HSE:
		RCC->CR |= (1<<16); 				  		// 1: HSE oscillator ON
		while(!((RCC->CR >> 17) & 0x01U)); 			// wait until external clock is ready
		RCC->CFGR &= ~(0b11UL);			  			// Clear previous clock selection
		RCC->CFGR |= 0x01UL;						// Set External oscillator HSE as clock source
		while(0x01 != ((RCC->CFGR >> 2) & 0x03UL)); // Wait until HSE is the clock source
		RCC->CR &= ~(1UL<<0);						// 0: internal 8 MHz RC oscillator OFF
		RCC->CR &= ~(1UL<<24);						// 0: PLL OFF
		break;
	case RCC_SELECT_PLL:
		/* TODO: Implement PLL Configuration */
		break;
	default: /* Do Nothing */ break;
	}
}

/**=============================================
  * @Fn				- MCAL_RCC_Enable_Peripheral
  * @brief 			- Enable the clock for a specific peripheral
  * @param [in] 	- peripheral: Select the peripheral from @ref RCC_PERIPHERALS_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_RCC_Enable_Peripheral(uint8 peripheral){
	switch(peripheral){
	case RCC_GPIOA: 	RCC->APB2ENR |= (1<<2);  break;
	case RCC_GPIOB: 	RCC->APB2ENR |= (1<<3);  break;
	case RCC_GPIOC: 	RCC->APB2ENR |= (1<<4);  break;
	case RCC_GPIOD: 	RCC->APB2ENR |= (1<<5);  break;
	case RCC_GPIOE: 	RCC->APB2ENR |= (1<<6);  break;
	case RCC_GPIOF: 	RCC->APB2ENR |= (1<<7);  break;
	case RCC_GPIOG: 	RCC->APB2ENR |= (1<<8);  break;
	case RCC_AFIO:		RCC->APB2ENR |= (1<<0);  break;
	case RCC_USART1:	RCC->APB2ENR |= (1<<14); break;
	case RCC_USART2:	RCC->APB1ENR |= (1<<17); break;
	case RCC_USART3:	RCC->APB1ENR |= (1<<18); break;
	case RCC_SPI1:		RCC->APB2ENR |= (1<<12); break;
	case RCC_SPI2:		RCC->APB1ENR |= (1<<14); break;
	default: /* Do Nothing */ break;
	}
}

/**=============================================
  * @Fn				- MCAL_RCC_Reset_Peripheral
  * @brief 			- Resets a specific peripheral
  * @param [in] 	- peripheral: Select the peripheral from @ref RCC_PERIPHERALS_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_RCC_Reset_Peripheral(uint8 peripheral){
	switch(peripheral){
	case RCC_GPIOA: 	RCC->APB2RSTR |= (1<<2);  break;
	case RCC_GPIOB: 	RCC->APB2RSTR |= (1<<3);  break;
	case RCC_GPIOC: 	RCC->APB2RSTR |= (1<<4);  break;
	case RCC_GPIOD: 	RCC->APB2RSTR |= (1<<5);  break;
	case RCC_GPIOE: 	RCC->APB2RSTR |= (1<<6);  break;
	case RCC_GPIOF: 	RCC->APB2RSTR |= (1<<7);  break;
	case RCC_GPIOG: 	RCC->APB2RSTR |= (1<<8);  break;
	case RCC_AFIO:		RCC->APB2RSTR |= (1<<0);  break;
	case RCC_USART1:	RCC->APB2RSTR |= (1<<14); break;
	case RCC_USART2:	RCC->APB1RSTR |= (1<<17); break;
	case RCC_USART3:	RCC->APB1RSTR |= (1<<18); break;
	case RCC_SPI1:		RCC->APB2RSTR |= (1<<12); break;
	case RCC_SPI2:		RCC->APB1RSTR |= (1<<14); break;
	default: /* Do Nothing */ break;
	}
}

/**=============================================
  * @Fn				- MCAL_RCC_GetSYS_CLKFreq
  * @brief 			- Gets the frequency of the system clock in HZ
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Frequency of the system clock
  * Note			- None
  */
uint32 MCAL_RCC_GetSYS_CLKFreq(void){
/*	Bits 3:2 SWS: System clock switch status
	Set and cleared by hardware to indicate which clock source is used as system clock.
	00: HSI oscillator used as system clock
	01: HSE oscillator used as system clock
	10: PLL used as system clock
	11: not applicable*/
	uint32 ret_val;
	switch((RCC->CFGR >> 2 & 0b11)){
	case 0:
		ret_val = HSI_RC_CLK;
		break;
	case 1:
		ret_val = HSE_CLK;
		break;
	case 2:
		/* TODO: Need to calculate the PLLCLK and PLLMUL and PLL Source MUX */
		ret_val = 16000000UL;
		break;
	default: ret_val = 0; break;
	}
	return ret_val;
}

/**=============================================
  * @Fn				- MCAL_RCC_GetHCLKFreq
  * @brief 			- Gets the frequency of the AHB bus clock in HZ
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Frequency of the AHB bus clock
  * Note			- None
  */
uint32 MCAL_RCC_GetHCLKFreq(void){
	// Bits 7:4 HPRE: AHB prescaler
	return (MCAL_RCC_GetSYS_CLKFreq() >> AHBPrescTable[((RCC->CFGR >> 4) & 0b111)]);
}

/**=============================================
  * @Fn				- MCAL_RCC_GetPCLK1Freq
  * @brief 			- Gets the frequency of the APB1 bus clock in HZ
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Frequency of the APB1 bus clock
  * Note			- None
  */
uint32 MCAL_RCC_GetPCLK1Freq(void){
	// Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	return (MCAL_RCC_GetSYS_CLKFreq() >> APBPrescTable[((RCC->CFGR >> 8) & 0b111)]);
}

/**=============================================
  * @Fn				- MCAL_RCC_GetPCLK1Freq
  * @brief 			- Gets the frequency of the APB2 bus clock in HZ
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- Frequency of the APB2 bus clock
  * Note			- None
  */
uint32 MCAL_RCC_GetPCLK2Freq(void){
	// Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	return (MCAL_RCC_GetSYS_CLKFreq() >> APBPrescTable[((RCC->CFGR >> 11) & 0b111)]);
}
