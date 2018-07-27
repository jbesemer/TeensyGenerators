// 
// VarSineWaveform.cpp
// 

#include "VarSineWaveform.h"

void VarSineWaveform::MaybeUpdateWaveform() {
	// Frequency.ReadFiltered();
	// Amplitude.ReadFiltered();
	// Offset.ReadFiltered();

	// redefine waveform if anything changes

	bool changes = false;

	if( Frequency.Changed() ) {
		SetFrequency( Frequency.Value() );
		changes = true;
	}

	if( Amplitude.Changed() || Offset.Changed() ) {
		Init(
			Amplitude.Value(),
			Offset.Value() );
		changes = true;
	}

	if( changes )
		Serial.println( "# " + ToString() );
}


void VarSineWaveform::Play( AnalogWriter* writer ) {
	// poll the pots and change waveform as needed
	MaybeUpdateWaveform();

	// after or in any case play out one cycle

	SineWaveform::Play( writer );
}
