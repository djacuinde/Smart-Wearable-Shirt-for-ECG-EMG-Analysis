//SAMD21G PINOUT
/*				

 *PA00		OSC				
 *PA01		OSC				
 *PA02		ANA				PB02	ANA
 *PA03		ANA				PB03	ANA
 *PA04		ANA
 
 *PA05		ANA
 *PA06		ANA
 *PA07		ANA
 *PA08		DIG				PB08	ANA
 *PA09		DIG				PB09	ANA
 
 *PA10		DIG				PB10	DIG
 *PA11		DIG				PB11	DIG
 *PA12		DIG
 *PA13		DIG
 *PA14		OSC
 
 *PA15		OSC
 *PA16		DIG
 *PA17		DIG
 *PA18		DIG
 *PA19		DIG
 
 *PA20		DIG
 *PA21		DIG
 *PA22		DIG
 *PA23		DIG				PB23	DIG
 *PA24		DIG				PB22	DIG
 
 *PA25		DIG
 
 */

#ifndef CONF_BOARD_H
#define CONF_BOARD_H

/******************* LED  *******************/
#define LED					PIN_PA27

/**************** ANALOG PIN ****************/
#define A0					PIN_PA02
#define A1					PIN_PA03
#define A2					PIN_PB08
#define A3					PIN_PB09
#define A4					PIN_PA04
#define A5					PIN_PA05
#define A6					PIN_PA06
#define A7					PIN_PA07

/**************** DIGITAL PIN ****************/
#define D0					PIN_PA08
#define D1					PIN_PA09
#define D2					PIN_PA10
#define D3					PIN_PA11
#define D4					PIN_PB10
#define D5					PIN_PB11
#define D6					PIN_PA12
#define D7					PIN_PA13
#define D8					PIN_PA14

#define D0_P				PORT_PA08
#define D1_P				PORT_PA09
#define D2_P				PORT_PA10
#define D3_P				PORT_PA11
#define D4_P				PORT_PB10
#define D5_P				PORT_PB11
#define D6_P				PORT_PA12
#define D7_P				PORT_PA13
#define D8_P				PORT_PA14

/*************** NINA (WIFI) ****************/
//	RX = Receive (Host's Input)
//	TX = Transmit (Host's Output)
//	RTS = Request to Send (Host's Output)
//	CTS = Clear to Send (Host's Input)

#define NINA_TX				PIN_PA16
#define NINA_RX				PIN_PA17
#define NINA_RTS_D			PIN_PA18
#define NINA_CTS_D			PIN_PA19
#define NINA_RTS_A			PIN_PB02
#define NINA_CTS_A			PIN_PB03

#define	NINA_28_TIMING_OUT	PIN_PB23
#define	NINA_32_TIMING_IN	PIN_PB22
#define NINA_25_BOOT		PIN_PA21
#define NINA_27_BOOT		PIN_PA20

/**************** Other *******************/
#define USB_EN				PIN_PA23
#define LOW					0
#define low					0
#define HIGH				1
#define high				1
#define INPUT				0
#define OUTPUT				1

#endif // CONF_BOARD_H