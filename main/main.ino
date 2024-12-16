unsigned long Time = 0;

void setup() {
  Serial.begin(9600);
  Time = millis();
}

void loop() {
  TemperatureLogger();
}

void TemperatureLogger() {
  if ((millis() - Time) > 1000) {
    Serial.print("Temperature: ");
    Serial.println((analogRead(A0) * 0.488));
    Time = millis();
  }
}