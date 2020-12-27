
#include <asf.h>
#include <stdio.h>

//#define SAMPLES 1000;

int main (void)
{
	//Variables
	int SAMPLES = 1000;
	float SAMPLE_ARRAY[SAMPLES];
	int counter = 0;
	
	//initial system
	system_init();
	
	//Set LED to OFF state 
	digitalWrite(LED, LOW);

	//configure_usart(9600);
	//configure_usart_callbacks();
	//system_interrupt_enable_global();
	
	//uint8_t string[] = "Hello World!\r\n";
	//usart_write_buffer_wait(&usart_instance, string, sizeof(string));
	
	while (counter <= SAMPLES){
		SAMPLE_ARRAY[counter] = analogRead (A0, 12);
		counter++;
		
		//usart_read_buffer_job(&usart_instance,(uint8_t *)rx_buffer, MAX_RX_BUFFER_LENGTH);
	}
	while(true){
		//blink_ms(1000);
		
		//Set LED to ON state 
		digitalWrite(LED, HIGH);
	}
}
