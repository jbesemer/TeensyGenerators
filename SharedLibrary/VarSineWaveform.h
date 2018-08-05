// VarSineWaveform.h

#pragma once
#include "Config.h"
#include "SineWaveform.h"
#include "AnalogReaderScaled.h"


// a SineWaveform which is associated with several Pots, each of which
// controls one of the three primary waveform parameters:
//
//		P1 -- amplitude
//		P2 -- offset
//		P3 -- frequency
// 
// when the waveform is defined, the number of samples is fixed, as are the
// ranges of each of the 3 parameters. The settings vary 

#define DEFAULTCOUNT 100

class VarSineWaveform : public SineWaveform
{
protected:

	AnalogReaderScaled Amplitude;
	AnalogReaderScaled Offset;
	AnalogReaderScaled Frequency;

	void MaybeUpdateWaveform();

public:

	VarSineWaveform( int ampPin, float ampMin, float ampMax, 
			int offPin, float offMin, float offMax,
			int freqPin, float freqMin, float freqMax,
			uint count = DEFAULTCOUNT )
		: SineWaveform( count )
		, Amplitude( ampPin, ampMin, ampMax )
		, Offset( offPin, offMin, offMax )
		, Frequency( freqPin, freqMin, freqMax )
	{
		SetFrequency( Frequency.Current );

		Init( Amplitude.Current, 
			Offset.Current );
	}

	virtual void Play( AnalogWriter* writer );
};
