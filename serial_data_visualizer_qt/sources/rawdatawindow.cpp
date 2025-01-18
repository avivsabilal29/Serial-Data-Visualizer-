#include "headers/rawdatawindow.h"
#include "ui_rawdatawindow.h"

rawDataWindow::rawDataWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rawDataWindow)
{
    ui->setupUi(this);
}

rawDataWindow::~rawDataWindow()
{
    delete ui;
}

void rawDataWindow::on_clearButton_clicked()
{
    ui->rawDataTextEdit->clear();
}

void rawDataWindow::on_closeButton_clicked()
{
    this->close();
}

void rawDataWindow::appendRawData(const QString &data)
{
    ui->rawDataTextEdit->append(data);
}
