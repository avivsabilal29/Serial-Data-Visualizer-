#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Generate random float
  float randomValue = random(1000, 10000) / 100.0;  // Example: 10.00 to 100.00
  Serial.println(randomValue, 2);  // Send as string with 2 decimal places
  delay(500);  // Send every second
}
