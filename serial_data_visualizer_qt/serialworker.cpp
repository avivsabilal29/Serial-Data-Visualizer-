#include "serialworker.h"
#include <QDebug>

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
        qDebug() << "Serial port is not open.";
        return;
    }
    isRunning = true;
    readTimer->start(100); // Baca data setiap 100ms
    qDebug() << "Started reading serial data.";
}

void SerialWorker::stopReading()
{
    isRunning = false;
    readTimer->stop();
    qDebug() << "Stopped reading serial data.";
}

void SerialWorker::readSerialData()
{
    if (serialPort && serialPort->bytesAvailable() > 0) {
        QByteArray data = serialPort->readAll();
        emit dataReceived(data);
        qDebug() << "Data received in worker:" << data;
    }
}

void SerialWorker::handleWorkerCommand(const QString &command)
{
    if (command == "startReading") {
        startReading(); // Mulai membaca data
    } else if (command == "stopReading") {
        stopReading(); // Hentikan pembacaan data
        // resetWorker();
    }
}

void SerialWorker::resetWorker()
{
    isRunning = false; // Pastikan loop berhenti
    if (serialPort) {
        serialPort->clear(); // Hapus data dari buffer serial port
    }
    qDebug() << "Worker reset. Serial buffer cleared.";
}

