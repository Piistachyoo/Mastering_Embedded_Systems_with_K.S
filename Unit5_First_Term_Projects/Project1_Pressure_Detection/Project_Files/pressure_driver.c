/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Pressure_Detection                                    */
/* File          : pressure_driver.c                                     */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "pressure_driver.h"

void (*Pressure_State_Handler)();
static int pressure_value;
Pressure_States_enu Pressure_Current_State;

void Pressure_Init(){
	GPIO_INITIALIZATION();
	Pressure_State_Handler = STATELBL(Pressure_reading);
}

STATEFUN(Pressure_reading){
	/* State Name */
	Pressure_Current_State = Pressure_reading;

	/* State Action */
	/* Get pressure sensor reading */
	pressure_value = getPressureVal();

	/* State Event */
	/* Set new state */
	Pressure_State_Handler = STATELBL(Pressure_updating);
}

STATEFUN(Pressure_updating){
	/* State Name */
	Pressure_Current_State = Pressure_updating;

	/* State Action */
	/* Update pressure value in main */
	Update_Pressure_value(pressure_value);

	/* State Event */
	/* Start timer for 10 seconds and wait for expiration */
	Delay(100000);

	/* Set new state */
	Pressure_State_Handler = STATELBL(Pressure_reading);

}
