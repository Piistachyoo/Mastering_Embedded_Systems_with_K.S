/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX3_Print_Reverse_String_Using_Pointers.c             */
/* Date          : May 21, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include<stdio.h>

int main(){
	char input_str[50];
	int index = 0;
	char *str_ptr = 0;
	printf("Input a string : ");
	fflush(stdin); fflush(stdout);
	gets(input_str);
	str_ptr = input_str;
	while(*str_ptr){
		str_ptr++;
		index++;
	}
	str_ptr--;
	printf("Reverse of the string is : ");
	while(index){
		printf("%c", *str_ptr);
		str_ptr--;
		index--;
	}
	return 0;
}
