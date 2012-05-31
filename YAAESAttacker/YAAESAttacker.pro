#-------------------------------------------------
#
# Project created by QtCreator 2012-05-23T21:19:44
#
#-------------------------------------------------

QT       += core gui

TARGET = YAAESAttacker
TEMPLATE = app
CONFIG += qt warn_on console debug
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build

SOURCES += src/main.cpp\
        ui/mainwindow.cpp \
    ../Rijndael/attacker/rijndaelattacker.cpp \
    ../Rijndael/fast-rijndael-1d/fast-rijndael-1d.cpp \
    ui/dialogshowsubkeys.cpp

HEADERS  += ui/mainwindow.h \
    ../Rijndael/attacker/rijndaelattacker.h \
    ../Rijndael/fast-rijndael-1d/fast-rijndael-1d.h \
    ui/dialogshowsubkeys.h

FORMS    += ui/mainwindow.ui \
    ui/dialogshowsubkeys.ui

OTHER_FILES +=
