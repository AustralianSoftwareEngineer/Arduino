unsigned long Time = 0;

int selectedLedPin = 0;
int LedDisplayArray[7] = {0,0,0,0,0,0,0};

bool logTemperature = false;

void setup() {
  Serial.begin(9600);
  Time = millis();

  SegmentStartUp();
  TEST_7SEGMENT_LED_TEST(); //Used for testing 7 segment array.
  // put your setup code here, to run once:
}

void loop() {
  if (logTemperature) {
    TemperatureLogger();
  }
  InputManager();
}

void Display(){
  digitalWrite(2, LedDisplayArray[0]);
  digitalWrite(3, LedDisplayArray[1]);
  digitalWrite(4, LedDisplayArray[2]);
  digitalWrite(5, LedDisplayArray[3]);
  digitalWrite(6, LedDisplayArray[4]);
  digitalWrite(7, LedDisplayArray[5]);
  digitalWrite(8, LedDisplayArray[6]);
}

void Display_A() {
    LedDisplayArray[0] = 0;
    LedDisplayArray[1] = 0;
    LedDisplayArray[2] = 0;
    LedDisplayArray[3] = 1;
    LedDisplayArray[4] = 0;
    LedDisplayArray[5] = 0;
    LedDisplayArray[6] = 0;
    Serial.println("Displaying the Letter A.");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TemperatureLogger() {
  if ((millis() - Time) > 1000) {
    Serial.print("Temperature: ");
    Serial.println((analogRead(A0) * 0.488));
    Time = millis();
  }
}

void InputManager() {
    if (Serial.available() > 0) {
        switch (Serial.read()) {
            case 10:
                break;
            case 48:
                LedDisplayArray[selectedLedPin] = 0;
                break;
            case 49:
                LedDisplayArray[selectedLedPin] = 1;
                break;
            case 50:
                selectedLedPin = 2;
                break;
            case 51:
                selectedLedPin = 3;
                break;
            case 52:
                selectedLedPin = 4;
                break;
            case 53:
                selectedLedPin = 5;
                break;
            case 54:
                selectedLedPin = 6;
                break;
            case 55:
                selectedLedPin = 7;
                break;
            case 56:
                selectedLedPin = 8;
                break;
            case 57:
                selectedLedPin = 9;
                break;
            case 65:
                Display_A();
                break;
            case 68:
                TEST_ALL_OFF_TEST();
                break;
            case 84:
                logTemperature = !logTemperature;
                break;
            case 97:
                Display_A();
                break;
            case 99:
                TEST_ALL_OFF_TEST();
                break;
            case 100:
                TEST_ALL_OFF_TEST();
                break;
            case 116:
                TemperatureLogger();
                break;
            default:
                break;
        }
    }
}

void SegmentStartUp() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void TEST_7SEGMENT_LED_TEST() {
    TEST_Display_ZERO_TEST();
    Display();
    delay(1000);
    TEST_Display_ONE_TEST();
    Display();
    delay(1000);
    TEST_Display_TWO_TEST();
    Display();
    delay(1000);
    TEST_Display_THREE_TEST();
    Display();
    delay(1000);
    TEST_Display_FOUR_TEST();
    Display();
    delay(1000);
    TEST_Display_FIVE_TEST();
    Display();
    delay(1000);
    TEST_Display_SIX_TEST();
    Display();
    delay(1000);
    TEST_Display_SEVEN_TEST();
    Display();
    delay(1000);
    TEST_Display_EIGHT_TEST();
    Display();
    delay(1000);
    TEST_Display_NINE_TEST();
    Display();
    delay(1000);
    TEST_ALL_ON_TEST();
    Display();
    delay(1000);
    TEST_ALL_OFF_TEST();
}

void TEST_OUTPUT_DISPLAY_ARRAY() {
    Serial.print("2 is ");
    Serial.println(LedDisplayArray[0]);
    Serial.print("3 is ");
    Serial.println(LedDisplayArray[1]);
    Serial.print("4 is ");
    Serial.println(LedDisplayArray[2]);
    Serial.print("5 is ");
    Serial.println(LedDisplayArray[3]);
    Serial.print("6 is ");
    Serial.println(LedDisplayArray[4]);
    Serial.print("7 is ");
    Serial.println(LedDisplayArray[5]);
    Serial.print("8 is ");
    Serial.println(LedDisplayArray[6]);
}

void TEST_Display_ZERO_TEST() {
    LedDisplayArray[0] = 0;
    LedDisplayArray[1] = 0;
    LedDisplayArray[2] = 0;
    LedDisplayArray[3] = 0;
    LedDisplayArray[4] = 0;
    LedDisplayArray[5] = 0;
    LedDisplayArray[6] = 1;
    Serial.println("Testing the number ZERO : 0");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_ONE_TEST() {
    LedDisplayArray[0] = 1;
    LedDisplayArray[1] = 0;
    LedDisplayArray[2] = 0;
    LedDisplayArray[3] = 1;
    LedDisplayArray[4] = 1;
    LedDisplayArray[5] = 1;
    LedDisplayArray[6] = 1;
    Serial.println("Testing the number ONE : 1");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_TWO_TEST() {
    LedDisplayArray[0] = 0;
    LedDisplayArray[1] = 0;
    LedDisplayArray[2] = 1;
    LedDisplayArray[3] = 0;
    LedDisplayArray[4] = 0;
    LedDisplayArray[5] = 1;
    LedDisplayArray[6] = 0;
    Serial.println("Testing the number TWO : 2");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_THREE_TEST() {
    LedDisplayArray[0] = 0;
    LedDisplayArray[1] = 0;
    LedDisplayArray[2] = 0;
    LedDisplayArray[3] = 0;
    LedDisplayArray[4] = 1;
    LedDisplayArray[5] = 1;
    LedDisplayArray[6] = 0;
    Serial.println("Testing the number THREE : 3");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_FOUR_TEST() {
    LedDisplayArray[0] = 1;
    LedDisplayArray[1] = 0;
    LedDisplayArray[2] = 0;
    LedDisplayArray[3] = 1;
    LedDisplayArray[4] = 1;
    LedDisplayArray[5] = 0;
    LedDisplayArray[6] = 0;
    Serial.println("Testing the number FOUR : 4");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_FIVE_TEST() {
    LedDisplayArray[0] = 0;
    LedDisplayArray[1] = 1;
    LedDisplayArray[2] = 0;
    LedDisplayArray[3] = 0;
    LedDisplayArray[4] = 1;
    LedDisplayArray[5] = 0;
    LedDisplayArray[6] = 0;
    Serial.println("Testing the number FIVE : 5");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_SIX_TEST() {
    LedDisplayArray[0] = 0;
    LedDisplayArray[1] = 1;
    LedDisplayArray[2] = 0;
    LedDisplayArray[3] = 0;
    LedDisplayArray[4] = 0;
    LedDisplayArray[5] = 0;
    LedDisplayArray[6] = 0;
    Serial.println("Testing the number SIX : 6");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_SEVEN_TEST() {
    LedDisplayArray[0] = 0;
    LedDisplayArray[1] = 0;
    LedDisplayArray[2] = 0;
    LedDisplayArray[3] = 1;
    LedDisplayArray[4] = 1;
    LedDisplayArray[5] = 1;
    LedDisplayArray[6] = 1;
    Serial.println("Testing the number SEVEN : 7");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_EIGHT_TEST() {
    LedDisplayArray[0] = 0;
    LedDisplayArray[1] = 0;
    LedDisplayArray[2] = 0;
    LedDisplayArray[3] = 0;
    LedDisplayArray[4] = 0;
    LedDisplayArray[5] = 0;
    LedDisplayArray[6] = 0;
    Serial.println("Testing the number EIGHT : 8");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_NINE_TEST() {
    LedDisplayArray[0] = 0;
    LedDisplayArray[1] = 0;
    LedDisplayArray[2] = 0;
    LedDisplayArray[3] = 1;
    LedDisplayArray[4] = 1;
    LedDisplayArray[5] = 0;
    LedDisplayArray[6] = 0;
    Serial.println("Testing the number NINE : 9");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_ALL_ON_TEST() {
  LedDisplayArray[0] = 0;
  LedDisplayArray[1] = 0;
  LedDisplayArray[2] = 0;
  LedDisplayArray[3] = 0;
  LedDisplayArray[4] = 0;
  LedDisplayArray[5] = 0;
  LedDisplayArray[6] = 0;
  Serial.println("Testing the array being turned ON.");
  TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_ALL_OFF_TEST() {
  LedDisplayArray[0] = 1;
  LedDisplayArray[1] = 1;
  LedDisplayArray[2] = 1;
  LedDisplayArray[3] = 1;
  LedDisplayArray[4] = 1;
  LedDisplayArray[5] = 1;
  LedDisplayArray[6] = 1;
  Serial.println("Testing the array being turned OFF.");
  TEST_OUTPUT_DISPLAY_ARRAY();
}

void Display_Off() {
    for (int i = 0; i++; i < 7)
    {
        LedDisplayArray[i] = 0;
    }
}