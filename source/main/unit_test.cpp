#include "unit_test.h"

const unsigned int DelayAmount = 500;

void TEST_7SEGMENT_LED_TEST() {
  if (!testsRunning) {
    testsRunning = true;
    TEST_Display_ZERO_TEST();
    delay(DelayAmount);
    TEST_Display_ONE_TEST();
    delay(DelayAmount);
    TEST_Display_TWO_TEST();
    delay(DelayAmount);
    TEST_Display_THREE_TEST();
    delay(DelayAmount);
    TEST_Display_FOUR_TEST();
    delay(DelayAmount);
    TEST_Display_FIVE_TEST();
    delay(DelayAmount);
    TEST_Display_SIX_TEST();
    delay(DelayAmount);
    TEST_Display_SEVEN_TEST();
    delay(DelayAmount);
    TEST_Display_EIGHT_TEST();
    delay(DelayAmount);
    TEST_Display_NINE_TEST();
    delay(DelayAmount);
    TEST_SPIN_TEST();
    delay(DelayAmount);
    TEST_SPIN_REVERSE_TEST();
    delay(DelayAmount);
    TEST_ALL_ON_TEST();
    delay(DelayAmount);
    TEST_ALL_OFF_TEST();
    testsRunning = false;
  }
}

void TEST_Display_ZERO_TEST() {
  int test_ZERO[7] = {0,0,0,0,0,0,1};
  Display(test_ZERO);
  Serial.println("Testing the number ZERO : 0");
}

void TEST_Display_ONE_TEST() {
  int test_ONE[7] = {1,0,0,1,1,1,1};
  Display(test_ONE);
  Serial.println("Testing the number ONE : 1");
}

void TEST_Display_TWO_TEST() {
  int test_TWO[7] = {0,0,1,0,0,1,0};
  Display(test_TWO);
  Serial.println("Testing the number TWO : 2");
}

void TEST_Display_THREE_TEST() {
  int test_THREE[7] = {0,0,0,0,1,1,0};
  Display(test_THREE);
  Serial.println("Testing the number THREE : 3");
}

void TEST_Display_FOUR_TEST() {
  int test_FOUR[7] = {1,0,0,1,1,0,0};
  Display(test_FOUR);
  Serial.println("Testing the number FOUR : 4");
}

void TEST_Display_FIVE_TEST() {
  int test_FIVE[7] = {0,1,0,0,1,0,0};
  Display(test_FIVE);
  Serial.println("Testing the number FIVE : 5");
}

void TEST_Display_SIX_TEST() {
  int test_SIX[7] = {0,1,0,0,0,0,0};
  Display(test_SIX);
  Serial.println("Testing the number SIX : 6");
}

void TEST_Display_SEVEN_TEST() {
  int test_SEVEN[7] = {0,0,0,1,1,1,1};
  Display(test_SEVEN);
  Serial.println("Testing the number SEVEN : 7");
}

void TEST_Display_EIGHT_TEST() {
  int test_EIGHT[7] = {0,0,0,0,0,0,0};
  Display(test_EIGHT);
  Serial.println("Testing the number EIGHT : 8");
}

void TEST_Display_NINE_TEST() {
  int test_NINE[7] = {0,0,0,1,1,0,0};
  Display(test_NINE);
  Serial.println("Testing the number NINE : 9");
}

void TEST_SPIN_TEST() {
  Serial.println("Testing the LED Spinning function with 7 Loops at 12FPS.");
  for (int i = 0; i < 28; i++) { 
    LED_Spin();
    delay(100);
  }
}

void TEST_SPIN_REVERSE_TEST() {
  Serial.println("Testing the LED Spinning reverse function with 7 Loops at 12FPS.");
  for (int i = 0; i < 28; i++) { 
    LED_Spin_Reverse();
    delay(100);
  }
}

void TEST_ALL_ON_TEST() {
  int test_all_on[7] = {0,0,0,0,0,0,0};
  Display(test_all_on);
  Serial.println("Testing the array being turned ON.");
}

void TEST_ALL_OFF_TEST() {
  int test_all_off[7] = {1,1,1,1,1,1,1};
  Display(test_all_off);
  Serial.println("Testing the array being turned OFF.");
}
