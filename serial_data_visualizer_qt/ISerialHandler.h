#ifndef ISERIALHANDLER_H
#define ISERIALHANDLER_H

#include <QByteArray>

class ISerialHandler {
public:
    virtual ~ISerialHandler() = default;
    virtual void startReading() = 0;
    virtual void stopReading() = 0;
    // virtual void sendData(const QByteArray &data) = 0;
    virtual void handleWorkerCommand(const QString &command) = 0;
};

#endif // ISERIALHANDLER_H
