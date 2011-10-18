/****************************************************************************
** Meta object code from reading C++ file 'newrijndael.h'
**
** Created: Tue Oct 18 15:16:06 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/newrijndael.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newrijndael.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewRijndael[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      41,   12,   12,   12, 0x08,
      74,   67,   12,   12, 0x08,
     113,   12,   12,   12, 0x08,
     138,   12,   12,   12, 0x08,
     163,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewRijndael[] = {
    "NewRijndael\0\0on_buttonSetInput_clicked()\0"
    "on_buttonSetKey_clicked()\0button\0"
    "on_buttonBox_clicked(QAbstractButton*)\0"
    "on_radioKey128_clicked()\0"
    "on_radioKey192_clicked()\0"
    "on_radioKey256_clicked()\0"
};

const QMetaObject NewRijndael::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewRijndael,
      qt_meta_data_NewRijndael, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewRijndael::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewRijndael::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewRijndael::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewRijndael))
        return static_cast<void*>(const_cast< NewRijndael*>(this));
    if (!strcmp(_clname, "Ui::DialogNewRijndael"))
        return static_cast< Ui::DialogNewRijndael*>(const_cast< NewRijndael*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewRijndael::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
