#include "headers/serialdatavisualizer.h"
#include "ui_serialdatavisualizer.h"
#include "headers/rawdatawindow.h"


bool isStreaming = false;

SerialDataVisualizer::SerialDataVisualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SerialDataVisualizer)
{
    ui->setupUi(this);
    dataProcessor = new SerialDataProcessor();
    workerThread = new QThread(this);
    serialWorker = new SerialWorker();
    serialWorker->moveToThread(workerThread);

    connect(workerThread, &QThread::started, serialWorker, &SerialWorker::startReading);
    connect(serialWorker, &SerialWorker::dataReceived, this, &SerialDataVisualizer::handleSerialData);
    connect(this, &SerialDataVisualizer::sendDataToWorker, serialWorker, &SerialWorker::handleWorkerCommand);
    workerThread->start();

    rawDataPopUp = new rawDataWindow(this);
    chartManager = new ChartManager(ui->dataChartView, rawDataPopUp, this);
    chartManager->setBufferSize(maxBufferSize);

    connect(chartManager, &ChartManager::chartUpdated, this, [this](double minValue, double maxValue, double averageValue) {
        ui->averageLabel->setText(QString("Average: %1").arg(averageValue, 0, 'f', 2));
        ui->maxLabel->setText(QString("Max: %1").arg(maxValue, 0, 'f', 2));
        ui->minLabel->setText(QString("Min: %1").arg(minValue, 0, 'f', 2));
    });
    chartManager->startTimers();

    refreshSerialPorts();
    updateConnectionStatus(false);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SerialDataVisualizer::refreshSerialPorts);
    timer->start(1000);

    ui->portDropdown->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->portDropdown->addItem(info.portName());
    }


    ui->baudrateDropdown->clear();
    foreach (qint32 baudrate, QSerialPortInfo::standardBaudRates()) {
        ui->baudrateDropdown->addItem(QString::number(baudrate));
    }
}

SerialDataVisualizer::~SerialDataVisualizer()
{
    if (workerThread && workerThread->isRunning()) {
        workerThread->quit();
        workerThread->wait();
    }
    delete serialWorker;
    delete ui;
}

void SerialDataVisualizer::on_portDropdown_activated(int index)
{
    QString selectedPort = nullptr;
    selectedPort = ui->portDropdown->itemText(index);
    if (!selectedPort.startsWith("/dev/")){
        selectedPort = "/dev/" + selectedPort;
    }
    selectPortCom = selectedPort;

}



void SerialDataVisualizer::on_baudrateDropdown_activated(int index)
{
    selectedBaudrate = ui->baudrateDropdown->itemText(index);
}


void SerialDataVisualizer::on_connectButton_clicked(bool checked)
{
    if (!serialPort) {
        serialPort = new QSerialPort(this);
    }

    serialPort->setPortName(selectPortCom);
    serialPort->setBaudRate(selectedBaudrate.toInt());
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        updateConnectionStatus(!checked);
        serialWorker->setSerialPort(serialPort);
    } else {
        updateConnectionStatus(checked);
    }
}



void SerialDataVisualizer::on_disconnectButton_clicked(bool checked)
{
    if (serialPort && serialPort->isOpen()) {
        serialPort->close();
        serialPort->clear();
        if (chartManager) {
            chartManager->clearData();
        }
        updateConnectionStatus(checked);
    }
}

void SerialDataVisualizer::on_startButton_clicked()
{
    if (serialPort && serialPort->isOpen()) {
        serialPort->write("START\n");

        emit sendDataToWorker("startReading");
        isStreaming = true;
    } else {
        qDebug() << "Serial port not open. Cannot send START command.";
    }
}


void SerialDataVisualizer::on_stopButton_clicked()
{
    if (serialPort && serialPort->isOpen()) {
        serialPort->write("STOP\n");

        emit sendDataToWorker("stopReading");
        isStreaming = false;
    } else {
        qDebug() << "Serial port not open. Cannot send STOP command.";
    }
}


void SerialDataVisualizer::on_clearButton_clicked()
{

    if (chartManager) {
        chartManager->clearData();
    }
}


void SerialDataVisualizer::on_viewRawDataButton_clicked()
{
    if (rawDataPopUp) {
        rawDataPopUp->show();
        rawDataPopUp->raise();
        rawDataPopUp->activateWindow();
    }
}


void SerialDataVisualizer::refreshSerialPorts()
{
    static QStringList previousPorts;
    QStringList currentPorts;

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        currentPorts << info.portName();
    }

    if (currentPorts != previousPorts) {
        previousPorts = currentPorts;

        ui->portDropdown->clear();
        foreach (const QString &portName, currentPorts) {
            ui->portDropdown->addItem(portName);
        }
    }
}

void SerialDataVisualizer::updateConnectionStatus(bool isConnected)
{
    QPixmap pixmap;
    if (isConnected) {
        pixmap = QPixmap(":/connected.png").scaled(16, 16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->statusTextLabel->setText("Connected");
    } else {
        pixmap = QPixmap(":/disconnected.png").scaled(16, 16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->statusTextLabel->setText("Disconnected");
    }
    ui->iconLabel->setPixmap(pixmap);
}


void SerialDataVisualizer::handleSerialData(const QByteArray &data)
{

    if (!isStreaming) return;

    static QByteArray buffer;
    buffer.append(data);

    while (true) {
        int startIdx = buffer.indexOf(0x02);
        int endIdx = buffer.indexOf(0x03, startIdx);

        if (startIdx == -1 || endIdx == -1) {
            break;
        }

        if (endIdx - startIdx + 1 != 15) {
            chartManager->enqueueRawData(QString(buffer.mid(0, startIdx + 1).toHex()), false);
            buffer.remove(0, startIdx + 1);
            continue;
        }

        QByteArray frame = buffer.mid(startIdx, 15);

        if (!dataProcessor->validateLRC(frame)) {
            QString warningMessage = "Warning: Invalid LRC detected. Frame ignored.";
            chartManager->enqueueRawData(QString(frame.toHex()), false);
            buffer.remove(0, endIdx + 1);
            continue;
        }

        double floatValue = dataProcessor->decodeData(frame);
        uint64_t timestamp = dataProcessor->parseTimestamp(frame);
        chartManager->appendData(floatValue, timestamp);
        chartManager->enqueueRawData(QString("Timestamp: %1, Value: %2")
                                         .arg(timestamp)
                                         .arg(floatValue, 0, 'f', 2),
                                     true);

        buffer.remove(0, endIdx + 1);
    }

    if (buffer.size() > 15) {
        buffer.clear();
    }
}
