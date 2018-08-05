// #pragma once

// definitions unique to Modulator project

// low-level hardware definitions & functions for Rick's custom gizmo

// ADC channel assignments to SDR:

#define BPTEMP 	A0		//baseplate temperature
#define PWRMON 	A1		//photodiode output
#define DIOPWR	A2		//diode current

// IO pin assignments to SDR:

#define INUSE 	9		//in, "SDR in use" pin. High if OBIS connected, pull low to enable RS-485 link
#define INHIBIT 10		//out, low to allow OBIS to receive RS-485
#define LSR_RDY	12		//in, high when ready
#define LSR_FLT	22		//in, high when faulted
#define DMOD	23		//out, high to turn laser on. Pin is hardware PWM.
#define nRX_EN	25		//out, low to receive RS-485
#define TX_EN	32		//out, high to transmit RS-485

// LED ports //////////////////////////////////////////////////////////////////

#define LED 13	// Blue, Arduino standard on-board LED

#define LED1 5	// Green
#define LED2 21	// Yellow
#define LED3 20	// Orange
#define LED4 6	// Red

#define LED_GREEN 5		// Green	aligned with BUTTON1
#define LED_YELLOW 21	// Yellow	aligned with BUTTON2
#define LED_ORANGE 20	// Orange	aligned with BUTTON3
#define LED_RED 6		// Red		aligned with BUTTON4

// button port assignments ////////////////////////////////////////////////////

#define BUTTON1 33	// A5	aligned with LED3 / GREEN
//#define BUTTON2 18	// A4	aligned with LED4 / YELLOW
//#define BUTTON3 17	// A3	aligned with LED5 / ORANGE
//#define BUTTON4 16	// A2	aligned with LED6 / RED

#define BUTTON_GREEN 33		// A5	aligned with LED3 / GREEN
//#define BUTTON_YELLOW 18	// A4	aligned with LED4 / YELLOW
//#define BUTTON_ORANGE 17	// A3	aligned with LED5 / ORANGE
//#define BUTTON_RED 16		// A2	aligned with LED6 / RED


// Global Firmware assignments of LEDs and Buttons ////////////////////////////

#define ZERO_LED LED_RED
#define ZERO_BUTTON BUTTON1

// #define UNASSIGNED P2
// #define UNASSIGNED P3
// #define UNASSIGNED LED_YELLOW
// #define UNASSIGNED BUTTON_GREEN
// #define UNASSIGNED BUTTON_YELLOW


// Misc. //////////////////////////////////////////////////////////////////////

extern void Modulator_Setup();
