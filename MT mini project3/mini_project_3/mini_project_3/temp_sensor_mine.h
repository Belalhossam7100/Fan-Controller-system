/*
 * temp_sensor_mine.h
 *
 *  Created on: Feb 17, 2024
 *      Author: dell
 */

#ifndef TEMP_SENSOR_MINE_H_
#define TEMP_SENSOR_MINE_H_
#include "std_types.h"

/*SENSOR definition*/
#define SENSOR_CHANNEL_NUM 2//sensor connected to PA2/ADC2
#define SENSOR_MAX_READING 150//IN C
#define SENSOR_MAX_VALUE 1.5//v sensor max=1.5v


uint8 get_temp(void);

#endif /* TEMP_SENSOR_MINE_H_ */


