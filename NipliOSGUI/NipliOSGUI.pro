TEMPLATE = app
TARGET = NipliOSGUI

QT= core gui

#CONFIG += console

greaterThan(QT_MAJOR_VERSION,4 ): QT+=widgets

SOURCES += \
    guidriver.cpp

HEADERS +=
