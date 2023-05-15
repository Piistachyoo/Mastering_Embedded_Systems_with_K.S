#include <stdio.h>

int main(){
	float N1, N2;
	printf("Enter two numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f", &N1, &N2);
	printf("Product: %f", (N1*N2));
	return 0;
}
