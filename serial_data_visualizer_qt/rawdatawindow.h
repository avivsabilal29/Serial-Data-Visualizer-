#ifndef RAWDATAWINDOW_H
#define RAWDATAWINDOW_H

#include <QDialog>

namespace Ui {
class rawDataWindow;
}

class rawDataWindow : public QDialog
{
    Q_OBJECT

public:
    explicit rawDataWindow(QWidget *parent = nullptr);
    ~rawDataWindow();


private slots:
    void on_clearButton_clicked();
    void appendRawData(const QString &data);
    void on_closeButton_clicked();

private:
    Ui::rawDataWindow *ui;
};

#endif // RAWDATAWINDOW_H
