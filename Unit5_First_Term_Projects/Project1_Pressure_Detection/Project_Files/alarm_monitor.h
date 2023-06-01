/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Pressure_Detection                                    */
/* File          : alarm_monitor.h	                                     */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

/* Section: Includes */
#include "states.h"
#include "driver.h"

/* Section: Data Types Declaration */
typedef enum{
	mAlarm_On,
	mAlarm_Off
}mAlarm_States_enu;

/* Section: Variables declarations */
extern void (*mAlarm_State_Handler)();
extern mAlarm_States_enu mAlarm_Current_State;

/* APIs and states */
void mAlarm_init();

STATEFUN(mAlarm_On);
STATEFUN(mAlarm_Off);

#endif /* ALARM_MONITOR_H_ */
