/*
 * adc_mine.c
 *
 *  Created on: Feb 16, 2024
 *      Author: dell
 */


#include "adc_mine.h"
#include <avr/io.h>




void ADC_init(const ADC_ConfigType *Config_Ptr){
ADMUX = 0;/*for initialization*/

/* Initialize ADC configuration */
desired_adc_config.ref_volt = ADC_REF_INTERNAL_VREF;
desired_adc_config.prescaler = ADC_PRESCALER_8;

switch(Config_Ptr->ref_volt)
	{
	case ADC_REF_AREF:
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
	break;

	case ADC_REF_AVCC:
		SET_BIT(ADMUX,REFS0);/*to choose internal 2.56v reference voltage*/
		CLEAR_BIT(ADMUX,REFS1);
		ADC_REF_VOLTAGE=5;
	break;

	case ADC_REF_RESERVED:
		CLEAR_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
	break;

	case ADC_REF_INTERNAL_VREF:
		SET_BIT(ADMUX,REFS0);/*to choose internal 2.56v reference voltage*/
		SET_BIT(ADMUX,REFS1);
		ADC_REF_VOLTAGE=2.56;
	break;
	}


SET_BIT(ADCSRA,ADEN);/*enable ADC*/

switch(Config_Ptr->prescaler)
		{
	case ADC_PRESCALER_2:
		/*Setting pre-scaler to 8*/
		CLEAR_BIT(ADCSRA,ADPS2);
		CLEAR_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS0);
	break;

	case ADC_PRESCALER_4:
			/*Setting pre-scaler to 8*/
			CLEAR_BIT(ADCSRA,ADPS2);
			CLEAR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS0);
	break;

	case ADC_PRESCALER_8:
		/*Setting pre-scaler to 8*/
		CLEAR_BIT(ADCSRA,ADPS2);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS0);
	break;

	case ADC_PRESCALER_16:
		/*Setting pre-scaler to 8*/
		SET_BIT(ADCSRA,ADPS2);
		CLEAR_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS0);
	break;

	case ADC_PRESCALER_32:
			/*Setting pre-scaler to 8*/
			SET_BIT(ADCSRA,ADPS2);
			CLEAR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS0);
	break;

	case ADC_PRESCALER_64:
			/*Setting pre-scaler to 8*/
			SET_BIT(ADCSRA,ADPS2);
			SET_BIT(ADCSRA,ADPS1);
			CLEAR_BIT(ADCSRA,ADPS0);
	break;

	case ADC_PRESCALER_128:
			/*Setting pre-scaler to 8*/
			SET_BIT(ADCSRA,ADPS2);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS0);
	break;
		}


}
uint16 ADC_readChannel(uint8 channel_num){//the needed pin as anolgue input pin is send to this fucntion
	// the line sets the appropriate bits in ADMUX to select the desired ADC channel for conversion.
	ADMUX=((ADMUX&0xE0)|(channel_num&0x0E));//insert channel num to the ADMUX0:4 bits
		//11100000=0xE0 clear the first 5 bits in ADMUX register
		SET_BIT(ADCSRA,ADSC);//start conversion
		while(!(ADCSRA&(1<<ADIF))){//Polling until ADIF=1 (conevrsion is completed)
		}
		SET_BIT(ADCSRA,ADIF);//clear it to start again
		return ADC;//gives back the output that is inside ADC REGISTER

}
