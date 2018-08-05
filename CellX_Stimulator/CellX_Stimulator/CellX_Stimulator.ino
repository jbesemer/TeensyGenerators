/*
 Name:		CellX_Stimulator.ino
 Created:	6/23/2017 4:11:00 PM
 Modified:	3/14/2018 2:39 PM
 Author:	BesemerJ
*/

#include "Config.h"
#include "CommandProcessing.h"
#include "PersistentSettings.h"
#include "AnalogReader.h"
#include "AnalogWriter.h"
#include <SPI.h>
#include "QuadMux.h"
#include "CommandProcessing.h"


// Principal Objects //////////////////////////////////////////////////////////


PersistentSettings Settings;
Parser TheParser;			// input commands, parsed

Blinker MainBlinker( LED, 0x15, 10, 100 );    // blinks LED thrice per sec

AnalogWriter TheAnalogWriter;	// analog writer for waveforms
AnalogWriterScaled TheAnalogWriterScaled;	// for dynamically scaled waverorms
Generator TheGenerator(&TheAnalogWriter);		// Generate waveforms to DAC
// ZeroingMode TheZeroingMode(ZERO_BUTTON, ZERO_LED);
QuadMux TheMux(SCK, nSPICS);
AnalogWriterMux TheMuxWriter(&TheMux);
CellX_Demo TheCellX_Demo(&TheMuxWriter, ZERO_BUTTON);

// Setup //////////////////////////////////////////////////////////////////////

void setup() {
	Serial1.begin( 115200 ); 		//see: https://www.pjrc.com/teensy/td_uart.html
	Serial.begin( 115200 );

	pinMode( LED, OUTPUT );
	pinMode( LED1, OUTPUT );
	pinMode( LED2, OUTPUT );
	pinMode( LED3, OUTPUT );
	pinMode( LED4, OUTPUT );

	pinMode( BUTTON1, INPUT_PULLUP );

	pinMode( PRES232, INPUT_PULLDOWN );

	pinMode( REDYOUT, INPUT_PULLDOWN );
	pinMode( STBYOUT, INPUT_PULLDOWN );
	pinMode( FALTOUT, INPUT_PULLDOWN );
	pinMode( REDOUT, INPUT_PULLDOWN );
	pinMode( GRNOUT, INPUT_PULLDOWN );
	pinMode( BLUOUT, INPUT_PULLDOWN );

	pinMode( DMOD1, OUTPUT );
	digitalWrite( DMOD1, LOW );		//turn laser off to start
	pinMode( DMOD2, OUTPUT );
	digitalWrite( DMOD1, LOW );		//turn laser off to start
	pinMode( DMOD3, OUTPUT );
	digitalWrite( DMOD1, LOW );		//turn laser off to start
	pinMode( DMOD4, OUTPUT );
	digitalWrite( DMOD1, LOW );		//turn laser off to start	
	pinMode( ExtDmod, OUTPUT );
	digitalWrite( ExtDmod, HIGH );	//get control

	pinMode( ExtAmod, OUTPUT );
	digitalWrite( ExtAmod, HIGH );	//get control	

	pinMode( SHDN, OUTPUT );
	digitalWrite( SHDN, LOW );		//enable unit		
	pinMode( KeyOn, OUTPUT );
	digitalWrite( KeyOn, HIGH );	//enable unit	
	pinMode( IntlkOn, OUTPUT );
	digitalWrite( IntlkOn, HIGH );	//enable unit		

	pinMode( nLDAC, OUTPUT );		//SPI init
	digitalWrite( nLDAC, HIGH );
	pinMode( nSPICS, OUTPUT );
	digitalWrite( nSPICS, HIGH );
	pinMode( nCLR, OUTPUT );
	digitalWrite( nCLR, HIGH );

	QuadMux TheMux( SCK, nSPICS );	// temporary instance for Reset
	TheMux.Reset();

	show( LED, LED1 );
	LedOn( LED );
	show( LED1, LED2 );
	show( LED2, LED3 );
	show( LED3, LED4 );
	show( LED4, LED );

	// if this function is undefined, you probably have the wrong device selected in your tool chain
	analogWriteResolution( DAC_BITS );
	analogReadResolution( ADC_BITS );

	Serial.println( "Starting..." );

	// fetch settings from eeprom or restore factory defaults
	if (!Settings.LoadFromEEPROM())
		Settings.SetFactoryDefaults();

	PrintFreeRam();

	IdentifyCommand();

	// handle other settings first
#if false
	char* command = Settings.Settings.StartupCommand;

	// handle startup command
	Serial.print( "Invoking Startup Command = " );
	Serial.println( command );
	InvokeCommand( command );
#endif

	// in settingactive, demo runs 1 cycle before returning
	TheCellX_Demo.SetActive( 1 );
}

// Loop ///////////////////////////////////////////////////////////////////////

// this main loop has two responsibilities:
//		1. it processes command input from the serial port
//		2. it drives the DemoMaker Loop, which when enabled regularly changes
//			the main generator's waveforms


void loop(){
	// animate LED
	MainBlinker.Loop();

	// TheZeroingMode.Loop();
	TheCellX_Demo.Loop();

#if false
	if( !TheZeroingMode.IsActive() )
	{
		MaybeAdjustGain();

		// generate one cycle of currently selected waveform
		TheGenerator.Loop();
	}
#endif

	// commands sent on serial port don't get processed until
	// after first Demo cycle

	// process any serial input
	SerialPolling();
}
