/*
 Name:		BlinkSlow.ino
 Created:	7/28/2018 1:18:52 PM
 Author:	jb
*/

// Simple LED blink

const int led = LED_BUILTIN;

void setup() {
	pinMode( led, OUTPUT );
}

void loop() {
	digitalWrite( led, HIGH );
	delay( 1000 );
	digitalWrite( led, LOW );
	delay( 1000 );
}
