#-------------------------------------------------
#
# Project created by QtCreator 2016-06-18T15:55:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projekt_Grafy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywidget.cpp \
    vertex.cpp \
    edges.cpp

HEADERS  += mainwindow.h \
    mywidget.h \
    vertex.h \
    edges.h

FORMS    += mainwindow.ui

DISTFILES += \
    Projekt_Grafy.pro.user
