TEMPLATE = app
QT = gui core
CONFIG += qt warn_on console debug
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/setmatrix.ui ui/dialognew.ui
HEADERS = src/mainwindowimpl.h src/dialogsetmatriximpl.h src/rijndael.h src/dialognew.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/dialogsetmatriximpl.cpp \
 src/rijndael.cpp \
 src/dialognew.cpp
