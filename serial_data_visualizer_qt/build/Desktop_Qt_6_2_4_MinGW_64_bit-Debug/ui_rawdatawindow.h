/********************************************************************************
** Form generated from reading UI file 'rawdatawindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAWDATAWINDOW_H
#define UI_RAWDATAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rawDataWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QTextEdit *rawDataTextEdit;
    QHBoxLayout *buttonLayout;
    QPushButton *clearButton;
    QPushButton *closeButton;

    void setupUi(QWidget *rawDataWindow)
    {
        if (rawDataWindow->objectName().isEmpty())
            rawDataWindow->setObjectName(QString::fromUtf8("rawDataWindow"));
        rawDataWindow->resize(800, 600);
        verticalLayout = new QVBoxLayout(rawDataWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(rawDataWindow);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        rawDataTextEdit = new QTextEdit(rawDataWindow);
        rawDataTextEdit->setObjectName(QString::fromUtf8("rawDataTextEdit"));
        rawDataTextEdit->setReadOnly(true);

        verticalLayout->addWidget(rawDataTextEdit);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        clearButton = new QPushButton(rawDataWindow);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        buttonLayout->addWidget(clearButton);

        closeButton = new QPushButton(rawDataWindow);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        buttonLayout->addWidget(closeButton);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(rawDataWindow);

        QMetaObject::connectSlotsByName(rawDataWindow);
    } // setupUi

    void retranslateUi(QWidget *rawDataWindow)
    {
        rawDataWindow->setWindowTitle(QCoreApplication::translate("rawDataWindow", "Raw Data Viewer", nullptr));
        titleLabel->setText(QCoreApplication::translate("rawDataWindow", "Raw Data Viewer", nullptr));
        rawDataTextEdit->setPlaceholderText(QCoreApplication::translate("rawDataWindow", "Incoming raw data will be displayed here...", nullptr));
        clearButton->setText(QCoreApplication::translate("rawDataWindow", "Clear Display", nullptr));
        closeButton->setText(QCoreApplication::translate("rawDataWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rawDataWindow: public Ui_rawDataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAWDATAWINDOW_H
