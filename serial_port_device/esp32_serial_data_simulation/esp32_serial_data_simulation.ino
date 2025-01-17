#include <Arduino.h>

// Struktur Frame:
// | STX | UNIX Timestamp | Floating Point Number | LRC | ETX |

const uint8_t STX = 0x02; // Start-of-Text
const uint8_t ETX = 0x03; // End-of-Text
const int delayInterval = 1000; // 1 detik interval pengiriman

bool isStreaming = false; // Status untuk streaming data

void setup() {
  Serial.begin(115200); // Inisialisasi serial
}

void loop() {
  // Periksa apakah ada data dari Qt
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Baca perintah sampai karakter newline
    handleCommand(command);
  }

  // Kirim data hanya jika streaming aktif
  if (isStreaming) {
    sendData();
    delay(delayInterval); // Tunggu sebelum mengirim frame berikutnya
  }
}

// Fungsi untuk menangani perintah dari Qt
void handleCommand(const String &command) {
  if (command == "START") {
    isStreaming = true;
    Serial.println("Streaming started"); // Konfirmasi ke Qt
  } else if (command == "STOP") {
    isStreaming = false;
    Serial.println("Streaming stopped"); // Konfirmasi ke Qt
  } else {
    Serial.println("Unknown command"); // Konfirmasi untuk perintah yang tidak valid
  }
}

void sendData() {
  uint8_t frame[15] = { 0 };
  frame[0] = 0x02;                       // STX
  uint64_t timestamp = millis() / 1000;  // UNIX Timestamp
  for (int i = 0; i < 8; i++) {
    frame[1 + i] = (timestamp >> (56 - i * 8)) & 0xFF;  // Big-endian
  }
  float value = random(1, 2000) / 100.0;  // Float value
  uint8_t *floatBytes = (uint8_t *)&value;
  for (int i = 0; i < 4; i++) {
    frame[9 + i] = floatBytes[3 - i];  // Big-endian
  }
  frame[13] = calculateLRC(frame + 1, 12);  // LRC
  frame[14] = 0x03;                         // ETX

  Serial.write(frame, 15);
}

uint8_t calculateLRC(uint8_t *data, size_t length) {
    uint8_t lrc = 0;
    for (size_t i = 0; i < length; i++) { // XOR semua byte
        lrc ^= data[i];
    }
    return lrc;
}

