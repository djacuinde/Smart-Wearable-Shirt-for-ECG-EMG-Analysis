/*
 * conf_adc.c
 *
 * Created: 9/10/2020 2:13:33 PM
 *  Author: Daniel Jacuinde-Alvarez
 */ 

#include <asf.h>
#include "conf_adc.h"

/* Structure for ADC module instance */
struct adc_module adc_instance;

/*  To Store ADC output in voltage format */
float result;

/* To store raw_result of ADC output */
uint16_t raw_result;

/* To read the STATUS register of ADC */
uint8_t status;



/**
* \brief ADC Differential mode configuration.
* This function configures ADC as differential mode with below Settings

*		Pulses = (time[s]* Oscilloscope Frequency[Hz])/Prescaler

* GLCK for ADC		-> GCLK_GENERATOR_1 (48MHz)
* REFERENCE			-> 0.5(3.3V) = 1.65V
* POSITIVE INPUT	-> Analog Pin
* NEGATIVE INPUT	-> GND
*/

void configure_adc_differential(uint8_t pin, uint8_t ADC_Resolution_Value)
{
	struct adc_config conf_adc;
	
	adc_get_config_defaults(&conf_adc);

	conf_adc.clock_source = GCLK_GENERATOR_1;
	conf_adc.reference = ADC_REFERENCE_INTVCC1;
	conf_adc.clock_prescaler = ADC_CLOCK_PRESCALER_DIV16;
	
	if (ADC_Resolution_Value == 10)
		conf_adc.resolution = ADC_RESOLUTION_10BIT;
	else if (ADC_Resolution_Value == 12)
		conf_adc.resolution = ADC_RESOLUTION_12BIT;
	else 
		conf_adc.resolution = ADC_RESOLUTION_8BIT;
	
	conf_adc.differential_mode = true;
	
	if (pin == A0)
		conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN0;
	else if (pin == A1)
		conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN1;
	else if (pin == A2)
		conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN2;
	else if (pin == A3)
		conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN3;
	else if (pin == A4)
		conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN4;
	else if (pin == A5)
		conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN5;
	else if (pin == A6)
		conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN6;
	else if (pin == A7)
		conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN7;

							
	conf_adc.negative_input = ADC_NEGATIVE_INPUT_GND;
	
	adc_init(&adc_instance, ADC, &conf_adc);
	adc_enable(&adc_instance);
}


/**
* \brief ADC START and Read Result.
*
* This function starts the ADC and wait for the ADC
* conversation to be complete and read the ADC result
* register and return the same to calling function.
*/


uint16_t adc_start_read_result(void)
{
	uint16_t adc_result = 0;
	
	adc_start_conversion(&adc_instance);
	while((adc_get_status(&adc_instance) & ADC_STATUS_RESULT_READY) != 1);
	
	adc_read(&adc_instance, &adc_result);
	
	return adc_result;
}


/**
* \brief ADC Differential mode.
*
* This function configures the ADC as differential mode
* and converts the differential voltage applied on positive
* input and negative input. Prints the differential voltage
* on serial console and disable the ADC.
*/

float adc_differential(uint8_t pin, uint8_t ADC_Resolution_Value)
{
	int16_t raw_result_signed;
	
	configure_adc_differential(pin, ADC_Resolution_Value);
	
	raw_result = adc_start_read_result();
	
	raw_result_signed = (int16_t)raw_result;
	result = ((float)raw_result_signed * (float)ADC_REFERENCE_INTVCC1_VALUE)/(float)ADC_11BIT_FULL_SCALE_VALUE;
	
	//printf("\nDifferential Voltage on ADC Input = %fV", result);
	
	adc_disable(&adc_instance);
	
	return result;
}