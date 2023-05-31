/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v2                                   */
/* File          : CA.c                                                  */
/* Date          : May 31, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

/* Includes */
#include "CA.h"


/* Defines */
#define SPEED_STOP	0
#define SPEED_MOVE	30

/* Variables */
static int CA_speed = 0;
static int CA_distance = 0;
static int CA_threshold = 50;
static CA_states CA_state_id;

/* State pointer */
void (*CA_state)();

/* APIs Definition */

void US_Get_Distance(int Distance){
	CA_distance = Distance;
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US ---------- Distance = %d -----------> CA\n", CA_distance);
}

STATE_define(CA_waiting){

	/* State Name */
	CA_state_id = CA_waiting;
	printf("CA_Waiting State: Distance = %d\tSpeed = %d\n", CA_distance, CA_speed);

	/* State Action */
	CA_speed = SPEED_STOP;
	DC_Motor_Set_Speed(CA_speed);

	/* Event Check */
}

STATE_define(CA_driving){
	/* State Name */
	CA_state_id = CA_driving;
	printf("CA_Driving State: Distance = %d\tSpeed = %d\n", CA_distance, CA_speed);

	/* State Action */
	CA_speed = SPEED_MOVE;
	DC_Motor_Set_Speed(CA_speed);

	/* Event Check */
	//US_Get_Distance(&CA_distance);
	//CA_distance = US_Get_Distance_random(45, 55, 1);
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("CA_Driving State: Distance = %d\tSpeed = %d\n", CA_distance, CA_speed);
}
