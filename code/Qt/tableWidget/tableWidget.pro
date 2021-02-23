QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
QMAKE_CXXFLAGS += -Wall
SOURCES +=\
    qtmain.cpp \
    qtdialog.cpp

HEADERS  += \
    qtdialog.h

FORMS    += \
    qtdialog.ui

RESOURCES += \
    tableWidget.qrc
