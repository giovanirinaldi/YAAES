/****************************************************************************
** Meta object code from reading C++ file 'dialogsetmatriximpl.h'
**
** Created: Fri Apr 27 22:06:55 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialogsetmatriximpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogsetmatriximpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogSetMatrixImpl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      50,   20,   20,   20, 0x08,
      84,   77,   20,   20, 0x08,
     123,   20,   20,   20, 0x08,
     154,   20,   20,   20, 0x08,
     188,   20,   20,   20, 0x08,
     222,   20,   20,   20, 0x08,
     256,   20,   20,   20, 0x08,
     290,   20,   20,   20, 0x08,
     324,   20,   20,   20, 0x08,
     358,   20,   20,   20, 0x08,
     392,   20,   20,   20, 0x08,
     426,   20,   20,   20, 0x08,
     460,   20,   20,   20, 0x08,
     494,   20,   20,   20, 0x08,
     528,   20,   20,   20, 0x08,
     562,   20,   20,   20, 0x08,
     596,   20,   20,   20, 0x08,
     630,   20,   20,   20, 0x08,
     664,   20,   20,   20, 0x08,
     698,   20,   20,   20, 0x08,
     732,   20,   20,   20, 0x08,
     766,   20,   20,   20, 0x08,
     800,   20,   20,   20, 0x08,
     834,   20,   20,   20, 0x08,
     868,   20,   20,   20, 0x08,
     902,   20,   20,   20, 0x08,
     936,   20,   20,   20, 0x08,
     970,   20,   20,   20, 0x08,
    1004,   20,   20,   20, 0x08,
    1038,   20,   20,   20, 0x08,
    1072,   20,   20,   20, 0x08,
    1106,   20,   20,   20, 0x08,
    1140,   20,   20,   20, 0x08,
    1174,   20,   20,   20, 0x08,
    1208,   20,   20,   20, 0x08,
    1242,   20,   20,   20, 0x08,
    1282,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogSetMatrixImpl[] = {
    "DialogSetMatrixImpl\0\0on_radioMatrixMode_clicked()\0"
    "on_radioTextMode_clicked()\0button\0"
    "on_buttonBox_clicked(QAbstractButton*)\0"
    "on_radioCharTextMode_clicked()\0"
    "on_setByte00_textChanged(QString)\0"
    "on_setByte01_textChanged(QString)\0"
    "on_setByte02_textChanged(QString)\0"
    "on_setByte03_textChanged(QString)\0"
    "on_setByte07_textChanged(QString)\0"
    "on_setByte04_textChanged(QString)\0"
    "on_setByte05_textChanged(QString)\0"
    "on_setByte06_textChanged(QString)\0"
    "on_setByte08_textChanged(QString)\0"
    "on_setByte09_textChanged(QString)\0"
    "on_setByte10_textChanged(QString)\0"
    "on_setByte11_textChanged(QString)\0"
    "on_setByte12_textChanged(QString)\0"
    "on_setByte13_textChanged(QString)\0"
    "on_setByte14_textChanged(QString)\0"
    "on_setByte15_textChanged(QString)\0"
    "on_setByte16_textChanged(QString)\0"
    "on_setByte17_textChanged(QString)\0"
    "on_setByte18_textChanged(QString)\0"
    "on_setByte19_textChanged(QString)\0"
    "on_setByte20_textChanged(QString)\0"
    "on_setByte21_textChanged(QString)\0"
    "on_setByte22_textChanged(QString)\0"
    "on_setByte23_textChanged(QString)\0"
    "on_setByte24_textChanged(QString)\0"
    "on_setByte25_textChanged(QString)\0"
    "on_setByte26_textChanged(QString)\0"
    "on_setByte27_textChanged(QString)\0"
    "on_setByte28_textChanged(QString)\0"
    "on_setByte29_textChanged(QString)\0"
    "on_setByte30_textChanged(QString)\0"
    "on_setByte31_textChanged(QString)\0"
    "on_setHexTextBytes_textChanged(QString)\0"
    "on_setCharTextBytes_textChanged(QString)\0"
};

const QMetaObject DialogSetMatrixImpl::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogSetMatrixImpl,
      qt_meta_data_DialogSetMatrixImpl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogSetMatrixImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogSetMatrixImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogSetMatrixImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogSetMatrixImpl))
        return static_cast<void*>(const_cast< DialogSetMatrixImpl*>(this));
    if (!strcmp(_clname, "Ui::DialogSetMatrix"))
        return static_cast< Ui::DialogSetMatrix*>(const_cast< DialogSetMatrixImpl*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogSetMatrixImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_radioMatrixMode_clicked(); break;
        case 1: on_radioTextMode_clicked(); break;
        case 2: on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 3: on_radioCharTextMode_clicked(); break;
        case 4: on_setByte00_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: on_setByte01_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: on_setByte02_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: on_setByte03_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: on_setByte07_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: on_setByte04_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: on_setByte05_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: on_setByte06_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: on_setByte08_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: on_setByte09_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: on_setByte10_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: on_setByte11_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: on_setByte12_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: on_setByte13_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: on_setByte14_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: on_setByte15_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: on_setByte16_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: on_setByte17_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: on_setByte18_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: on_setByte19_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: on_setByte20_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: on_setByte21_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: on_setByte22_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: on_setByte23_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: on_setByte24_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: on_setByte25_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: on_setByte26_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: on_setByte27_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: on_setByte28_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: on_setByte29_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: on_setByte30_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: on_setByte31_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: on_setHexTextBytes_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: on_setCharTextBytes_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 38;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
