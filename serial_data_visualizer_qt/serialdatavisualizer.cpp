#include "serialdatavisualizer.h"
#include "ui_serialdatavisualizer.h"

SerialDataVisualizer::SerialDataVisualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SerialDataVisualizer)
{
    ui->setupUi(this);
}

SerialDataVisualizer::~SerialDataVisualizer()
{
    delete ui;
}
