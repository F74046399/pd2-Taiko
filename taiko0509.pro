#-------------------------------------------------
#
# Project created by QtCreator 2016-05-09T12:44:33
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taiko0509
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    pics.qrc \
    sound.qrc
RC_ICONS = icon.ico
