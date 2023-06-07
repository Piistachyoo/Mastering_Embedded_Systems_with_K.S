/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit7_lesson1_section                                 */
/* File          : Utils.h                           					 */
/* Date          : Jun 7, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef UTILS_H_
#define UTILS_H_

//function to set a bit to 1
#define SET_BIT(REG_Name, BIT_No) (REG_Name |= (1<<BIT_No))

//function to toggle a bit (0 to 1 or 1 to 0)
#define TOG_BIT(REG_Name, BIT_No) (REG_Name ^= (1<<BIT_No))

//function to clear a bit to 0
#define CLR_BIT(REG_Name, BIT_No) (REG_Name &= (~(1<<BIT_No)))

//function to read a bit
#define GET_BIT(REG_Name, BIT_No) ((REG_Name>>BIT_No) & 1)

#endif /* UTILS_H_ */
