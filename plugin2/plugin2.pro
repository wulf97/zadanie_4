QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plugin2
TEMPLATE = lib
CONFIG += plugin

DESTDIR = ../plugins

DEFINES += PLUGIN2_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Plugin2.cpp \
    NumBottomWidget.cpp \
    NumTopWidget.cpp

HEADERS += \
    Plugin2.h \
    NumBottomWidget.h \
    NumTopWidget.h

FORMS += \
    NumBottomWidget.ui \
    NumTopWidget.ui
