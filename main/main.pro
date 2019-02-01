QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    PluginManager.cpp \
    Calc.cpp \
    Manager.cpp

HEADERS += \
    Interface.h \
    MainWindow.h \
    PluginManager.h \
    Calc.h \
    Manager.h

FORMS += \
    MainWindow.ui

unix {
    QMAKE_LFLAGS += -no-pie
}
