/*
 Name:		BlinkFast.ino
 Created:	7/28/2018 1:18:32 PM
 Author:	jb
*/

// Simple LED blink

const int led = LED_BUILTIN;

void setup() {
	pinMode( led, OUTPUT );
}

void loop() {
	digitalWrite( led, HIGH );
	delay( 100 );
	digitalWrite( led, LOW );
	delay( 100 );
}

