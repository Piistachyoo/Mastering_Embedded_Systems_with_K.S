/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : bootloader.c 			                             */
/* Date          : Jul 30, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include <stdarg.h>
#include <stdio.h>
#include "bootloader.h"
#include "USART_driver.h"
#include "string_lib.h"
#include "CRC_driver.h"

//----------------------------------------------
// Section: Static Functions Declaration
//----------------------------------------------
static void BL_Send_ACK(uint8 reply_len);
static void BL_Send_NACK(void);
static CRC_Result BL_CRC_Verify(uint8 *pData, uint8 Data_Len, uint32 Host_CRC);
static void BL_Print_Message(uint8 *format, ...);
static void BL_Send_Data_To_Host(uint8 *Host_Buffer, uint32 Data_Len);
static void Bootloader_Get_Version(uint8_t *Host_Buffer);
static void Bootloader_Get_Help(uint8_t *Host_Buffer);
static void Bootloader_Get_Chip_Identification_Number(uint8_t *Host_Buffer);
static void Bootloader_Read_Protection_Level(uint8_t *Host_Buffer);
static void Bootloader_Jump_To_Address(uint8_t *Host_Buffer);
static void Bootloader_Erase_Flash(uint8_t *Host_Buffer);
static void Bootloader_Memory_Write(uint8_t *Host_Buffer);
static void Bootloader_Enable_RW_Protection(uint8_t *Host_Buffer);
static void Bootloader_Memory_Read(uint8_t *Host_Buffer);
static void Bootloader_Get_Sector_Protection_Status(uint8_t *Host_Buffer);
static void Bootloader_Read_OTP(uint8_t *Host_Buffer);
static void Bootloader_Change_Read_Protection_Level(uint8_t *Host_Buffer);

//----------------------------------------------
// Section: Global Variables Definitions
//----------------------------------------------
static uint8 BL_Host_Buffer[Host_Buffer_RX_Length];

//----------------------------------------------
// Section: API Definitions
//----------------------------------------------

void BL_Init(void){
	USART_cfg_t myUART;
	myUART.BaudRate = UART_BaudRate_115200;
	myUART.HwFlowCtl = UART_HwFlowCtl_NONE;
	myUART.IRQ_Enable = UART_IRQ_Enable_NONE;
	myUART.P_IRQ_CallBack = NULL;
	myUART.Parity = UART_Parity_NONE;
	myUART.Payload_Length = UART_Payload_Length_8B;
	myUART.StopBits = UART_StopBits_1;
	myUART.USART_Mode = UART_Mode_TX_RX;
	MCAL_USART_Init(BL_HOST_COMMUNICATION_UART, &myUART);
	MCAL_USART_Init(BL_DEBUG_UART, &myUART);
}

BL_Status BL_UART_Fetch_Host_Command(void){
	BL_Status ret_val = BL_NACK;
	uint8 Data_Length;


	/* Clear buffer */
	STRING_set_memoryLocation(BL_Host_Buffer, 0, Host_Buffer_RX_Length);

	// Host command format: Command length (1 byte = N)
	// + Command Code (1 byte) + Details (N bytes) + CRC (4 bytes)

	// Receive number of bytes (Data_Length)
	MCAL_USART_ReceiveData(BL_HOST_COMMUNICATION_UART, (uint16*)BL_Host_Buffer, enable);
	Data_Length = BL_Host_Buffer[0];

	// Receive N(Data_Length) bytes (command code + Data + CRC)
	MCAL_USART_ReceiveBuffer(BL_HOST_COMMUNICATION_UART, (uint16*)(&BL_Host_Buffer[1]), Data_Length);

	/* Switch case on command code */
	switch(BL_Host_Buffer[1]){
	case CBL_GET_VER_CMD:
		BL_Print_Message((uint8*)"Read the bootloader version from the MCU\r\n");
		Bootloader_Get_Version(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_GET_HELP_CMD:
		BL_Print_Message((uint8*)"Read the commands supported by the bootloader\r\n");
		Bootloader_Get_Help(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_GET_CID_CMD:
		BL_Print_Message((uint8*)"Read the MCU chip identification number\r\n");
		Bootloader_Get_Chip_Identification_Number(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_GET_RDP_STATUS_CMD:
		BL_Print_Message((uint8*)"Read the FLASH Read Protection level\r\n");
		Bootloader_Read_Protection_Level(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_GO_TO_ADDR_CMD:
		BL_Print_Message((uint8*)"Jump bootloader to specified address\r\n");
		Bootloader_Jump_To_Address(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_FLASH_ERASE_CMD:
		BL_Print_Message((uint8*)"Mass erase or sector erase of the user FLASH\r\n");
		Bootloader_Erase_Flash(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_MEM_WRITE_CMD:
		BL_Print_Message((uint8*)"Write data into different memories of the MCU\r\n");
		Bootloader_Memory_Write(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_ED_W_PROTECT_CMD:
		BL_Print_Message((uint8*)"Enable read/write protect on different sectors of the user FLASH\r\n");
		Bootloader_Enable_RW_Protection(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_MEM_READ_CMD:
		BL_Print_Message((uint8*)"Read data from different memories of the microcontroller\r\n");
		Bootloader_Memory_Read(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_READ_SECTOR_STATUS_CMD:
		BL_Print_Message((uint8*)"Read all the sector protection status\r\n");
		Bootloader_Get_Sector_Protection_Status(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_OTP_READ_CMD:
		BL_Print_Message((uint8*)"Read the OTP contents\r\n");
		Bootloader_Read_OTP(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	case CBL_CHANGE_ROP_Level_CMD:
		BL_Print_Message((uint8*)"Disable read/write protection on different sectors of the user FLASH\r\n");
		Bootloader_Change_Read_Protection_Level(BL_Host_Buffer);
		ret_val = BL_OK;
		break;
	default:
		BL_Print_Message((uint8*)"Invalid command code received from host !!\r\n");
		ret_val = BL_NACK;
		break;
	}
	return ret_val;
}

//----------------------------------------------
// Section: Static Functions Definitions
//----------------------------------------------
static void BL_Send_ACK(uint8 reply_len){
	uint8 ACK_Value[2];
	ACK_Value[0] = BL_ACK;
	ACK_Value[1] = reply_len;
	MCAL_USART_SendString(BL_HOST_COMMUNICATION_UART, ACK_Value, 2);
}

static void BL_Send_NACK(void){
	uint8 ACK_Value = BL_NACK;
	MCAL_USART_SendData(BL_HOST_COMMUNICATION_UART, (uint16*)&ACK_Value, enable);
}

static CRC_Result BL_CRC_Verify(uint8 *pData, uint8 Data_Len, uint32 Host_CRC){
	CRC_Result ret_val = CRC_NOK;
	uint32 Calculated_CRC;
	uint8 counter;
	uint32 Buffer_Without_CRC[Host_Buffer_RX_Length] = {0};
	uint8 *pSrc, *pDst;
	uint8 Data_Len_32bits;

	/* Create a new buffer without CRC */
	pSrc = pData;
	pDst = (uint8*)Buffer_Without_CRC;
	// Copy data byte by byte
	for(counter = 0; counter < Data_Len; counter++){
		pDst[counter] = pSrc[counter];
	}

	/* Get new length */
	if(Data_Len%CRC_SIZE_BYTES == 0){
		Data_Len_32bits = Data_Len/4;
	}
	else{
		Data_Len_32bits = Data_Len/4;
		Data_Len_32bits++;
	}

	/* Reset CRC */
	MCAL_CRC_Reset();

	/* Calculate CRC32 */
	for(counter = 0; counter < Data_Len_32bits; counter++){
		Calculated_CRC = MCAL_CRC_Calculate(Buffer_Without_CRC, Data_Len_32bits, CRC_NO_RESET);
	}

	/* Compare the Host CRC with the calculated CRC */
	if(Calculated_CRC == Host_CRC){
		ret_val = CRC_OK;
	}
	else{
		ret_val = CRC_NOK;
	}

	return ret_val;
}

static void BL_Print_Message(uint8 *format, ...){
	uint8 buffer[100];

	va_list args;
	/* Enables access to the variable arguments */
	va_start(args, format);
	/* Write the formatted data from variable argument list to string */
	vsprintf((char*)buffer, (const char*)format, args);
#ifdef BL_ENABLE_UART_DEBUG_MESSAGE
	/* Transmit the formatted data through UART */
	MCAL_USART_SendString(BL_DEBUG_UART, buffer, 0);
#endif
	/* Performs cleanup for an ap object initialized by a call to va_start */
	va_end(args);
}

static void BL_Send_Data_To_Host(uint8 *Host_Buffer, uint32 Data_Len){
	MCAL_USART_SendString(BL_HOST_COMMUNICATION_UART, Host_Buffer, Data_Len);
}

static void Bootloader_Get_Version(uint8_t *Host_Buffer){
	CRC_Result result;
	/* Extract bootloader info */
	uint8 BL_Version[4] = {BL_VENDOR_ID, BL_SW_MAJOR_VERSION, BL_SW_MINOR_VERSION, BL_SW_PATH_VERSION};

	/* Extract packet length */
	uint8 packet_length = Host_Buffer[0] + 1;
	uint32 Host_CRC32 = *((uint32*)&(Host_Buffer[packet_length - CRC_SIZE_BYTES]));

	result = BL_CRC_Verify(Host_Buffer, (packet_length - CRC_SIZE_BYTES), Host_CRC32);

	if(CRC_OK == result){
		BL_Send_ACK(4);
		BL_Send_Data_To_Host(BL_Version, 4);
	}
	else{
		BL_Send_NACK();
	}
}

static void Bootloader_Get_Help(uint8_t *Host_Buffer){

}

static void Bootloader_Get_Chip_Identification_Number(uint8_t *Host_Buffer){

}

static void Bootloader_Read_Protection_Level(uint8_t *Host_Buffer){

}

static void Bootloader_Jump_To_Address(uint8_t *Host_Buffer){

}


static void Bootloader_Erase_Flash(uint8_t *Host_Buffer){

}

static void Bootloader_Memory_Write(uint8_t *Host_Buffer){

}

static void Bootloader_Enable_RW_Protection(uint8_t *Host_Buffer){

}

static void Bootloader_Memory_Read(uint8_t *Host_Buffer){

}

static void Bootloader_Get_Sector_Protection_Status(uint8_t *Host_Buffer){

}

static void Bootloader_Read_OTP(uint8_t *Host_Buffer){

}

static void Bootloader_Change_Read_Protection_Level(uint8_t *Host_Buffer){

}
