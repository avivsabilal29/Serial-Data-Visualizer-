/********************************************************************************
** Form generated from reading UI file 'serialdatavisualizer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALDATAVISUALIZER_H
#define UI_SERIALDATAVISUALIZER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialDataVisualizer
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QHBoxLayout *serialConnectionLayout;
    QLabel *serialConnectionLabel;
    QHBoxLayout *serialOptionsLayout;
    QLabel *portLabel;
    QComboBox *portDropdown;
    QLabel *baudrateLabel;
    QComboBox *baudrateDropdown;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QHBoxLayout *controlButtonsLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *clearButton;
    QPushButton *viewRawDataButton;
    QTableWidget *dataTable;
    QHBoxLayout *analysisLayout;
    QLabel *averageLabel;
    QLabel *minLabel;
    QLabel *maxLabel;
    QLabel *statusLabel;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuSetting;

    void setupUi(QMainWindow *SerialDataVisualizer)
    {
        if (SerialDataVisualizer->objectName().isEmpty())
            SerialDataVisualizer->setObjectName(QString::fromUtf8("SerialDataVisualizer"));
        SerialDataVisualizer->resize(800, 600);
        centralwidget = new QWidget(SerialDataVisualizer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        serialConnectionLayout = new QHBoxLayout();
        serialConnectionLayout->setObjectName(QString::fromUtf8("serialConnectionLayout"));
        serialConnectionLabel = new QLabel(centralwidget);
        serialConnectionLabel->setObjectName(QString::fromUtf8("serialConnectionLabel"));
        QFont font1;
        font1.setBold(true);
        serialConnectionLabel->setFont(font1);

        serialConnectionLayout->addWidget(serialConnectionLabel);


        verticalLayout->addLayout(serialConnectionLayout);

        serialOptionsLayout = new QHBoxLayout();
        serialOptionsLayout->setObjectName(QString::fromUtf8("serialOptionsLayout"));
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

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        controlButtonsLayout->addWidget(clearButton);

        viewRawDataButton = new QPushButton(centralwidget);
        viewRawDataButton->setObjectName(QString::fromUtf8("viewRawDataButton"));

        controlButtonsLayout->addWidget(viewRawDataButton);


        verticalLayout->addLayout(controlButtonsLayout);

        dataTable = new QTableWidget(centralwidget);
        if (dataTable->columnCount() < 4)
            dataTable->setColumnCount(4);
        dataTable->setObjectName(QString::fromUtf8("dataTable"));
        dataTable->setColumnCount(4);

        verticalLayout->addWidget(dataTable);

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

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        QFont font2;
        font2.setItalic(true);
        statusLabel->setFont(font2);
        statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(statusLabel);

        SerialDataVisualizer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SerialDataVisualizer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SerialDataVisualizer->setStatusBar(statusbar);
        menubar = new QMenuBar(SerialDataVisualizer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        SerialDataVisualizer->setMenuBar(menubar);

        menubar->addAction(menuSetting->menuAction());

        retranslateUi(SerialDataVisualizer);

        QMetaObject::connectSlotsByName(SerialDataVisualizer);
    } // setupUi

    void retranslateUi(QMainWindow *SerialDataVisualizer)
    {
        SerialDataVisualizer->setWindowTitle(QCoreApplication::translate("SerialDataVisualizer", "Serial Data Visualizer", nullptr));
        titleLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Serial Data Visualizer", nullptr));
        serialConnectionLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Serial Connection", nullptr));
        portLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Port:", nullptr));
        baudrateLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Baudrate:", nullptr));
        connectButton->setText(QCoreApplication::translate("SerialDataVisualizer", "Connect", nullptr));
        disconnectButton->setText(QCoreApplication::translate("SerialDataVisualizer", "Disconnect", nullptr));
        startButton->setText(QCoreApplication::translate("SerialDataVisualizer", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("SerialDataVisualizer", "Stop", nullptr));
        clearButton->setText(QCoreApplication::translate("SerialDataVisualizer", "Clear", nullptr));
        viewRawDataButton->setText(QCoreApplication::translate("SerialDataVisualizer", "View Raw Data", nullptr));
        dataTable->setProperty("horizontalHeaderLabels", QVariant(QStringList()
            << QCoreApplication::translate("SerialDataVisualizer", "Timestamp", nullptr)
            << QCoreApplication::translate("SerialDataVisualizer", "Data", nullptr)
            << QCoreApplication::translate("SerialDataVisualizer", "Status", nullptr)
            << QCoreApplication::translate("SerialDataVisualizer", "Checksum", nullptr)));
        averageLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Average:", nullptr));
        minLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Min:", nullptr));
        maxLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Max:", nullptr));
        statusLabel->setText(QCoreApplication::translate("SerialDataVisualizer", "Status: Disconnected", nullptr));
        menuSetting->setTitle(QCoreApplication::translate("SerialDataVisualizer", "Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialDataVisualizer: public Ui_SerialDataVisualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALDATAVISUALIZER_H
