/*
 * pwm_mine.c
 *
 *  Created on: Feb 22, 2024
 *      Author: dell
 */
#include <avr/io.h>
#include "pwm_mine.h"

void PWM_Timer0_Start(uint8 duty_cycle){
		TCNT0 = 0; /* Set Timer Initial Value to 0*/
		/* F CPU = 1 MHZ
		 * F PWM = 500 HZ
		 * N = 8*/
		uint8 compare_value=(duty_cycle*255)/100;
		OCR0  = compare_value; /*Set Compare value*/
		DDRB  = DDRB | (1<<PB3);/*EN1  output pin for PWM*/
		/* Configure timer control register
		 * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
		 */
		TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
