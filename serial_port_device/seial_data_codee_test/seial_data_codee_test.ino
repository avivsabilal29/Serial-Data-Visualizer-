#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  float randomValue = random(1000, 10000) / 100.0;
  Serial.println(randomValue, 2);
  delay(500);
}
