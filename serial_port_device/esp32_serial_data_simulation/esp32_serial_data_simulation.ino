#include <Arduino.h>

const uint8_t STX = 0x02;  // Start-of-Text
const uint8_t ETX = 0x03;  // End-of-Text
bool isStreaming = false;  // Status streaming data

uint8_t calculateLRC(const uint8_t *data, size_t length) {
  uint8_t lrc = 0;
  for (size_t i = 0; i < length; i++) {
    lrc ^= data[i];
  }
  return lrc;
}

void sendData() {
  uint8_t buffer[15];

  // STX
  buffer[0] = STX;

  // UNIX Timestamp (8 bytes, big-endian)
  uint64_t timestamp = (uint64_t)time(NULL);
  for (int i = 0; i < 8; i++) {
    buffer[1 + i] = (timestamp >> (56 - 8 * i)) & 0xFF;  // Big-endian
  }

  float randomFloat = random(1000, 10000) / 100.0;
  uint8_t *floatBytes = (uint8_t *)&randomFloat;
  for (int i = 0; i < 4; i++) {
    buffer[9 + i] = floatBytes[3 - i];  // Big-endian
  }

  // LRC (1 byte)
  buffer[13] = calculateLRC(buffer, 13);

  // ETX
  buffer[14] = ETX;


  // Serial.write(buffer, sizeof(buffer));
  Serial.print("Buffer: ");
  for (size_t i = 0; i < sizeof(buffer); i++) {
    Serial.print("0x");
    if (buffer[i] < 0x10) Serial.print("0");  // Tambahkan nol di depan jika kurang dari 0x10
    Serial.print(buffer[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));
}

void loop() {
  // Periksa perintah START/STOP dari Qt
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    if (command == "START") {
      isStreaming = true;  // Mulai streaming data
    } else if (command == "STOP") {
      isStreaming = false;  // Hentikan streaming data
    }
  }


  if (isStreaming) {
    sendData();
    delay(1000);
  }
  sendData();
  delay(1000);
}
