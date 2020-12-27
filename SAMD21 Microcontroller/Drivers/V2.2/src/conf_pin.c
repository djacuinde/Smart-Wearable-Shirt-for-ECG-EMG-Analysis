/*
 * conf_pin.c
 *
 * Created: 8/22/2020 12:27:33 PM
 *  Author: Daniel Jacuinde-Alvarez
 */ 
#include <asf.h>
#include "conf_pin.h"

/************************************************************************/
/* Blink the on board LED every "timer" ms (MAX == 65 sec)			    */
/************************************************************************/
void blink_ms (uint16_t timer){
	
	digitalWrite(LED, HIGH);
	delay_ms (timer);
	digitalWrite(LED, LOW);
	delay_ms (timer);
	
}//END of blink_ms


/************************************************************************/
/* Set digital or analog pin to desire state: INPUT or OUTPUT			*/
/************************************************************************/
void pinMode (uint8_t pin, uint8_t mode){
	
	if(mode == OUTPUT)
		ioport_set_pin_dir(pin, IOPORT_DIR_OUTPUT);
	else if (mode == INPUT)
		ioport_set_pin_dir(pin, IOPORT_DIR_INPUT);
	else 
		return;
}//END of pinMode


/************************************************************************/
/* Set the digital pin to either HIGH (~3.3V) or LOW (~0V)              */
/************************************************************************/
void digitalWrite(uint8_t pin, uint8_t state){
	
	if (!Check_PIN_DIGITAL(pin)){// If not a registered digital pin then return
		//printf("Cannot digitalWrite() an non-digital pin! \n");
		return;
	}
	pinMode(pin, OUTPUT);
	
	if (state == LOW)
		ioport_set_pin_level(pin, false);//0V
	else if (state == HIGH)
		ioport_set_pin_level(pin, true);//3.3V
	else 
		return;
}//END of digitalWrite


/************************************************************************/
/* Read ADC value of analog signal							            */
/************************************************************************/
float analogRead (uint8_t pin, uint8_t resolution){
	//ADC
	
	if (!Check_PIN_ANALOG(pin)){ // If not a registered analog pin then return

		//printf("Cannot analogRead() an non-analog pin! \n");
		return 0;
	}
	else{
		float result;
		result = adc_differential(pin, resolution);
		return result;
	}
}//END of analogRead

//
///************************************************************************/
///* Check if digital input pin is High or LOW state	                    */
///************************************************************************/
//bool digitalRead(uint8_t pin, uint8_t pin_p){
	//
	//if (Check_PIN_DIGITAL(pin))
	//{
		//pinMode(pin, INPUT);
		//
		//if(REG_PORT_IN0 & pin_p)
			//return true;
		//else
			//return false;
	//}
//}//END of digitalRead


/************************************************************************/
/* Check if pin is analog, return true is so 				             */
/************************************************************************/
bool Check_PIN_ANALOG(uint8_t pin){
	if (pin == A0 || A1 ||  A2 || A3 || A4 || A5 || A6 || A7 )
		return true;
	else 
		return false;
}//END of CHECK_PIN_ANALOG


/************************************************************************/
/* Check if pin is digit, return true is so		     		             */
/************************************************************************/
bool Check_PIN_DIGITAL(uint8_t pin){
	if (pin == D0 || D1 ||  D2 || D3 || D4 || D5 || D6 || D7 || D7 )
		return true;
	else 
		return false;
}//END of CHECK_PIN_DIGITAL

