/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : unit4_lesson2_CA_v2                                   */
/* File          : state.h                                               */
/* Date          : May 31, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef STATE_H_
#define STATE_H_

/* Automatic state function generated */
#define STATE_define(_stateFun_) void ST_##_stateFun_()
#define STATE(_stateFun_) ST_##_stateFun_

/* States Connection */
void US_Get_Distance(int Distance);
void DC_Motor_Set_Speed(int Speed);

#endif /* STATE_H_ */
