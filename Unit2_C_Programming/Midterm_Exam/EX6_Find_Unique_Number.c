/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX6_Find_Unique_Number.c                           	 */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int Find_Unique_Number(int arr[], int arr_len);

int main(){
	int arr1[] = {4,2,5,2,5,7,4};
	int arr2[] = {4,2,4};
	printf("Input: int a[7]={4,2,5,2,5,7,4}; Output: %i\n", Find_Unique_Number(arr1, 7));
	printf("Input: int a[3]={4,2,4}; Output: %i\n", Find_Unique_Number(arr2, 3));
	return 0;
}

int Find_Unique_Number(int arr[], int arr_len){
	int index = 0;
	int numbers_arr[10] = {0};
	for(; index < arr_len; index++){
		numbers_arr[arr[index]]++;
	}
	if(1 == numbers_arr[0]){
		return 0;
	}
	else if(1 == numbers_arr[1]){
		return 1;
	}
	else if(1 == numbers_arr[2]){
		return 2;
	}
	else if(1 == numbers_arr[3]){
		return 3;
	}
	else if(1 == numbers_arr[4]){
		return 4;
	}
	else if(1 == numbers_arr[5]){
		return 5;
	}
	else if(1 == numbers_arr[6]){
		return 6;
	}
	else if(1 == numbers_arr[7]){
		return 7;
	}
	else if(1 == numbers_arr[8]){
		return 8;
	}
	else if(1 == numbers_arr[9]){
		return 9;
	}
	else{ return -1; }
}
