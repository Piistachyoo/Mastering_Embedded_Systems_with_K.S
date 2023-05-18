/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project		 : C_Programming									 	 */
/* File          : LAB1_Calculate_Factorial.c                            */
/* Date          : May 18, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>
#include <string.h>

int Factorial(int _number);

int main(){
	printf("Factorial (10) = %d\n", Factorial(10));
	printf("Factorial (0) = %d\n", Factorial(0));
	printf("Factorial (5) = %d\n", Factorial(5));
	return 0;
}

int Factorial(int _number){
	int result = 1;
	if(0 != _number){
		int index = 1;
		for(;index <= _number; index++){
			result *= index;
		}
	}
	return result;
}
