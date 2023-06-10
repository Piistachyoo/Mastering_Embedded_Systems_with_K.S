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
#define NVIC_BASE							0xE000E100UL

//----------------------------------------------
// Section: Base addresses for Cortex-M3 Peripherals
//----------------------------------------------

	/* NVIC: */
#define NVIC_ISER0			(*(vuint32_t*)(NVIC_BASE))
#define NVIC_ISER1			(*(vuint32_t*)(NVIC_BASE + 0x004))
#define NVIC_ISER2			(*(vuint32_t*)(NVIC_BASE + 0x008))
#define NVIC_ICER0			(*(vuint32_t*)(NVIC_BASE + 0x080))
#define NVIC_ICER1			(*(vuint32_t*)(NVIC_BASE + 0x084))
#define NVIC_ICER2			(*(vuint32_t*)(NVIC_BASE + 0x088))
#define NVIC_ISPR0			(*(vuint32_t*)(NVIC_BASE + 0x100))
#define NVIC_ISPR1			(*(vuint32_t*)(NVIC_BASE + 0x104))
#define NVIC_ISPR2			(*(vuint32_t*)(NVIC_BASE + 0x108))
#define NVIC_ICPR0			(*(vuint32_t*)(NVIC_BASE + 0x180))
#define NVIC_ICPR1			(*(vuint32_t*)(NVIC_BASE + 0x184))
#define NVIC_ICPR2			(*(vuint32_t*)(NVIC_BASE + 0x188))
#define NVIC_IABR0			(*(vuint32_t*)(NVIC_BASE + 0x200))
#define NVIC_IABR1			(*(vuint32_t*)(NVIC_BASE + 0x204))
#define NVIC_IABR2			(*(vuint32_t*)(NVIC_BASE + 0x208))
#define NVIC_IPR0			(*(vuint32_t*)(NVIC_BASE + 0x300))
#define NVIC_IPR2			(*(vuint32_t*)(NVIC_BASE + 0x320))
#define NVIC_STIR			(*(vuint32_t*)(NVIC_BASE + 0xE00))

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

//----------------------------------------------
// Section: Base addresses for APB1 Peripherals
//----------------------------------------------

//----------------------------------------------
// Section: Interrupt Vector Table
//----------------------------------------------
#define EXTI0_IRQ	6
#define EXTI1_IRQ	7
#define EXTI2_IRQ	8
#define EXTI3_IRQ	9
#define EXTI4_IRQ	10
#define EXTI5_IRQ	23
#define EXTI6_IRQ	23
#define EXTI7_IRQ	23
#define EXTI8_IRQ	23
#define EXTI9_IRQ	23
#define EXTI10_IRQ	40
#define EXTI11_IRQ	40
#define EXTI12_IRQ	40
#define EXTI13_IRQ	40
#define EXTI14_IRQ	40
#define EXTI15_IRQ	40

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

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

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Peripheral instants
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

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

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Clock enable macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define	RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= (1<<2))
#define	RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= (1<<3))
#define	RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= (1<<4))
#define	RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= (1<<5))
#define	RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= (1<<6))
#define	RCC_GPIOF_CLK_EN()	(RCC->APB2ENR |= (1<<7))
#define	RCC_GPIOG_CLK_EN()	(RCC->APB2ENR |= (1<<8))

#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= (1<<0))

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: NVIC IRQ enable/disable Macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define NVIC_IRQ6_EXTI0_Enable()		(NVIC_ISER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Enable()		(NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Enable()		(NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Enable()		(NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Enable()		(NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Enable()		(NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Enable()	(NVIC_ISER1 |= (1<<8))


#define NVIC_IRQ6_EXTI0_Disable()		(NVIC_ICER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Disable()		(NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Disable()		(NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Disable()		(NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Disable()		(NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Disable()	(NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Disable()	(NVIC_ICER1 |= (1<<8))


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Generic macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#endif /* INC_STM32F103X8_H_ */
