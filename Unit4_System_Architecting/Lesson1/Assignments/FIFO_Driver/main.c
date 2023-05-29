/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : FIFO_buffer                                 		   	 */
/* File          : main.c                                                */
/* Date          : May 29, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "fifo.h"

element_type UART_BUFFER[width];

int main(void){
	element_type i, temp;
	FIFO_buffer_status ret_val;
	FIFO_buffer_t UART_FIFO;
	ret_val = FIFO_Init(&UART_FIFO, UART_BUFFER, width);
	if(FIFO_NO_ERROR == ret_val)
		printf("FIFO Initialization done!\n");
	else if(FIFO_NULL == ret_val)
		printf("ERROR: FIFO is NULL!\n");

	for(i = 0; i < 7; i++){
		printf("FIFO Enqueue (%x) \n", i);
		ret_val = FIFO_Enqueue(&UART_FIFO, i);
		if(FIFO_NO_ERROR == ret_val)
			printf("%d was added successfully!\n", i);
		else if(FIFO_FULL == ret_val)
			printf("\t ERROR: FIFO is FULL!\n");
		else if(FIFO_NULL == ret_val)
			printf("\t ERROR: FIFO is NULL!\n");
		if(2 == i){
			FIFO_Print(&UART_FIFO);
		}
	}

	FIFO_Print(&UART_FIFO);
	for(i = 0; i < 7; i++){
		ret_val = FIFO_Dequeue(&UART_FIFO, &temp);
		if(FIFO_NO_ERROR == ret_val)
			printf("FIFO Dequeue %x is done!\n", temp);
		else if(FIFO_EMPTY == ret_val)
			printf("\t ERROR: FIFO is EMPTY!\n");
		else if(FIFO_NULL == ret_val)
			printf("\t ERROR: FIFO is NULL!\n");
		if(2 == i){
			FIFO_Print(&UART_FIFO);
		}
	}
	FIFO_Print(&UART_FIFO);
	return 0;
}
