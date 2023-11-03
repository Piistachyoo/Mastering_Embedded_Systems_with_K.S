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
#define CRC_BASE	0x40023000UL

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

		/* I2C */
#define I2C1_BASE	0x40005400UL
#define I2C2_BASE	0x40005800UL

		/* DAC */
#define DAC_BASE	0x40007400UL

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

		/* I2C */
typedef struct{
	vuint32_t CR1;
	vuint32_t CR2;
	vuint32_t OAR1;
	vuint32_t OAR2;
	vuint32_t DR;
	vuint32_t SR1;
	vuint32_t SR2;
	vuint32_t CCR;
	vuint32_t TRISE;
}I2C_TypeDef;

		/* DAC */
typedef struct{
	vuint32_t CR;
	vuint32_t SWTRIGR;
	vuint32_t DHR12R1;
	vuint32_t DHR12L1;
	vuint32_t DHR8R1;
	vuint32_t DHR12R2;
	vuint32_t DHR12L2;
	vuint32_t DHR8R2;
	vuint32_t DOR1;
	vuint32_t DOR2;
}DAC_TypeDef;

		/* CRC */
typedef struct{
	vuint32_t DR;
	vuint32_t IDR;
	vuint32_t CR;
}CRC_TypeDef;

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

#define I2C1		((I2C_TypeDef*)I2C1_BASE)
#define I2C2		((I2C_TypeDef*)I2C2_BASE)

#define DAC			((DAC_TypeDef*)DAC_BASE)

#define CRC			((CRC_TypeDef*)CRC_BASE)

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Bit definition
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */

#endif /* INC_STM32F103X8_H_ */
