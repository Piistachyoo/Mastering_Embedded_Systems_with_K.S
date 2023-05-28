/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : LIFO_buffer                                    		 */
/* File          : lifo.c                                                */
/* Date          : May 29, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "lifo.h"

LIFO_status_t LIFO_Init(LIFO_Buf_t* lifo_buf, unsigned int* buff_base, unsigned int size){
	LIFO_status_t return_value = LIFO_NO_ERROR;

	/* Check if buffer is not null */
	if(NULL == buff_base){
		return_value = LIFO_NULL;
	}
	else{
		lifo_buf->base = buff_base;
		lifo_buf->head = buff_base;
		lifo_buf->length = size;
		lifo_buf->count = 0;
	}
	return return_value;
}

LIFO_status_t LIFO_Add_Item(LIFO_Buf_t* lifo_buf, unsigned int item){
	LIFO_status_t return_value = LIFO_NO_ERROR;

	/* Check if LIFO is valid */
	if((NULL == lifo_buf->head) || (NULL == lifo_buf->base)){
		return_value = LIFO_NULL;
	}
	else{
		/* Check if LIFO is full */
		if(lifo_buf->count >= lifo_buf->length){
			return_value = LIFO_FULL;
		}
		else{
			/* Add value */
			*(lifo_buf->head) = item;
			lifo_buf->head++;
			lifo_buf->count++;
		}
	}
	return return_value;
}

LIFO_status_t LIFO_Get_Item(LIFO_Buf_t* lifo_buf, unsigned int *item){
	LIFO_status_t return_value = LIFO_NO_ERROR;

	/* Check if LIFO is valid */
	if((NULL == lifo_buf->head) || (NULL == lifo_buf->base)){
		return_value = LIFO_NULL;
	}
	else{
		/* Check if LIFO is empty */
		if(0 == lifo_buf->count){
			return_value = LIFO_EMPTY;
		}
		else{
			/* Get value */
			lifo_buf->head--;
			*item = *(lifo_buf->head);
			lifo_buf->count--;
		}
	}
	return return_value;
}
