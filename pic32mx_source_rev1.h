/*

Name: Mitch Fronczak
File:   gsa_rev1.c
Date: Feb 26, 2018
 */

#include <xc.h> // required for pic32 devices
#include "usart.h" // add file to folder

/* set appropriate config bits
#pragma config OSC = INTIO1;    // set OSCTUN // calibrate via register values 
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config POSC = OFF;    	// Primary Oscillator (External RC oscillator)
#pragma config SOSC = OFF;      // Secondary oscillator - may be used as aux clock for gps
// May enable RTCC - real time clock as an additional feature for consumers
#pragma config RTCC = OFF; 		//figure out RTCC
 */ 

// determine how to enable only a few analog inputs
#pragma config AN01 = ON;	// GSR input
//#pragma config AN02 = ON;	// Battery monitor voltage?
#pragma config AN03 = ON;	// 
// digital input ports
#pragma config RA0 = ;

__config    _CONFIG1, _DEBUG_OFF & _LVP_OFF & _FCMEN_OFF & _IESO_OFF & _BOR_NSLEEP & _CPD_OFF & _PGM_CP & _MCLRE_OFF & _PWRTE_ON & _WDT_OFF & _OSC_SRC
__config    _CONFIG2, _WRT_HALF & _BOR21V _POSC_OFF_ & _SOSC_OFF_ & _RTCC_OFF_ & _AN01_ON_
	
	
#define _XTAL_FREQ 800000L  // needs to be set for _delay_ms	

unsigned int VAR; // loose variables for device - RM IF NOT USED

int main(void);

int main(void) 
{
	OSCCON = 0x6C; 			// change to 40 MHz
	TRISA  = 0b00000001;    // enable Tri-state Buffer pin 1 - port A 
	
	
	//    while (1); // while activation button is NOT held for 4 seconds
	// run the program while X input is not triggered
	// when condition is met run shutdown of device
	
	// alternatively when button is held for 1 second 
	// trigger startup procedure

	// primary oscillator
	OSCCON = 0x6C; //change to 20 MHz
	
    // DIGITAL port assignments and control 
    TRISBbits.TRISB1 = 0;
    PORTBbits.RB1 = 0;

    // ANALOG port assignments and control 
    TRISAbits.TRISA1 = 0;
    PORTAbits.RA1 = 0; // change to correct port

	
	// read in analog input from gsr circuit
    TRISA = 1;// setting all control regs to take input
	
    
    
    
// if a trigger value is received from the ESP8266
    // change the state of the gps from OFF/ idle to ON
    // boot up
    // ping gps
    // report users location
    // display path on google maps api
    
    
    
// check device battery level
    // while battery level is below X value
    // do a 2ms pule/blink of the charge LED 1ce every 10 seconds
    // 
    
}


int gps(void) { // function for GSR analog input

    return main;
}

int gsr(void) { // function for GSR analog input

    return main;
}


int tumble(void) { // function for tumble sensor input

    return main;
}

