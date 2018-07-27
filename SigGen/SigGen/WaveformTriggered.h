#pragma once

#include "Waveform.h"
#include "Button.h"
#include "LiTeensy.h"

// WaveformTriggered waits for a button to be pressed and released
//		before playing the supplied waveform

class WaveformTriggered : public Waveform
{
	Button TriggerButton;
	bool Waiting;

public:
	Waveform* TheWaveform;

	WaveformTriggered( int button, Waveform* waveform )
		: TriggerButton( button )
	{
		TheWaveform = waveform;
		Waiting = false;
	}

	virtual void Play( AnalogWriter* writer );
	void Shutdown();

	virtual String ToString() { 
		String r = "Triggered ";
		r.append( TheWaveform->ToString() );
		return r;
	}
};
