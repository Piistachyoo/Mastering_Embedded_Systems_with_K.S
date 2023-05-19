/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX9_Reverse_Words_In_String.c                         */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

void reverse_string(char str[], int str_len);

int main(){
	char p[] = "mohamed gamal.";
	printf("Input string: %s\n", p);
	reverse_string(p, 15);
	printf("Reversed string: %s\n", p);
	return 0;
}

void reverse_string(char str[], int str_len){
	int space_index = -1;
	int index, reversed_array_index;
	char reversed_temp_array[50];
	for(index = 0; index < str_len; index++){
		if(' ' == str[index]){
			space_index = index;
			break;
		}
	}
	if(-1 == space_index){
		printf("Space not found, please enter two words separated by space!\n");
	}
	else{
		for(index = (space_index+1), reversed_array_index = 0; index < str_len; index++, reversed_array_index++){
			if(('.' == str[index]) || ('\0' == str[index]))
				break;
			else
				reversed_temp_array[reversed_array_index] = str[index];
		}
		reversed_temp_array[reversed_array_index++] = ' ';
		for(index = 0; str[index] != ' '; index++, reversed_array_index++){
			reversed_temp_array[reversed_array_index] = str[index];
		}
		reversed_temp_array[reversed_array_index++] = '.';
		reversed_temp_array[reversed_array_index++] = '\0';
	}
	for(index = 0; index < str_len; index++){
		str[index] = reversed_temp_array[index];
	}
}
