/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : main.c                           				 	 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "USART_driver.h"
#include "SPI_driver.h"

#define MCU_ACT_AS_MASTER
//#define MCU_ACT_AS_SLAVE

void clock_init();

uint8 temp;

void UART_CALLBACK(void){
#ifdef MCU_ACT_AS_MASTER
	MCAL_USART_ReceiveData(USART1, &temp, disable);
	MCAL_USART_SendData(USART1, &temp, enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	MCAL_SPI_TX_RX(SPI1, &temp, PollingEnable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif
}

int main(void)
{
	USART_cfg_t myUART1;
	myUART1.BaudRate = UART_BaudRate_115200;
	myUART1.HwFlowCtl = UART_HwFlowCtl_NONE;
	myUART1.IRQ_Enable = UART_IRQ_Enable_RXNE;
	myUART1.Parity = UART_Parity_NONE;
	myUART1.Payload_Length = UART_Payload_Length_8B;
	myUART1.StopBits = UART_StopBits_1;
	myUART1.USART_Mode = UART_Mode_TX_RX;
	myUART1.P_IRQ_CallBack = UART_CALLBACK;
	MCAL_USART_Init(USART1, &myUART1);

	SPI_config mySPI1;
	mySPI1.CLKPhase = SPI_CLKPhase_SECOND_EDGE;
	mySPI1.CLKPolarity = SPI_CLKPolarity_HIGH_IDLE;
	mySPI1.DataSize = SPI_DataSize_8BIT;
	mySPI1.Frame_Format = SPI_Frame_Format_MSB_First;
	mySPI1.SPI_BAUDRATEPRESCALER = SPI_BAUDRATEPRESCALER_8;
	mySPI1.Communication_Mode = SPI_DIRECTION_2LINES;

#ifdef MCU_ACT_AS_MASTER
	mySPI1.Device_Mode = SPI_DEVICE_MODE_MASTER;
	mySPI1.IRQ_Enable = SPI_IRQ_ENABLE_NONE;
	mySPI1.P_IRQ_CallBack = NULL;
	mySPI1.NSS = SPI_NSS_SOFTWARE_NSSINTERNALSOFT_SET;
#endif

	MCAL_SPI_Init(SPI1, &mySPI1);

	/* Configure slave select on PA4 by GPIO */
	GPIO_PinConfig_t pincfg ;
	pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincfg.GPIO_PinNumber = GPIO_PIN_4;
	pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &pincfg);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	while(1);
}

void clock_init(){

//	MCAL_RCC_Select_Clock(RCC_SELECT_HSI);
	MCAL_RCC_Enable_Peripheral(RCC_GPIOA);
	MCAL_RCC_Enable_Peripheral(RCC_GPIOB);
	MCAL_RCC_Enable_Peripheral(RCC_GPIOC);
	MCAL_RCC_Enable_Peripheral(RCC_AFIO);
/*	MCAL_RCC_Enable_Peripheral(RCC_USART1);*/
}

