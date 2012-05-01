TEMPLATE = app
QT = gui core
CONFIG += qt warn_on console debug
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/setmatrix.ui ui/dialognew.ui \
    ui/dialogshowexpkey.ui
HEADERS = \
 src/rijndael/rijndael.h \
 src/global.h \
    ui/dialogshowexpkey.h \
    src/fast-rijndael-1d/fast-rijndael-1d.h \
    ui/dialognew.h \
    ui/mainwindowimpl.h \
    ui/dialogsetmatrix.h
SOURCES = \
 src/main.cpp \
 src/rijndael/rijndael.cpp \
    ui/dialogshowexpkey.cpp \
    src/fast-rijndael-1d/fast-rijndael-1d.cpp \
    ui/dialognew.cpp \
    ui/mainwindowimpl.cpp \
    ui/dialogsetmatrix.cpp

OTHER_FILES +=
