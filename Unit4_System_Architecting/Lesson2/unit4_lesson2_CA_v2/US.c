/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v2                                   */
/* File          : US.c                                                  */
/* Date          : May 31, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "US.h"

/* Variables */
static int US_distance = 0;
static US_states US_state_id;

/* State pointer */
void (*US_state)();

/* APIs Definition */
static int US_Get_Distance_random(int l, int r, int count){
	/* This will generate random number in range l and r */
	int i, rand_num;
	for(i = 0; i < count; i++){
		rand_num = (rand() % (r - l + 1)) + l;
	}
	return rand_num;
}

void US_init(){
	/* Init Ultrasonic Driver */
	printf("US Initialized\n");
}

STATE_define(US_busy){
	/* State Name */
	US_state_id = US_busy;

	/* State Action */
	US_distance = US_Get_Distance_random(45, 55, 1);
	printf("US_busy State: distance = %d \n", US_distance);
	US_Get_Distance(US_distance);
	US_state = STATE(US_busy);
}
