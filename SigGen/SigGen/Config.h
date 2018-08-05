// Config.h -- global configuration switch and options

#pragma once

#include "TeensyCommon.h"
#include "SigGen.h"

// app identification

#define ASSEMBLYNAME "SigGen"
#define VERSION "3.0.1"
#define MODEL "Teensy 3.1"
#define DATE "5-Aug-2018 11:40"

// individual features/commands

#define ONE_SHOT_COMMAND	1	// enable OneShotCommand
#define VARIABLE_COMMANDS	1	// variable waveforms based on Pot inputs 
#define ENABLE_DOWNLOAD_COMMANDS	0	// downloading is work in progress

