/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Student_Information_Management                        */
/* File          : fifo.c                           					 */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "fifo.h"

FIFO_error_enu FIFO_init(FIFO_t *fifo, element_type *buffer, uint16_t length){
	FIFO_error_enu ret_state = FIFO_NO_ERROR;
	if((NULL == fifo) || (NULL == buffer)){
		DPRINTF("[ERROR] Students database is not found!\n");
		ret_state = FIFO_NULL;
	}
	else{
		fifo->base = buffer;
		fifo->head = buffer;
		fifo->tail = buffer;
		fifo->count = 0;
		fifo->length = length;
		DPRINTF("[INFO] Students database is initialized successfully!\n");
	}
	return ret_state;
}

uint8_t FIFO_RollNum_Check(FIFO_t *fifo, uint32_t Number){
	uint8_t Roll_Num_Flag = ROLL_NUMBER_UNIQUE;
	element_type *index_ptr = fifo->tail;
	int fifo_count = fifo->count;
	while(0 != fifo_count--){
		if(Number == index_ptr->Roll_Number){
			Roll_Num_Flag = ROLL_NUMBER_REPEATED;
			break;
		}
		if(index_ptr == (fifo->base + (fifo->length * sizeof(element_type)))){
			index_ptr = fifo->base;
		}
		else{
			index_ptr++;
		}
	}
	return Roll_Num_Flag;
}

FIFO_error_enu FIFO_Enqueue(FIFO_t *fifo, element_type item){
	FIFO_error_enu ret_state = FIFO_NO_ERROR;
	if(!fifo->base || !fifo->head || !fifo->tail){
		DPRINTF("[ERROR] Students database is not found!\n");
		ret_state = FIFO_NULL;
	}
	else{
		if(FIFO_NO_ERROR == FIFO_IS_FULL(fifo)){
			*(fifo->head) = item;
			fifo->count++;
			if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type)))){
				fifo->head = fifo->base;
			}
			else{
				fifo->head++;
			}
		}
		else{
			ret_state = FIFO_FULL;
		}
	}
	return ret_state;
}

FIFO_error_enu FIFO_IS_FULL(FIFO_t *fifo){
	FIFO_error_enu ret_state = FIFO_NO_ERROR;
	if(!fifo->base || !fifo->head || !fifo->tail){
		DPRINTF("[ERROR] Students database is not found!\n");
		ret_state = FIFO_NULL;
	}
	else{
		if(fifo->count >= fifo->length){
			ret_state = FIFO_FULL;
		}
		else{ /* Do Nothing */ }
	}
	return ret_state;
}

FIFO_error_enu FIFO_Remove(FIFO_t *fifo, uint32_t Number){
	FIFO_error_enu ret_state = FIFO_NO_ERROR;
	element_type *index_ptr = fifo->tail;
	if(!fifo->base || !fifo->head || !fifo->tail){
		DPRINTF("[ERROR] Students database is not found!\n");
		ret_state = FIFO_NULL;
	}
	else{
		int counter = 0, found_flag = 0;
		if(0 == fifo->count){
			DPRINTF("[ERROR] Students database is empty!\n");
			ret_state = FIFO_EMPTY;
		}
		else{
			while(counter < fifo->count){
				if(Number == index_ptr->Roll_Number){
					found_flag = 1;
					break;
				}
				else{ /* Do Nothing */ }
				if(index_ptr == (fifo->base + (fifo->length * sizeof(element_type)))){
					index_ptr = fifo->base;
				}
				else{
					index_ptr++;
				}
				counter++;
			}
			if(1 == found_flag){
				fifo->count--;
				while(counter < fifo->count){
					*(index_ptr) = *(index_ptr + 1);
					counter++;
					index_ptr++;
				}
				DPRINTF("[INFO] The Roll Number is removed Successfully\n");
			}
			else{
				DPRINTF("[ERROR] The roll number %d was not found!\n", Number);
			}
		}
	}
	return ret_state;
}

FIFO_error_enu FIFO_print_all(FIFO_t *fifo){
	FIFO_error_enu ret_state = FIFO_NO_ERROR;
	element_type *index_ptr = fifo->tail;
	if(!fifo->base || !fifo->head || !fifo->tail){
		DPRINTF("[ERROR] Students database is not found!\n");
		ret_state = FIFO_NULL;
	}
	else{
		int fifo_count = fifo->count;
		if(0 == fifo_count){
			DPRINTF("[ERROR] Students database is empty!\n");
			ret_state = FIFO_EMPTY;
		}
		else{
			while(0 != fifo_count--){
				DPRINTF("Student first name: %s\n", index_ptr->First_Name);
				DPRINTF("Student last name: %s\n", index_ptr->Last_Name);
				DPRINTF("Student roll number: %d\n", index_ptr->Roll_Number);
				DPRINTF("Student GPA number: %.2f\n", index_ptr->GPA);
				for(int i = 0; i < 5; i++){
					DPRINTF("Course %d ID is: %d\n", i+1, index_ptr->courses_ids[i]);
				}
				DPRINTF("-----------------------------------\n");
				if(index_ptr == (fifo->base + (fifo->length * sizeof(element_type)))){
					index_ptr = fifo->base;
				}
				else{
					index_ptr++;
				}
			}
		}
	}
	return ret_state;
}

FIFO_error_enu FIFO_Print_RollNum(FIFO_t *fifo, uint32_t Number){
	FIFO_error_enu ret_state = FIFO_NO_ERROR;
	element_type *index_ptr = fifo->tail;
	int found_flag = 0;
	if(!fifo->base || !fifo->head || !fifo->tail){
		DPRINTF("[ERROR] Students database is not found!\n");
		ret_state = FIFO_NULL;
	}
	else{
		int fifo_count = fifo->count;
		if(0 == fifo->count){
			DPRINTF("[ERROR] Students database is empty!\n");
			ret_state = FIFO_EMPTY;
		}
		else{
			while(0 != fifo_count--){
				if(Number == index_ptr->Roll_Number){
					found_flag = 1;
					DPRINTF("[INFO] Student Found!\n");
					DPRINTF("-----------------------------------\n");
					DPRINTF("First name: %s\n", index_ptr->First_Name);
					DPRINTF("Last name: %s\n", index_ptr->Last_Name);
					DPRINTF("Student roll number: %d\n", index_ptr->Roll_Number);
					DPRINTF("GPA: %.2f\n", index_ptr->GPA);
					for(int i = 0; i < 5; i++){
						DPRINTF("Course %d is: %d\n", i+1, index_ptr->courses_ids[i]);
					}
					DPRINTF("-----------------------------------\n");
					break;
				}
				if(index_ptr == (fifo->base + (fifo->length * sizeof(element_type)))){
					index_ptr = fifo->base;
				}
				else{
					index_ptr++;
				}
			}
			if(!found_flag){
				DPRINTF("[ERROR] Roll Number %d is not found!\n", Number);
			}
		}
	}
	return ret_state;
}

FIFO_error_enu FIFO_Print_First_Name(FIFO_t *fifo, char Name[]){
	FIFO_error_enu ret_state = FIFO_NO_ERROR;
	element_type *index_ptr = fifo->tail;
	int found_flag = 0;
	if(!fifo->base || !fifo->head || !fifo->tail){
		DPRINTF("[ERROR] Students database is not found!\n");
		ret_state = FIFO_NULL;
	}
	else{
		int fifo_count = fifo->count;
		if(0 == fifo->count){
			DPRINTF("[ERROR] Students database is empty!\n");
			ret_state = FIFO_EMPTY;
		}
		else{
			while(0 != fifo_count--){
				if(0 == strcmp(index_ptr->First_Name, Name)){
					found_flag++;
					DPRINTF("[INFO] Student Found!\n");
					DPRINTF("-----------------------------------\n");
					DPRINTF("First name: %s\n", index_ptr->First_Name);
					DPRINTF("Last name: %s\n", index_ptr->Last_Name);
					DPRINTF("Student roll number: %d\n", index_ptr->Roll_Number);
					DPRINTF("GPA: %.2f\n", index_ptr->GPA);
					for(int i = 0; i < 5; i++){
						DPRINTF("Course %d is: %d\n", i+1, index_ptr->courses_ids[i]);
					}
					DPRINTF("-----------------------------------\n");
				}
				if(index_ptr == (fifo->base + (fifo->length * sizeof(element_type)))){
					index_ptr = fifo->base;
				}
				else{
					index_ptr++;
				}
			}
			if(!found_flag){
				DPRINTF("[ERROR] No students found with first name: %s!\n", Name);
			}
		}
	}
	return ret_state;
}

FIFO_error_enu FIFO_Print_Course(FIFO_t *fifo, uint16_t course_no){
	FIFO_error_enu ret_state = FIFO_NO_ERROR;
	element_type *index_ptr = fifo->tail;
	int found_flag = 0;
	if(!fifo->base || !fifo->head || !fifo->tail){
		DPRINTF("[ERROR] Students database is not found!\n");
		ret_state = FIFO_NULL;
	}
	else{
		int fifo_count = fifo->count;
		if(0 == fifo->count){
			DPRINTF("[ERROR] Students database is empty!\n");
			ret_state = FIFO_EMPTY;
		}
		else{
			while(0 != fifo_count--){
				for(int i = 0; i < 5; i++){
					if(index_ptr->courses_ids[i] == course_no){
						found_flag++;
						DPRINTF("[INFO] Student Found!\n");
						DPRINTF("-----------------------------------\n");
						DPRINTF("First name: %s\n", index_ptr->First_Name);
						DPRINTF("Last name: %s\n", index_ptr->Last_Name);
						DPRINTF("Student roll number: %d\n", index_ptr->Roll_Number);
						DPRINTF("GPA: %.2f\n", index_ptr->GPA);
						DPRINTF("-----------------------------------\n");
						break;
					}
				}
				if(index_ptr == (fifo->base + (fifo->length * sizeof(element_type)))){
					index_ptr = fifo->base;
				}
				else{
					index_ptr++;
				}
			}
			if(!found_flag){
				DPRINTF("[ERROR] No students are enrolled in course: %d!\n", course_no);
			}
			else{
				DPRINTF("[INFO] %d students are enrolled in course: %d!\n",found_flag, course_no);
			}
		}
	}
	return ret_state;
}

FIFO_error_enu FIFO_Update_Student(FIFO_t *fifo, uint32_t Number){
	FIFO_error_enu ret_state = FIFO_NO_ERROR;
	element_type *index_ptr = fifo->tail;
	int found_flag = 0;
	if(!fifo->base || !fifo->head || !fifo->tail){
		DPRINTF("[ERROR] Students database is not found!\n");
		ret_state = FIFO_NULL;
	}
	else{
		int fifo_count = fifo->count;
		if(0 == fifo->count){
			DPRINTF("[ERROR] Students database is empty!\n");
			ret_state = FIFO_EMPTY;
		}
		else{
			while(0 != fifo_count--){
				if(Number == index_ptr->Roll_Number){
					found_flag = 1;
					break;
				}
				if(index_ptr == (fifo->base + (fifo->length * sizeof(element_type)))){
					index_ptr = fifo->base;
				}
				else{
					index_ptr++;
				}
			}
			if(0 == found_flag){
				DPRINTF("[ERROR] No students found with roll number: %d!\n", Number);
			}
			else{
				int user_choice;
				char temp_entry[50];
				DPRINTF("[INFO] Student found!\n");
				DPRINTF("\nChoose what do you want to update: ");
				DPRINTF("\n1. First Name\n");
				DPRINTF("2. Last Name\n");
				DPRINTF("3. Roll Number\n");
				DPRINTF("4. GPA\n");
				DPRINTF("5. Courses\n");
				DPRINTF("5. Cancel\n");
				DPRINTF("Your Choice: ");
				scanf("%d", &user_choice);
				getchar();
				switch(user_choice){
				case 1:
					DPRINTF("Enter the new first name: ");
					gets(temp_entry);
					strcpy(index_ptr->First_Name, temp_entry);
					DPRINTF("[INFO] First name updated successfully!");
					break;
				case 2:
					DPRINTF("Enter the new last name: ");
					gets(temp_entry);
					strcpy(index_ptr->Last_Name, temp_entry);
					DPRINTF("[INFO] Last name updated successfully!");
					break;
				case 3:
					DPRINTF("Enter the new roll number: ");
					gets(temp_entry);
					if(ROLL_NUMBER_UNIQUE == FIFO_RollNum_Check(fifo, atoi(temp_entry))){
						index_ptr->Roll_Number = atoi(temp_entry);
						DPRINTF("[INFO] Roll number updated successfully!\n");
					}
					else{
						DPRINTF("[ERROR] Roll number repeated, aborting operation!\n");
					}
					break;
				case 4:
					DPRINTF("Enter the new GPA: ");
					gets(temp_entry);
					index_ptr->GPA = atof(temp_entry);
					DPRINTF("[INFO] GPA updated successfully!");
					break;
				case 5:
					DPRINTF("Enter the new courses:\n");
					for(int i = 0; i < 5; i++){
						DPRINTF("Course %d: ", i+1);
						gets(temp_entry);
						index_ptr->courses_ids[i] = atoi(temp_entry);
					}
					DPRINTF("[INFO] Courses updated successfully!");
					break;
				case 6:
					DPRINTF("Operation canceled!");
					break;
				default: DPRINTF("Wrong choice, operation canceled!"); break;
				}
			}
		}
	}
	return ret_state;
}
