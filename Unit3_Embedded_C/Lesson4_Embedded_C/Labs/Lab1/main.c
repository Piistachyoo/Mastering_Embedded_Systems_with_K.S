/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c			         	                 		 */
/* Date          : May 28, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/


#include "Platform_Types.h"

// register addresses
#define SYSCTL_BASE			0x400FE000
#define GPIO_PORTF_BASE		0x40025000

#define SYSCTL_RCGC2_R		(*((vuint32_t*)(SYSCTL_BASE + 0x108)))
#define GPIO_PORTF_DIR_R	(*((vuint32_t*)(GPIO_PORTF_BASE + 0x400)))
#define GPIO_PORTF_DEN_R	(*((vuint32_t*)(GPIO_PORTF_BASE + 0x51C)))
#define GPIO_PORTF_DATA_R	(*((vuint32_t*)(GPIO_PORTF_BASE + 0x3FC)))



int main(void)
{
	vuint32_t delay_counter;

	/* Enable GPIO PORTF */
	SYSCTL_RCGC2_R = 0x20;

	/* Delay to make sure GPIO is up and initialized */
	for(delay_counter = 0; delay_counter < 200; delay_counter++);

	/* Set PF3 Direction OUTPUT */
	GPIO_PORTF_DIR_R |= (1<<3);

	/* Enable the GPIO pin */
	GPIO_PORTF_DEN_R |= (1<<3);

	/* Toggle the pin */
	while(1){
		GPIO_PORTF_DATA_R |= (1<<3);
		for(delay_counter = 0; delay_counter < 5000; delay_counter++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_counter = 0; delay_counter < 5000; delay_counter++);
	}
	return 0;
}
