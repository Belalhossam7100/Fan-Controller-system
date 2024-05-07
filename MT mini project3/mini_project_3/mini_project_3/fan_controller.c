/*
 * fan_controller.c
 *
 *  Created on: Feb 21, 2024
 *      Author: dell
 */
#include "lcd.h"
#include "temp_sensor_mine.h"
#include "motor_mine.h"
int main(){
	uint8 measered_temp;
	uint8 duty_cycle;
	DcMotor_State fan_state=MOTOR_OFF;
	LCD_init();

	DcMotor_Init();
	/**  LCD screen display**/
	LCD_moveCursor(0,2);
	LCD_displayString("FAN IS ");
	LCD_moveCursor(1,2);
	LCD_displayString("TEMP=    C");

	while(1)
{

	if(measered_temp<30){
		fan_state=MOTOR_OFF;
		duty_cycle=0;
		DcMotor_Rotate(fan_state,duty_cycle);
	}
	else{
		fan_state=MOTOR_CW;
		if(measered_temp>=30 && measered_temp<60 ){
			duty_cycle=25;/*to get 25% of the motor speed*/
		}
		else if(measered_temp>=60 && measered_temp<90){
			duty_cycle=50;/*to get 50% of the motor speed*/
		}
		else if(measered_temp>=90 && measered_temp<120){
			duty_cycle=75;/*to get 75% of the motor speed*/
		}
		else if(measered_temp>120){
			duty_cycle=100;/*to get 100% of the motor speed*/
		}
		DcMotor_Rotate(fan_state,duty_cycle);
	}


			/***** LCD screen variable display ******/
	/*FAN STATE*/
	LCD_moveCursor(0,9);
		if(fan_state==MOTOR_OFF){
			LCD_displayString("OFF");
		}
		else{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}
	/*TEMPRATURE STATE*/
	LCD_moveCursor(1,7);
		measered_temp=get_temp();
		if(measered_temp >= 100)
				{
					LCD_intgerToString(measered_temp);
				}
				else
				{
					LCD_intgerToString(measered_temp);
					/* In case the digital value is two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
}
return 0;
}
