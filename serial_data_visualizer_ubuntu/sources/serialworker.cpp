#include "headers/serialworker.h"

SerialWorker::SerialWorker(QObject *parent)
    : QObject(parent), serialPort(nullptr), readTimer(new QTimer(this)), isRunning(false)
{
    connect(readTimer, &QTimer::timeout, this, &SerialWorker::readSerialData);
}

SerialWorker::~SerialWorker()
{
    stopReading();
}

void SerialWorker::setSerialPort(QSerialPort *port)
{
    serialPort = port;
}

void SerialWorker::startReading()
{
    if (!serialPort || !serialPort->isOpen()) {
        return;
    }
    isRunning = true;
    readTimer->start(100);
}

void SerialWorker::stopReading()
{
    isRunning = false;
    readTimer->stop();
}

void SerialWorker::readSerialData()
{
    if (serialPort && serialPort->bytesAvailable() > 0) {
        QByteArray data = serialPort->readAll();
        emit dataReceived(data);
    }
}

void SerialWorker::handleWorkerCommand(const QString &command)
{
    if (command == "startReading") {
        startReading();
    } else if (command == "stopReading") {
        stopReading();
    }
}


