#pragma once

#include "Config.h"

// Trace, Printf //////////////////////////////////////////////////////

extern bool TraceEnabled;
extern void Trace(const char*fmt, ...);	// don't forget "\n"
extern void Printf(const char*fmt, ...);
