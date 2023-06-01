/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Pressure_Detection                                    */
/* File          : startup.c 	    			                         */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

/* Startup Code for STM32F103C8T6 based on Cortex-M3 */

void main(void);
void Reset_Handler(void);
void DefaultInterruptHandler(void);

extern unsigned long _S_stack;
extern unsigned long _E_text;
extern unsigned long _S_data;
extern unsigned long _E_data;
extern unsigned long _S_bss;
extern unsigned long _E_bss;

void NMI_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void H_Fault_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void MM_Fault_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void Bus_Fault_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void Usage_Fault_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void SVCall_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void Debug_Mon_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void PendSV_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void SysTick_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void Window_WD_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void PVD_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void Tamper_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void RTC_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void Flash_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void RCC_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void EXTI0_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void EXTI1_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void EXTI2_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void EXTI3_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void EXTI4_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA_CH1_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA_CH2_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA_CH3_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA_CH4_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA_CH5_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA_CH6_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA_CH7_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void ADC1_2_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void CAN1_TX_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void CAN1_RX0_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void CAN1_RX1_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void CAN1_SCE_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void EXTI9_5_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void TIM1_BRK_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void TIM1_UP_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void TIM1_TRG_COM_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void TIM1_CC_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void TIM2_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void TIM3_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void TIM4_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void I2C1_EV_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void I2C1_ER_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void I2C2_EV_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void I2C2_ER_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void SPI1_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void SPI2_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void USART1_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void USART2_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void USART3_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void EXTI15_10_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void RTCAlarm_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void OTG_FS_WKUP_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void TIM5_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void SPI3_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void UART4_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void UART5_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void TIM6_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void TIM7_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA2_Channel1_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA2_Channel2_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA2_Channel3_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA2_Channel4_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void DMA2_Channel5_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void ETH_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void ETH_WKUP() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void CAN2_TX_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void CAN2_RX0_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void CAN2_RX1_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void CAN2_SCE_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));
void OTG_FS_Handler() __attribute__ ((weak, alias ("DefaultInterruptHandler")));

unsigned long vector_table[] __attribute__((section(".vector_table"))) = {
	(unsigned long)	&_S_stack, 				/* Stack Top Address */
	(unsigned long)	&Reset_Handler,			/* -3 Reset */
	(unsigned long) &NMI_Handler,			/* -2 NMI */
	(unsigned long) &H_Fault_Handler,		/* -1 Hard Fault */
	(unsigned long) &MM_Fault_Handler,		/* 0 MM Fault */
	(unsigned long) &Bus_Fault_Handler,		/* 1 Bus Fault */
	(unsigned long) &Usage_Fault_Handler,	/* 2 Usage Fault */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) &SVCall_Handler,		/* 3 SVCall */
	(unsigned long) &Debug_Mon_Handler,		/* 4 Debug Monitor */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) &PendSV_Handler,		/* 5 Pendable request for system service */
	(unsigned long) &SysTick_Handler,		/* 6 System Tick Timer */
	(unsigned long) &Window_WD_Handler,		/* 7 Window Watchdog interrupt */
	(unsigned long) &PVD_Handler,			/* 8 PVD through EXTI Line detection interrupt */
	(unsigned long) &Tamper_Handler,		/* 9 Tamper interrupt */
	(unsigned long) &RTC_Handler,			/* 10 RTC global interrupt */
	(unsigned long) &Flash_Handler,			/* 11 Flash global interrupt */
	(unsigned long) &RCC_Handler,			/* 12 RCC global interrupt */
	(unsigned long) &EXTI0_Handler,			/* 13 EXTI Line0 interrupt */
	(unsigned long) &EXTI1_Handler,			/* 14 EXTI Line1 interrupt */
	(unsigned long) &EXTI2_Handler,			/* 15 EXTI Line2 interrupt */
	(unsigned long) &EXTI3_Handler,			/* 16 EXTI Line3 interrupt */
	(unsigned long) &EXTI4_Handler,			/* 17 EXTI Line4 interrupt */
	(unsigned long) &DMA_CH1_Handler,		/* 18 DMA1 Channel1 global interrupt */
	(unsigned long) &DMA_CH2_Handler,		/* 19 DMA1 Channel2 global interrupt */
	(unsigned long) &DMA_CH3_Handler,		/* 20 DMA1 Channel3 global interrupt */
	(unsigned long) &DMA_CH4_Handler,		/* 21 DMA1 Channel4 global interrupt */
	(unsigned long) &DMA_CH5_Handler,		/* 22 DMA1 Channel5 global interrupt */
	(unsigned long) &DMA_CH6_Handler,		/* 23 DMA1 Channel6 global interrupt */
	(unsigned long) &DMA_CH7_Handler,		/* 24 DMA1 Channel7 global interrupt */
	(unsigned long) &ADC1_2_Handler,		/* 25 ADC1 and ADC2 global interrupt */
	(unsigned long) &CAN1_TX_Handler,		/* 26 CAN1 TX interrupts */
	(unsigned long) &CAN1_RX0_Handler,		/* 27 CAN1 RX0 interrupts */
	(unsigned long) &CAN1_RX1_Handler,		/* 28 CAN1 RX1 interrupts */
	(unsigned long) &CAN1_SCE_Handler,		/* 29 CAN1 SCE interrupts */
	(unsigned long) &EXTI9_5_Handler,		/* 30 EXTI Line[9:5] interrupts */
	(unsigned long) &TIM1_BRK_Handler,		/* 31 TIM1 Break interrupt */
	(unsigned long) &TIM1_UP_Handler,		/* 32 TIM1 Update interrupt */
	(unsigned long) &TIM1_TRG_COM_Handler,	/* 33 TIM1 Trigger and Commutation interrupts */
	(unsigned long) &TIM1_CC_Handler,		/* 34 TIM1 Capture Compare interrupt */
	(unsigned long) &TIM2_Handler,			/* 35 TIM2 global interrupt */
	(unsigned long) &TIM3_Handler,			/* 36 TIM3 global interrupt */
	(unsigned long) &TIM4_Handler,			/* 37 TIM4 global interrupt */
	(unsigned long) &I2C1_EV_Handler,		/* 38 I2C1 event interrupt */
	(unsigned long) &I2C1_ER_Handler,		/* 39 I2C1 error interrupt */
	(unsigned long) &I2C2_EV_Handler,		/* 40 I2C2 event interrupt */
	(unsigned long) &I2C2_ER_Handler,		/* 41 I2C2 error interrupt */
	(unsigned long) &SPI1_Handler,			/* 42 SPI1 global interrupt */
	(unsigned long) &SPI2_Handler,			/* 43 SPI2 global interrupt */
	(unsigned long) &USART1_Handler,		/* 44 USART1 global interrupt */
	(unsigned long) &USART2_Handler,		/* 45 USART2 global interrupt */
	(unsigned long) &USART3_Handler,		/* 46 USART3 global interrupt */
	(unsigned long) &EXTI15_10_Handler,		/* 47 EXTI Line[15:10] interrupts */
	(unsigned long) &RTCAlarm_Handler,		/* 48 RTC alarm through EXTI line interrupt */
	(unsigned long) &OTG_FS_WKUP_Handler,	/* 49 USB On-The-Go FS Wakeup through EXTI line interrupt */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) 0,						/* Reserved */
	(unsigned long) &TIM5_Handler,			/* 57 TIM5 global interrupt */
	(unsigned long) &SPI3_Handler,			/* 58 SPI3 global interrupt */
	(unsigned long) &UART4_Handler,			/* 59 UART4 global interrupt */
	(unsigned long) &UART5_Handler,			/* 60 UART5 global interrupt */
	(unsigned long) &TIM6_Handler,			/* 61 TIM6 global interrupt */
	(unsigned long) &TIM7_Handler,			/* 62 TIM7 global interrupt */
	(unsigned long) &DMA2_Channel1_Handler,	/* 63 DMA2 Channel1 global interrupt */
	(unsigned long) &DMA2_Channel2_Handler,	/* 64 DMA2 Channel2 global interrupt */
	(unsigned long) &DMA2_Channel3_Handler,	/* 65 DMA2 Channel3 global interrupt */
	(unsigned long) &DMA2_Channel4_Handler,	/* 66 DMA2 Channel4 global interrupt */
	(unsigned long) &DMA2_Channel5_Handler,	/* 67 DMA2 Channel5 global interrupt */
	(unsigned long) &ETH_Handler,			/* 68 Ethernet global interrupt */
	(unsigned long) &ETH_WKUP,				/* 69 Ethernet Wakeup through EXTI line interrupt */
	(unsigned long) &CAN2_TX_Handler,		/* 70 CAN2 TX interrupts */
	(unsigned long) &CAN2_RX0_Handler,		/* 71 CAN2 RX0 interrupts */
	(unsigned long) &CAN2_RX1_Handler,		/* 72 CAN2 RX1 interrupts */
	(unsigned long) &CAN2_SCE_Handler,		/* 73 CAN2 SCE interrupts */
	(unsigned long) &OTG_FS_Handler			/* 74 USB On The Go FS global interrupt */
};

void Reset_Handler(void){
	unsigned char *pSource, *pDestination;
	int i;
	unsigned int Data_Size = (unsigned char*)&_E_data - (unsigned char*)&_E_data;

	/* Copy .Data from FLASH to SRAM */
	pSource = (unsigned char*)&_E_text;
	pDestination = (unsigned char*)&_S_data;
	for(i = 0; i < Data_Size; i++){
		*(unsigned char*)pDestination++ = *(unsigned char*)pSource++;
	}

	/* Initialize .bss section in SRAM */
	Data_Size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	pDestination = (unsigned char*)&_S_bss;
	for(i = 0; i < Data_Size; i++){
		*(unsigned char*)pDestination = 0;
	}

	/* Call main function */
	for(;;){
		main();
	}
}

void DefaultInterruptHandler(void){
	/* Reset MCU */
	Reset_Handler();
}
