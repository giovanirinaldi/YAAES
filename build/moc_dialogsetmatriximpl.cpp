/****************************************************************************
** Meta object code from reading C++ file 'dialogsetmatriximpl.h'
**
** Created: Tue Oct 18 16:54:07 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialogsetmatriximpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogsetmatriximpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogSetMatrixImpl[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      50,   20,   20,   20, 0x08,
      84,   77,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogSetMatrixImpl[] = {
    "DialogSetMatrixImpl\0\0on_radioMatrixMode_clicked()\0"
    "on_radioTextMode_clicked()\0button\0"
    "on_buttonBox_clicked(QAbstractButton*)\0"
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
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
