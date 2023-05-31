/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v1                                   */
/* File          : CA.c                                                  */
/* Date          : May 30, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

/* Includes */
#include "CA.h"
#include <stdio.h>
#include <stdlib.h>

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

static int US_Get_Distance_random(int l, int r, int count){
	/* This will generate random number in range l and r */
	int i, rand_num;
	for(i = 0; i < count; i++){
		rand_num = (rand() % (r - 1 + 1)) + 1;
	}
	return rand_num;
}

STATE_define(CA_waiting){

	/* State Name */
	CA_state_id = CA_waiting;

	/* State Action */
	CA_speed = SPEED_STOP;

	/* Event Check */
	//US_Get_Distance(&CA_distance);
	CA_distance = US_Get_Distance_random(45, 55, 1);
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("CA_Waiting State: Distance = %d\tSpeed = %d\n", CA_distance, CA_speed);
}

STATE_define(CA_driving){
	/* State Name */
	CA_state_id = CA_driving;

	/* State Action */
	CA_speed = SPEED_MOVE;

	/* Event Check */
	//US_Get_Distance(&CA_distance);
	CA_distance = US_Get_Distance_random(45, 55, 1);
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("CA_Driving State: Distance = %d\tSpeed = %d\n", CA_distance, CA_speed);
}
