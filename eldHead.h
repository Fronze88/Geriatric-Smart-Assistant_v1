// define clock frequency (if we are using the clock on the GSR board - may comflict with PIC 40MHz clock
#define  
#define _XTAL_FREQ // 40MHz ? 

// store SSID Info as variables MACROS - called by TCP/IP stack 
#define ssid "NETGEAR56"
#define password "littlebrother"

// set Baud Rate (9600)
#ifndef UART_BAUD
#define UART_BAUD  9600

#endif