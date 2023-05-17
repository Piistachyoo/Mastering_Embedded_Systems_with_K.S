#include <stdio.h>
#include <string.h>

int main(){
	char myString[50];
	int index;
	char temp;
	printf("Enter the string  : ");
	fflush(stdin); fflush(stdout);
	gets(myString);
	int string_len = strlen(myString);
	string_len--;
	for(index = 0; index < (string_len/2); index++){
		temp = myString[index];
		myString[index] = myString[(string_len - index)];
		myString[(string_len - index)] = temp;
	}
	puts(myString);
	return 0;
}
