/*
 * temp_sensor_mine.c
 *
 *  Created on: Feb 17, 2024
 *      Author: dell
 */

#include "temp_sensor_mine.h"
#include "adc_mine.h"


uint8 get_temp(){
	ADC_init(&desired_adc_config);
	uint16 reading_from_adc=0;
	uint8 temp=0;
	reading_from_adc=ADC_readChannel(SENSOR_CHANNEL_NUM);
	temp=(uint8)(((uint32)(reading_from_adc) * (SENSOR_MAX_READING) * (ADC_REF_VOLTAGE))/(SENSOR_MAX_VALUE*ADC_MAXIMUM_VALUE));
return temp;
}
