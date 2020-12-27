///*
 //* conf_USART.c
 //*
 //* Created: 10/26/2020 2:30:47 PM
 //*  Author: Daniel J
 //*/ 
//
//#include "conf_USART.h"
//
//void usart_read_callback(struct usart_module *const usart_module)
//{
	//usart_write_buffer_job(&usart_instance,
	//(uint8_t *)rx_buffer, MAX_RX_BUFFER_LENGTH);
//}
//
//
//void usart_write_callback(struct usart_module *const usart_module)
//{
	//port_pin_toggle_output_level(LED);
//}
//
//void configure_usart(unsigned int rate){
	//struct usart_config config_usart;
	//usart_get_config_defaults(&config_usart);
	//
	//if (rate != 4800 ||9600 ||19200 ||38400 ||57600 ||115200 )
		//config_usart.baudrate    = 9600;
	//else 
		//config_usart.baudrate    = rate;
	//config_usart.generator_source = GCLK_GENERATOR_1;
	//config_usart.mux_setting = EDBG_CDC_SERCOM_MUX_SETTING;
	//config_usart.pinmux_pad0 = PINMUX_PA00D_SERCOM1_PAD0
	//config_usart.pinmux_pad1 = PINMUX_PA17C_SERCOM1_PAD1
	//config_usart.pinmux_pad2 = PINMUX_UNUSED
	//config_usart.pinmux_pad3 = PINMUX_UNUSED
//
	//while (usart_init(&usart_instance,
	//EDBG_CDC_MODULE, &config_usart) != STATUS_OK) {
	//}
	//
	//usart_enable(&usart_instance);
//}
//
//void configure_usart_callbacks(void)
//{
	//usart_register_callback(&usart_instance,
	//usart_write_callback, USART_CALLBACK_BUFFER_TRANSMITTED);
	//usart_register_callback(&usart_instance,
	//usart_read_callback, USART_CALLBACK_BUFFER_RECEIVED);
//
	//usart_enable_callback(&usart_instance, USART_CALLBACK_BUFFER_TRANSMITTED);
	//usart_enable_callback(&usart_instance, USART_CALLBACK_BUFFER_RECEIVED);
//}