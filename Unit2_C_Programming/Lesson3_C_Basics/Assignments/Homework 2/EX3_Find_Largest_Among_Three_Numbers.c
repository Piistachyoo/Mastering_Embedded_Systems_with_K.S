#include <stdio.h>

int main(){
	float N1,N2,N3;
	printf("Enter three numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f %f", &N1, &N2, &N3);
	if(N1 > N2){
		if(N1 > N3){
			printf("Largest number = %.2f", N1);
		}
		else{
			printf("Largest number = %.2f", N3);
		}
	}
	else if(N2>N1){
		if(N2 > N3){
			printf("Largest number = %.2f", N2);
		}
		else{
			printf("Largest number = %.2f", N3);
		}
	}
	else if(N3>N1){
		if(N3 > N2){
			printf("Largest number = %.2f", N3);
		}
		else{
			printf("Largest number = %.2f", N2);
		}
	}
	else{ printf("Error! Two or more numbers are equal!"); }
	return 0;
}
