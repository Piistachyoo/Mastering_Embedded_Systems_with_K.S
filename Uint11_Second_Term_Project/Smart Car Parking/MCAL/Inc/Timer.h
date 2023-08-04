/*
 * Timer.h
 *
 *  Created on: Oct 10, 2021
 *      Author: Mostafa Elshiekh
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "STM32F103x8.h"
#include "gpio_driver.h"

#define RCC_APB1ENR                           *( volatile uint32 *)(RCC_BASE+0x1C)
#define RCC_APB2ENR                           *( volatile uint32 *)(RCC_BASE+0x18)





//TIMER2
#define TIM2_timer_Base                        0x40000000
#define TIM2_CNT                              *( volatile uint32 *)(TIM2_timer_Base+0x24)
#define TIM2_CR1                              *( volatile uint32 *)(TIM2_timer_Base+0x00)
#define TIM2_PSC                              *( volatile uint32 *)(TIM2_timer_Base+0x28)
#define TIM2_SR                               *( volatile uint32 *)(TIM2_timer_Base+0x10)
#define TIM2_DIER                             *( volatile uint32 *)(TIM2_timer_Base+0x0c)
#define TIM2_ARR                              *( volatile uint32 *)(TIM2_timer_Base+0x2c)



/*=================Timer2======================*/
void Timer2_init(void);
void dus(int us);
void dms(int ms);

#endif /* INC_TIMER_H_ */
