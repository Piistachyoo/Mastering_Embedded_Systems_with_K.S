/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Smart_Car_Parking_STM32F103  	                     */
/* File          : ecu.c 			                            		 */
/* Date          : Aug 3, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "ecu.h"

//----------------------------------------------
// Section: Functions Declaration
//----------------------------------------------
void Enter_UART_CallBack(void);
void Exit_UART_CallBack(void);

//----------------------------------------------
// Section: Global Variables Definitions
//----------------------------------------------
static LED_cfg_t Green_LED;
static LED_cfg_t Red_LED;
static LCD_t Admin_LCD;
static LCD_t User_LCD;
static USART_cfg_t Enter_Gate_UART;
static USART_cfg_t Exit_Gate_UART;
static GPIO_PinConfig_t PIR;
volatile uint8 Enter_Flag, Exit_Flag;
uint8 Free_Slots = 3;
uint8 Print_Slots_LCD_Flag;
static uint8 Users_IDs[USERS_COUNT];

//----------------------------------------------
// Section: API Definitions
//----------------------------------------------

/**=============================================
 * @Fn			- ECU_Init
 * @brief 		- This function initializes all hardware components and peripherals
 * @param [in] 	- None
 * @retval 		- None
 * Note			- Must be called on boot
 */
void ECU_Init(void){
	/* Clock initialization */
	MCAL_RCC_Enable_Peripheral(RCC_GPIOA);
	MCAL_RCC_Enable_Peripheral(RCC_GPIOB);
	MCAL_RCC_Enable_Peripheral(RCC_TIM2);

	/* LEDs initialization */
	Green_LED.LED_Port = GPIOA;
	Green_LED.LED_Mode = LED_Active_Low;
	Green_LED.LED_Pin.GPIO_PinNumber = GPIO_PIN_11;
	Green_LED.LED_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Green_LED.LED_Pin.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	LED_Init(&Green_LED);

	Red_LED.LED_Port = GPIOA;
	Red_LED.LED_Mode = LED_Active_Low;
	Red_LED.LED_Pin.GPIO_PinNumber = GPIO_PIN_0;
	Red_LED.LED_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Red_LED.LED_Pin.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	LED_Init(&Red_LED);

	/* LCDs initialization */
	Admin_LCD.Mode = LCD_4BIT;
	Admin_LCD.GPIO_PORT = GPIOB;
	Admin_LCD.Entry_Mode = LCD_ENTRY_MODE_INC_SHIFT_OFF;
	Admin_LCD.Display_Mode = LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF;
	Admin_LCD.EN_PIN = GPIO_PIN_10;
	Admin_LCD.RS_PIN = GPIO_PIN_11;
	Admin_LCD.D4_PIN = GPIO_PIN_12;
	Admin_LCD.D5_PIN = GPIO_PIN_13;
	Admin_LCD.D6_PIN = GPIO_PIN_14;
	Admin_LCD.D7_PIN = GPIO_PIN_15;
	LCD_Init(&Admin_LCD);

	User_LCD.Mode = LCD_4BIT;
	User_LCD.GPIO_PORT = GPIOA;
	User_LCD.Entry_Mode = LCD_ENTRY_MODE_INC_SHIFT_OFF;
	User_LCD.Display_Mode = LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF;
	User_LCD.RS_PIN = GPIO_PIN_5;
	User_LCD.EN_PIN = GPIO_PIN_6;
	User_LCD.D4_PIN = GPIO_PIN_12;
	User_LCD.D5_PIN = GPIO_PIN_13;
	User_LCD.D6_PIN = GPIO_PIN_14;
	User_LCD.D7_PIN = GPIO_PIN_15;
	LCD_Init(&User_LCD);

	/* UART initialization */
	Enter_Gate_UART.USART_Mode = UART_Mode_TX_RX;
	Enter_Gate_UART.BaudRate = UART_BaudRate_115200;
	Enter_Gate_UART.HwFlowCtl = UART_HwFlowCtl_NONE;
	Enter_Gate_UART.IRQ_Enable = UART_IRQ_Enable_RXNE;
	Enter_Gate_UART.P_IRQ_CallBack = Enter_UART_CallBack;
	Enter_Gate_UART.Parity = UART_Parity_NONE;
	Enter_Gate_UART.Payload_Length = UART_Payload_Length_8B;
	Enter_Gate_UART.StopBits = UART_StopBits_1;
	MCAL_USART_Init(ENTER_USART_INSTANT, &Enter_Gate_UART);

	Exit_Gate_UART.USART_Mode = UART_Mode_TX_RX;
	Exit_Gate_UART.BaudRate = UART_BaudRate_115200;
	Exit_Gate_UART.HwFlowCtl = UART_HwFlowCtl_NONE;
	Exit_Gate_UART.IRQ_Enable = UART_IRQ_Enable_RXNE;
	Exit_Gate_UART.P_IRQ_CallBack = Exit_UART_CallBack;
	Exit_Gate_UART.Parity = UART_Parity_NONE;
	Exit_Gate_UART.Payload_Length = UART_Payload_Length_8B;
	Exit_Gate_UART.StopBits = UART_StopBits_1;
	MCAL_USART_Init(EXIT_USART_INSTANT, &Exit_Gate_UART);

	/* PIRs initialization */
	PIR.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	PIR.GPIO_PinNumber = ENTER_PIR_PIN;
	MCAL_GPIO_Init(ENTER_PIR_PORT, &PIR);

	PIR.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	PIR.GPIO_PinNumber = EXIT_PIR_PIN;
	MCAL_GPIO_Init(EXIT_PIR_PORT, &PIR);

	/* Servo motors initialization */
	Timer2_init();
	Servo1_Entry_Gate_Init();
	Servo2_Exit_Gate_Init();

	/* Keypad initialization */
	keypad_init();
}

/**=============================================
 * @Fn			- Admin_Init
 * @brief 		- This function is called at the very start of the system to set the users' IDs
 * @param [in] 	- None
 * @retval 		- None
 * Note			- None
 */
void Admin_Init(void){
	uint8 keypad_buffer;

	/* Ask the admin to enter the users' IDs */
	LCD_Send_string_Pos(&Admin_LCD, (uint8*)"Enter users' IDs", LCD_FIRST_ROW, 1);

	LCD_Send_string_Pos(&Admin_LCD, (uint8*)"User1 ID: ", LCD_SECOND_ROW, 6);

	/* Set user IDs */
	do{
		keypad_buffer = keypad_Get_Pressed_Key();
	}while('F' == keypad_buffer);

	LCD_Send_Char(&Admin_LCD, keypad_buffer);
	Users_IDs[USER1] = keypad_buffer;

	LCD_Send_string_Pos(&Admin_LCD, (uint8*)"User2 ID: ", LCD_THIRD_ROW, 2);

	do{
		keypad_buffer = keypad_Get_Pressed_Key();
	}while('F' == keypad_buffer);

	LCD_Send_Char(&Admin_LCD, keypad_buffer);
	Users_IDs[USER2] = keypad_buffer;

	LCD_Send_string_Pos(&Admin_LCD, (uint8*)"User3 ID: ", LCD_FOURTH_ROW, 2);

	do{
		keypad_buffer = keypad_Get_Pressed_Key();
	}while('F' == keypad_buffer);

	LCD_Send_Char(&Admin_LCD, keypad_buffer);
	Users_IDs[USER3] = keypad_buffer;

	/* Set the default screen for the rest of the program */
	LCD_Send_Command(&Admin_LCD, LCD_CLEAR_DISPLAY);
	LCD_Send_string_Pos(&Admin_LCD, (uint8*)"System is ON", LCD_FIRST_ROW, 3);
	LCD_Send_string_Pos(&Admin_LCD, (uint8*)"User1 ID: ", LCD_SECOND_ROW, 6);
	LCD_Send_Char(&Admin_LCD, Users_IDs[USER1]);
	LCD_Send_string_Pos(&Admin_LCD, (uint8*)"User2 ID: ", LCD_THIRD_ROW, 2);
	LCD_Send_Char(&Admin_LCD, Users_IDs[USER2]);
	LCD_Send_string_Pos(&Admin_LCD, (uint8*)"User3 ID: ", LCD_FOURTH_ROW, 2);
	LCD_Send_Char(&Admin_LCD, Users_IDs[USER3]);
}

/**=============================================
 * @Fn			- UserLCD_PrintFreeSlots
 * @brief 		- This function prints number of free slots on UserLCD on demand
 * @param [in] 	- None
 * @retval 		- None
 * Note			- Must set Print_Slots_LCD_Flag to 1 before calling this function to print
 */
void UserLCD_PrintFreeSlots(){
	/* Check if we need to print free slots, to avoid unnecessary prints */
	if(Print_Slots_LCD_Flag){
		Print_Slots_LCD_Flag = 0;
		if(0 >= Free_Slots){
			LCD_Send_Command(&User_LCD, LCD_CLEAR_DISPLAY);
			LCD_Send_string_Pos(&User_LCD, (uint8*)"Welcome!", LCD_FIRST_ROW, 4);
			LCD_Send_string_Pos(&User_LCD, (uint8*)"Parking is full!", LCD_SECOND_ROW, 1);
		}
		else{
			LCD_Send_Command(&User_LCD, LCD_CLEAR_DISPLAY);
			LCD_Send_string_Pos(&User_LCD, (uint8*)"Welcome!", LCD_FIRST_ROW, 4);
			LCD_Send_Char_Pos(&User_LCD, (Free_Slots+'0'), LCD_SECOND_ROW, 1);
			LCD_Send_string_Pos(&User_LCD, (uint8*)"Slots free!", LCD_SECOND_ROW, 3);
		}
	}
	else{ /* Do Nothing */ }
}

/**=============================================
 * @Fn			- Check_ID
 * @brief 		- This function checks for the given ID in the saved IDs and return the result
 * @param [in] 	- _ID: ID to check
 * @retval 		- IF_Found if found, ID_NOT_Found else
 * Note			- None
 */
ID_Check_Result Check_ID(uint8 _ID){
	uint8 counter;
	uint8 found_flag = 0;

	for(counter = 0; counter < NO_OF_SLOTS; counter++){
		if(_ID == Users_IDs[counter]){
			found_flag = 1;
			break;
		}
		else{ /* Do Nothing */ }
	}

	return (found_flag == 1) ? ID_Found : ID_NOT_Found;
}

/**=============================================
 * @Fn			- Enter_Gate_Open
 * @brief 		- Opens the enter gate and prints on LCD that the gate is open
 * @param [in] 	- None
 * @retval 		- None
 * Note			- None
 */
void Enter_Gate_Open(){
	LCD_Send_Command(&User_LCD, LCD_CLEAR_DISPLAY);
	LCD_Send_String(&User_LCD, (uint8*)"Enter gate open!");
	Servo1_Entry_Gate(SERVO_UP);
	LED_TurnOn(&Green_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Green_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOn(&Green_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Green_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOn(&Green_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Green_LED);
	for(int i = 0; i < 50000; i++);
	while(MCAL_GPIO_ReadPin(ENTER_PIR_PORT, ENTER_PIR_PIN));
	Servo1_Entry_Gate(SERVO_DOWN);
}

/**=============================================
 * @Fn			- Exit_Gate_Open
 * @brief 		- Opens the exit gate and prints on LCD that the gate is open
 * @param [in] 	- None
 * @retval 		- None
 * Note			- None
 */
void Exit_Gate_Open(){
	LCD_Send_Command(&User_LCD, LCD_CLEAR_DISPLAY);
	LCD_Send_String(&User_LCD, (uint8*)"Exit gate open!");
	Servo2_Exit_Gate(SERVO_UP);
	LED_TurnOn(&Green_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Green_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOn(&Green_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Green_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOn(&Green_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Green_LED);
	for(int i = 0; i < 50000; i++);
	while(MCAL_GPIO_ReadPin(EXIT_PIR_PORT, EXIT_PIR_PIN));
	Servo2_Exit_Gate(SERVO_DOWN);
}

/**=============================================
 * @Fn			- Wrong_RFID
 * @brief 		- Triggeres the alarm and prints "UNKOWN ID!" on LCD
 * @param [in] 	- None
 * @retval 		- None
 * Note			- None
 */
void Wrong_RFID(){
	LCD_Send_Command(&User_LCD, LCD_CLEAR_DISPLAY);
	LCD_Send_String(&User_LCD, (uint8*)"UNKNOWN ID!");
	Servo1_Entry_Gate(SERVO_DOWN);
	Servo2_Exit_Gate(SERVO_DOWN);
	LED_TurnOn(&Red_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Red_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOn(&Red_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Red_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOn(&Red_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Red_LED);
	for(int i = 0; i < 50000; i++);
}

/**=============================================
 * @Fn			- Trigger_Alarm
 * @brief 		- This function echo the entered ID on UART and flashes the RED LED
 * @param [in] 	- _USART: Pointer to the USART instant that have the entered ID
 * @retval 		- None
 * Note			- None
 */
void Trigger_Alarm(USART_TypeDef* _USART){
	uint8 ID;
	/* Flush UART buffer and flash red LED */

	/* Get received ID from UART */
	MCAL_USART_ReceiveData(_USART, (uint16*)&ID, disable);

	/* Echo the ID on UART */
	MCAL_USART_SendData(_USART, (uint16*)&ID, disable);

	LED_TurnOn(&Red_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Red_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOn(&Red_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Red_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOn(&Red_LED);
	for(int i = 0; i < 50000; i++);
	LED_TurnOff(&Red_LED);
	for(int i = 0; i < 50000; i++);
}

void Enter_UART_CallBack(void){
	Enter_Flag = 1;
}

void Exit_UART_CallBack(void){
	Exit_Flag = 1;
}

//----------------------------------------------
// Section: Static Functions Definitions
//----------------------------------------------

