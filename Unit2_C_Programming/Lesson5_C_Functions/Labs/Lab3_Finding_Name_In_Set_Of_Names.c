/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project		 : C_Programming				 						 */
/* File          : LAB3_Finding_Name_In_Set_Of_Names.c                   */
/* Date          : May 18, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>


int findName(char names[][14], int n, char name[]);

int main(){
	char name[14];
	char names[5][14] = {"Alaa", "Osama", "Mamdouh", "Samy", "Hossain"};
	puts("Enter your first name: ");
	fflush(stdin); fflush(stdout);
	gets(name);
	if(findName(names, 5, name) == 1)
		puts("Welcome");
	else
		puts("Goodbye");
	return 0;
}

int findName(char names[][14], int n, char name[]){
	int found_flag;
	int row_index = 0;
	int col_index = 0;
	for(; row_index < n; row_index++){
		found_flag = 1;
		for(;col_index < 14; col_index++){
			if((names[row_index][col_index] == '\0') && (name[col_index] == '\0')){
				break;
			}
			if(name[col_index] == names[row_index][col_index]){
				found_flag = 1;
			}
			else{
				found_flag = 0;
				break;
			}
		}
		if(1 == found_flag){
			break;
		}
	}
	return found_flag;
}
