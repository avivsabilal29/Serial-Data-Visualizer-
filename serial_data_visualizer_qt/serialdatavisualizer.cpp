#include "serialdatavisualizer.h"
#include "ui_serialdatavisualizer.h"
#include "rawdatawindow.h"


bool isStreaming = false;



SerialDataVisualizer::SerialDataVisualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SerialDataVisualizer)
{
    ui->setupUi(this);
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
    if (serialPort) {
        serialPort->close();
        delete serialPort;
    }
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

    if (serialPort->open(QIODevice::ReadWrite)) { // Ubah ke ReadWrite
        updateConnectionStatus(!checked);
        connect(serialPort, &QSerialPort::readyRead, this, &SerialDataVisualizer::readSerialData);
        qDebug() << "Serial port connected in ReadWrite mode.";
    } else {
        updateConnectionStatus(checked);
        qDebug() << "Failed to connect to port";
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
        serialPort->write("START\n"); // Kirim perintah START ke ESP32
        isStreaming = true;
    }
}

void SerialDataVisualizer::on_stopButton_clicked()
{
    if (serialPort && serialPort->isOpen()) {
        serialPort->write("STOP\n"); // Kirim perintah STOP ke ESP32
        isStreaming = false;
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
        previousPorts = currentPorts; // Perbarui daftar sebelumnya

        // Perbarui dropdown
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

void SerialDataVisualizer::readSerialData()
{
    if (!isStreaming) return;
    static QByteArray buffer; // Buffer untuk menyimpan data sementara
    buffer.append(serialPort->readAll());

    while (buffer.contains(0x02) && buffer.contains(0x03)) { // Cari STX dan ETX
        int startIdx = buffer.indexOf(0x02); // Posisi STX
        int endIdx = buffer.indexOf(0x03, startIdx); // Posisi ETX setelah STX

        if (endIdx - startIdx + 1 == 15) { // Pastikan frame memiliki panjang 15 byte
            QByteArray frame = buffer.mid(startIdx, 15); // Ambil frame lengkap
            qDebug() << "Received frame:" << frame.toHex();

            if (validateLRC(frame)) { // Validasi LRC
                // Parsing data
                double floatValue = decodeData(frame);
                uint64_t timestamp = parseTimestamp(frame);


                // Tambahkan data ke buffer
                if (dataBuffer.size() >= maxBufferSize) {
                    dataBuffer.removeFirst(); // Hapus elemen pertama jika buffer penuh
                    timestamps.removeFirst();
                }
                dataBuffer.append(floatValue);
                timestamps.append(timestamp);

                // Perbarui grafik
                updateChart();

                // Log raw data (opsional)
                QString rawData = QString("Value: %1").arg(floatValue);
                if (rawDataPopUp) {
                    rawDataPopUp->appendRawData(rawData); // Kirim ke jendela raw data
                }
            } else {
                qDebug() << "Invalid LRC, frame ignored.";
            }

            buffer.remove(0, endIdx + 1); // Hapus frame yang sudah diproses
        } else {
            break; // Tunggu hingga frame lengkap
        }
    }
}

void SerialDataVisualizer::updateChart()
{
    series->clear(); // Hapus data grafik sebelumnya
    double minValue = std::numeric_limits<double>::max();
    double maxValue = std::numeric_limits<double>::min();

    for (int i = 0; i < dataBuffer.size(); ++i) {
        series->append(timestamps[i], dataBuffer[i]); // Gunakan timestamp sebagai sumbu X
        minValue = qMin(minValue, dataBuffer[i]);
        maxValue = qMax(maxValue, dataBuffer[i]);
    }

    // Perbarui sumbu X berdasarkan timestamp
    auto xAxis = static_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first());
    if (!timestamps.isEmpty()) {
        xAxis->setRange(timestamps.first(), timestamps.last()); // Gunakan range timestamp
    }

    // Perbarui sumbu Y
    auto yAxis = static_cast<QValueAxis *>(chart->axes(Qt::Vertical).first());
    yAxis->setRange(minValue, maxValue);
    yAxis->setLabelFormat("%.2f");
}





bool SerialDataVisualizer::validateLRC(const QByteArray &data) {
    if (data.size() != 15) return false;

    uint8_t calculatedLRC = 0;
    qDebug() << "Data for LRC Calculation:";
    for (int i = 1; i < 13; i++) { // XOR byte dari 1 hingga 12
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
        static_cast<uint8_t>(data[9]),    // Byte ke-9 dari frame
        static_cast<uint8_t>(data[10]),  // Byte ke-10 dari frame
        static_cast<uint8_t>(data[11]),  // Byte ke-11 dari frame
        static_cast<uint8_t>(data[12])   // Byte ke-12 dari frame
    };

    // Konversi dari big-endian ke float
    uint32_t intRepresentation =
        (static_cast<uint32_t>(floatBytes[0]) << 24) |
        (static_cast<uint32_t>(floatBytes[1]) << 16) |
        (static_cast<uint32_t>(floatBytes[2]) << 8) |
        (static_cast<uint32_t>(floatBytes[3]));

    float value;
    memcpy(&value, &intRepresentation, sizeof(float)); // Interpretasikan sebagai float
    qDebug() << "Parsed Float Value:" << value;        // Debug nilai float
    return static_cast<double>(value);
}
