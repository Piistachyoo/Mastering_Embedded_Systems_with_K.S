/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : DAC_driver.h 			                             */
/* Date          : Jul 30, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_DAC_DRIVER_H_
#define INC_DAC_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "STM32F103x8.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef struct{
	uint32	Buffer_Control;  // Enables or disables the output buffer @ref DAC_OP_BUFFER_define
	uint32	Trigger_Control; // Sets the trigger mode for the DAC @ref DAC_TRIGR_define
	uint32	DMA_Control;	 // Enables or disables DMA for the DAC @ref DAC_DMA_define
}DAC_config;

typedef enum{
	DAC_CHANNEL_1 = 0,
	DAC_CHANNEL_DUAL,
	DAC_CHANNEL_2 = 16
}DAC_Channels;

typedef enum{
	DAC_12bit_right,
	DAC_12bit_left,
	DAC_8bit_right
}DAC_Data_Allignment;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

// @ref DAC_OP_BUFFER_define
#define DAC_OP_BUFFER_ENABLE	(0x00000000UL)
#define DAC_OP_BUFFER_DISABLE	(1UL<<1)

// @ref DAC_TRIGR_define
#define DAC_TRIGR_NONE		(0x00000000UL)
#define DAC_TRIGR_TMR6		((1UL<<2) | (0b000<<3))
#define DAC_TRIGR_TMR3		((1UL<<2) | (0b001<<3))
#define DAC_TRIGR_TMR7		((1UL<<2) | (0b010<<3))
#define DAC_TRIGR_TMR5		((1UL<<2) | (0b011<<3))
#define DAC_TRIGR_TMR2		((1UL<<2) | (0b100<<3))
#define DAC_TRIGR_TMR4		((1UL<<2) | (0b101<<3))
#define DAC_TRIGR_EXT9		((1UL<<2) | (0b110<<3))
#define DAC_TRIGR_SWTR		((1UL<<2) | (0b111<<3))

// @ref DAC_DMA_define
#define DAC_DMA_DISABLE		0x00000000UL
#define DAC_DMA_ENABLE		(1UL<<12)

/*
 * =============================================
 * APIs Supported by "DAC"
 * =============================================
 */

/**=============================================
 * @Fn			- 
 * @brief 		- 
 * @param [in] 	- 
 * @retval 		- 
 * Note			- 
 */
void MCAL_DAC_Init(DAC_Channels Channel, DAC_config *cfg);
void MCAL_DAC_DeInit();
void MCAL_DAC_GPIO_Set_Pins(DAC_Channels Channel);
void MCAL_DAC_Set_Value(DAC_Channels Channel, DAC_Data_Allignment Allignment, uint16 Value);


#endif /* INC_DAC_DRIVER_H_ */
