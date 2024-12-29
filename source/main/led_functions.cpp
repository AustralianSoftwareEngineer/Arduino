#include "led_functions.h"

unsigned int luminosity[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
bool direction = false;

void ledFadeOff(uint8_t led_target) {
  if (luminosity[led_target] == 0) {
    luminosity[led_target] = 255;
  }
  if (luminosity[led_target] <= 11) {
    luminosity[led_target] = 0;
  }
  else if (luminosity[led_target] > 11) {
    luminosity[led_target] -= 5;
  }
  analogWrite(led_target, luminosity[led_target]);
}

void ledFadeOn(uint8_t led_target) {
  if (luminosity[led_target] == 255) {
    luminosity[led_target] = 0;
  }
  if (luminosity[led_target] > 244) {
    luminosity[led_target] = 255;
  }
  else if (luminosity[led_target] < 245) {
    luminosity[led_target] += 5;
  }
  analogWrite(led_target, luminosity[led_target]);
}

void ledFadePingPong(uint8_t led_target) {
  if (luminosity[led_target] == 0) {
    direction = !direction;
  }
  if (luminosity[led_target] == 255) {
    direction = !direction;
  }
  if (direction) {
    if (luminosity[led_target] > 244) {
      luminosity[led_target] = 255;
    }
    else if (luminosity[led_target] < 245) {
      luminosity[led_target] += 5;
    }
  }
  else if (!direction) {
    if (luminosity[led_target] <= 11) {
      luminosity[led_target] = 0;
    }
    else if (luminosity[led_target] > 11) {
      luminosity[led_target] -= 5;
    }
  }
  analogWrite(led_target, luminosity[led_target]);
}