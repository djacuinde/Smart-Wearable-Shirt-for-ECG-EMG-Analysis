
#include <asf.h>
#include <board.h>
#include <conf_board.h>
#include "conf_pin.h"

#if defined(__GNUC__)
void board_init(void) WEAK __attribute__((alias("system_board_init")));
#elif defined(__ICCARM__)
void board_init(void);
#  pragma weak board_init=system_board_init
#endif

//Initial Configuration state of the micro-board
void system_board_init(void)
{
	digitalWrite(LED, LOW);
	
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);
	pinMode(A2, INPUT);
	pinMode(A3, INPUT);
	pinMode(A4, INPUT);
	pinMode(A5, INPUT);
	pinMode(A6, INPUT);
	pinMode(A7, INPUT);

	digitalWrite(D0, LOW);
	digitalWrite(D1, LOW);
	digitalWrite(D2, LOW);
	digitalWrite(D3, LOW);
	digitalWrite(D4, LOW);
	digitalWrite(D5, LOW);
	digitalWrite(D6, LOW);
	digitalWrite(D7, LOW);
	digitalWrite(D8, LOW);
	
}//END of system_board_init