/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Smart_Car_Parking_STM32F103  	                     */
/* File          : app_states.c 			                             */
/* Date          : Aug 3, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "app_states.h"

extern volatile uint8 Enter_Flag, Exit_Flag;
extern uint8 Free_Slots, Print_Slots_LCD_Flag;

/* Global pointer to function */
void (*fp_App_State_Handler)() = STATE_NAME(Init_STATE);
STATES APP_Current_State;

STATE_API(Init_STATE){
	APP_Current_State = Init_STATE;

	ECU_Init();

	fp_App_State_Handler = STATE_NAME(Admin_STATE);
}

STATE_API(Admin_STATE){
	APP_Current_State = Admin_STATE;

	Admin_Init();

	Print_Slots_LCD_Flag = 1;

	fp_App_State_Handler = STATE_NAME(Idle_STATE);
}

STATE_API(Idle_STATE){
	APP_Current_State = Idle_STATE;

	UserLCD_PrintFreeSlots();

	/* Check if someone entered their RFID card */

	if(Exit_Flag != 0){
		/* Check that there is someone already inside */
		if(NO_OF_SLOTS != Free_Slots){
			fp_App_State_Handler = STATE_NAME(Exit_Gate_STATE);
		}
		else{
			Exit_Flag = 0;
			Trigger_Alarm(EXIT_USART_INSTANT);
		}
	}
	else{ /* Do Nothing */ }

	if(Enter_Flag != 0){
		/* Idle state means that there will be always free slots */
		fp_App_State_Handler = STATE_NAME(Enter_Gate_STATE);
	}
	else{ /* Do Nothing */ }
}

STATE_API(Enter_Gate_STATE){
	uint8 ID;

	APP_Current_State = Enter_Gate_STATE;

	/* Clear flag */
	Enter_Flag = 0;

	/* Get received ID from UART */
	MCAL_USART_ReceiveData(ENTER_USART_INSTANT, (uint16*)&ID, disable);

	/* Echo the ID on UART */
	MCAL_USART_SendData(ENTER_USART_INSTANT, (uint16*)&ID, disable);

	if(ID_Found == Check_ID(ID)){
		Free_Slots--;
		Enter_Gate_Open();
	}
	else{
		Wrong_RFID();
	}

	fp_App_State_Handler = (Free_Slots > 0) ? STATE_NAME(Idle_STATE) : STATE_NAME(Full_STATE) ;
	Print_Slots_LCD_Flag = 1;
}

STATE_API(Exit_Gate_STATE){
	uint8 ID;

	APP_Current_State = Exit_Gate_STATE;

	/* Clear flag */
	Exit_Flag = 0;

	/* Get received ID from UART */
	MCAL_USART_ReceiveData(EXIT_USART_INSTANT, (uint16*)&ID, disable);

	/* Echo the ID on UART */
	MCAL_USART_SendData(EXIT_USART_INSTANT, (uint16*)&ID, disable);

	if(ID_Found == Check_ID(ID)){
		Free_Slots++;
		Exit_Gate_Open();
	}
	else{
		Wrong_RFID();
	}

	fp_App_State_Handler = (Free_Slots > 0) ? STATE_NAME(Idle_STATE) : STATE_NAME(Full_STATE) ;
	Print_Slots_LCD_Flag = 1;
}

STATE_API(Full_STATE){
	APP_Current_State = Full_STATE;

	UserLCD_PrintFreeSlots();

	/* Check if someone wants to enter or exit */

	if(Enter_Flag != 0){
		/* Someone wants to enter but the parking is full */
		Enter_Flag = 0;
		Trigger_Alarm(ENTER_USART_INSTANT);
	}
	else{ /* Do Nothing */ }


	if(Exit_Flag != 0){
		fp_App_State_Handler = STATE_NAME(Exit_Gate_STATE);
	}
	else{ /* Do Nothing */ }
}
