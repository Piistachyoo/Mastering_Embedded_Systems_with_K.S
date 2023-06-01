/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Pressure_Detection                                    */
/* File          : pressure_driver.h                                     */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef PRESSURE_DRIVER_H_
#define PRESSURE_DRIVER_H_

/* Section: Includes */
#include "states.h"
#include "driver.h"

/* Section: Data Types Declaration */
typedef enum{
	Pressure_reading,
	Pressure_updating
}Pressure_States_enu;

/* Section: Variables declarations */
extern void (*Pressure_State_Handler)();
extern Pressure_States_enu Pressure_Current_State;

/* APIs and states */
void Pressure_Init();

STATEFUN(Pressure_reading);
STATEFUN(Pressure_updating);

#endif /* PRESSURE_DRIVER_H_ */
