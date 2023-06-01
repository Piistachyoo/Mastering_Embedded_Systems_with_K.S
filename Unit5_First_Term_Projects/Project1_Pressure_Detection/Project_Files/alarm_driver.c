/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Pressure_Detection                                    */
/* File          : alarm_driver.c     	                                 */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "alarm_driver.h"

void (*dAlarm_State_Handler)();
dAlarm_States_enu dAlarm_Current_State;

void dAlarm_init(){
	GPIO_INITIALIZATION();
	dAlarm_State_Handler = STATELBL(dAlarm_waiting);
}

void Start_Alarm(){
	dAlarm_State_Handler = STATELBL(dAlarm_On);
	dAlarm_State_Handler();
}

void Stop_Alarm(){
	dAlarm_State_Handler = STATELBL(dAlarm_Off);
	dAlarm_State_Handler();
}

STATEFUN(dAlarm_waiting){
	/* State Name */
	dAlarm_Current_State = dAlarm_waiting;

	/* State Action */
}

STATEFUN(dAlarm_On){
	/* State Name */
	dAlarm_Current_State = dAlarm_On;

	/* State Action */
	/* Start Alarm Actuator */
	Set_Alarm_actuator(ALARM_ON);

	/* State Event */
	/* Set new state */
	dAlarm_State_Handler = STATELBL(dAlarm_waiting);
}

STATEFUN(dAlarm_Off){
	/* State Name */
	dAlarm_Current_State = dAlarm_On;

	/* State Action */
	/* Stop Alarm Actuator */
	Set_Alarm_actuator(ALARM_OFF);

	/* State Event */
	/* Set new state */
	dAlarm_State_Handler = STATELBL(dAlarm_waiting);
}
