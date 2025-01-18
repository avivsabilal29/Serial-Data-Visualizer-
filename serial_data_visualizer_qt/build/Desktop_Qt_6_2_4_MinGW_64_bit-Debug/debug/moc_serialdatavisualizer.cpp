/****************************************************************************
** Meta object code from reading C++ file 'serialdatavisualizer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../headers/serialdatavisualizer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialdatavisualizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialDataVisualizer_t {
    const uint offsetsAndSize[28];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SerialDataVisualizer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SerialDataVisualizer_t qt_meta_stringdata_SerialDataVisualizer = {
    {
QT_MOC_LITERAL(0, 20), // "SerialDataVisualizer"
QT_MOC_LITERAL(21, 16), // "sendDataToWorker"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 4), // "data"
QT_MOC_LITERAL(44, 25), // "on_portDropdown_activated"
QT_MOC_LITERAL(70, 5), // "index"
QT_MOC_LITERAL(76, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(101, 7), // "checked"
QT_MOC_LITERAL(109, 29), // "on_baudrateDropdown_activated"
QT_MOC_LITERAL(139, 27), // "on_disconnectButton_clicked"
QT_MOC_LITERAL(167, 28), // "on_viewRawDataButton_clicked"
QT_MOC_LITERAL(196, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(219, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(241, 22) // "on_clearButton_clicked"

    },
    "SerialDataVisualizer\0sendDataToWorker\0"
    "\0data\0on_portDropdown_activated\0index\0"
    "on_connectButton_clicked\0checked\0"
    "on_baudrateDropdown_activated\0"
    "on_disconnectButton_clicked\0"
    "on_viewRawDataButton_clicked\0"
    "on_startButton_clicked\0on_stopButton_clicked\0"
    "on_clearButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialDataVisualizer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   71,    2, 0x08,    3 /* Private */,
       6,    1,   74,    2, 0x08,    5 /* Private */,
       8,    1,   77,    2, 0x08,    7 /* Private */,
       9,    1,   80,    2, 0x08,    9 /* Private */,
      10,    0,   83,    2, 0x08,   11 /* Private */,
      11,    0,   84,    2, 0x08,   12 /* Private */,
      12,    0,   85,    2, 0x08,   13 /* Private */,
      13,    0,   86,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SerialDataVisualizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialDataVisualizer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendDataToWorker((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 1: _t->on_portDropdown_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_connectButton_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_baudrateDropdown_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_disconnectButton_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_viewRawDataButton_clicked(); break;
        case 6: _t->on_startButton_clicked(); break;
        case 7: _t->on_stopButton_clicked(); break;
        case 8: _t->on_clearButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialDataVisualizer::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialDataVisualizer::sendDataToWorker)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SerialDataVisualizer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SerialDataVisualizer.offsetsAndSize,
    qt_meta_data_SerialDataVisualizer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SerialDataVisualizer_t
, QtPrivate::TypeAndForceComplete<SerialDataVisualizer, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SerialDataVisualizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialDataVisualizer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialDataVisualizer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SerialDataVisualizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SerialDataVisualizer::sendDataToWorker(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
