/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : FIFO_buffer                                    	 	 */
/* File          : fifo.c                                                */
/* Date          : May 29, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "fifo.h"

FIFO_buffer_status FIFO_Init(FIFO_buffer_t* fifo, element_type* buffer, unsigned int length){
	FIFO_buffer_status ret_val = FIFO_NO_ERROR;
	/* Check if buffer is valid */
	if((NULL == fifo) || (NULL == buffer)){
		ret_val = FIFO_NULL;
	}
	else{
		fifo->base = buffer;
		fifo->head = buffer;
		fifo->tail = buffer;
		fifo->length = length;
		fifo->count = 0;
	}
	return ret_val;
}

FIFO_buffer_status FIFO_Enqueue(FIFO_buffer_t* fifo, element_type item){
	FIFO_buffer_status ret_val = FIFO_NO_ERROR;
	/* Check if buffer is valid */
	if(!fifo->base || !fifo->head || !fifo->tail){
		ret_val = FIFO_NULL;
	}
	else{
		/* Check if FIFO is full */
		ret_val = FIFO_IS_FULL(fifo);
		if(FIFO_FULL != ret_val){
			*(fifo->head) = item;
			fifo->count++;
			/* Circular FIFO */
			if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type)))){
				fifo->head = fifo->base;
			}
			else{
				fifo->head++;
			}
		}
	}
	return ret_val;
}

FIFO_buffer_status FIFO_Dequeue(FIFO_buffer_t* fifo, element_type* item){
	FIFO_buffer_status ret_val = FIFO_NO_ERROR;
	/* Check if buffer is valid */
	if(!fifo->base || !fifo->head || !fifo->tail){
		ret_val = FIFO_NULL;
	}
	else{
		if(0 == fifo->count){
			ret_val = FIFO_EMPTY;
		}
		else{
			/* Circular FIFO */
			*item = *(fifo->tail);
			fifo->count--;
			if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type)))){
				fifo->tail = fifo->base;
			}
			else{
				fifo->tail++;
			}
		}
	}
	return ret_val;
}

FIFO_buffer_status FIFO_IS_FULL(FIFO_buffer_t* fifo){
	FIFO_buffer_status ret_val = FIFO_NO_ERROR;
	/* Check if buffer is valid */
	if(!fifo->base || !fifo->head || !fifo->tail){
		ret_val = FIFO_NULL;
	}
	else{
		if(fifo->count >= fifo->length){
			ret_val = FIFO_FULL;
		}
		else{ ret_val = FIFO_NO_ERROR; }
	}
	return ret_val;
}

void FIFO_Print(FIFO_buffer_t* fifo){
	printf("\n===== FIFO_Print started! =====\n");
	/* Check if buffer is valid */
	if(!fifo->base || !fifo->head || !fifo->tail){
		printf("ERROR: Fifo not valid!\n");
	}
	else{
		element_type *temp;
		int fifo_count = fifo->count;;
		if(0 == fifo_count){
			printf("ERROR: FIFO is EMPTY!\n");
		}
		else{
			temp = fifo->tail;
			while(fifo_count--){
				printf("\t %d \n", *temp);
				if(temp == (fifo->base + (fifo->length * sizeof(element_type)))){
					temp = fifo->base;
				}
				else{
					temp++;
				}
			}

		}
	}
	printf("===== FIFO_Print is done! =====\n\n");
}
