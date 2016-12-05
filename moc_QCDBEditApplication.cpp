/****************************************************************************
** Meta object code from reading C++ file 'QCDBEditApplication.h'
**
** Created: Thu Jul 4 14:22:03 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QCDBEditApplication.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QCDBEditApplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QCDBEdit__QCDBEditApplication[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      36,   31,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QCDBEdit__QCDBEditApplication[] = {
    "QCDBEdit::QCDBEditApplication\0\0file\0"
    "open(QString)\0"
};

const QMetaObject QCDBEdit::QCDBEditApplication::staticMetaObject = {
    { &QApplication::staticMetaObject, qt_meta_stringdata_QCDBEdit__QCDBEditApplication,
      qt_meta_data_QCDBEdit__QCDBEditApplication, 0 }
};

const QMetaObject *QCDBEdit::QCDBEditApplication::metaObject() const
{
    return &staticMetaObject;
}

void *QCDBEdit::QCDBEditApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QCDBEdit__QCDBEditApplication))
        return static_cast<void*>(const_cast< QCDBEditApplication*>(this));
    return QApplication::qt_metacast(_clname);
}

int QCDBEdit::QCDBEditApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: open((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
