/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX2_Print_Alphabets_Using_Pointers.c                  */
/* Date          : May 21, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int main(){
	char letter = 'A';
	char * const cPtr = &letter;
	while(1){
		printf("%c ", *cPtr);
		if('Z' == *cPtr)
			break;
		(*cPtr)++;
	}
	return 0;
}
