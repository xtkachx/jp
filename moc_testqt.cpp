/****************************************************************************
** Meta object code from reading C++ file 'testqt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "testqt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestQT_t {
    QByteArrayData data[14];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestQT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestQT_t qt_meta_stringdata_TestQT = {
    {
QT_MOC_LITERAL(0, 0, 6), // "TestQT"
QT_MOC_LITERAL(1, 7, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "on_pushButton_9_clicked"
QT_MOC_LITERAL(4, 56, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 78, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 102, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 126, 30), // "on_pushButton_SaleMode_clicked"
QT_MOC_LITERAL(8, 157, 32), // "on_pushButtonFillingMode_clicked"
QT_MOC_LITERAL(9, 190, 33), // "on_pushButton_ServiceMode_cli..."
QT_MOC_LITERAL(10, 224, 32), // "on_pushButton_TestButton_clicked"
QT_MOC_LITERAL(11, 257, 29), // "on_pushButton_Standby_clicked"
QT_MOC_LITERAL(12, 287, 35), // "on_pushButton_ServiceMode_2_c..."
QT_MOC_LITERAL(13, 323, 14) // "slotTextOutput"

    },
    "TestQT\0on_pushButton_8_clicked\0\0"
    "on_pushButton_9_clicked\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_SaleMode_clicked\0"
    "on_pushButtonFillingMode_clicked\0"
    "on_pushButton_ServiceMode_clicked\0"
    "on_pushButton_TestButton_clicked\0"
    "on_pushButton_Standby_clicked\0"
    "on_pushButton_ServiceMode_2_clicked\0"
    "slotTextOutput"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestQT[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestQT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestQT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_8_clicked(); break;
        case 1: _t->on_pushButton_9_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->on_pushButton_SaleMode_clicked(); break;
        case 6: _t->on_pushButtonFillingMode_clicked(); break;
        case 7: _t->on_pushButton_ServiceMode_clicked(); break;
        case 8: _t->on_pushButton_TestButton_clicked(); break;
        case 9: _t->on_pushButton_Standby_clicked(); break;
        case 10: _t->on_pushButton_ServiceMode_2_clicked(); break;
        case 11: _t->slotTextOutput(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TestQT::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_TestQT.data,
    qt_meta_data_TestQT,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestQT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestQT::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestQT.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestQT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
