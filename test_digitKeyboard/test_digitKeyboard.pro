#-------------------------------------------------
#
# Project created by QtCreator 2019-12-18T09:54:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_digitKeyboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    digitkeyboard.cpp \
    digitbutton.cpp

HEADERS  += mainwindow.h \
    digitkeyboard.h \
    digitbutton.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
