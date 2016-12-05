/****************************************************************************
** Meta object code from reading C++ file 'OptionNumberEditor.h'
**
** Created: Thu Jul 4 14:22:07 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "OptionNumberEditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OptionNumberEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QCDBEdit__OptionNumberEditor[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QCDBEdit__OptionNumberEditor[] = {
    "QCDBEdit::OptionNumberEditor\0\0accept()\0"
};

const QMetaObject QCDBEdit::OptionNumberEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QCDBEdit__OptionNumberEditor,
      qt_meta_data_QCDBEdit__OptionNumberEditor, 0 }
};

const QMetaObject *QCDBEdit::OptionNumberEditor::metaObject() const
{
    return &staticMetaObject;
}

void *QCDBEdit::OptionNumberEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QCDBEdit__OptionNumberEditor))
        return static_cast<void*>(const_cast< OptionNumberEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int QCDBEdit::OptionNumberEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accept(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
