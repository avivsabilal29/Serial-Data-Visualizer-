#include <Arduino.h>

const uint8_t STX = 0x02;
const uint8_t ETX = 0x03;
const int delayInterval = 1000;

bool isStreaming = false;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    handleCommand(command);
  }

  if (isStreaming) {
    sendData();
    delay(delayInterval);
  }
}

void handleCommand(const String &command) {
  if (command == "START") {
    isStreaming = true;
    Serial.println("Streaming started");
  } else if (command == "STOP") {
    isStreaming = false;
    Serial.println("Streaming stopped");
  } else {
    Serial.println("Unknown command");
  }
}

void sendData() {
  uint8_t frame[15] = { 0 };
  frame[0] = STX;

// UNIX Timestamp
  uint64_t timestamp = millis() / 1000;
  for (int i = 0; i < 8; i++) {
    frame[1 + i] = (timestamp >> (56 - i * 8)) & 0xFF;
  }

// Floating Point
  float value = random(1, 2000) / 100.0;
  uint8_t *floatBytes = (uint8_t *)&value;
  for (int i = 0; i < 4; i++) {
    frame[9 + i] = floatBytes[3 - i];
  }

  frame[13] = calculateLRC(frame + 1, 12);
    frame[14] = ETX;

  Serial.write(frame, 15);
}

uint8_t calculateLRC(uint8_t *data, size_t length) {
    uint8_t lrc = 0;
    for (size_t i = 0; i < length; i++) {
        lrc ^= data[i];
    }
    return lrc;
}

