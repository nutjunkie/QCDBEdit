/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Thu Jul 4 14:22:04 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QCDBEdit__MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,
      29,   21,   21,   21, 0x08,
      40,   21,   21,   21, 0x08,
      58,   56,   21,   21, 0x08,
      85,   21,   21,   21, 0x08,
     118,   21,   21,   21, 0x08,
     154,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QCDBEdit__MainWindow[] = {
    "QCDBEdit::MainWindow\0\0quit()\0openFile()\0"
    "commitChanges()\0,\0itemDoubleClicked(int,int)\0"
    "on_addOptionButton_clicked(bool)\0"
    "on_deleteOptionButton_clicked(bool)\0"
    "on_editOptionButton_clicked(bool)\0"
};

const QMetaObject QCDBEdit::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QCDBEdit__MainWindow,
      qt_meta_data_QCDBEdit__MainWindow, 0 }
};

const QMetaObject *QCDBEdit::MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *QCDBEdit::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QCDBEdit__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QCDBEdit::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: quit(); break;
        case 1: openFile(); break;
        case 2: commitChanges(); break;
        case 3: itemDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: on_addOptionButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: on_deleteOptionButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: on_editOptionButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE