/*
 Name:		Modulator.ino
 Created:	5/21/2015 11:45:44 AM
 Author:	besemerj
*/

// standard main/startup for Modulator project

#include "Config.h"
#include "CommandProcessing.h"
#include "PersistentSettings.h"
#include "AnalogWriter.h"
#include "AnalogReader.h"
#include "Blinker.h"
#include <EEPROM.h>

// Burn-down list:
//
//	Test/Debug:
//		LpemWaveform
//
//		ArbTestWave			# download? not implemented
//		StairWaveform
//		WaveformPadded
//		WaveformRepeated
//
//	Eventually:
//		need separate header/payload for PersistentSettings
//		Finish incorporating Gain and VarGain to PersistentSettings
//		special syntax for Waveform modifiers
//		convert all files to pro-forma boilerplate
//		utilize Parser.Query property to eliminate need for separate set/get "names"
//			one name => one command/function with get/set functionality
//		system of blinky lights to indicate errors

// Principal Objects //////////////////////////////////////////////////////////

// blinks LED twice every sec
Blinker blinker( LED, 0x5, 10, 100 );

// processes commands, possibly affecting waveform generation
CommandProcessing CommandProcessor; //  ( &TheGenerator );

// Setup //////////////////////////////////////////////////////////////////////

void setup() {
	Serial1.begin( 921600 ); 		//see: https://www.pjrc.com/teensy/td_uart.html

	pinMode( LED, OUTPUT );
	pinMode( LED1, OUTPUT );
	pinMode( LED2, OUTPUT );
	pinMode( LED3, OUTPUT );
	pinMode( LED4, OUTPUT );

	pinMode( BUTTON1, INPUT_PULLUP );

	pinMode( INHIBIT, OUTPUT );
	digitalWrite( INHIBIT, HIGH );	//disable RS-485 deception by OBIS for now

	pinMode( DMOD, OUTPUT );
	digitalWrite( DMOD, LOW );		//turn laser off to start

	pinMode( nRX_EN, OUTPUT );		//enable TX & RX for loop back testing
	digitalWrite( DMOD, LOW );
	pinMode( TX_EN, OUTPUT );
	digitalWrite( DMOD, HIGH );

	pinMode( INUSE, INPUT_PULLDOWN ); //OBIS will pull high if connected, force low to talk RS-485


	show( LED, LED1 );
	show( LED1, LED2 );
	show( LED2, LED3 );
	show( LED3, LED4 );
	show( LED4, LED );

	// if this function is undefined, you probably have the wrong device selected in your tool chain
	analogWriteResolution( DAC_BITS );
	analogReadResolution( ADC_BITS );

	Serial.println( "Starting..." );

	CommandProcessor.Setup();
}

// Loop ///////////////////////////////////////////////////////////////////////

void loop(){
	// animate LED
	blinker.Loop();

	// process any commands from Serial port
	CommandProcessor.Loop();
}
