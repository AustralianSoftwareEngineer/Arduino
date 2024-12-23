#include "main.h"

unsigned long deltaTime = 0;
unsigned long fixedTime = 0;
int pinState = 0;
bool logTemperature = false;
bool ledSpinActive = false;
bool ledSpinReverseActive = false;
bool ledElevateActive = false;
bool ledDescendActive = false;
unsigned int ledLocationLit = 0;
unsigned int frameCount = 0;

void setup() {
  Serial.begin(9600);
  deltaTime = millis();
  fixedTime = millis();

  SegmentStartUp();
  #ifdef UNIT_TEST_H
  TEST_7SEGMENT_LED_TEST();
  #endif
}

void SegmentStartUp() {
  for (int i = 0; i<7; i++)
  {
    pinMode((i+2), OUTPUT);
  }
}

void loop() {
  #ifdef TEMPERATURE_HANDLER_H
  if (logTemperature) {
    TemperatureLogger();
  }
  #endif
  InputManager();
  if (millis() - fixedTime >= 16)
  {
    FixedLoop();
    fixedTime = millis();
    frameCount++;
    if (frameCount > 60) {
      frameCount = 0;
    }
  }
}

//Scaled to a fixed framerate
void FixedLoop() {
  if (ledSpinActive && frameCount % 5 == 0) {
    LED_Spin();
  }
  else if (ledSpinReverseActive && frameCount % 5 == 0) {
    LED_Spin_Reverse();
  }
  else if (ledElevateActive && frameCount % 10 == 0) {
    LED_Elevate();
  }
  else if (ledDescendActive && frameCount % 10 == 0) {
    //LED_Descend();
  }
}
