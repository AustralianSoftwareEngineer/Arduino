void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Temperature: ");
  Serial.println((analogRead(A0) / 1.8));
}
