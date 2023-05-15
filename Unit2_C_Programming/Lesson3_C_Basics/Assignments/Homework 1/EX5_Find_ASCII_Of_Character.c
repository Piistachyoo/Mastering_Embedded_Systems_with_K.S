#include <stdio.h>

int main(){
	char entered_char;
	printf("Enter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &entered_char);
	printf("ASCII value of %c = %i", entered_char, entered_char);
	return 0;
}
