/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : linked_list_students_project                        	 */
/* File          : main.c                           					 */
/* Date          : May 29, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DPRINTF(...)	{fflush(stdout);fflush(stdin);\
						 printf(__VA_ARGS__);\
						 fflush(stdout);fflush(stdin);}

typedef struct{
	unsigned int ID;
	char 		 name[40];
	float		 height;
}S_data;

struct S_student{
	S_data data;
	struct S_student* P_next_student;
};

struct S_student *gpFirstStudent;

void AddStudent(void);
int DeleteStudent(void);
void ListStudents();
void DeleteAll();
void fill_the_record(struct S_student* new_student);
void Get_Nth_Node();
void Calculate_Nodes_In_LinkedList();
int Calculate_Nodes_In_LinkedList_Recursive(struct S_student* pStudentNode);
void Get_Nth_Node_From_End();
void Print_Middle_Of_Linkedlist();
void Detect_Loop();
void Reverse_List();

int main(){
	int user_choice;

	while(1){
		DPRINTF("\n===============");
		DPRINTF("\n\tChoose one of the following options: \n");
		DPRINTF("\n 1: Add Student");
		DPRINTF("\n 2: Delete Student");
		DPRINTF("\n 3: List all students");
		DPRINTF("\n 4: Delete all students");
		DPRINTF("\n 5: Print student data at Nth node");
		DPRINTF("\n 6: Print number of nodes in linkedlist (Normal)");
		DPRINTF("\n 7: Print number of nodes in linkedlist (Recursive)");
		DPRINTF("\n 8: Print Nth node from the end");
		DPRINTF("\n 9: Print middle node of linkedlist");
		DPRINTF("\n 10: Check if there is a loop");
		DPRINTF("\n 11: Reverse the list");
		DPRINTF("\n 12: Exit app");
		DPRINTF("\n Enter option number: ");
		scanf("%i", &user_choice);
		switch(user_choice){
		case 1:
			AddStudent();
			break;
		case 2:
			DeleteStudent();
			break;
		case 3:
			ListStudents();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			Get_Nth_Node();
			break;
		case 6:
			Calculate_Nodes_In_LinkedList();
			break;
		case 7:
			int count;
			count = Calculate_Nodes_In_LinkedList_Recursive(gpFirstStudent);
			DPRINTF("\nNumber of nodes is: %i\n", count);
			break;
		case 8:
			Get_Nth_Node_From_End();
			break;
		case 9:
			Print_Middle_Of_Linkedlist();
			break;
		case 10:
			Detect_Loop();
			break;
		case 11:
			Reverse_List();
			break;
		case 12: return 1;
		default: DPRINTF("ERROR: Enter a correct option!\n");
		}
	}
	return 0;
}

void AddStudent(void){
	struct S_student *pLast_student;
	struct S_student *pNew_student;

	/* Check if the list is empty */
	if(NULL == gpFirstStudent){
		/* Create new record */
		pNew_student = (struct S_student*)malloc(sizeof(struct S_student));
		/* Assign new student to head */
		gpFirstStudent = pNew_student;
	}
	else{
		pLast_student = gpFirstStudent;
		/* Navigate to last student */
		while(NULL != pLast_student->P_next_student){
			pLast_student = pLast_student->P_next_student;
		}
		/* Create new record */
		pNew_student = (struct S_student*)malloc(sizeof(struct S_student));
		/* Set new record as last student */
		pLast_student->P_next_student = pNew_student;
	}

	fill_the_record(pNew_student);
	pNew_student->P_next_student = NULL;
}

int DeleteStudent(void){
	struct S_student *pPreviousStudent = NULL;
	struct S_student *pCurrentStudent = gpFirstStudent;
	int selected_ID;

	/* Get the selected ID */
	DPRINTF("Enter the student ID to be deleted : ");
	fflush(stdin); fflush(stdout);
	scanf("%i", &selected_ID);

	/* If list is not empty */
	if(gpFirstStudent){
		/* Loop on all records */
		while(pCurrentStudent){
			/* Compare each node with the selected ID */
			if(selected_ID == pCurrentStudent->data.ID){
				/* Check if selected node is first node or not */
				if(pPreviousStudent){
					pPreviousStudent->P_next_student = pCurrentStudent->P_next_student;
				}
				else{
					gpFirstStudent = pCurrentStudent->P_next_student;
				}
				free(pCurrentStudent);
				return 1;
			}
			pPreviousStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->P_next_student;
		}
	}
	DPRINTF("\nCannot find student with ID = %i\n", selected_ID);
	return 0;
}

void ListStudents(){
	struct S_student *pCurrentStudent = gpFirstStudent;
	int count = 1;
	if(pCurrentStudent){
		DPRINTF("================\n\n");
		while(pCurrentStudent){
			DPRINTF("Record Number %i\n", count);
			DPRINTF("\tID: %i\n", pCurrentStudent->data.ID);
			DPRINTF("\tName: %s\n", pCurrentStudent->data.name);
			DPRINTF("\tHeight: %.2f\n\n", pCurrentStudent->data.height);
			pCurrentStudent = pCurrentStudent->P_next_student;
			count++;
		}
		DPRINTF("================\n\n");
	}
	else{
		DPRINTF("\nERROR: List is empty!\n");
	}
}

void DeleteAll(){
	struct S_student *pCurrentStudent = gpFirstStudent;
	struct S_student *pTempStudent = NULL;
	int count = 0;
	if(pCurrentStudent){
		while(pCurrentStudent){
			pTempStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->P_next_student;
			free(pTempStudent);
			count++;
		}
		gpFirstStudent = NULL;
		DPRINTF("\nDeleted %i students!\n", count);
	}
	else{
		DPRINTF("\nERROR: List is empty!\n");
	}
}

void fill_the_record(struct S_student* new_student){
	DPRINTF("\nEnter the ID : ");
	scanf("%i", &(new_student->data.ID));
	DPRINTF("Enter Student Full Name : ");
	getchar();
	gets(new_student->data.name);
	DPRINTF("Enter height : ");
	scanf("%f", &new_student->data.height);
}

void Get_Nth_Node(){
	int selected_node, count = 0;
	DPRINTF("Enter index of the student to print: ");
	scanf("%i", &selected_node);
	struct S_student *pCurrentStudent = gpFirstStudent;
	while(pCurrentStudent){
		if(count == selected_node){
			DPRINTF("\tID: %i\n", pCurrentStudent->data.ID);
			DPRINTF("\tName: %s\n", pCurrentStudent->data.name);
			DPRINTF("\tHeight: %.2f\n\n", pCurrentStudent->data.height);
			return;
		}
		count++;
		pCurrentStudent = pCurrentStudent->P_next_student;
	}
	DPRINTF("ERROR: Index not found!");
}

void Calculate_Nodes_In_LinkedList(){
	struct S_student *pCurrentStudent = gpFirstStudent;
	int count = 0;
	while(pCurrentStudent){
		pCurrentStudent = pCurrentStudent->P_next_student;
		count++;
	}
	DPRINTF("\nNumber of nodes is: %i\n", count);
}

int Calculate_Nodes_In_LinkedList_Recursive(struct S_student* pStudentNode){
	if(pStudentNode)
		return (1 + Calculate_Nodes_In_LinkedList_Recursive(pStudentNode->P_next_student));
	else
		return 0;
}

void Get_Nth_Node_From_End(){
	struct S_student* pCurrentStudent = gpFirstStudent;
	struct S_student* pLateStudent = gpFirstStudent;
	int node_difference, i=0;
	DPRINTF("\nEnter index of the student from the end to print: ");
	scanf("%i", &node_difference);
	while(i<node_difference){
		pCurrentStudent = pCurrentStudent->P_next_student;
		i++;
	}
	while(pCurrentStudent){
		pCurrentStudent = pCurrentStudent->P_next_student;
		pLateStudent = pLateStudent->P_next_student;
	}
	DPRINTF("\n\tID: %i\n", pLateStudent->data.ID);
	DPRINTF("\tName: %s\n", pLateStudent->data.name);
	DPRINTF("\tHeight: %.2f\n\n", pLateStudent->data.height);
}

void Print_Middle_Of_Linkedlist(){
	if(!gpFirstStudent){
		DPRINTF("ERROR: List is empty!\n");
		return;
	}
	struct S_student *pFastPtr = gpFirstStudent, *pSlowPtr = gpFirstStudent;
	while((pFastPtr->P_next_student != NULL) && (pFastPtr->P_next_student->P_next_student != NULL)){
		pFastPtr = pFastPtr->P_next_student->P_next_student;
		pSlowPtr = pSlowPtr->P_next_student;
	}
	DPRINTF("\n\tID: %i\n", pSlowPtr->data.ID);
	DPRINTF("\tName: %s\n", pSlowPtr->data.name);
	DPRINTF("\tHeight: %.2f\n\n", pSlowPtr->data.height);
}

void Detect_Loop(){
	struct S_student *pCurrentStudent = gpFirstStudent, *pReferenceStudent = gpFirstStudent;
	while(pCurrentStudent && pReferenceStudent && pCurrentStudent->P_next_student){
		pReferenceStudent = pReferenceStudent->P_next_student;
		pCurrentStudent = pCurrentStudent->P_next_student->P_next_student;
		if(pCurrentStudent == pReferenceStudent){
			DPRINTF("\nLOOP FOUND!\n");
			return;
		}
	}
	DPRINTF("\nNo loop found\n");
}

void Reverse_List(){
	struct S_student *pPreviousStudent = gpFirstStudent, *pCurrentStudent = gpFirstStudent->P_next_student, *pNextStudent;
	while(pCurrentStudent){
		pNextStudent = pCurrentStudent->P_next_student;
		pCurrentStudent->P_next_student = pPreviousStudent;
		if(pPreviousStudent == gpFirstStudent)
			pPreviousStudent->P_next_student = NULL;
		pPreviousStudent = pCurrentStudent;
		pCurrentStudent = pNextStudent;
	}
	gpFirstStudent = pPreviousStudent;
}
