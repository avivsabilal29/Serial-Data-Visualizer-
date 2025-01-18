#include "headers/serialdataprocessor.h"
#include <cstring>


bool SerialDataProcessor::validateLRC(const QByteArray &data) const {
    if (data.size() != 15) return false;

    uint8_t calculatedLRC = 0;
    for (int i = 1; i < 13; i++) {
        calculatedLRC ^= static_cast<uint8_t>(data[i]);
    }
    uint8_t frameLRC = static_cast<uint8_t>(data[13]);
    return calculatedLRC == frameLRC;
}

double SerialDataProcessor::decodeData(const QByteArray &data) const {
    if (data.size() != 15) return 0.0;

    uint8_t floatBytes[4] = {
        static_cast<uint8_t>(data[9]),
        static_cast<uint8_t>(data[10]),
        static_cast<uint8_t>(data[11]),
        static_cast<uint8_t>(data[12])
    };

    uint32_t intRepresentation =
        (static_cast<uint32_t>(floatBytes[0]) << 24) |
        (static_cast<uint32_t>(floatBytes[1]) << 16) |
        (static_cast<uint32_t>(floatBytes[2]) << 8) |
        (static_cast<uint32_t>(floatBytes[3]));

    float value;
    memcpy(&value, &intRepresentation, sizeof(float));
    return static_cast<double>(value);
}

uint64_t SerialDataProcessor::parseTimestamp(const QByteArray &data) const {
    if (data.size() != 15) return 0;

    uint64_t timestamp = 0;
    for (int i = 0; i < 8; i++) {
        timestamp = (timestamp << 8) | static_cast<uint8_t>(data[1 + i]);
    }
    return timestamp;
}

