


void Display(int inputAr[7]) {
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(i+2, inputAr[i]);
  }
}

void Display_Off() {
  int test_all_off[7] = {1,1,1,1,1,1,1};
  Display(test_all_off);
}

void ChangeLEDState(int pin, int state) {
    digitalWrite(pin, state);
}