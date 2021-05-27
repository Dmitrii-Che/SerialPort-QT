QT += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPort20200831
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        serialportworker.cpp

HEADERS += \
        serialportworker.h

FORMS += \
        serialportworker.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
