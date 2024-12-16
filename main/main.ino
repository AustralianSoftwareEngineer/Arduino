int pin = 0;
int val = 0;
int dOn[7] = {0,0,0,0,0,0,0};
unsigned long Time = 0;

void setup() {
  Serial.begin(9600);
  Time = millis();
  SegmentStartUp();
  
  TEST_7SEGMENT_LED_TEST(); //Used for testing 7 segment array.
  // put your setup code here, to run once:
}

void loop() {
  //TemperatureOutput();
  InputManagerLED();
  Display();
}

void Display_A() {
    dOn[0] = 0;
    dOn[1] = 0;
    dOn[2] = 0;
    dOn[3] = 1;
    dOn[4] = 0;
    dOn[5] = 0;
    dOn[6] = 0;
    Serial.println("Displaying the Letter A.");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void Display() {
  digitalWrite(2, dOn[0]);
  digitalWrite(3, dOn[1]);
  digitalWrite(4, dOn[2]);
  digitalWrite(5, dOn[3]);
  digitalWrite(6, dOn[4]);
  digitalWrite(7, dOn[5]);
  digitalWrite(8, dOn[6]);
}

void TemperatureLogger() {
  if ((millis() - Time) > 1000) {
    Serial.print("Temperature: ");
    Serial.println((analogRead(A0) * 0.488));
    Time = millis();
  }
}

//User inputs 2 numbers E.g.(11) Which means digitalWrite(3, HIGH).
void InputManagerLED() {
  if (Serial.available() > 0) {
    // Check to see if pin is populated
    if (pin) {
      //Allocate the state
      val = Serial.read()-48;
      if (val > -1) {
        dOn[pin-2] = val;
        Serial.print("Updated pin: "); Serial.print(pin); Serial.print(". To state: "); Serial.println(val);
        pin = 0;
        val = 0;
      }
    }
    //Allocate the pin
    else if (!pin) {
      pin = Serial.read() -48;
      if (pin == 9) {
        TEST_OUTPUT_DISPLAY_ARRAY();
        pin = 0;
      }
      if (pin == 1) {
        Display();
        pin = 0;
      }
      else if (pin < 0) {
        pin = 0;
      }
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
    Serial.println(dOn[0]);
    Serial.print("3 is ");
    Serial.println(dOn[1]);
    Serial.print("4 is ");
    Serial.println(dOn[2]);
    Serial.print("5 is ");
    Serial.println(dOn[3]);
    Serial.print("6 is ");
    Serial.println(dOn[4]);
    Serial.print("7 is ");
    Serial.println(dOn[5]);
    Serial.print("8 is ");
    Serial.println(dOn[6]);
}

void TEST_Display_ZERO_TEST() {
    dOn[0] = 0;
    dOn[1] = 0;
    dOn[2] = 0;
    dOn[3] = 0;
    dOn[4] = 0;
    dOn[5] = 0;
    dOn[6] = 1;
    Serial.println("Testing the number ZERO : 0");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_ONE_TEST() {
    dOn[0] = 1;
    dOn[1] = 0;
    dOn[2] = 0;
    dOn[3] = 1;
    dOn[4] = 1;
    dOn[5] = 1;
    dOn[6] = 1;
    Serial.println("Testing the number ONE : 1");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_TWO_TEST() {
    dOn[0] = 0;
    dOn[1] = 0;
    dOn[2] = 1;
    dOn[3] = 0;
    dOn[4] = 0;
    dOn[5] = 1;
    dOn[6] = 0;
    Serial.println("Testing the number TWO : 2");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_THREE_TEST() {
    dOn[0] = 0;
    dOn[1] = 0;
    dOn[2] = 0;
    dOn[3] = 0;
    dOn[4] = 1;
    dOn[5] = 1;
    dOn[6] = 0;
    Serial.println("Testing the number THREE : 3");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_FOUR_TEST() {
    dOn[0] = 1;
    dOn[1] = 0;
    dOn[2] = 0;
    dOn[3] = 1;
    dOn[4] = 1;
    dOn[5] = 0;
    dOn[6] = 0;
    Serial.println("Testing the number FOUR : 4");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_FIVE_TEST() {
    dOn[0] = 0;
    dOn[1] = 1;
    dOn[2] = 0;
    dOn[3] = 0;
    dOn[4] = 1;
    dOn[5] = 0;
    dOn[6] = 0;
    Serial.println("Testing the number FIVE : 5");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_SIX_TEST() {
    dOn[0] = 0;
    dOn[1] = 1;
    dOn[2] = 0;
    dOn[3] = 0;
    dOn[4] = 0;
    dOn[5] = 0;
    dOn[6] = 0;
    Serial.println("Testing the number SIX : 6");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_SEVEN_TEST() {
    dOn[0] = 0;
    dOn[1] = 0;
    dOn[2] = 0;
    dOn[3] = 1;
    dOn[4] = 1;
    dOn[5] = 1;
    dOn[6] = 1;
    Serial.println("Testing the number SEVEN : 7");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_EIGHT_TEST() {
    dOn[0] = 0;
    dOn[1] = 0;
    dOn[2] = 0;
    dOn[3] = 0;
    dOn[4] = 0;
    dOn[5] = 0;
    dOn[6] = 0;
    Serial.println("Testing the number EIGHT : 8");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_Display_NINE_TEST() {
    dOn[0] = 0;
    dOn[1] = 0;
    dOn[2] = 0;
    dOn[3] = 1;
    dOn[4] = 1;
    dOn[5] = 0;
    dOn[6] = 0;
    Serial.println("Testing the number NINE : 9");
    TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_ALL_ON_TEST() {
  dOn[0] = 0;
  dOn[1] = 0;
  dOn[2] = 0;
  dOn[3] = 0;
  dOn[4] = 0;
  dOn[5] = 0;
  dOn[6] = 0;
  Serial.println("Testing the array being turned ON.");
  TEST_OUTPUT_DISPLAY_ARRAY();
}

void TEST_ALL_OFF_TEST() {
  dOn[0] = 1;
  dOn[1] = 1;
  dOn[2] = 1;
  dOn[3] = 1;
  dOn[4] = 1;
  dOn[5] = 1;
  dOn[6] = 1;
  Serial.println("Testing the array being turned OFF.");
  TEST_OUTPUT_DISPLAY_ARRAY();
}