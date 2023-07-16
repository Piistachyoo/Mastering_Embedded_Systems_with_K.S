/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : main.c                           				 	 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "USART_driver.h"

volatile uint32 stk_timer = 1;
volatile uint8 stk_flag = 0;


void clock_init();

int main(void)
{
	USART_cfg_t myUART1;
	uint16 temp;
	myUART1.BaudRate = UART_BaudRate_9600;
	myUART1.HwFlowCtl = UART_HwFlowCtl_NONE;
	myUART1.IRQ_Enable = UART_IRQ_Enable_NONE;
	myUART1.Parity = UART_Parity_NONE;
	myUART1.Payload_Length = UART_Payload_Length_8B;
	myUART1.StopBits = UART_StopBits_1;
	myUART1.USART_Mode = UART_Mode_TX_RX;
	MCAL_USART_Init(USART1, &myUART1);

	uint8 *welcome_string = (uint8*)"Learn in depth!\n\rTesting UART\n\r------------\n\n\r";

	while(*welcome_string){
		MCAL_USART_SendData(USART1, (uint16*)welcome_string, enable);
		welcome_string++;
	}
	while(1){
		MCAL_USART_ReceiveData(USART1, &temp, enable);
		MCAL_USART_SendData(USART1, &temp, enable);

	}
}

void clock_init(){

	MCAL_RCC_Select_Clock(RCC_SELECT_HSE);
/*	MCAL_RCC_Enable_Peripheral(RCC_GPIOA);
	MCAL_RCC_Enable_Peripheral(RCC_GPIOB);
	MCAL_RCC_Enable_Peripheral(RCC_GPIOC);
	MCAL_RCC_Enable_Peripheral(RCC_AFIO);
	MCAL_RCC_Enable_Peripheral(RCC_USART1);*/
}

