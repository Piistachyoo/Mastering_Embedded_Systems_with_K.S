#include <stdio.h>

int main(){
	float matrix_A[2][2];
	float matrix_B[2][2];
	int index_rows, index_cols;
	printf("Enter the elements of 1st matrix\n");
	for(index_rows = 0; index_rows < 2; index_rows++){
		for(index_cols = 0; index_cols < 2; index_cols++){
			printf("Enter a%i%i: ", index_rows+1, index_cols+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &matrix_A[index_rows][index_cols]);
		}
	}
	printf("Enter the elements of 2nd matrix\n");
	for(index_rows = 0; index_rows < 2; index_rows++){
		for(index_cols = 0; index_cols < 2; index_cols++){
			printf("Enter b%i%i: ", index_rows+1, index_cols+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &matrix_B[index_rows][index_cols]);
		}
	}
	printf("\nSum Of Matrix:\n");
	for(index_rows = 0; index_rows < 2; index_rows++){
		for(index_cols = 0; index_cols < 2; index_cols++){
			printf("%.1f\t", (matrix_A[index_rows][index_cols] + matrix_B[index_rows][index_cols]));
		}
		printf("\n");
	}
	return 0;
}
