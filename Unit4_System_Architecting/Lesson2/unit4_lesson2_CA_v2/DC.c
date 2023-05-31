/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v2                                   */
/* File          : DC.c                                                  */
/* Date          : May 31, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "DC.h"

/* Variables */
static int DC_speed = 0;
static DC_states DC_state_id;

/* State pointer */
void (*DC_state)();

/* APIs Definition */
void DC_init(){
	/* Initialize PWM */
	printf("DC Motor Initialized \n");
}

void DC_Motor_Set_Speed(int Speed){
	DC_speed = Speed;
	DC_state = STATE(DC_busy);
	printf("CA ---------- Speed = %d -----------> DC\n", DC_speed);
}

STATE_define(DC_idle){
	/* State Name */
	DC_state_id = DC_idle;

	/* State Action */
	// Call PWM to make speed = DC_speed
	printf("DC_idle State: Speed = %d \n", DC_speed);
}

STATE_define(DC_busy){
	/* State Name */
	DC_state_id = DC_idle;

	/* State Action */
	// Call PWM to make speed = DC_speed
	DC_state = STATE(DC_idle);
	printf("DC_idle State: Speed = %d \n", DC_speed);
}
