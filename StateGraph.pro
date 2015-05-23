#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T17:59:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StateGraph
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    state.cpp \
    stategraph.cpp \
    testclass.cpp

HEADERS  += mainwindow.h \
    state.h \
    stategraph.h \
    simplelogger.h \
    testclass.h

FORMS    += mainwindow.ui
