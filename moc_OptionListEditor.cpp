/****************************************************************************
** Meta object code from reading C++ file 'OptionListEditor.h'
**
** Created: Thu Jul 4 14:22:06 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "OptionListEditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OptionListEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QCDBEdit__OptionListEditor[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x0a,
      37,   27,   27,   27, 0x08,
      64,   27,   27,   27, 0x08,
      94,   27,   27,   27, 0x08,
     120,   27,   27,   27, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QCDBEdit__OptionListEditor[] = {
    "QCDBEdit::OptionListEditor\0\0accept()\0"
    "on_addButton_clicked(bool)\0"
    "on_deleteButton_clicked(bool)\0"
    "on_upButton_clicked(bool)\0"
    "on_downButton_clicked(bool)\0"
};

const QMetaObject QCDBEdit::OptionListEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QCDBEdit__OptionListEditor,
      qt_meta_data_QCDBEdit__OptionListEditor, 0 }
};

const QMetaObject *QCDBEdit::OptionListEditor::metaObject() const
{
    return &staticMetaObject;
}

void *QCDBEdit::OptionListEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QCDBEdit__OptionListEditor))
        return static_cast<void*>(const_cast< OptionListEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int QCDBEdit::OptionListEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accept(); break;
        case 1: on_addButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_deleteButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: on_upButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: on_downButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
