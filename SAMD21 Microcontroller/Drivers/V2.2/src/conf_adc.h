/*
 * conf_adc.h
 *
 * Created: 9/10/2020 2:13:33 PM
 *  Author: Daniel Jacuinde-Alvarez
 */ 


#ifndef CONF_ADC_H_
#define CONF_ADC_H_

#define ADC_REFERENCE_INTVCC1_VALUE		1.65
#define ADC_12BIT_FULL_SCALE_VALUE		4095
#define ADC_11BIT_FULL_SCALE_VALUE		2047
#define ADC_16BIT_FULL_SCALE_VALUE		65535

void configure_adc_differential(uint8_t pin, uint8_t ADC_Resolution_Value);
uint16_t adc_start_read_result(void);
float adc_differential(uint8_t pin, uint8_t ADC_Resolution_Value);


#endif /* CONF_ADC_H_ */