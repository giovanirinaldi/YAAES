/****************************************************************************
** Meta object code from reading C++ file 'dialognew.h'
**
** Created: Sat Oct 22 19:11:51 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialognew.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialognew.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogNew[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      39,   10,   10,   10, 0x08,
      72,   65,   10,   10, 0x08,
     111,   10,   10,   10, 0x08,
     136,   10,   10,   10, 0x08,
     161,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogNew[] = {
    "DialogNew\0\0on_buttonSetInput_clicked()\0"
    "on_buttonSetKey_clicked()\0button\0"
    "on_buttonBox_clicked(QAbstractButton*)\0"
    "on_radioKey128_clicked()\0"
    "on_radioKey192_clicked()\0"
    "on_radioKey256_clicked()\0"
};

const QMetaObject DialogNew::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogNew,
      qt_meta_data_DialogNew, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogNew::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogNew::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogNew::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogNew))
        return static_cast<void*>(const_cast< DialogNew*>(this));
    if (!strcmp(_clname, "Ui::DialogNew"))
        return static_cast< Ui::DialogNew*>(const_cast< DialogNew*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogNew::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_buttonSetInput_clicked(); break;
        case 1: on_buttonSetKey_clicked(); break;
        case 2: on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 3: on_radioKey128_clicked(); break;
        case 4: on_radioKey192_clicked(); break;
        case 5: on_radioKey256_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
