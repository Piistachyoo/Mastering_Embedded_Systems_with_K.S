/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                               		 	 */
/* File          : EX4_Power_Of_Number_Recursion.c                       */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

int Get_Power(int number, int power);

int main(){
	int entered_number, entered_power;
	printf("Enter base number: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &entered_number);
	printf("Enter power number(positive integer): ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &entered_power);
	printf("%i^%i = %i", entered_number, entered_power, Get_Power(entered_number, entered_power));
	return 0;
}

int Get_Power(int number, int power){
	static int result = 1;
	if(0 != power){
		result *= number;
		Get_Power(number, --power);
	}
	return result;
}
