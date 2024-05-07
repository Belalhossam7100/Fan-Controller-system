/*
 * motor_mine.c
 *
 *  Created on: Feb 22, 2024
 *      Author: dell
 */
#include "gpio.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "motor_mine.h"
#include "pwm_mine.h"
void DcMotor_Init(void){
	/*set up pin directions*/
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);/*IN1*/
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);/*IN2*/

	/*STOP THE MOTOR AT THE BEGINING*/
	GPIO_writePin(PORTB_ID,PIN0_ID,0);/*IN1*/
	GPIO_writePin(PORTB_ID,PIN1_ID,0);/*IN2*/
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	if ((state==MOTOR_OFF))
	{
	PWM_Timer0_Start(speed);
	GPIO_writePin(PORTB_ID,PIN0_ID,0);/*IN1*/
	GPIO_writePin(PORTB_ID,PIN1_ID,0);/*IN2*/
	}
	else
	{
	PWM_Timer0_Start(speed);
		if((state==MOTOR_CW)){
			/*A(IN1)=0,   B(IN2)=1 */
			GPIO_writePin(PORTB_ID,PIN0_ID,0);/*IN1*/
			GPIO_writePin(PORTB_ID,PIN1_ID,1);/*IN2*/
		}
		else if((state==MOTOR_A_CW)){
			/*A(IN1)=1,   B(IN2)=0 */
			GPIO_writePin(PORTB_ID,PIN0_ID,1);/*IN1*/
			GPIO_writePin(PORTB_ID,PIN1_ID,0);/*IN2*/
		}
	}
}
