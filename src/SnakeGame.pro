QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeGame
TEMPLATE = app


SOURCES += gui/desktop/main.cpp \
    brick_game/snake/model.cpp \
    brick_game/snake/controller.cpp \
    gui/desktop/QtView.cpp \
    gui/desktop/mainwindow.cpp \
    gui/desktop/helpfield.cpp

HEADERS  += gui/desktop/main.cpp \
    brick_game/snake/model.h \
    brick_game/snake/controller.h \
    gui/desktop/QtView.h \
    gui/desktop/mainwindow.h \
    gui/desktop/helpfield.h

FORMS    +=


