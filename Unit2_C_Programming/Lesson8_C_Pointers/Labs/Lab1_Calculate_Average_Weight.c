/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : Lab1_Calculate_Average_Weight.c                       */
/* Date          : May 21, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int main(){
	int weights[5];
	int index = 0;
	int sum = 0;
	int *ptr_weight = weights;
	printf("Enter weights: ");
	fflush(stdin); fflush(stdout);
	for(; index < 5; index++){
		scanf("%i", ptr_weight + index);
	}
	printf("Entered weights: ");
	for(index = 0; index < 5; index++){
		printf("%i ", *(ptr_weight + index));
	}
	printf("\n");
	for(index = 0; index < 5; index++, ptr_weight++){
		sum += *ptr_weight;
	}
	printf("Sum = %i", sum);
	return 0;
}
