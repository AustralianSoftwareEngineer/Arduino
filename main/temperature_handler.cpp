#ifndef TEMPERATURE_HANDLER_CPP
#define TEMPERATURE_HANDLER_CPP
#include "namespaces.h"

void TemperatureLogger() {
  if ((analogRead(A0) * 0.488) > 24.0 && logTemperature) {
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

#endif