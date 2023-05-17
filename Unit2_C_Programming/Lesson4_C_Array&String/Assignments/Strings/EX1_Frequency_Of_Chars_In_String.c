#include <stdio.h>
#include <string.h>

int main(){
	char myString[50];
	char search_char;
	int frequency, index;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(myString);
	printf("Enter a character to find frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &search_char);
	for(index = 0; myString[index] != '\0'; index++){
		if(search_char == myString[index]){
			frequency++;
		}
	}
	printf("Frequency of %c = %i", search_char, frequency);
	return 0;
}
