/*
 Name:		SigGen.ino
 Created:	5/21/2015 11:45:44 AM
 Author:	besemerj
*/

#include "Config.h"
#include "Blinker.h"
#include "CommandProcessing.h"

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
	Serial.begin( 19200 );

	pinMode( LED, OUTPUT );
	pinMode( LED1, OUTPUT );
	pinMode( LED2, OUTPUT );
	pinMode( LED3, OUTPUT );
	pinMode( LED4, OUTPUT );

	show( LED, LED1 );
	show( LED1, LED2 );
	show( LED2, LED3 );
	show( LED3, LED4 );
	show( LED4, LED );

	pinMode( BUTTON1, INPUT_PULLUP );
	pinMode( BUTTON2, INPUT_PULLUP );
	pinMode( BUTTON3, INPUT_PULLUP );
	pinMode( BUTTON4, INPUT_PULLUP );

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

// AllButtons and AnyButtonPressed ////////////////////////////////////////////

int AllButtons[] = {
	BUTTON1,
	BUTTON2,
	BUTTON3,
	BUTTON4,
	BUTTON_NONE,
};

int AnyButtonPressed(){ return AnyButtonPressed( AllButtons ); }

