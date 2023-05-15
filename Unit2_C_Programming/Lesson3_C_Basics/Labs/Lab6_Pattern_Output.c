#include <stdio.h>

int main(){
	int index_1, index_2;
	for(index_1 = 0;index_1 < 10;index_1++){
		for(index_2 = index_1;index_2 < 10;index_2++){
			printf("%i ", index_2);
		}
		printf("\n");
	}
	return 0;
}
