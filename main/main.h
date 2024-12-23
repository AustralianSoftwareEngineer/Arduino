#ifndef MAIN_H
#define MAIN_H

extern unsigned long deltaTime;
extern unsigned long fixedTime;
extern int pinState;
extern bool logTemperature;
extern bool ledSpinActive;
extern bool ledSpinReverseActive;
extern bool ledElevateActive;
extern bool ledDescendActive;
extern unsigned int ledLocationLit;
extern unsigned int frameCount;

#include "display_functions.h"
#include "display_handler.h"
#include "input_handler.h"
#include "temperature_handler.h"
//#include "unit_test.h"

#endif