#ifndef INPUT_HANDLER_CPP
#define INPUT_HANDLER_CPP

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
                ClearStates();
                Display_A();
                break;
            case 68:
                ClearStates();
                Display_Off();
                break;
            case 83:
                ClearStates();
                ledSpinReverseActive = true;
                break;
            case 84:
                logTemperature = !logTemperature;
                break;
            case 97:
                ClearStates();
                Display_A();
                break;
            case 99:
                ClearStates();
                Display_Off();
                break;
            case 100:
                ClearStates();
                ledDescendActive = true;
                break;
            case 101:
                ClearStates();
                ledElevateActive = true;
                break;
            case 115:
                ClearStates();
                ledSpinActive = true;
                break;
            case 116:
                TemperatureLogger();
                break;
            default:
                break;
        }
    }
}

void ClearStates() {
  ledLocationLit = 0;
  ledSpinActive = false;
  ledSpinReverseActive = false;
  ledElevateActive = false;
  ledDescendActive = false;
}

#define INPUT_HANDLER_CPP