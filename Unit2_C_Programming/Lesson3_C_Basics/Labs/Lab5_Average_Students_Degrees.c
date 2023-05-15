#include <stdio.h>

int main(){
	int index;
	int temp_buffer;
	int no_of_students;
	int students_sum=0;
	float students_average;
	printf("Enter the number of the students: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &no_of_students);
	for(index = 0;index < no_of_students;index++){
		printf("Enter Student (%i) degree: ", (index+1));
		fflush(stdin); fflush(stdout);
		scanf("%i", &temp_buffer);
		students_sum += temp_buffer;
	}
	students_average = (float)students_sum / (float) no_of_students;
	printf("Average students degree is : %.2f", students_average);
	return 0;
}
