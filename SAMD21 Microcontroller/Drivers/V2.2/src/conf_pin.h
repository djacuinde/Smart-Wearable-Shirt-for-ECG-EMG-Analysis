/*
 * conf_pin.h
 *
 * Created: 8/22/2020 12:27:51 PM
 *  Author: Daniel Jacuinde-Alvarez
 */ 


#ifndef CONF_PIN_H_
#define CONF_PIN_H_

//"timer" is in units of microseconds
void blink_ms (uint16_t timer);

void pinMode (uint8_t pin, uint8_t mode );

void digitalWrite(uint8_t pin, uint8_t state);

float analogRead (uint8_t pin, uint8_t resolution);
//bool digitalRead(uint8_t pin, uint8_t pin_p);

bool Check_PIN_ANALOG(uint8_t pin);
bool Check_PIN_DIGITAL(uint8_t pin);

#endif /* CONF_PIN_H_ */