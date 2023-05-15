#include <stdio.h>

int main(){
	char entered_char;
	printf("Enter an alphabet: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &entered_char);
	if(('a' == entered_char) || ('e' == entered_char) ||
	('i' == entered_char) || ('o' == entered_char) || ('u' == entered_char) ||
	('A' == entered_char) || ('E' == entered_char) ||
	('I' == entered_char) || ('O' == entered_char) || ('U' == entered_char)){
		printf("%c is a vowel.", entered_char);
	}
	else{
		printf("%c is a consonant.", entered_char);
	}
	return 0;
}
