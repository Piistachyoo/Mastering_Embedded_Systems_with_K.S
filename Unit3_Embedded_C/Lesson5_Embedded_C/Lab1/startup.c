/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : startup_cortexM3.c         	                 		 */
/* Date          : May 27, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "Platform_Types.h"

extern int main(void);
void Default_Handler();
void Reset_Handler();
void NMI_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void H_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void MM_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void Bus_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void Usage_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void SVCall_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void Debug_Mon_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void PendSV_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void SysTick_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void Window_WD_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void PVD_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void Tamper_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void RTC_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void Flash_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void RCC_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void EXTI0_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void EXTI1_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void EXTI2_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void EXTI3_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void EXTI4_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA_CH1_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA_CH2_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA_CH3_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA_CH4_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA_CH5_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA_CH6_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA_CH7_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void ADC1_2_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void CAN1_TX_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void CAN1_RX0_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void CAN1_RX1_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void CAN1_SCE_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void EXTI9_5_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_BRK_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_UP_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_TRG_COM_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_CC_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void TIM2_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void TIM3_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void TIM4_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void I2C1_EV_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void I2C1_ER_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void I2C2_EV_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void I2C2_ER_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void SPI1_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void SPI2_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void USART1_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void USART2_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void USART3_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void EXTI15_10_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void RTCAlarm_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void OTG_FS_WKUP_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void TIM5_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void SPI3_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void UART4_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void UART5_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void TIM6_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void TIM7_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Channel1_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Channel2_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Channel3_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Channel4_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Channel5_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void ETH_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void ETH_WKUP() __attribute__ ((weak, alias ("Default_Handler")));
void CAN2_TX_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void CAN2_RX0_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void CAN2_RX1_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void CAN2_SCE_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void OTG_FS_Handler() __attribute__ ((weak, alias ("Default_Handler")));

extern uint32 _stack_top;
extern uint32 _E_text;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;

uint32 vectors[] __attribute__((section(".vectors"))) = {
	(uint32) &_stack_top,			/* Stack Top Address */
	(uint32) &Reset_Handler,		/* -3 Reset */
	(uint32) &NMI_Handler,			/* -2 NMI */
	(uint32) &H_Fault_Handler,		/* -1 Hard Fault */
	(uint32) &MM_Fault_Handler,		/* 0 MM Fault */
	(uint32) &Bus_Fault_Handler,	/* 1 Bus Fault */
	(uint32) &Usage_Fault_Handler,	/* 2 Usage Fault */
	(uint32) 0,						/* Reserved */
	(uint32) 0,						/* Reserved */
	(uint32) 0,						/* Reserved */
	(uint32) 0,						/* Reserved */
	(uint32) &SVCall_Handler,		/* 3 SVCall */
	(uint32) &Debug_Mon_Handler,	/* 4 Debug Monitor */
	(uint32) 0,						/* Reserved */
	(uint32) &PendSV_Handler,		/* 5 Pendable request for system service */
	(uint32) &SysTick_Handler,		/* 6 System Tick Timer */
	(uint32) &Window_WD_Handler,	/* 7 Window Watchdog interrupt */
	(uint32) &PVD_Handler,			/* 8 PVD through EXTI Line detection interrupt */
	(uint32) &Tamper_Handler,		/* 9 Tamper interrupt */
	(uint32) &RTC_Handler,			/* 10 RTC global interrupt */
	(uint32) &Flash_Handler,		/* 11 Flash global interrupt */
	(uint32) &RCC_Handler,			/* 12 RCC global interrupt */
	(uint32) &EXTI0_Handler,		/* 13 EXTI Line0 interrupt */
	(uint32) &EXTI1_Handler,		/* 14 EXTI Line1 interrupt */
	(uint32) &EXTI2_Handler,		/* 15 EXTI Line2 interrupt */
	(uint32) &EXTI3_Handler,		/* 16 EXTI Line3 interrupt */
	(uint32) &EXTI4_Handler,		/* 17 EXTI Line4 interrupt */
	(uint32) &DMA_CH1_Handler,		/* 18 DMA1 Channel1 global interrupt */
	(uint32) &DMA_CH2_Handler,		/* 19 DMA1 Channel2 global interrupt */
	(uint32) &DMA_CH3_Handler,		/* 20 DMA1 Channel3 global interrupt */
	(uint32) &DMA_CH4_Handler,		/* 21 DMA1 Channel4 global interrupt */
	(uint32) &DMA_CH5_Handler,		/* 22 DMA1 Channel5 global interrupt */
	(uint32) &DMA_CH6_Handler,		/* 23 DMA1 Channel6 global interrupt */
	(uint32) &DMA_CH7_Handler,		/* 24 DMA1 Channel7 global interrupt */
	(uint32) &ADC1_2_Handler,		/* 25 ADC1 and ADC2 global interrupt */
	(uint32) &CAN1_TX_Handler,		/* 26 CAN1 TX interrupts */
	(uint32) &CAN1_RX0_Handler,		/* 27 CAN1 RX0 interrupts */
	(uint32) &CAN1_RX1_Handler,		/* 28 CAN1 RX1 interrupts */
	(uint32) &CAN1_SCE_Handler,		/* 29 CAN1 SCE interrupts */
	(uint32) &EXTI9_5_Handler,		/* 30 EXTI Line[9:5] interrupts */
	(uint32) &TIM1_BRK_Handler,		/* 31 TIM1 Break interrupt */
	(uint32) &TIM1_UP_Handler,		/* 32 TIM1 Update interrupt */
	(uint32) &TIM1_TRG_COM_Handler,	/* 33 TIM1 Trigger and Commutation interrupts */
	(uint32) &TIM1_CC_Handler,		/* 34 TIM1 Capture Compare interrupt */
	(uint32) &TIM2_Handler,			/* 35 TIM2 global interrupt */
	(uint32) &TIM3_Handler,			/* 36 TIM3 global interrupt */
	(uint32) &TIM4_Handler,			/* 37 TIM4 global interrupt */
	(uint32) &I2C1_EV_Handler,		/* 38 I2C1 event interrupt */
	(uint32) &I2C1_ER_Handler,		/* 39 I2C1 error interrupt */
	(uint32) &I2C2_EV_Handler,		/* 40 I2C2 event interrupt */
	(uint32) &I2C2_ER_Handler,		/* 41 I2C2 error interrupt */
	(uint32) &SPI1_Handler,			/* 42 SPI1 global interrupt */
	(uint32) &SPI2_Handler,			/* 43 SPI2 global interrupt */
	(uint32) &USART1_Handler,		/* 44 USART1 global interrupt */
	(uint32) &USART2_Handler,		/* 45 USART2 global interrupt */
	(uint32) &USART3_Handler,		/* 46 USART3 global interrupt */
	(uint32) &EXTI15_10_Handler,	/* 47 EXTI Line[15:10] interrupts */
	(uint32) &RTCAlarm_Handler,		/* 48 RTC alarm through EXTI line interrupt */
	(uint32) &OTG_FS_WKUP_Handler,	/* 49 USB On-The-Go FS Wakeup through EXTI line interrupt */
	(uint32) 0,						/* Reserved */
	(uint32) 0,						/* Reserved */
	(uint32) 0,						/* Reserved */
	(uint32) 0,						/* Reserved */
	(uint32) 0,						/* Reserved */
	(uint32) 0,						/* Reserved */
	(uint32) 0,						/* Reserved */
	(uint32) &TIM5_Handler,			/* 57 TIM5 global interrupt */
	(uint32) &SPI3_Handler,			/* 58 SPI3 global interrupt */
	(uint32) &UART4_Handler,		/* 59 UART4 global interrupt */
	(uint32) &UART5_Handler,		/* 60 UART5 global interrupt */
	(uint32) &TIM6_Handler,			/* 61 TIM6 global interrupt */
	(uint32) &TIM7_Handler,			/* 62 TIM7 global interrupt */
	(uint32) &DMA2_Channel1_Handler,/* 63 DMA2 Channel1 global interrupt */
	(uint32) &DMA2_Channel2_Handler,/* 64 DMA2 Channel2 global interrupt */
	(uint32) &DMA2_Channel3_Handler,/* 65 DMA2 Channel3 global interrupt */
	(uint32) &DMA2_Channel4_Handler,/* 66 DMA2 Channel4 global interrupt */
	(uint32) &DMA2_Channel5_Handler,/* 67 DMA2 Channel5 global interrupt */
	(uint32) &ETH_Handler,			/* 68 Ethernet global interrupt */
	(uint32) &ETH_WKUP,				/* 69 Ethernet Wakeup through EXTI line interrupt */
	(uint32) &CAN2_TX_Handler,		/* 70 CAN2 TX interrupts */
	(uint32) &CAN2_RX0_Handler,		/* 71 CAN2 RX0 interrupts */
	(uint32) &CAN2_RX1_Handler,		/* 72 CAN2 RX1 interrupts */
	(uint32) &CAN2_SCE_Handler,		/* 73 CAN2 SCE interrupts */
	(uint32) &OTG_FS_Handler,		/* 74 USB On The Go FS global interrupt */
};

void Reset_Handler(){
	/* Copy .data from flash to sram */
	uint32 DATA_size = (uint8*)(&_E_DATA) - (uint8*)(&_S_DATA);
	uint8* P_SRC = (uint8*)(&_E_text);
	uint8* P_DST = (uint8*)(&_S_DATA);
	for(int i=0; i<DATA_size; i++, P_DST++, P_SRC++){
		*(uint8*)P_DST = *(uint8*)P_SRC;
	}
	
	/* init .BSS in sram = 0 */
	uint32 bss_size = (uint8*)(&_E_BSS) - (uint8*)(&_S_BSS);
	P_DST = (uint8*)(&_S_BSS);
	for(int i=0; i<bss_size; i++, P_DST){
		*(uint8*)P_DST = (uint8)0;
	}
	
	/* Jump to main() */
	main();
}

void Default_Handler(){
	Reset_Handler();
}
