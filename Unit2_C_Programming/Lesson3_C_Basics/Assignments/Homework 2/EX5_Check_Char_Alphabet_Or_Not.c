#include <stdio.h>

int main(){
	char entered_char;
	printf("Enter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &entered_char);
	if((('A' <= entered_char) && ('Z' >= entered_char)) || (('a' <= entered_char) && ('z' >= entered_char))){
		printf("%c is an alphabet", entered_char);
	}
	else{ printf("%c is not an alphabet", entered_char); }
	return 0;
}
