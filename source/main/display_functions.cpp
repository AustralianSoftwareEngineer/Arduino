#include "display_functions.h"

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