/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v2                                   */
/* File          : main.c                                                */
/* Date          : May 31, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "CA.h"
#include "DC.h"
#include "US.h"

void setup(){
	/* Init drivers */
	/* Init IRQ */
	/* Init HAL US_Driver DC_Driver */
	DC_init();
	US_init();

	/* Init Block */
	/* Set states pointers for each block */
	CA_state = STATE(CA_waiting);
	DC_state = STATE(DC_idle);
	US_state = STATE(US_busy);
}

int main(){
	setup();
	while(1){
		/* Call state for each block */
		CA_state();
		US_state();
		DC_state();
	}
	return 0;
}
