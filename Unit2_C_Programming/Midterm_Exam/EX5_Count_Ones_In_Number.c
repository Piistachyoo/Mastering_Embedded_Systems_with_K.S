/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX5_Count_Ones_In_Number.c                            */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int Get_No_Of_Ones(long _number);

int main(){
	printf("Input: 5 -> Output: %i\n", Get_No_Of_Ones(5ul));
	printf("Input: 15 -> Output: %i\n", Get_No_Of_Ones(15ul));
	return 0;
}

int Get_No_Of_Ones(long _number){
	int count = 0;
	int index;
	for(index = 0; index < 32; index++){
		if((_number >> index) & 1){
			count++;
		}
	}
	return count;
}
