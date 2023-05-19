/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX8_Reverse_Array_Elements.c                          */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

void Reverse_Array(int arr[], int arr_len);

int main(){
	int index=0;
	int array[5];
	printf("Enter elements of array: ");
	fflush(stdin); fflush(stdout);
	for(; index < 5; index++){
		scanf("%i", &array[index]);
		fflush(stdin); fflush(stdout);
	}
	Reverse_Array(array, 5);
	printf("Array after reversing: ");
	for(index = 0; index < 5; index++){
		printf("%i  ", array[index]);
	}
	return 0;
}

void Reverse_Array(int arr[], int arr_len){
	int index = (arr_len/2);
	int temp;
	arr_len--;
	for(; index >= 0; index--){
		temp = arr[index];
		arr[index] = arr[arr_len - index];
		arr[arr_len - index] = temp;
	}
}
