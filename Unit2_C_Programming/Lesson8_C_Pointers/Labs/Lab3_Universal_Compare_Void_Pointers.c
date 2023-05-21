/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : Lab3_Universal_Compare_Void_Pointers.c                */
/* Date          : May 21, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

#define INTEGER		0
#define DOUBLE		1

int compare_numbers(void *x, void *y, int type);

int main(){
	int n1, n2;
	double f1, f2;
	printf("Enter two numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%i %i", &n1, &n2);
	if(compare_numbers(&n1, &n2, INTEGER))
		printf("%i and %i are equal!\n", n1, n2);
	else
		printf("%i and %i are not equal!\n", n1, n2);
	printf("Enter two floats: ");
	fflush(stdin); fflush(stdout);
	scanf("%lf %lf", &f1, &f2);
	if(compare_numbers(&n1, &n2, DOUBLE))
		printf("%.2f and %.2f are equal!\n", f1, f2);
	else
		printf("%.2f and %.2f are not equal!\n", f1, f2);
	return 0;
}

int compare_numbers(void *x, void *y, int type){
	int result = 0;
	switch(type){
	case INTEGER:
		if(*(int*)x == *(int*)y)
			result = 1;
		else
			result = 0;
		break;
	case DOUBLE:
		if(*(double*)x == *(double*)y)
			result = 1;
		else
			result = 0;
		break;
	default: printf("Error in data type!"); break;
	}
	return result;
}
