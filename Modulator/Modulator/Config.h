// Config.h -- global configuration switch and options

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

// board specifics

// only define one of these

#define TEENSY_LI			0	// original "Li" board
#define TEENSY_OBIS		1	// revisions for modulating obis lasers
#define TEENSY_CELLEX	0	// revisions for cellex version

// individual features/commands 

#define ONE_SHOT_COMMAND	0	// enable OneShotCommand
#define VARIABLE_COMMANDS	0	// variable waveforms based on Pot inputs (which of course presumes a Pot)

#include "Teensy.h"

// app configuration

#define ASSEMBLYNAME "Modulator"
#define VERSION "0.0.3"
#define MODEL "Teensy 3.1"
#define DATE "23-Jul-2018 14:50"

#if VER_0_0_1
#define ASSEMBLYNAME "SigGen"
#define VERSION "0.0.1"
#define MODEL = "Teensy 3.1"
#define DATE "2-Jun-2017 14:00"
#endif

#define ENABLE_DOWNLOAD_COMMANDS	0	// downloading is work in progress

// preferred abbreviations

typedef unsigned int uint;		// 16 bits
typedef unsigned long ulong;	// 32 bits

