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

// Referencing

#include "unit_test.h"

void setup() {
  Serial.begin(9600);
  deltaTime = millis();
  fixedTime = millis();

  SegmentStartUp();
  TEST_7SEGMENT_LED_TEST();
}

void loop() {
  if (logTemperature) {
    TemperatureLogger();
  }
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






// Character Commands
void Display_A() {
  int arr[7] = {0,0,0,1,0,0,0};
  Display(arr);
  Serial.println("Displaying the Letter A.");
}

void Display_H() {
  int arr[7] = {1,0,0,1,0,0,0};
  Display(arr);
  Serial.println("Displaying the Letter H.");
}

void LED_Spin() {
  int ledSpinArr[7] = {1,1,1,1,1,1,1};
  if (ledLocationLit > 6 ) {
    ledLocationLit = 0;
  }
  ledSpinArr[ledLocationLit] = 0;
  ledLocationLit++;
  if (ledLocationLit == 6) {
    ledLocationLit++;
  }
  Display(ledSpinArr);
}

void LED_Spin_Reverse() {
  unsigned int ledSpinArr[7] = {1,1,1,1,1,1,1};
  if (ledLocationLit > 6 ) {
    ledLocationLit = 5;
  }
  ledSpinArr[ledLocationLit] = 0;
  ledLocationLit--;
  Display(ledSpinArr);
}

void LED_Elevate() {
  unsigned int ledElevate[7] = {1,1,1,1,1,1,1};
  if (ledLocationLit == 6) {
    ledLocationLit = 0;
  }
  else if (ledLocationLit == 0) {
    ledLocationLit = 3;
  }
  else {
    ledLocationLit = 6;
  }
}

/* Wrong
void LED_Elevate() {
  unsigned int ledElevate[7] = {1,1,1,1,1,1,1};
  if (ledLocationLit > 6 ) {
    ledLocationLit = 0;
  }
  ledElevate[ledLocationLit] = 0;
  ledLocationLit += 3;
  Display(ledElevate);
}

void LED_Descend() {
  unsigned int ledDescend[7] = {1,1,1,1,1,1,1};
  if (ledLocationLit > 6 ) {
    ledLocationLit = 6;
  }
  ledDescend[ledLocationLit] = 0;
  Serial.println(ledLocationLit);
  ledLocationLit -= 3;
  Display(ledDescend);
}
*/
// Initialisation
void SegmentStartUp() {
  for (int i = 0; i<7; i++)
  {
    pinMode((i+2), OUTPUT);
  }
}




// TESTS


