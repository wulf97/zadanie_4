QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plugin1
TEMPLATE = lib
CONFIG += plugin

DESTDIR = ../plugins

DEFINES += PLUGIN1_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Plugin1.cpp \
    EquWidget.cpp \
    OperationsWidget.cpp \
    ValWidget.cpp

HEADERS += \
    Plugin1.h \
    EquWidget.h \
    OperationsWidget.h \
    ValWidget.h

FORMS += \
    EquWidget.ui \
    OperationsWidget.ui \
    ValWidget.ui
