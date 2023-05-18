/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project		 : C_Programming				 						 */
/* File          : Lab4_Pattern_Using_Function.c                         */
/* Date          : May 19, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

void print_to_9(int number);

int main(){
	int index = 0;
	for(;index <= 9; index++){
		print_to_9(index);
	}
	return 0;
}

void print_to_9(int number){
	if(9 >= number){
		int index = number;
		for(;index <= 9; index++){
			printf("%d ", index);
		}
		printf("\n");
	}
	else
		printf("Error!");
}
