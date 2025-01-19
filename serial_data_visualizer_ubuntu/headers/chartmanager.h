#ifndef CHARTMANAGER_H
#define CHARTMANAGER_H

#include <QObject>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QTimer>
#include <QQueue>
#include <QPair>
#include <QString>

class rawDataWindow;
class ChartManager : public QObject {
    Q_OBJECT

public:
    explicit ChartManager(QChartView *chartView, rawDataWindow *rawWindow, QObject *parent = nullptr);

    ~ChartManager();

    void appendData(double value, uint64_t timestamp);
    void enqueueRawData(const QString &data, bool isValid);

    void startTimers();
    void stopTimers();

    void setBufferSize(int size);
    void clearData();

signals:
    void chartUpdated(double minValue, double maxValue, double averageValue);

private slots:
    void updateChart();
    void updateRawData();

private:
    QChartView *chartView;
    QLineSeries *series;
    QChart *chart;
    QTimer *chartUpdateTimer;
    QTimer *rawDataUpdateTimer;

    QVector<double> dataBuffer;
    QVector<uint64_t> timestamps;
    QQueue<QPair<QString, bool>> rawDataBuffer;
    int maxBufferSize = 100;

    void configureChart();
    rawDataWindow *rawWindowInstance;


};

#endif // CHARTMANAGER_H
