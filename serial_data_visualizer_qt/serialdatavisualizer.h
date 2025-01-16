#ifndef SERIALDATAVISUALIZER_H
#define SERIALDATAVISUALIZER_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QSerialPort>


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

private:
    Ui::SerialDataVisualizer *ui;
    QSerialPort* COMPORT;
};
#endif // SERIALDATAVISUALIZER_H
