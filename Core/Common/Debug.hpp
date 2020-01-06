#pragma once

/*
DEBUG macros enable compile-time choice of logging messages.
Per-file debugging can be done by turning on/off #define DEBUG.
Per-module debugging can be done by turning on/off #define DEBUG_[MODULE].

Example

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif
...
#ifdef DEBUG
// log messages
#endif
*/

#define DEBUG_APPLICATION
#define DEBUG_COMMON
#define DEBUG_GRAPHICS
#define DEBUG_INTERACTION
#define DEBUG_PHYSICS