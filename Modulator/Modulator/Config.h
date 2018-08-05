#pragma once

// Config.h -- global configuration switch and options

#include "TeensyCommon.h"
#include "Modulator.h"

// app identification

#define ASSEMBLYNAME "Modulator"
#define VERSION "1.0.1"
#define MODEL "Teensy 3.1"
#define DATE "5-Aug-2018 12:57"

// individual features/commands 

#define ONE_SHOT_COMMAND	0	// enable OneShotCommand
#define VARIABLE_COMMANDS	0	// variable waveforms based on Pot inputs
#define ENABLE_DOWNLOAD_COMMANDS	0	// downloading is not working yet 

