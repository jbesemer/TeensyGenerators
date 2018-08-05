// Config.h -- global configuration switch and options

#pragma once

#include "arduino.h"

// individual features/commands 

#define ONE_SHOT_COMMAND	0	// enable OneShotCommand
#define VARIABLE_COMMANDS	0	// variable waveforms based on Pot inputs (which of course presumes a Pot)

// board specifics

#include "LiTeensy.h"

// app configuration

#define ASSEMBLYNAME "SigGen"
#define VERSION "3.0.0"
#define MODEL "Teensy 3.1"
#define DATE "4-Aug-2018 18:33"

#define ENABLE_DOWNLOAD_COMMANDS	0	// downloading is work in progress

// preferred abbreviations

typedef unsigned int uint;		// 16 bits
typedef unsigned long ulong;	// 32 bits

