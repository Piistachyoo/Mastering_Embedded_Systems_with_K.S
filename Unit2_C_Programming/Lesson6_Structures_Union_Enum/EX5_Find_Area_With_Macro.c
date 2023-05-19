/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : C_Programming                                    	 */
/* File          : EX5_Find_Area_With_Macro.c                            */
/* Date          : May 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>

#define pi		3.141593f
#define Get_Area(_radius)	(_radius * _radius * pi)

int main(){
	int radius;
	printf("Enter the radius: ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &radius);
	printf("Area=%.2f", (float)Get_Area(radius));
	return 0;
}
