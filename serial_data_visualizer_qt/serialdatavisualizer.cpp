#include "serialdatavisualizer.h"
#include "ui_serialdatavisualizer.h"
#include "rawdatawindow.h"


bool isStreaming = false;



SerialDataVisualizer::SerialDataVisualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SerialDataVisualizer)
{
    ui->setupUi(this);
    // Inisialisasi thread dan worker
    workerThread = new QThread(this);
    serialWorker = new SerialWorker();
    serialWorker->moveToThread(workerThread);

    // Hubungkan signal-slot
    connect(workerThread, &QThread::started, serialWorker, &SerialWorker::startReading);
    connect(serialWorker, &SerialWorker::dataReceived, this, &SerialDataVisualizer::handleSerialData);
    connect(this, &SerialDataVisualizer::sendDataToWorker, serialWorker, &SerialWorker::handleWorkerCommand);




    workerThread->start();

    initializeTimers();
    refreshSerialPorts();
    updateConnectionStatus(false);
    rawDataPopUp = new rawDataWindow(this);

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

    // initialize chart
    series = new QLineSeries();
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();


    chart->axes(Qt::Vertical).first()->setRange(0, 100);
    chart->axes(Qt::Horizontal).first()->setRange(0, 10);
    chart->setVisible(true);

    ui->dataChartView->setChart(chart);


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
    selectPortCom = ui->portDropdown->itemText(index);
    qDebug() << "Port selected:" << selectPortCom;
}



void SerialDataVisualizer::on_baudrateDropdown_activated(int index)
{
    selectedBaudrate = ui->baudrateDropdown->itemText(index);
    qDebug() << "Baudrate selected:" << selectedBaudrate;
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
        qDebug() << "Serial port successfully opened.";
        updateConnectionStatus(!checked);
        serialWorker->setSerialPort(serialPort);
    } else {
        qDebug() << "Failed to open serial port.";
        updateConnectionStatus(checked);
    }
}



void SerialDataVisualizer::on_disconnectButton_clicked(bool checked)
{
    if (serialPort && serialPort->isOpen()) {
        serialPort->close();
        updateConnectionStatus(checked);
    }
}

void SerialDataVisualizer::on_startButton_clicked()
{
    if (serialPort && serialPort->isOpen()) {
        serialPort->write("START\n");
        qDebug() << "Sent command: START";

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
        qDebug() << "Sent command: STOP";

        emit sendDataToWorker("stopReading");
        isStreaming = false;
    } else {
        qDebug() << "Serial port not open. Cannot send STOP command.";
    }
}


void SerialDataVisualizer::on_clearButton_clicked()
{
    series->clear();
    dataBuffer.clear();
    timestamps.clear();
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
        qDebug() << "Serial ports changed!";
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
        pixmap = QPixmap(":/component_asset/connected.png").scaled(16, 16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->statusTextLabel->setText("Connected");
    } else {
        pixmap = QPixmap(":/component_asset/disconnected.png").scaled(16, 16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->statusTextLabel->setText("Disconnected");
    }
    ui->iconLabel->setPixmap(pixmap);
}


void SerialDataVisualizer::handleSerialData(const QByteArray &data)
{
    qDebug() << "Data received in main thread:" << data;

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
            qDebug() << "Invalid frame length. Removing invalid data.";
            rawDataBuffer.enqueue(qMakePair(QString(buffer.mid(0, startIdx + 1).toHex()), false));
            buffer.remove(0, startIdx + 1);
            continue;
        }

        QByteArray frame = buffer.mid(startIdx, 15);
        qDebug() << "Received frame:" << frame.toHex();

        if (!validateLRC(frame)) {
            QString warningMessage = "Warning: Invalid LRC detected. Frame ignored.";
            qDebug() << warningMessage;
            rawDataBuffer.enqueue(qMakePair(QString(frame.toHex()), false));

            buffer.remove(0, endIdx + 1);
            continue;
        }

        double floatValue = decodeData(frame);
        uint64_t timestamp = parseTimestamp(frame);

        if (dataBuffer.size() >= maxBufferSize) {
            dataBuffer.removeFirst();
            timestamps.removeFirst();
        }
        dataBuffer.append(floatValue);
        timestamps.append(timestamp);

        rawDataBuffer.enqueue(qMakePair(QString("Timestamp: %1, Value: %2")
                                            .arg(timestamp)
                                            .arg(floatValue, 0, 'f', 2),
                                        true));

        buffer.remove(0, endIdx + 1);
    }

    qDebug() << "Remaining buffer size:" << buffer.size();
    if (buffer.size() > 15) {
        qDebug() << "Warning: Buffer might be stuck. Resetting buffer.";
        buffer.clear();
    }
}


void SerialDataVisualizer::initializeTimers()
{
    QTimer *chartUpdateTimer = new QTimer(this);
    connect(chartUpdateTimer, &QTimer::timeout, this, &SerialDataVisualizer::updateChart);
    chartUpdateTimer->start(100);

    QTimer *rawDataUpdateTimer = new QTimer(this);
    connect(rawDataUpdateTimer, &QTimer::timeout, this, &SerialDataVisualizer::updateRawData);
    rawDataUpdateTimer->start(100);
}

void SerialDataVisualizer::updateChart()
{
    if (dataBuffer.isEmpty()) return;
    series->clear();
    double minValue = std::numeric_limits<double>::max();
    double maxValue = std::numeric_limits<double>::min();
    double sumValues = 0.0;

    for (int i = 0; i < dataBuffer.size(); ++i) {
        series->append(timestamps[i], dataBuffer[i]);
        minValue = qMin(minValue, dataBuffer[i]);
        maxValue = qMax(maxValue, dataBuffer[i]);
        sumValues += dataBuffer[i];
    }

    if (timestamps.size() > maxBufferSize) {
        qDebug() << "Buffer size exceeded. Resetting chart.";
        dataBuffer.clear();
        timestamps.clear();
    }

    double averageValue = dataBuffer.isEmpty() ? 0.0 : sumValues / dataBuffer.size();

    auto xAxis = static_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first());
    if (!timestamps.isEmpty()) {
        xAxis->setRange(timestamps.first(), timestamps.last());
    }

    auto yAxis = static_cast<QValueAxis *>(chart->axes(Qt::Vertical).first());
    yAxis->setRange(minValue, maxValue);
    yAxis->setLabelFormat("%.2f");

    ui->averageLabel->setText(QString("Average: %1").arg(averageValue, 0, 'f', 2));
    ui->maxLabel->setText(QString("Max: %1").arg(maxValue, 0, 'f', 2));
    ui->minLabel->setText(QString("Min: %1").arg(minValue, 0, 'f', 2));

    chart->setAnimationOptions(QChart::SeriesAnimations);
}


void SerialDataVisualizer::updateRawData()
{
    if (!rawDataPopUp || rawDataBuffer.isEmpty()) return;

    while (!rawDataBuffer.isEmpty()) {
        auto rawData = rawDataBuffer.dequeue();
        if (rawData.second) {
            rawDataPopUp->appendRawData(rawData.first);
        } else {
            rawDataPopUp->appendRawData("Error: " + rawData.first);
        }
    }
}



bool SerialDataVisualizer::validateLRC(const QByteArray &data) {
    if (data.size() != 15) return false;

    uint8_t calculatedLRC = 0;
    qDebug() << "Data for LRC Calculation:";
    for (int i = 1; i < 13; i++) {
        calculatedLRC ^= static_cast<uint8_t>(data[i]);
    }
    uint8_t frameLRC = static_cast<uint8_t>(data[13]);
    qDebug() << "Calculated LRC:" << calculatedLRC << ", Frame LRC:" << frameLRC;

    return calculatedLRC == frameLRC;
}


uint64_t SerialDataVisualizer::parseTimestamp(const QByteArray &data) {
    if (data.size() != 15) return 0;

    uint64_t timestamp = 0;
    for (int i = 0; i < 8; i++) {
        timestamp = (timestamp << 8) | static_cast<uint8_t>(data[1 + i]);
    }
    return timestamp;
}

double SerialDataVisualizer::decodeData(const QByteArray &data) {
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
    qDebug() << "Parsed Float Value:" << value;
    return static_cast<double>(value);
}
