#pragma once

#include "arduino.h"

#define BUTTON_NONE	0	// returned by AnyButtonPressed if no button is pressed

// map button num (1,2,3,4) to above port nums
#define BUTTON_TO_PORT( BUTTON ) 	\
	((BUTTON)										\
		? ( BUTTON1 + 1 - (BUTTON))		\
		: 0 )

// map above port nums to button num (1,2,3,4)
#define PORT_TO_BUTTON( BUTTON )  	\
	((BUTTON)										\
		? ( BUTTON1 - (BUTTON) + 1 )		\
		: 0 )

extern void LedSet( int ledPin, int isOn );
extern void LedOn( int ledPin );
extern void LedOff( int ledPin );

// return the other state
extern int OppositeState( int state );

// return 1 iff button is ...
extern int ButtonPressed( int button );		// ...pressed (input is LOW)
extern int ButtonReleased( int button );	// ...released (input is HIGH)

											// return 1 if any of the 4 buttons are pressed
extern int AnyButtonPressed();

// preferred abbreviations

typedef unsigned int uint;		// 16 bits
typedef unsigned long ulong;	// 32 bits

// Misc. //////////////////////////////////////////////////////////////////////

extern void show( int pinOff, int pinOn );
extern int FreeRam();
extern void PrintFreeRam();


// Trace, Printf //////////////////////////////////////////////////////

extern bool TraceEnabled;

extern void Trace( const char*fmt, ... );	// don't forget "\n"
extern void Printf( const char*fmt, ... );
