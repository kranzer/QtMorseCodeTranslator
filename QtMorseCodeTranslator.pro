#-------------------------------------------------
#
# Project created by QtCreator 2016-03-29T17:03:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtMorseCodeTranslator
TEMPLATE = app


SOURCES += main.cpp\
        qtmorsecodetranslator.cpp \
    translatemanager.cpp

HEADERS  += qtmorsecodetranslator.h \
    translatemanager.h

FORMS    += qtmorsecodetranslator.ui

DISTFILES += \
    config.txt
