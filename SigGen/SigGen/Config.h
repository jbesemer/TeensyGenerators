// Config.h -- global configuration switch and options

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

// individual features/commands 

#define ONE_SHOT_COMMAND	0	// enable OneShotCommand
#define VARIABLE_COMMANDS	1	// variable waveforms based on Pot inputs (which of course presumes a Pot)

// board specifics

#include "LiTeensy.h"

// app configuration

#define ASSEMBLYNAME "SigGen"
#define VERSION "2.0.7"
#define MODEL "Teensy 3.1"
#define DATE "17-Jul-2017 17:22"

#if VER_2_0_6A
#define VERSION "2.0.6A"
#endif
#if VER_2_0_6
#define DATE "26-Jul-2016 12:00"
#define VERSION "2.0.6"
#endif

#define ENABLE_DOWNLOAD_COMMANDS	0	// downloading is work in progress

// preferred abbreviations

typedef unsigned int uint;		// 16 bits
typedef unsigned long ulong;	// 32 bits

