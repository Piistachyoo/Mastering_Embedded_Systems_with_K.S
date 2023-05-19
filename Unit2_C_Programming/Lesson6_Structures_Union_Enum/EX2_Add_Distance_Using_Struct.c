/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX2_Add_Distance_Using_Struct.c                       */
/* Date          : May 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

struct distance{
	int feet;
	float inch;
};

int main(){
	struct distance distance1, distance2, result;
	printf("Enter information for 1st distance\n");
	printf("Enter feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &distance1.feet);
	printf("Enter inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &distance1.inch);
	printf("\nEnter information for 2nd distance\n");
	printf("Enter feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &distance2.feet);
	printf("Enter inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &distance2.inch);
	result.feet = distance1.feet + distance2.feet;
	result.inch = distance1.inch + distance2.inch;
	if(12 < result.inch){
		result.inch -= 12;
		result.feet++;
	}
	printf("\nSum of distances=%i'-%.1f\"", result.feet, result.inch);
	return 0;
}
