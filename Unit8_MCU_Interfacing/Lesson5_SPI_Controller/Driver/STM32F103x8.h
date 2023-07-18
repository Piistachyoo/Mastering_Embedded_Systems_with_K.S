/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : STM32F103x8.h 			                             */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_STM32F103X8_H_
#define INC_STM32F103X8_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include <stdlib.h>
#include "Platform_Types.h"

//----------------------------------------------
// Section: Base addresses for Memories
//----------------------------------------------

#define FLASH_MEMORY_BASE					0x08000000UL
#define SYSTEM_MEMORY_BASE					0x1FFFF000UL
#define SRAM_MEMORY_BASE					0x20000000UL
#define PERIPHERALS_BASE					0x40000000UL
#define Cortex_M3_Internal_Peripherals_Base	0xE0000000UL


//----------------------------------------------
// Section: Base addresses for Cortex-M3 Peripherals
//----------------------------------------------

#define NVIC_BASE							0xE000E100UL
#define SCB_BASE							0xE000ED00UL
#define STK_BASE							0xE000E010UL


//----------------------------------------------
// Section: Base addresses for AHB Peripherals
//----------------------------------------------

	/* RCC: */
#define RCC_BASE	0x40021000UL

//----------------------------------------------
// Section: Base addresses for APB2 Peripherals
//----------------------------------------------

	/* GPIO:
	 * Ports A, B fully included in LQFP48 Package
	 * Ports C, D Partially included in LQFP48 Package
	 * Ports E, F, G not included in LQFP48 Package    */
#define GPIOA_BASE	0x40010800UL
#define GPIOB_BASE	0x40010C00UL
#define GPIOC_BASE	0x40011000UL
#define GPIOD_BASE	0x40011400UL
#define GPIOE_BASE	0x40011800UL
#define GPIOF_BASE	0x40011C00UL
#define GPIOG_BASE	0x40012000UL

		/* EXTI: */
#define EXTI_BASE	0x40010400UL

		/* AFIO */
#define AFIO_BASE	0x40010000UL

		/* USART */
#define USART1_BASE	0x40013800UL

		/* SPI */
#define SPI1_BASE	0x40013000UL

//----------------------------------------------
// Section: Base addresses for APB1 Peripherals
//----------------------------------------------

		/* USART */
#define USART2_BASE	0x40004400UL
#define USART3_BASE	0x40004800UL

		/* SPI */
#define SPI2_BASE	0x40003800UL

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

		/* NVIC */
typedef struct{
	vuint32_t ISER[3];
	uint32 RESERVED0[29];
	vuint32_t ICER[3];
	uint32 RESERVED1[29];
	vuint32_t ISPR[3];
	uint32 RESERVED2[29];
	vuint32_t ICPR[3];
	uint32 RESERVED3[29];
	vuint32_t IABR[3];
	uint32 RESERVED4[61];
	vuint8_t IP[80];
	uint32 RESERVED5[684];
	vuint32_t STIR;
}NVIC_TypeDef;

		/* SCB */
typedef struct{
	vuint32_t CPUID;
	vuint32_t ICSR;
	vuint32_t VTOR;
	vuint32_t AIRCR;
	vuint32_t SCR;
	vuint32_t CCR;
	vuint8_t  SHP[12];
	vuint32_t SHCSR;
	vuint32_t CFSR;
	vuint32_t HFSR;
	uint32	  RESERVED;
	vuint32_t MMAR;
	vuint32_t BFAR;
}SCB_TypeDef;

		/* STK */
typedef struct{
	vuint32_t CTRL;
	vuint32_t LOAD;
	vuint32_t VAL;
	vuint32_t CALIB;
}STK_TypeDef;

		/* GPIO */
typedef struct{
	vuint32_t CRL;
	vuint32_t CRH;
	vuint32_t IDR;
	vuint32_t ODR;
	vuint32_t BSRR;
	vuint32_t BRR;
	vuint32_t LCKR;
}GPIO_TypeDef;

		/* RCC */
typedef struct{
	vuint32_t CR;
	vuint32_t CFGR;
	vuint32_t CIR;
	vuint32_t APB2RSTR;
	vuint32_t APB1RSTR;
	vuint32_t AHBENR;
	vuint32_t APB2ENR;
	vuint32_t APB1ENR;
	vuint32_t BDCR;
	vuint32_t CSR;
}RCC_TypeDef;

		/* EXTI */
typedef struct{
	vuint32_t IMR;
	vuint32_t EMR;
	vuint32_t RTSR;
	vuint32_t FTSR;
	vuint32_t SWIER;
	vuint32_t PR;
}EXTI_TypeDef;

		/* AFIO */
typedef struct{
	vuint32_t EVCR;
	vuint32_t MAPR;
	vuint32_t EXTICR[4];
	uint32	  RESERVED0;
	vuint32_t MAPR2;
}AFIO_TypeDef;

		/* USART */
typedef struct{
	vuint32_t SR;
	vuint32_t DR;
	vuint32_t BRR;
	vuint32_t CR1;
	vuint32_t CR2;
	vuint32_t CR3;
	vuint32_t GTPR;
}USART_TypeDef;

		/* SPI */
typedef struct{
	vuint32_t CR1;
	vuint32_t CR2;
	vuint32_t SR;
	vuint32_t DR;
	vuint32_t CRCPR;
	vuint32_t RXCRCR;
	vuint32_t TXCRCR;
	vuint32_t I2SCFGR;
	vuint32_t I2SPR;
}SPI_TypeDef;

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Peripheral instants
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define NVIC		((NVIC_TypeDef*)NVIC_BASE)
#define SCB			((SCB_TypeDef* )SCB_BASE )
#define STK			((STK_TypeDef* )STK_BASE )

#define GPIOA		((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB		((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC		((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD		((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE		((GPIO_TypeDef*)GPIOE_BASE)
#define GPIOF		((GPIO_TypeDef*)GPIOF_BASE)
#define GPIOG		((GPIO_TypeDef*)GPIOG_BASE)

#define RCC			((RCC_TypeDef*)RCC_BASE)

#define EXTI		((EXTI_TypeDef*)EXTI_BASE)

#define AFIO		((AFIO_TypeDef*)AFIO_BASE)

#define USART1		((USART_TypeDef*)USART1_BASE)
#define USART2		((USART_TypeDef*)USART2_BASE)
#define USART3		((USART_TypeDef*)USART3_BASE)

#define SPI1		((SPI_TypeDef*)SPI1_BASE)
#define SPI2		((SPI_TypeDef*)SPI2_BASE)

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Generic macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#endif /* INC_STM32F103X8_H_ */
