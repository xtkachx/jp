/****************************************************************************
** Meta object code from reading C++ file 'AddonfFridge.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "AddonfFridge.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddonfFridge.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddonFridge_t {
    QByteArrayData data[11];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddonFridge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddonFridge_t qt_meta_stringdata_AddonFridge = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AddonFridge"
QT_MOC_LITERAL(1, 12, 16), // "signalInitReader"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "signalGetUid"
QT_MOC_LITERAL(4, 43, 14), // "slotRecieveUid"
QT_MOC_LITERAL(5, 58, 5), // "field"
QT_MOC_LITERAL(6, 64, 5), // "value"
QT_MOC_LITERAL(7, 70, 11), // "slotReadUID"
QT_MOC_LITERAL(8, 82, 18), // "slotRunRFIDProcess"
QT_MOC_LITERAL(9, 101, 19), // "slotKillRFIDProcess"
QT_MOC_LITERAL(10, 121, 14) // "slotInitReader"

    },
    "AddonFridge\0signalInitReader\0\0"
    "signalGetUid\0slotRecieveUid\0field\0"
    "value\0slotReadUID\0slotRunRFIDProcess\0"
    "slotKillRFIDProcess\0slotInitReader"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddonFridge[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   51,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddonFridge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddonFridge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalInitReader(); break;
        case 1: _t->signalGetUid(); break;
        case 2: _t->slotRecieveUid((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->slotReadUID(); break;
        case 4: _t->slotRunRFIDProcess(); break;
        case 5: _t->slotKillRFIDProcess(); break;
        case 6: _t->slotInitReader(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddonFridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddonFridge::signalInitReader)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddonFridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddonFridge::signalGetUid)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AddonFridge::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AddonFridge.data,
    qt_meta_data_AddonFridge,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AddonFridge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddonFridge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddonFridge.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AddonFridge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AddonFridge::signalInitReader()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AddonFridge::signalGetUid()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
