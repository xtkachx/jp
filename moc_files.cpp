/****************************************************************************
** Meta object code from reading C++ file 'files.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "files.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'files.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Files_t {
    QByteArrayData data[12];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Files_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Files_t qt_meta_stringdata_Files = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Files"
QT_MOC_LITERAL(1, 6, 16), // "signalDoorSensor"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "signalTextBrowser"
QT_MOC_LITERAL(4, 42, 8), // "listText"
QT_MOC_LITERAL(5, 51, 21), // "signalEnableNFCReader"
QT_MOC_LITERAL(6, 73, 20), // "signalRunRFIDProcess"
QT_MOC_LITERAL(7, 94, 21), // "signalKillRFIDProcess"
QT_MOC_LITERAL(8, 116, 14), // "signalOpenDoor"
QT_MOC_LITERAL(9, 131, 16), // "signalInitReader"
QT_MOC_LITERAL(10, 148, 8), // "slotLock"
QT_MOC_LITERAL(11, 157, 7) // "changed"

    },
    "Files\0signalDoorSensor\0\0signalTextBrowser\0"
    "listText\0signalEnableNFCReader\0"
    "signalRunRFIDProcess\0signalKillRFIDProcess\0"
    "signalOpenDoor\0signalInitReader\0"
    "slotLock\0changed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Files[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       5,    0,   65,    2, 0x06 /* Public */,
       6,    0,   66,    2, 0x06 /* Public */,
       7,    0,   67,    2, 0x06 /* Public */,
       8,    0,   68,    2, 0x06 /* Public */,
       9,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Files::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Files *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalDoorSensor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->signalTextBrowser((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->signalEnableNFCReader(); break;
        case 3: _t->signalRunRFIDProcess(); break;
        case 4: _t->signalKillRFIDProcess(); break;
        case 5: _t->signalOpenDoor(); break;
        case 6: _t->signalInitReader(); break;
        case 7: _t->slotLock(); break;
        case 8: _t->changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Files::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files::signalDoorSensor)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Files::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files::signalTextBrowser)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Files::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files::signalEnableNFCReader)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Files::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files::signalRunRFIDProcess)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Files::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files::signalKillRFIDProcess)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Files::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files::signalOpenDoor)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Files::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Files::signalInitReader)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Files::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Files.data,
    qt_meta_data_Files,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Files::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Files::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Files.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Files::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Files::signalDoorSensor(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Files::signalTextBrowser(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Files::signalEnableNFCReader()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Files::signalRunRFIDProcess()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Files::signalKillRFIDProcess()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Files::signalOpenDoor()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Files::signalInitReader()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
