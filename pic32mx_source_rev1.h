/*

Name: Mitch Fronczak
File:   gsa_rev1.c
Date: Feb 26, 2018
 */

#include <xc.h> // required for pic32 devices

// determine how to enable only a few analog inputs
#pragma config AN01 = ON;	// GSR input
//#pragma config AN02 = ON;	// Battery monitor voltage?
#pragma config AN03 = ON;	// 

// ---------------------------------------------------------------------------------
#include < xc.h > // Blog code Bug : Shorten spaces to match <xc.h>
#include < plib.h > // Shorten spaces to match <plib.h> 
#include < p32xxxx.h >  // Shorten spaces to match <p32xxxx.h>
//#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_2, FWDTEN = OFF
//#pragma config POSCMOD = OFF, FNOSC = FRCPLL, FPBDIV = DIV_1
#pragma config   JTAGEN    = OFF    // JTAG Enable OFF
#pragma config   FNOSC     = FRCPLL // Fast RC w PLL 8mHz internal rc Osc
#pragma config   FPLLIDIV  = DIV_2  // PLL in 8mHz/2 = 4mHz
#pragma config   FPLLMUL   = MUL_20 // PLL mul 4mHz * 20 = 80mHz 24??
#pragma config   FPLLODIV  = DIV_2  // PLL Out 8mHz/2= 40 mHz system frequency osc
#pragma config   FPBDIV    = DIV_1  // Peripheral Bus Divisor
#pragma config   FCKSM     = CSECME // Clock Switch Enable, FSCM Enabled
#pragma config   POSCMOD   = OFF    // Primary osc disabled
#pragma config   IESO      = OFF    // Internal/external switch over
#pragma config   OSCIOFNC  = OFF    // CLKO Output Signal Active on the OSCO Pin
#pragma config   FWDTEN    = OFF    // Watchdog Timer Enable:
// add memory location for alert flag for tumble sensor
// 
#define GetSystemClock()       (40000000ul)
#define GetPeripheralClock()    (GetSystemClock()/(1<<OSCCONbits.PBDIV))// 

main(void){

#define _XTAL_FREQ 800000L  // needs to be set for _delay_ms	

unsigned int VAR; // loose variables for device - RM IF NOT USED

int main(void);

int main(void) 
{
	OSCCON = 0x6C; 			// change primary oscillator to 40 MHz
	
	TRISA  = 0b00000001;    // enable Tri-state Buffer pin 1 - port A 
	
	
	// while (1); // while activation button is NOT held for 4 seconds
	// run the program while X input is not triggered
	// when condition is met run shutdown of device
	
	// alternatively when button is held for 1 second 
	// trigger startup procedure

	
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

