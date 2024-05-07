/*
 * adc_mine.h
 *
 *  Created on: Feb 16, 2024
 *      Author: dell
 */

#ifndef ADC_MINE_H_
#define ADC_MINE_H_
#include "std_types.h"
#include"Common_Macros.h"
				/**for ADC configuration**/
#define ADC_MAXIMUM_VALUE    1023


typedef enum{
	 ADC_REF_AREF,/*AREF, Internal Vref turned off*/
	 ADC_REF_AVCC,/*AVCC with external capacitor at AREF pin*/
	 ADC_REF_RESERVED,
	 ADC_REF_INTERNAL_VREF,/*Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
}ADC_ReferenceVolatge;



typedef enum{
	ADC_PRESCALER_2,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128,
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;
         /**desired configuration global variables used*/
ADC_ConfigType desired_adc_config;
float32 ADC_REF_VOLTAGE;

/*ADC configure to operate using the internal reference voltage 2.56 voltage
		 * and pre-scaler F_CPU/8.*/


				/**function proto-ypes**/
void ADC_init(const ADC_ConfigType *Config_Ptr);
uint16 ADC_sendChannel(uint8 channel);

#endif /* ADC_MINE_H_ */
