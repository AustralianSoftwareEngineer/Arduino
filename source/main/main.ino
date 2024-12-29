#include "main.h"

unsigned long deltaTime = 0;
unsigned long fixedTime = 0;
int pinState = 0;
bool logTemperature = false;
bool ledSpinActive = false;
bool ledSpinReverseActive = false;
bool ledElevateActive = false;
bool ledDescendActive = false;
bool ledFadeOnActive = true;
bool ledFadeOffActive = true;
bool ledPongActive = true;
bool testsRunning = false;
unsigned int ledLocationLit = 0;
unsigned int frameCount = 0;
unsigned int fadedAmount = 0;

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
  for (int i = 2; i<12; i++)
  {
    pinMode((i), OUTPUT);
  }
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
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
  if (analogRead(A1) == 1023 && !testsRunning) { {
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
  if (Serial.println(analogRead(A2) != 119 && Serial.println(analogRead(A2)) != 118)) {
    Serial.println(analogRead(A2));
  }
  if (ledFadeOnActive && frameCount % 5 == 0) {
    ledFadeOn(9);
  }
  if (ledFadeOffActive && frameCount % 5 == 0) {
    ledFadeOff(10);
  }
  if (ledPongActive && frameCount % 5 == 0) {
    ledFadePingPong(11);
  }
}
