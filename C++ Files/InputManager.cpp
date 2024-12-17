//User inputs 2 numbers E.g.(11) Which means digitalWrite(3, HIGH).

/*Depreciated
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
*/




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
                TEST_OUTPUT_DISPLAY_ARRAY();
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
        Display();
    }
}