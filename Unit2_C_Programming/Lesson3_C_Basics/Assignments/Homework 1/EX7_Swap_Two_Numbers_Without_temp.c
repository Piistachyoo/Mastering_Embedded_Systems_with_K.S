#include <stdio.h>

int main(){
	int a, b;
	printf("Enter value of a: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &a);
	printf("Enter value of b: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &b);
	/* Perform swap without temp */
	a ^= b;
	b ^= a;
	a ^= b;
	printf("\nAfter swapping, value of a = %i", a);
	printf("\nAfter swapping, value of b = %i", b);
	return 0;
}
