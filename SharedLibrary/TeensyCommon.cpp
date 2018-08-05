#include "TeensyCommon.h"

// LED ports //////////////////////////////////////////////////////////

void LedSet( int ledPin, int isOn ){
	digitalWrite(
		ledPin,
		( isOn == 0 )
		? LOW
		: HIGH );
}

void LedOn( int ledPin ){
	digitalWrite( ledPin, HIGH );
}

void LedOff( int ledPin ){
	digitalWrite( ledPin, LOW );
}

int LEDONTIME = 500;	// msec

void show( int pinOff, int pinOn ){
	digitalWrite( pinOff, LOW );
	digitalWrite( pinOn, HIGH );
	delay( LEDONTIME );
}

// Buttons ////////////////////////////////////////////////////////////

int OppositeState( int state ){
	if( state == HIGH )
		return LOW;
	else
		return HIGH;
}

int ButtonPressed( int button ){
	return digitalRead( button ) == LOW;
}

int ButtonReleased( int button ){
	return digitalRead( button ) == HIGH;
}

// first button found to be pressed else BUTTON_NONE, list terminated by BUTTON_NONE
int AnyButtonPressed( int* buttons ){
	for( int i = 0; buttons[ i ] != BUTTON_NONE; i++ )
		if( ButtonPressed( buttons[ i ] ) )
			return buttons[ i ];

	return BUTTON_NONE;
}

// first button found to be pressed else BUTTON_NONE, list has explict length
int AnyButtonPressed( int* buttons, int length ){
	for( int i = 0; i < length; i++ )
		if( ButtonPressed( buttons[ i ] ) )
			return buttons[ i ];

	return BUTTON_NONE;
}

// Misc. //////////////////////////////////////////////////////////////

int FreeRam()
{
	//	extern int __heap_start;
	extern int *__brkval;
	int v;
	return (int)&v - (int)__brkval;
	//	return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
	// https://learn.adafruit.com/memories-of-an-arduino/measuring-free-memory
}


// TODO: access LED and Buttons as groups:
// http://tronixstuff.com/2011/10/22/tutorial-arduino-port-manipulation/
// http://playground.arduino.cc/Learning/PortManipulation


void PrintFreeRam(){
	Serial.print( "Free ram: " );
	Serial.println( FreeRam() );
}


