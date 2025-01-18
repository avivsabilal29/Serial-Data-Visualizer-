#ifndef SERIALDATAVISUALIZER_H
#define SERIALDATAVISUALIZER_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QTimer>
#include <QtCharts/QLineSeries>
#include <headers/rawdatawindow.h>
#include <headers/serialworker.h>
#include <QThread>
#include <QQueue>
#include <headers/serialdataprocessor.h>
#include <headers/chartmanager.h>



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
    SerialDataProcessor *dataProcessor;
    ChartManager *chartManager;
    QThread *workerThread;
    SerialWorker *serialWorker;
    rawDataWindow *rawDataPopUp = nullptr;
    QString selectPortCom = nullptr;
    QString selectedBaudrate = nullptr;
    QQueue<QPair<QString, bool>> rawDataBuffer;

    void refreshSerialPorts();
    void updateConnectionStatus(bool isConnected);
    void handleSerialData(const QByteArray &data);

    const int maxBufferSize = 100;






signals:
    void sendDataToWorker(const QByteArray &data);

};
#endif // SERIALDATAVISUALIZER_H
