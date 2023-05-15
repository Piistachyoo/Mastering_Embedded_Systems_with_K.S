#include <stdio.h>

int main(){
	char entered_operator;
	float operand1, operand2;
	printf("Enter operator either + or - or * or divide : ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &entered_operator);
	printf("Enter two operands: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f", &operand1, &operand2);
	switch(entered_operator){
	case '+':
		printf("%.1f %c %.1f = %.1f", operand1, entered_operator, operand2, (operand1 + operand2));
		break;
	case '-':
		printf("%.1f %c %.1f = %.1f", operand1, entered_operator, operand2, (operand1 - operand2));
		break;
	case '*':
		printf("%.1f %c %.1f = %.1f", operand1, entered_operator, operand2, (operand1 * operand2));
		break;
	case '/':
		printf("%.1f %c %.1f = %.1f", operand1, entered_operator, operand2, (operand1 / operand2));
		break;
	default: printf("Wrong operator!"); break;
	}
	return 0;
}
