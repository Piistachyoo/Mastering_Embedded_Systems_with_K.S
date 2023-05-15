#include <stdio.h>

int main(){
	int N1, N2;
	printf("Enter two integers: ");
	fflush(stdin); fflush(stdout);
	scanf("%i %i", &N1, &N2);
	printf("Sum: %i", (N1+N2));
	return 0;
}
