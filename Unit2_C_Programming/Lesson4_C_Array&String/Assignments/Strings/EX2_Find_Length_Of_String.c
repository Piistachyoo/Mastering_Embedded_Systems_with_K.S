#include <stdio.h>

int main(){
	char myString[50];
	int length = 0;
	int index;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(myString);
	for(index = 0; myString[index] != '\0'; index++){
		length++;
	}
	printf("Length of string: %i", length);
	return 0;
}
