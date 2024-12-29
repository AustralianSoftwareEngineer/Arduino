#include "display_functions.h"
#include "display_handler.h"
#include "input_handler.h"
#include "temperature_handler.h"
#include "unit_test.h"

unsigned long deltaTime = 0;
unsigned long fixedTime = 0;
int pinState = 0;
bool logTemperature = false;
bool ledSpinActive = false;
bool ledSpinReverseActive = false;
bool ledElevateActive = false;
bool ledDescendActive = false;
bool testsRunning = false;
unsigned int ledLocationLit = 0;
unsigned int frameCount = 0;
unsigned int fadedAmount = 0;

void setup() {
  Serial.begin(9600);
  deltaTime = millis();
  fixedTime = millis();

  SegmentStartUp();
  TEST_7SEGMENT_LED_TEST();
}

void SegmentStartUp() {
  for (int i = 2; i<10; i++)
  {
    pinMode((i), OUTPUT);
  }
}

void loop() {
  InputManager();
  if (logTemperature) {
    TemperatureLogger();
  }
  if (millis() - fixedTime >= 16)
  {
    FixedLoop();
    fixedTime = millis();
    frameCount++;
    if (frameCount > 60) {
      frameCount = 0;
    }
  }
  if (analogRead(A1) == 1023 && !testsRunning) {
    {
      Serial.println(analogRead(A1)); //Current left in for debugging on analog input.
      TEST_7SEGMENT_LED_TEST();
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
