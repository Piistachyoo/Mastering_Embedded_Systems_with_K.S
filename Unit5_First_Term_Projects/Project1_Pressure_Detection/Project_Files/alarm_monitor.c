/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Pressure_Detection                                    */
/* File          : alarm_monitor.c	                                     */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "alarm_monitor.h"

void (*mAlarm_State_Handler)();
mAlarm_States_enu mAlarm_Current_State;

void mAlarm_init(){
	GPIO_INITIALIZATION();
	Stop_Alarm();
	mAlarm_State_Handler = STATELBL(mAlarm_Off);
}

void High_Pressure_Detected(){
	mAlarm_State_Handler = STATELBL(mAlarm_On);
}

STATEFUN(mAlarm_On){
	/* State Name */
	mAlarm_Current_State = mAlarm_On;

	/* State Action */
	/* Start Alarm */
	Start_Alarm();

	/* Start a 60 seconds timer */
	Delay(60000);

	/* State Event */
	/* When timer expires, turn off alarm */
	Stop_Alarm();

	/* Set new state */
	mAlarm_State_Handler = STATELBL(mAlarm_Off);
}

STATEFUN(mAlarm_Off){
	/* State Name */
	mAlarm_Current_State = mAlarm_Off;

	/* State Action */
	/* Do Nothing */
}
