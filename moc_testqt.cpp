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
    QByteArrayData data[25];
    char stringdata0[502];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestQT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestQT_t qt_meta_stringdata_TestQT = {
    {
QT_MOC_LITERAL(0, 0, 6), // "TestQT"
QT_MOC_LITERAL(1, 7, 16), // "signalInitReader"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "signalGetUid"
QT_MOC_LITERAL(4, 38, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(5, 62, 23), // "on_pushButton_9_clicked"
QT_MOC_LITERAL(6, 86, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 108, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(8, 132, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(9, 156, 30), // "on_pushButton_SaleMode_clicked"
QT_MOC_LITERAL(10, 187, 32), // "on_pushButtonFillingMode_clicked"
QT_MOC_LITERAL(11, 220, 33), // "on_pushButton_ServiceMode_cli..."
QT_MOC_LITERAL(12, 254, 32), // "on_pushButton_TestButton_clicked"
QT_MOC_LITERAL(13, 287, 29), // "on_pushButton_Standby_clicked"
QT_MOC_LITERAL(14, 317, 30), // "on_pushButton_UID_Sent_clicked"
QT_MOC_LITERAL(15, 348, 35), // "on_pushButton_ServiceMode_2_c..."
QT_MOC_LITERAL(16, 384, 14), // "slotRecieveUid"
QT_MOC_LITERAL(17, 399, 5), // "field"
QT_MOC_LITERAL(18, 405, 5), // "value"
QT_MOC_LITERAL(19, 411, 15), // "slotRecieveText"
QT_MOC_LITERAL(20, 427, 8), // "listText"
QT_MOC_LITERAL(21, 436, 11), // "slotReadUID"
QT_MOC_LITERAL(22, 448, 18), // "slotRunRFIDProcess"
QT_MOC_LITERAL(23, 467, 19), // "slotKillRFIDProcess"
QT_MOC_LITERAL(24, 487, 14) // "slotInitReader"

    },
    "TestQT\0signalInitReader\0\0signalGetUid\0"
    "on_pushButton_8_clicked\0on_pushButton_9_clicked\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0"
    "on_pushButton_SaleMode_clicked\0"
    "on_pushButtonFillingMode_clicked\0"
    "on_pushButton_ServiceMode_clicked\0"
    "on_pushButton_TestButton_clicked\0"
    "on_pushButton_Standby_clicked\0"
    "on_pushButton_UID_Sent_clicked\0"
    "on_pushButton_ServiceMode_2_clicked\0"
    "slotRecieveUid\0field\0value\0slotRecieveText\0"
    "listText\0slotReadUID\0slotRunRFIDProcess\0"
    "slotKillRFIDProcess\0slotInitReader"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestQT[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    0,  115,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    0,  120,    2, 0x08 /* Private */,
       9,    0,  121,    2, 0x08 /* Private */,
      10,    0,  122,    2, 0x08 /* Private */,
      11,    0,  123,    2, 0x08 /* Private */,
      12,    0,  124,    2, 0x08 /* Private */,
      13,    0,  125,    2, 0x08 /* Private */,
      14,    0,  126,    2, 0x08 /* Private */,
      15,    0,  127,    2, 0x08 /* Private */,
      16,    2,  128,    2, 0x0a /* Public */,
      19,    1,  133,    2, 0x0a /* Public */,
      21,    0,  136,    2, 0x0a /* Public */,
      22,    0,  137,    2, 0x0a /* Public */,
      23,    0,  138,    2, 0x0a /* Public */,
      24,    0,  139,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

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
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   18,
    QMetaType::Void, QMetaType::QStringList,   20,
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
        case 0: _t->signalInitReader(); break;
        case 1: _t->signalGetUid(); break;
        case 2: _t->on_pushButton_8_clicked(); break;
        case 3: _t->on_pushButton_9_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_SaleMode_clicked(); break;
        case 8: _t->on_pushButtonFillingMode_clicked(); break;
        case 9: _t->on_pushButton_ServiceMode_clicked(); break;
        case 10: _t->on_pushButton_TestButton_clicked(); break;
        case 11: _t->on_pushButton_Standby_clicked(); break;
        case 12: _t->on_pushButton_UID_Sent_clicked(); break;
        case 13: _t->on_pushButton_ServiceMode_2_clicked(); break;
        case 14: _t->slotRecieveUid((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->slotRecieveText((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 16: _t->slotReadUID(); break;
        case 17: _t->slotRunRFIDProcess(); break;
        case 18: _t->slotKillRFIDProcess(); break;
        case 19: _t->slotInitReader(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TestQT::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestQT::signalInitReader)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TestQT::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestQT::signalGetUid)) {
                *result = 1;
                return;
            }
        }
    }
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void TestQT::signalInitReader()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TestQT::signalGetUid()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
