QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TetrisGame
TEMPLATE = app


SOURCES += gui/desktop/tetris/main.cpp \
    gui/desktop/tetris/mainwindow.cpp \
    gui/desktop/tetris/helpfield.cpp \
    gui/desktop/tetris/QtView.cpp \
    brick_game/tetris/s21_backend.c \

HEADERS  += gui/desktop/tetris/mainwindow.h \
    gui/desktop/tetris/helpfield.h \
    gui/desktop/tetris/QtView.h \
    brick_game/tetris/s21_backend.h \

FORMS    +=


