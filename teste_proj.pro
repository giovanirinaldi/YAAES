TEMPLATE = app
QT = gui core
CONFIG += qt warn_on console debug
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/setmatrix.ui ui/dialognew.ui \
    ui/dialogshowexpkey.ui
HEADERS = src/mainwindowimpl.h \
 src/dialogsetmatriximpl.h \
 src/rijndael/rijndael.h \
 src/dialognew.h \
 src/global.h \
    ui/dialogshowexpkey.h \
    src/fast-rijndael-1d/fast-rijndael-1d.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/dialogsetmatriximpl.cpp \
 src/rijndael/rijndael.cpp \
 src/dialognew.cpp \
    ui/dialogshowexpkey.cpp \
    src/fast-rijndael-1d/fast-rijndael-1d.cpp

OTHER_FILES +=
