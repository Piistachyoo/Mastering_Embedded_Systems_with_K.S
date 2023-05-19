/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX10_Max_Number_Of_Ones_Between_Two_Zeroes.c          */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int Find_Max_Number_Of_Ones(long _number);

int main(){
	printf("Input: 14(0 1110) -> Output: %i\n", Find_Max_Number_Of_Ones(14));
	printf("Input: 110(0110 1110) -> Output: %i\n", Find_Max_Number_Of_Ones(110));
	return 0;
}

int Find_Max_Number_Of_Ones(long _number){
	int count = 0;
	int max_count = 0;
	int index = 0;
	for(; index < 32; index++){
		if((_number>>index)&1){
			count++;
			if(count > max_count){
				max_count = count;
			}
		}
		else{
			if(count > max_count){
				max_count = count;
			}
			count = 0;
		}
	}
	return max_count;
}
