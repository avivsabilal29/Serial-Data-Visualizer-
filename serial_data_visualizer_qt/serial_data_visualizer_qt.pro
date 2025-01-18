QT       += core gui serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/main.cpp \
    sources/rawdatawindow.cpp \
    sources/serialdatavisualizer.cpp \
    sources/serialworker.cpp \
    sources/chartmanager.cpp \
    sources/serialdataprocessor.cpp

HEADERS += \
    headers/rawdatawindow.h \
    headers/serialdatavisualizer.h \
    headers/serialworker.h \
    headers/chartmanager.h \
    headers/serialdataprocessor.h \
    headers/ISerialHandler.h

FORMS += \
    ui/rawdatawindow.ui \
    ui/serialdatavisualizer.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc
