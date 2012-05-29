/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon May 28 21:25:29 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../YAAESAttacker/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      88,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     240,   11,   11,   11, 0x08,
     279,   11,   11,   11, 0x08,
     316,   11,   11,   11, 0x08,
     355,   11,   11,   11, 0x08,
     392,   11,   11,   11, 0x08,
     431,   11,   11,   11, 0x08,
     467,   11,   11,   11, 0x08,
     493,   11,   11,   11, 0x08,
     516,   11,   11,   11, 0x08,
     555,   11,   11,   11, 0x08,
     594,   11,   11,   11, 0x08,
     633,   11,   11,   11, 0x08,
     673,   11,   11,   11, 0x08,
     713,   11,   11,   11, 0x08,
     753,   11,   11,   11, 0x08,
     784,   11,   11,   11, 0x08,
     822,   11,   11,   11, 0x08,
     851,   11,   11,   11, 0x08,
     879,   11,   11,   11, 0x08,
     907,   11,   11,   11, 0x08,
     935,   11,   11,   11, 0x08,
     966,   11,   11,   11, 0x08,
     995,   11,   11,   11, 0x08,
    1026,   11,   11,   11, 0x08,
    1056,   11,   11,   11, 0x08,
    1094,   11,   11,   11, 0x08,
    1131,   11,   11,   11, 0x08,
    1176,   11,   11,   11, 0x08,
    1221,   11,   11,   11, 0x08,
    1266,   11,   11,   11, 0x08,
    1311,   11,   11,   11, 0x08,
    1342,   11,   11,   11, 0x08,
    1370,   11,   11,   11, 0x08,
    1398,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_editByte00From_textChanged(QString)\0"
    "on_editByte00To_textChanged(QString)\0"
    "on_editByte05From_textChanged(QString)\0"
    "on_editByte05To_textChanged(QString)\0"
    "on_editByte07From_textChanged(QString)\0"
    "on_editByte07To_textChanged(QString)\0"
    "on_editByte08From_textChanged(QString)\0"
    "on_editByte08To_textChanged(QString)\0"
    "on_editByte10From_textChanged(QString)\0"
    "on_editByte10To_textChanged(QString)\0"
    "on_editByte15From_textChanged(QString)\0"
    "on_editByte15To_textEdited(QString)\0"
    "on_actionExit_triggered()\0"
    "on_buttonRun_clicked()\0"
    "on_editPlaintext1_textChanged(QString)\0"
    "on_editPlaintext2_textChanged(QString)\0"
    "on_editPlaintext3_textChanged(QString)\0"
    "on_editCiphertext1_textChanged(QString)\0"
    "on_editCiphertext2_textChanged(QString)\0"
    "on_editCiphertext3_textChanged(QString)\0"
    "on_actionExample_1_triggered()\0"
    "on_tabWidget_currentChanged(QWidget*)\0"
    "on_buttonS01E01ARK_clicked()\0"
    "on_buttonS01E01SB_clicked()\0"
    "on_buttonS01E01SR_clicked()\0"
    "on_buttonS01E01MC_clicked()\0"
    "on_buttonS01E02InvMC_clicked()\0"
    "on_buttonS01E02XOR_clicked()\0"
    "on_buttonS01E02InvSR_clicked()\0"
    "on_buttonSBoxLookup_clicked()\0"
    "on_editByteAlpha_textChanged(QString)\0"
    "on_editByteBeta_textChanged(QString)\0"
    "on_editByte00ResultSbox_textChanged(QString)\0"
    "on_editByte01ResultSbox_textChanged(QString)\0"
    "on_editByte02ResultSbox_textChanged(QString)\0"
    "on_editByte03ResultSbox_textChanged(QString)\0"
    "on_buttonS01E04ArkK1_clicked()\0"
    "on_buttonS01E04SB_clicked()\0"
    "on_buttonS01E04SR_clicked()\0"
    "on_buttonS01E04FindU2Bytes_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_editByte00From_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_editByte00To_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: on_editByte05From_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_editByte05To_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: on_editByte07From_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: on_editByte07To_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: on_editByte08From_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: on_editByte08To_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: on_editByte10From_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: on_editByte10To_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: on_editByte15From_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: on_editByte15To_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: on_actionExit_triggered(); break;
        case 13: on_buttonRun_clicked(); break;
        case 14: on_editPlaintext1_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: on_editPlaintext2_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: on_editPlaintext3_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: on_editCiphertext1_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: on_editCiphertext2_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: on_editCiphertext3_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: on_actionExample_1_triggered(); break;
        case 21: on_tabWidget_currentChanged((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 22: on_buttonS01E01ARK_clicked(); break;
        case 23: on_buttonS01E01SB_clicked(); break;
        case 24: on_buttonS01E01SR_clicked(); break;
        case 25: on_buttonS01E01MC_clicked(); break;
        case 26: on_buttonS01E02InvMC_clicked(); break;
        case 27: on_buttonS01E02XOR_clicked(); break;
        case 28: on_buttonS01E02InvSR_clicked(); break;
        case 29: on_buttonSBoxLookup_clicked(); break;
        case 30: on_editByteAlpha_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: on_editByteBeta_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: on_editByte00ResultSbox_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: on_editByte01ResultSbox_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: on_editByte02ResultSbox_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: on_editByte03ResultSbox_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: on_buttonS01E04ArkK1_clicked(); break;
        case 37: on_buttonS01E04SB_clicked(); break;
        case 38: on_buttonS01E04SR_clicked(); break;
        case 39: on_buttonS01E04FindU2Bytes_clicked(); break;
        default: ;
        }
        _id -= 40;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
