#ifndef SERIALDATAVISUALIZER_H
#define SERIALDATAVISUALIZER_H

#include <QMainWindow>

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
};
#endif // SERIALDATAVISUALIZER_H
