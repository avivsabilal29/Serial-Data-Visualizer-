#include "chartmanager.h"
#include <limits>
#include "rawdatawindow.h"

ChartManager::ChartManager(QChartView *chartView, rawDataWindow *rawWindowInstance, QObject *parent)
    : QObject(parent), chartView(chartView), rawWindowInstance(rawWindowInstance) {
    series = new QLineSeries();
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    configureChart();

    chartView->setChart(chart);

    chartUpdateTimer = new QTimer(this);
    connect(chartUpdateTimer, &QTimer::timeout, this, &ChartManager::updateChart);

    rawDataUpdateTimer = new QTimer(this);
    connect(rawDataUpdateTimer, &QTimer::timeout, this, &ChartManager::updateRawData);
}

ChartManager::~ChartManager() {
    stopTimers();
    delete series;
    delete chart;
}

void ChartManager::appendData(double value, uint64_t timestamp) {
    if (dataBuffer.size() >= maxBufferSize) {
        dataBuffer.removeFirst();
        timestamps.removeFirst();
    }
    dataBuffer.append(value);
    timestamps.append(timestamp);
}

void ChartManager::enqueueRawData(const QString &data, bool isValid) {
    rawDataBuffer.enqueue(qMakePair(data, isValid));
}

void ChartManager::startTimers() {
    chartUpdateTimer->start(100);
    rawDataUpdateTimer->start(100);
}

void ChartManager::stopTimers() {
    chartUpdateTimer->stop();
    rawDataUpdateTimer->stop();
}

void ChartManager::setBufferSize(int size) {
    maxBufferSize = size;
}

void ChartManager::updateChart() {
    if (dataBuffer.isEmpty()) return;

    series->clear();
    double minValue = std::numeric_limits<double>::max();
    double maxValue = std::numeric_limits<double>::min();
    double sumValues = 0.0;

    for (int i = 0; i < dataBuffer.size(); ++i) {
        series->append(timestamps[i], dataBuffer[i]);
        minValue = qMin(minValue, dataBuffer[i]);
        maxValue = qMax(maxValue, dataBuffer[i]);
        sumValues += dataBuffer[i];
    }

    double averageValue = sumValues / dataBuffer.size();

    auto xAxis = static_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first());
    if (!timestamps.isEmpty()) {
        xAxis->setRange(timestamps.first(), timestamps.last());
    }

    auto yAxis = static_cast<QValueAxis *>(chart->axes(Qt::Vertical).first());
    yAxis->setRange(minValue, maxValue);

    emit chartUpdated(minValue, maxValue, averageValue);
}

void ChartManager::updateRawData() {
    while (!rawDataBuffer.isEmpty()) {
        auto rawData = rawDataBuffer.dequeue();
        QString output = rawData.second ? rawData.first : "Error: " + rawData.first;
        rawWindowInstance->appendRawData(output);
        qDebug() << output;
    }
}

void ChartManager::configureChart() {
    chart->axes(Qt::Vertical).first()->setRange(0, 100);
    chart->axes(Qt::Horizontal).first()->setRange(0, 10);
    chart->setVisible(true);
    chart->setAnimationOptions(QChart::SeriesAnimations);
}

void ChartManager::clearData() {
    series->clear();

    dataBuffer.clear();
    timestamps.clear();

    rawDataBuffer.clear();

    qDebug() << "ChartManager: All data cleared.";
}

