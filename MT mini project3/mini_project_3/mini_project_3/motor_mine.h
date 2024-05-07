/*
 * motor_mine.h
 *
 *  Created on: Feb 22, 2024
 *      Author: dell
 */

#ifndef MOTOR_MINE_H_
#define MOTOR_MINE_H_
#include "std_types.h"
/**motor state**/
typedef enum{
	MOTOR_OFF,
	MOTOR_CW,/*A(IN1)=0,   B(IN2)=1 */
	MOTOR_A_CW,/*A(IN1)=1,   B(IN2)=0 */
}DcMotor_State;

/**function prototypes**/
/* Description
➢ The Function responsible for setup the direction for the two motor pins through the GPIO driver.
➢ Stop at the DC-Motor at the beginning through the GPIO driver.*/
void DcMotor_Init(void);

/*Description:
➢ The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
➢ Send the required duty cycle to the PWM driver based on the required speed value.*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed);
#endif /* MOTOR_MINE_H_ */
