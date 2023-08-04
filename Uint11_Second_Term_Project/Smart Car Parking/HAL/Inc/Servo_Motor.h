/*
 * Servo_Motor.h
 *
 *  Created on: Nov 12, 2021
 *      Author:  Mostafa Mahmoud Elshiekh
 */



#ifndef SERVO_MOTOR_SERVO_MOTOR_H_
#define SERVO_MOTOR_SERVO_MOTOR_H_

#include "STM32F103x8.h"
#include "gpio_driver.h"
#include "Timer.h"

#define SERVO_UP		0
#define SERVO_DOWN		1


void Servo1_Entry_Gate_Init(void);
void Servo1_Entry_Gate(uint8 Direction);

void Servo2_Exit_Gate_Init(void);
void Servo2_Exit_Gate(uint8 Direction);





#endif /* SERVO_MOTOR_SERVO_MOTOR_H_ */
