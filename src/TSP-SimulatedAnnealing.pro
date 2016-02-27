#-------------------------------------------------
#
# Project created by QtCreator 2015-06-12T20:28:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TSP-SimulatedAnnealing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tsp.cpp \
    cities.cpp \
    tsproute.cpp \
    drawcitieswidget.cpp

HEADERS  += mainwindow.h \
    tsp.h \
    cities.h \
    tsproute.h \
    drawcitieswidget.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -O2
CONFIG += c++11
