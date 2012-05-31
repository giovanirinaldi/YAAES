TEMPLATE = app
QT = gui core
CONFIG += qt warn_on console debug
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/setmatrix.ui ui/dialognew.ui \
    ui/dialogshowexpkey.ui \
    ui/dialogkeyschedule.ui \
    ui/dialogaddroundkey.ui \
    ui/dialogshiftrows.ui \
    ui/dialogsubbytes.ui \
    ui/dialogmixcolumns.ui \
    ui/dialogexport.ui
HEADERS = \
 src/global.h \
    ui/dialogshowexpkey.h \
    ../Rijndael/fast-rijndael-1d/fast-rijndael-1d.h \
    ui/dialognew.h \
    ui/mainwindowimpl.h \
    ui/dialogsetmatrix.h \
    ui/dialogkeyschedule.h \
    ui/dialogaddroundkey.h \
    ui/dialogshiftrows.h \
    ui/dialogsubbytes.h \
    ui/dialogmixcolumns.h \
    ui/dialogexport.h
SOURCES = \
 src/main.cpp \
    ui/dialogshowexpkey.cpp \
    ../Rijndael/fast-rijndael-1d/fast-rijndael-1d.cpp \
    ui/dialognew.cpp \
    ui/mainwindowimpl.cpp \
    ui/dialogsetmatrix.cpp \
    ui/dialogkeyschedule.cpp \
    ui/dialogaddroundkey.cpp \
    ui/dialogshiftrows.cpp \
    ui/dialogsubbytes.cpp \
    ui/dialogmixcolumns.cpp \
    ui/dialogexport.cpp

OTHER_FILES +=

RESOURCES += \
    ui/images.qrc
