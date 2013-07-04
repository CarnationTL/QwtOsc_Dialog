#-------------------------------------------------
#
# Project created by QtCreator 2013-07-04T11:49:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IntergreadWithOsc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    oscilloscope/curvedata.cpp \
    oscilloscope/knob.cpp \
    oscilloscope/plot.cpp \
    oscilloscope/samplingthread.cpp \
    oscilloscope/signaldata.cpp \
    oscilloscope/wheelbox.cpp \
    qwtoscmain.cpp

HEADERS  += mainwindow.h \
    oscilloscope/curvedata.h \
    oscilloscope/knob.h \
    oscilloscope/plot.h \
    oscilloscope/samplingthread.h \
    oscilloscope/signaldata.h \
    oscilloscope/wheelbox.h \
    qwtoscmain.h

FORMS    += mainwindow.ui

CONFIG += qwt


unix:!macx: LIBS += -L$$PWD/../../../../usr/local/qwt-6.1.0-rc3/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../usr/local/qwt-6.1.0-rc3/include
DEPENDPATH += $$PWD/../../../../usr/local/qwt-6.1.0-rc3/include
