/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Pressure_Detection                                    */
/* File          : alarm_driver.h	                                     */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef ALARM_DRIVER_H_
#define ALARM_DRIVER_H_

/* Section: Includes */
#include "states.h"
#include "driver.h"

/* Section: Macro Definitions */
#define ALARM_ON	0
#define ALARM_OFF	1

/* Section: Data Types Declaration */
typedef enum{
	dAlarm_waiting,
	dAlarm_On,
	dAlarm_Off
}dAlarm_States_enu;

/* Section: Variables declarations */
extern void (*dAlarm_State_Handler)();
extern dAlarm_States_enu dAlarm_Current_State;

/* APIs and states */
void dAlarm_init();

STATEFUN(dAlarm_waiting);
STATEFUN(dAlarm_On);
STATEFUN(dAlarm_Off);

#endif /* ALARM_DRIVER_H_ */
