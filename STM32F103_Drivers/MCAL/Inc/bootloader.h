/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : bootloader.h 			                             */
/* Date          : Jul 30, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_BOOTLOADER_H_
#define INC_BOOTLOADER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------


//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef enum{
	BL_NACK = 0,
	BL_OK
}BL_Status;

typedef enum{
	CRC_NOK,
	CRC_OK
}CRC_Result;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------
#define BL_ENABLE_UART_DEBUG_MESSAGE
#define	BL_DEBUG_UART				USART1
#define BL_HOST_COMMUNICATION_UART	USART1
#define Host_Buffer_RX_Length 		100


/* Bootloader commands */
#define CBL_GET_VER_CMD              0x10
#define CBL_GET_HELP_CMD             0x11
#define CBL_GET_CID_CMD              0x12
/* Get Read Protection Status */
#define CBL_GET_RDP_STATUS_CMD       0x13
#define CBL_GO_TO_ADDR_CMD           0x14
#define CBL_FLASH_ERASE_CMD          0x15
#define CBL_MEM_WRITE_CMD            0x16
/* Enable/Disable Write Protection */
#define CBL_ED_W_PROTECT_CMD         0x17
#define CBL_MEM_READ_CMD             0x18
/* Get Sector Read/Write Protection Status */
#define CBL_READ_SECTOR_STATUS_CMD   0x19
#define CBL_OTP_READ_CMD             0x20
/* Change Read Out Protection Level */
#define CBL_CHANGE_ROP_Level_CMD     0x21

/* Bootloader data */
#define BL_VENDOR_ID				125
#define BL_SW_MAJOR_VERSION			1
#define BL_SW_MINOR_VERSION			0
#define BL_SW_PATH_VERSION			0

#define CRC_SIZE_BYTES				4

#define BL_NACK						0xAB
#define BL_ACK						0xCD

/*
 * =============================================
 * APIs Supported by "Bootloader"
 * =============================================
 */

/**=============================================
 * @Fn			- 
 * @brief 		- 
 * @param [in] 	- 
 * @retval 		- 
 * Note			- 
 */
void BL_Init(void);
BL_Status BL_UART_Fetch_Host_Command(void);

#endif /* INC_BOOTLOADER_H_ */
