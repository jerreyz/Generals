#-------------------------------------------------
#
# Project created by QtCreator 2016-12-31T11:34:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = generalsboard
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    square.cpp \
    gameboard.cpp \
    button.cpp \
    king.cpp

HEADERS  += \
    game.h \
    square.h \
    gameboard.h \
    button.h \
    king.h

FORMS    += mainwindow.ui
