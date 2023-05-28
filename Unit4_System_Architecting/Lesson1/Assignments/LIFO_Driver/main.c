/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : LIFO_buffer                                    	 	 */
/* File          : main.c                                                */
/* Date          : May 29, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int BUFFER1[5];

int main(){
	int i;
	unsigned int temp;
	LIFO_Buf_t UART_LIFO, I2C_LIFO;
	LIFO_status_t ret_status;
	/* Static Allocation */
	LIFO_Init(&UART_LIFO, BUFFER1, 5);

	/* Dynamic Allocation */
	unsigned int* BUFFER2 = (unsigned int*)malloc(5 * sizeof(unsigned int)); /* 5*4=20Bytes */
	LIFO_Init(&I2C_LIFO, BUFFER2, 5);

	for(i = 0; i < 7; i++){
		ret_status = LIFO_Add_Item(&UART_LIFO, i);
		if(LIFO_NO_ERROR == ret_status)
			printf("UART_LIFO add : %d\n", i);
		else if(LIFO_FULL == ret_status)
			printf("LIFO FULL!\n");
		else if(LIFO_NULL == ret_status)
			printf("LIFO IS NULL!\n");
	}
	for(i = 0; i < 7; i++){
		ret_status = LIFO_Get_Item(&UART_LIFO, &temp);
		if(LIFO_NO_ERROR == ret_status)
			printf("UART_LIFO get : %d\n", temp);
		else if(LIFO_EMPTY == ret_status)
			printf("LIFO EMPTY!\n");
		else if(LIFO_NULL == ret_status)
			printf("LIFO IS NULL!\n");
	}

	return 0;
}
