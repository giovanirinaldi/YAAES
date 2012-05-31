#-------------------------------------------------
#
# Project created by QtCreator 2012-05-23T21:19:44
#
#-------------------------------------------------

QT       += core gui

TARGET = YAAESAttacker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../src/attacker/rijndaelattacker.cpp \
    ../../src/fast-rijndael-1d/fast-rijndael-1d.cpp \
    ../../src/dialogshowsubkeys.cpp

HEADERS  += mainwindow.h \
    ../../src/attacker/rijndaelattacker.h \
    ../../src/fast-rijndael-1d/fast-rijndael-1d.h \
    ../../src/dialogshowsubkeys.h

FORMS    += mainwindow.ui \
    ../../src/dialogshowsubkeys.ui
