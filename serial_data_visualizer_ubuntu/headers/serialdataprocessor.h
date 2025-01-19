#ifndef SERIALDATAPROCESSOR_H
#define SERIALDATAPROCESSOR_H

#include <QByteArray>
#include <QVector>

class SerialDataProcessor {
public:
    bool validateLRC(const QByteArray &data) const;
    double decodeData(const QByteArray &data) const;
    uint64_t parseTimestamp(const QByteArray &data) const;
};

#endif // SERIALDATAPROCESSOR_H
