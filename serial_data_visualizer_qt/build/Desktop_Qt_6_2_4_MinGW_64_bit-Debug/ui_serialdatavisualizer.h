/********************************************************************************
** Form generated from reading UI file 'serialdatavisualizer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALDATAVISUALIZER_H
#define UI_SERIALDATAVISUALIZER_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialDataVisualizer
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *titleLayout;
    QLabel *titleLabel;
    QHBoxLayout *serialOptionsLayout;
    QLabel *serialConnectionLabel;
    QLabel *portLabel;
    QComboBox *portDropdown;
    QLabel *baudrateLabel;
    QComboBox *baudrateDropdown;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QHBoxLayout *controlButtonsLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *viewRawDataButton;
    QPushButton *clearButton;
    QChartView *dataChartView;
    QHBoxLayout *analysisLayout;
    QLabel *averageLabel;
    QLabel *minLabel;
    QLabel *maxLabel;
    QHBoxLayout *statusLayout;
    QLabel *iconLabel;
    QLabel *statusTextLabel;

    void setupUi(QMainWindow *SerialDataVisualizer)
    {
        if (SerialDataVisualizer->objectName().isEmpty())
            SerialDataVisualizer->setObjectName(QString::fromUtf8("SerialDataVisualizer"));
        SerialDataVisualizer->resize(800, 600);
        centralwidget = new QWidget(SerialDataVisualizer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLayout = new QHBoxLayout();
        titleLayout->setObjectName(QString::fromUtf8("titleLayout"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        titleLayout->addWidget(titleLabel);


        verticalLayout->addLayout(titleLayout);

        serialOptionsLayout = new QHBoxLayout();
        serialOptionsLayout->setObjectName(QString::fromUtf8("serialOptionsLayout"));
        serialConnectionLabel = new QLabel(centralwidget);
        serialConnectionLabel->setObjectName(QString::fromUtf8("serialConnectionLabel"));
        QFont font1;
        font1.setBold(true);
        serialConnectionLabel->setFont(font1);

        serialOptionsLayout->addWidget(serialConnectionLabel);

        portLabel = new QLabel(centralwidget);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        serialOptionsLayout->addWidget(portLabel);

        portDropdown = new QComboBox(centralwidget);
        portDropdown->setObjectName(QString::fromUtf8("portDropdown"));

        serialOptionsLayout->addWidget(portDropdown);

        baudrateLabel = new QLabel(centralwidget);
        baudrateLabel->setObjectName(QString::fromUtf8("baudrateLabel"));

        serialOptionsLayout->addWidget(baudrateLabel);

        baudrateDropdown = new QComboBox(centralwidget);
        baudrateDropdown->setObjectName(QString::fromUtf8("baudrateDropdown"));

        serialOptionsLayout->addWidget(baudrateDropdown);

        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        serialOptionsLayout->addWidget(connectButton);

        disconnectButton = new QPushButton(centralwidget);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));

        serialOptionsLayout->addWidget(disconnectButton);


        verticalLayout->addLayout(serialOptionsLayout);

        controlButtonsLayout = new QHBoxLayout();
        controlButtonsLayout->setObjectName(QString::fromUtf8("controlButtonsLayout"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        controlButtonsLayout->addWidget(startButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        controlButtonsLayout->addWidget(stopButton);

        viewRawDataButton = new QPushButton(centralwidget);
        viewRawDataButton->setObjectName(QString::fromUtf8("viewRawDataButton"));

        controlButtonsLayout->addWidget(viewRawDataButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        controlButtonsLayout->addWidget(clearButton);


        verticalLayout->addLayout(controlButtonsLayout);

        dataChartView = new QChartView(centralwidget);
        dataChartView->setObjectName(QString::fromUtf8("dataChartView"));

        verticalLayout->addWidget(dataChartView);

        analysisLayout = new QHBoxLayout();
        analysisLayout->setObjectName(QString::fromUtf8("analysisLayout"));
        averageLabel = new QLabel(centralwidget);
        averageLabel->setObjectName(QString::fromUtf8("averageLabel"));

        analysisLayout->addWidget(averageLabel);

        minLabel = new QLabel(centralwidget);
        minLabel->setObjectName(QString::fromUtf8("minLabel"));

        analysisLayout->addWidget(minLabel);

        maxLabel = new QLabel(centralwidget);
        maxLabel->setObjectName(QString::fromUtf8("maxLabel"));

        analysisLayout->addWidget(maxLabel);


        verticalLayout->addLayout(analysisLayout);

        statusLayout = new QHBoxLayout();
        statusLayout->setSpacing(5);
        statusLayout->setObjectName(QString::fromUtf8("statusLayout"));
        statusLayout->setAlignment(Qt::AlignLeft);
        iconLabel = new QLabel(centralwidget);
        iconLabel->setObjectName(QString::fromUtf8("iconLabel"));
        iconLabel->setAlignment(Qt::AlignVCenter);

        statusLayout->addWidget(iconLabel);

        statusTextLabel = new QLabel(centralwidget);
        statusTextLabel->setObjectName(QString::fromUtf8("statusTextLabel"));
        QFont font2;
        font2.setItalic(true);
        statusTextLabel->setFont(font2);
        statusTextLabel->setAlignment(Qt::AlignVCenter);

        statusLayout->addWidget(statusTextLabel);


        verticalLayout->addLayout(statusLayout);

        SerialDataVisualizer->setCentralWidget(centralwidget);

        retranslateUi(SerialDataVisualizer);

        QMetaObject::connectSlotsByName(SerialDataVisualizer);
    } // setupUi

    void retranslateUi(QMainWindow *SerialDataVisualizer)
    {
        SerialDataVisualizer->setWindowTitle(QCoreApplication::translate("SerialDataVisualizer", "Serial Data Visualizer", nullptr));
        titleLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Serial Data Visualizer", nullptr));
        serialConnectionLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Serial Connection:", nullptr));
        portLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Port:", nullptr));
        baudrateLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Baudrate:", nullptr));
        connectButton->setText(QCoreApplication::translate("SerialDataVisualizer", "Connect", nullptr));
        disconnectButton->setText(QCoreApplication::translate("SerialDataVisualizer", "Disconnect", nullptr));
        startButton->setText(QCoreApplication::translate("SerialDataVisualizer", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("SerialDataVisualizer", "Stop", nullptr));
        viewRawDataButton->setText(QCoreApplication::translate("SerialDataVisualizer", "View Raw Data", nullptr));
        clearButton->setText(QCoreApplication::translate("SerialDataVisualizer", "Clear", nullptr));
        averageLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Average:", nullptr));
        minLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Min:", nullptr));
        maxLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Max:", nullptr));
        statusTextLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Disconnected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialDataVisualizer: public Ui_SerialDataVisualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALDATAVISUALIZER_H
