#ifndef SERIALDATAVISUALIZER_H
#define SERIALDATAVISUALIZER_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <rawdatawindow.h>
#include <serialworker.h>
#include <QThread>



QT_BEGIN_NAMESPACE
namespace Ui {
class SerialDataVisualizer;
}
QT_END_NAMESPACE

class SerialDataVisualizer : public QMainWindow
{
    Q_OBJECT

public:
    SerialDataVisualizer(QWidget *parent = nullptr);
    ~SerialDataVisualizer();

private slots:
    void on_portDropdown_activated(int index);

    void on_connectButton_clicked(bool checked);

    void on_baudrateDropdown_activated(int index);

    void on_disconnectButton_clicked(bool checked);

    void on_viewRawDataButton_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::SerialDataVisualizer *ui;
    QLineSeries *series = nullptr;
    QSerialPort *serialPort = nullptr;
    QChart *chart = nullptr;
    QString selectPortCom = nullptr;
    QString selectedBaudrate = nullptr;
    // rawDataWindow *RawDataPopUp;
    rawDataWindow *rawDataPopUp = nullptr;
    void refreshSerialPorts();
    void updateConnectionStatus(bool isConnected);
    void readSerialData();
    bool validateLRC(const QByteArray &data);
    double decodeData(const QByteArray &data);
    uint64_t parseTimestamp(const QByteArray &data);
    QVector<double> dataBuffer; // Buffer untuk menyimpan data
    QVector<double> timestamps;
    const int maxBufferSize = 100; // Ukuran maksimum buffer
    void updateChart();
    void initializeTimers();
    QThread *workerThread;
    SerialWorker *serialWorker;
    void handleSerialData(const QByteArray &data);

signals:
    void sendDataToWorker(const QByteArray &data);

};
#endif // SERIALDATAVISUALIZER_H
