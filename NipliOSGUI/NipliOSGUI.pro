TEMPLATE = app
TARGET = Test

QT= core gui

#CONFIG += console

greaterThan(QT_MAJOR_VERSION,4 ): QT+=widgets

SOURCES += \
    guidriver.cpp
