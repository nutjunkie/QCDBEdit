/****************************************************************************
** Meta object code from reading C++ file 'QMsgBox.h'
**
** Created: Thu Jul 4 14:22:03 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QMsgBox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMsgBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMsgBox[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_QMsgBox[] = {
    "QMsgBox\0"
};

const QMetaObject QMsgBox::staticMetaObject = {
    { &QMessageBox::staticMetaObject, qt_meta_stringdata_QMsgBox,
      qt_meta_data_QMsgBox, 0 }
};

const QMetaObject *QMsgBox::metaObject() const
{
    return &staticMetaObject;
}

void *QMsgBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMsgBox))
        return static_cast<void*>(const_cast< QMsgBox*>(this));
    return QMessageBox::qt_metacast(_clname);
}

int QMsgBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMessageBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
