#include "serialdatavisualizer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialDataVisualizer w;
    w.show();
    return a.exec();
}
