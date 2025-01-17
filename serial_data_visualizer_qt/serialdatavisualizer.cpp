#include "serialdatavisualizer.h"
#include "ui_serialdatavisualizer.h"
#include "rawdatawindow.h"


bool isStreaming = false;



SerialDataVisualizer::SerialDataVisualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SerialDataVisualizer)
    // , RawDataPopUp(new rawDataWindow(this))
{
    ui->setupUi(this);
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
        ui->baudrateDropdown->addItem(QString::number(baudrate)); // Konversi baudrate ke string
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


    if (serialPort->open(QIODevice::ReadOnly)) {
        updateConnectionStatus(!checked);
        connect(serialPort, &QSerialPort::readyRead, this, &SerialDataVisualizer::readSerialData);
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


// void SerialDataVisualizer::on_startButton_clicked()
// {
//     if (serialPort && serialPort->isOpen()) {
//         serialPort->write("START\n");
//     }
// }


// void SerialDataVisualizer::on_stopButton_clicked()
// {
//     if (serialPort && serialPort->isOpen()) {
//         serialPort->write("STOP\n");
//     }
// }


// void SerialDataVisualizer::on_clearButton_clicked()
// {
//     series->clear();
// }

void SerialDataVisualizer::on_startButton_clicked()
{
    isStreaming = true;
}

void SerialDataVisualizer::on_stopButton_clicked()
{
    isStreaming = false;
}

void SerialDataVisualizer::on_clearButton_clicked()
{
    series->clear();
}


void SerialDataVisualizer::on_viewRawDataButton_clicked()
{
    qDebug() << "Raw Data selected:";
    // RawDataPopUp->show(); // Show the raw data window
    // RawDataPopUp->raise(); // Bring it to the front
    // RawDataPopUp->activateWindow(); // Focus the window

    rawDataWindow RawDataPopUp;
    RawDataPopUp.setModal(true);
    RawDataPopUp.exec();
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



// void SerialDataVisualizer::readSerialData() {
//     static QByteArray buffer;  // Buffer untuk menyimpan data sementara
//     buffer.append(serialPort->readAll());  // Tambahkan data baru ke buffer

//     while (buffer.contains(0x02) && buffer.contains(0x03)) {  // Cari STX dan ETX
//         int startIdx = buffer.indexOf(0x02);  // Cari posisi STX
//         int endIdx = buffer.indexOf(0x03, startIdx);  // Cari posisi ETX setelah STX

//         if (endIdx - startIdx + 1 == 15) {  // Pastikan panjang frame adalah 15 byte
//             QByteArray frame = buffer.mid(startIdx, 15);  // Ambil frame

//             // Validasi LRC
//             if (validateLRC(frame)) {
//                 double value = decodeData(frame);
//                 static int time = 0;
//                 series->append(time++, value);  // Tambahkan data ke grafik
//                 qDebug() << "Decoded Value:" << value;
//             } else {
//                 qDebug() << "LRC validation failed";
//             }
//             buffer.remove(0, endIdx + 1);  // Hapus data yang sudah diproses dari buffer
//         } else {
//             break;  // Tunggu hingga frame lengkap
//         }
//     }
// }


void SerialDataVisualizer::readSerialData()
{
    if (!isStreaming) return;

    while (serialPort->canReadLine()) {
        QByteArray line = serialPort->readLine().trimmed();
        // QString rawData = QString::fromUtf8(line);

        // RawDataPopUp->appendRawData(rawData);

        bool ok;
        double value = line.toDouble(&ok);
        if (ok) {
            static int time = 0;
            series->append(time++, value);  // Append value to the chart
            if (time > 10) {  // Scroll the chart dynamically
                chart->axes(Qt::Horizontal).first()->setRange(time - 10, time);
            }
        }
    }
}

bool SerialDataVisualizer::validateLRC(const QByteArray &data) {
    if (data.size() != 15) return false;

    uint8_t calculatedLRC = 0;
    for (int i = 1; i < 13; i++) {  // Hitung LRC dari byte 1 hingga 12
        calculatedLRC ^= static_cast<uint8_t>(data[i]);
    }
    return calculatedLRC == static_cast<uint8_t>(data[13]);  // Cocokkan dengan byte ke-13
}


double SerialDataVisualizer::decodeData(const QByteArray &data) {
    if (data.size() != 15) return 0.0;

    // Ekstrak float (big-endian) dari byte ke-9 hingga ke-12
    uint8_t floatBytes[4] = {
        static_cast<uint8_t>(data[9]),
        static_cast<uint8_t>(data[10]),
        static_cast<uint8_t>(data[11]),
        static_cast<uint8_t>(data[12])
    };
    float value;
    memcpy(&value, floatBytes, sizeof(float));
    return static_cast<double>(value);
}


