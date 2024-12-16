int pin = 0;
int val = 0;
int dOn[7] = {0,0,0,0,0,0,0};
unsigned long Time = 0;

void setup() {
  Serial.begin(9600);
  Time = millis();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
  //Used for testing 7 segment array.
  // put your setup code here, to run once:
}

void loop() {
  //TemperatureOutput();
  InputManagerLED();
  Display();
}

void Display(){
  digitalWrite(2, dOn[0]);
  digitalWrite(3, dOn[1]);
  digitalWrite(4, dOn[2]);
  digitalWrite(5, dOn[3]);
  digitalWrite(6, dOn[4]);
  digitalWrite(7, dOn[5]);
  digitalWrite(8, dOn[6]);
}

void TemperatureOutput()
{
  if ((millis() - Time) > 1000) {
    Serial.print("Temperature: ");
    Serial.println((analogRead(A0) / 0.488));
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
        pin = 0;
        val = 0;
      }
    }
    //Allocate the pin
    else if (!pin) {
      pin = Serial.read() -48;
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