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
    void appendRawData(const QString &data);


private slots:
    void on_clearButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::rawDataWindow *ui;
};

#endif // RAWDATAWINDOW_H
