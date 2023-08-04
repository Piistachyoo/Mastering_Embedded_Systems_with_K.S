/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Smart_Car_Parking_STM32F103  	                     */
/* File          : ecu.h 			                            		 */
/* Date          : Aug 3, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INCS_ECU_H_
#define INCS_ECU_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "USART_driver.h"
#include "Servo_Motor.h"
#include "lcd_driver.h"
#include "led_driver.h"
#include "keypad_driver.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef enum{
	ID_NOT_Found,
	ID_Found
}ID_Check_Result;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

#define NO_OF_SLOTS				3
#define USERS_COUNT				3
#define USER1					0
#define USER2					1
#define USER3					2
#define ENTER_USART_INSTANT		USART1
#define EXIT_USART_INSTANT		USART2
#define ENTER_PIR_PORT			GPIOA
#define ENTER_PIR_PIN			GPIO_PIN_7
#define EXIT_PIR_PORT			GPIOA
#define EXIT_PIR_PIN			GPIO_PIN_1

/*
 * =============================================
 * APIs Supported by "ECU"
 * =============================================
 */

/**=============================================
 * @Fn			- ECU_Init
 * @brief 		- This function initializes all hardware components and peripherals
 * @param [in] 	- None
 * @retval 		- None
 * Note			- Must be called on boot
 */
void ECU_Init(void);

/**=============================================
 * @Fn			- Admin_Init
 * @brief 		- This function is called at the very start of the system to set the users' IDs
 * @param [in] 	- None
 * @retval 		- None
 * Note			- None
 */
void Admin_Init(void);

/**=============================================
 * @Fn			- UserLCD_PrintFreeSlots
 * @brief 		- This function prints number of free slots on UserLCD on demand
 * @param [in] 	- None
 * @retval 		- None
 * Note			- Must set Print_Slots_LCD_Flag to 1 before calling this function to print
 */
void UserLCD_PrintFreeSlots();

/**=============================================
 * @Fn			- Check_ID
 * @brief 		- This function checks for the given ID in the saved IDs and return the result
 * @param [in] 	- _ID: ID to check
 * @retval 		- IF_Found if found, ID_NOT_Found else
 * Note			- None
 */
ID_Check_Result Check_ID(uint8 _ID);

/**=============================================
 * @Fn			- Enter_Gate_Open
 * @brief 		- Opens the enter gate and prints on LCD that the gate is open
 * @param [in] 	- None
 * @retval 		- None
 * Note			- None
 */
void Enter_Gate_Open();

/**=============================================
 * @Fn			- Exit_Gate_Open
 * @brief 		- Opens the exit gate and prints on LCD that the gate is open
 * @param [in] 	- None
 * @retval 		- None
 * Note			- None
 */
void Exit_Gate_Open();

/**=============================================
 * @Fn			- Wrong_RFID
 * @brief 		- Triggeres the alarm and prints "UNKOWN ID!" on LCD
 * @param [in] 	- None
 * @retval 		- None
 * Note			- None
 */
void Wrong_RFID();

/**=============================================
 * @Fn			- Trigger_Alarm
 * @brief 		- This function echo the entered ID on UART and flashes the RED LED
 * @param [in] 	- _USART: Pointer to the USART instant that have the entered ID
 * @retval 		- None
 * Note			- None
 */
void Trigger_Alarm(USART_TypeDef* _USART);

#endif /* INCS_ECU_H_ */
