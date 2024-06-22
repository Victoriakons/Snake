QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeGame
TEMPLATE = app


SOURCES += main.cpp \
    model.cpp \
#    controller.cpp \
    QtView.cpp \
    mainwindow.cpp \
    helpfield.cpp

HEADERS  += main.cpp \
    model.h \
#    controller.h \
    QtView.h \
    mainwindow.h \
    helpfield.h

FORMS    +=


