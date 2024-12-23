unsigned long deltaTime = 0;
unsigned long fixedTime = 0;
int pinState = 0;
bool logTemperature = false;
bool ledSpinActive = false;
bool ledSpinReverseActive = false;
unsigned int ledSpinLocPrevious = 0;
unsigned int frameCount = 0;

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
}

// Temperature Logging
void TemperatureLogger() {
  if ((analogRead(A0) * 0.488) > 28.0 && logTemperature) {
    if ((millis() - deltaTime) > 1000) {
      Display_H();
    }
  }
  if ((millis() - deltaTime) > 1000) {
    Serial.print("Temperature: ");
    Serial.println((analogRead(A0) * 0.488));
    deltaTime = millis();
  }
}

// Input Handling
void InputManager() {
    if (Serial.available() > 0) {
        switch (Serial.read()) {
            case 10:
                break;
            case 48:
                pinState = 0;
                break;
            case 49:
                pinState = 1;
                break;
            case 50:
                ChangeLEDState(2, pinState);
                break;
            case 51:
                ChangeLEDState(3, pinState);
                break;
            case 52:
                ChangeLEDState(4, pinState);
                break;
            case 53:
                ChangeLEDState(5, pinState);
                break;
            case 54:
                ChangeLEDState(6, pinState);
                break;
            case 55:
                ChangeLEDState(7, pinState);
                break;
            case 56:
                ChangeLEDState(8, pinState);
                break;
            case 57:
                break;
            case 65:
                Display_A();
                break;
            case 68:
                Display_Off();
                break;
            case 83:
                ledSpinReverseActive = false;
                ledSpinActive = !ledSpinActive;
                break;
            case 115:
                ledSpinActive = false;
                ledSpinReverseActive = !ledSpinReverseActive;
                break;
            case 84:
                logTemperature = !logTemperature;
                break;
            case 97:
                Display_A();
                break;
            case 99:
                Display_Off();
                break;
            case 100:
                Display_Off();
                break;
            case 116:
                TemperatureLogger();
                break;
            default:
                break;
        }
    }
}

void Display(int inputAr[7]) {
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(i+2, inputAr[i]);
  }
}

void ChangeLEDState(int pin, int state) {
    digitalWrite(pin, state);
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

void Display_Off() {
  int test_all_off[7] = {1,1,1,1,1,1,1};
  Display(test_all_off);
}

void LED_Spin() {
  int ledSpinArr[7] = {1,1,1,1,1,1,1};
  if (ledSpinLocPrevious > 6 ) {
    ledSpinLocPrevious = 0;
  }
  ledSpinArr[ledSpinLocPrevious] = 0;
  ledSpinLocPrevious++;
  Display(ledSpinArr);
}

void LED_Spin_Reverse() {
  unsigned int ledSpinArr[7] = {1,1,1,1,1,1,1};
  if (ledSpinLocPrevious > 6 ) {
    ledSpinLocPrevious = 6;
  }
  ledSpinArr[ledSpinLocPrevious] = 0;
  ledSpinLocPrevious--;
  Display(ledSpinArr);
}


// Initialisation
void SegmentStartUp() {
  for (int i = 0; i<7; i++)
  {
    pinMode((i+2), OUTPUT);
  }
}




// TESTS
const unsigned int DelayAmount = 500;

void TEST_7SEGMENT_LED_TEST() {
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