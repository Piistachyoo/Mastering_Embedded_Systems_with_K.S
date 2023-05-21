/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX4_Print_Elements_Of_Array_Reversed_Pointers.c       */
/* Date          : May 21, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int main(){
	int *arr_ptr, array_len, index;
	int array[15];
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &array_len);
	for(index = 0; index < array_len; index++){
		printf("element - %i : ", index+1);
		fflush(stdin); fflush(stdout);
		scanf("%i", &array[index]);
	}
	arr_ptr = &array[array_len-1];
	printf("\nThe elements of array in reverse order are: \n");
	for(index = array_len-1; index >= 0; index--){
		printf("element - %i : %i\n", index+1, *arr_ptr--);
	}
	return 0;
}
