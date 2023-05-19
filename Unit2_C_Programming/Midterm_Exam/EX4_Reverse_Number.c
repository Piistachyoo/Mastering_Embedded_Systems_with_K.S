/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX4_Reverse_Number.c                           		 */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int Reverse_Number(int _number);

int main(){
	printf("Input: 2457 -> Output: %i\n", Reverse_Number(2457));
	printf("Input: 1057 -> Output: %i\n", Reverse_Number(1057));
	return 0;
}

int Reverse_Number(int _number){
	int reversed_number = 0;
	while(0 != _number){
		reversed_number += (_number%10);
		reversed_number *= 10;
		_number /= 10;
	}
	reversed_number /= 10;
	return reversed_number;
}
