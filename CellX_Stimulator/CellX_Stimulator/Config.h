#pragma once

// Config.h -- global configuration switch and options

#include "TeensyCommon.h"
#include "CellX_Stimulator.h"

// app identification

#define VERSION "1.1.0"
#define DATE "5-August-2018 12:15"

#define ASSEMBLYNAME "Jaeger Stimulator"
#define MODEL "Teensy 3.1"
#define AUTHOR "JB, Inc"

// individual features/commands 

#define ONE_SHOT_COMMAND	0	// enable OneShotCommand
#define VARIABLE_COMMANDS	0	// variable waveforms based on Pot inputs
#define ENABLE_DOWNLOAD_COMMANDS	0	// downloading is not working yet 
