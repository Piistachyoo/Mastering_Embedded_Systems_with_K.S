/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : EX3_Reverse_Sentence_Recursion.c                      */
/* Date          : May 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

void reverse_sentence_recursion(char sen[], int str_len);

int main(){
	char entered_sentence[50];
	int str_len = 0;
	printf("Enter a sentence: ");
	fflush(stdin); fflush(stdout);
	gets(entered_sentence);
	for(; entered_sentence[str_len] != '\0'; str_len++);
	str_len--;
	reverse_sentence_recursion(entered_sentence, str_len);
	puts(entered_sentence);
	return 0;
}

void reverse_sentence_recursion(char sen[], int str_len){
	static int iterator = 0;
	if((str_len/2) >= iterator){
		char temp = sen[iterator];
		sen[iterator] = sen[str_len-iterator];
		sen[str_len-iterator] = temp;
		if((str_len/2) != iterator){
			iterator++;
			reverse_sentence_recursion(sen, str_len);
		}
	}
}
