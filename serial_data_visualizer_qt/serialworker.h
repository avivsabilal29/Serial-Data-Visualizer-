#ifndef SERIALWORKER_H
#define SERIALWORKER_H

#include <QObject>
#include <QSerialPort>
#include <QTimer>

class SerialWorker : public QObject
{
    Q_OBJECT

public:
    explicit SerialWorker(QObject *parent = nullptr);
    ~SerialWorker();

    void setSerialPort(QSerialPort *port);

signals:
    void dataReceived(const QByteArray &data);

public slots:
    void startReading();
    void stopReading();
    void handleWorkerCommand(const QString &command);



private slots:
    void readSerialData();

private:
    QSerialPort *serialPort;
    QTimer *readTimer; // Timer untuk pembacaan serial
    bool isRunning;
};

#endif // SERIALWORKER_H
