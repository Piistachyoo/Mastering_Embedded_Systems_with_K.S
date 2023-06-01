/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Pressure_Detection                                    */
/* File          : main.c              			                         */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "alarm_driver.h"
#include "alarm_monitor.h"
#include "pressure_driver.h"

#define threshold 20

void system_init();

static int local_pressure_value;

void main(void){
	/* Initialization */
	system_init();

	/* Super loop */
	while(1){
		Pressure_State_Handler();
		if(threshold < local_pressure_value)
			High_Pressure_Detected();
		mAlarm_State_Handler();
		dAlarm_State_Handler();
	}
}

void system_init(){
	Pressure_Init();
	mAlarm_init();
	dAlarm_init();
}

void Update_Pressure_value(int pressure_value){
	local_pressure_value = pressure_value;
}
