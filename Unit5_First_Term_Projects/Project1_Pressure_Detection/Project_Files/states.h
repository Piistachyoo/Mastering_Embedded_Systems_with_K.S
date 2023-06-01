/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Pressure_Detection                                    */
/* File          : states.h			                                     */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef STATES_H_
#define STATES_H_

/* States macros */
#define STATEFUN(_STATE_)	void ST_##_STATE_()
#define STATELBL(_STATE_)	ST_##_STATE_

/* Global APIs */
void Update_Pressure_value(int pressure_value);
void Start_Alarm();
void Stop_Alarm();
void High_Pressure_Detected();

#endif /* STATES_H_ */
