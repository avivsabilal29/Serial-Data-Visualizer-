#ifndef SERIALWORKER_H
#define SERIALWORKER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include "ISerialHandler.h"

class SerialWorker : public QObject, public ISerialHandler {
    Q_OBJECT

public:
    explicit SerialWorker(QObject *parent = nullptr);
    ~SerialWorker() override;

    void startReading() override;
    void stopReading() override;
    void handleWorkerCommand(const QString &command) override;

    void setSerialPort(QSerialPort *port);


signals:
    void dataReceived(const QByteArray &data);

private slots:
    void readSerialData();

private:
    QSerialPort *serialPort;
    QTimer *readTimer;
    bool isRunning;
};

#endif // SERIALWORKER_H
