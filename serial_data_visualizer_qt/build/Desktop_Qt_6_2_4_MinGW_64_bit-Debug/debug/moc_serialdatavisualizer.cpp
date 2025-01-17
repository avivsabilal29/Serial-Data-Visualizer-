/****************************************************************************
** Meta object code from reading C++ file 'serialdatavisualizer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../serialdatavisualizer.h"
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
    const uint offsetsAndSize[24];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SerialDataVisualizer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SerialDataVisualizer_t qt_meta_stringdata_SerialDataVisualizer = {
    {
QT_MOC_LITERAL(0, 20), // "SerialDataVisualizer"
QT_MOC_LITERAL(21, 25), // "on_portDropdown_activated"
QT_MOC_LITERAL(47, 0), // ""
QT_MOC_LITERAL(48, 5), // "index"
QT_MOC_LITERAL(54, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(79, 7), // "checked"
QT_MOC_LITERAL(87, 29), // "on_baudrateDropdown_activated"
QT_MOC_LITERAL(117, 27), // "on_disconnectButton_clicked"
QT_MOC_LITERAL(145, 28), // "on_viewRawDataButton_clicked"
QT_MOC_LITERAL(174, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(197, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(219, 22) // "on_clearButton_clicked"

    },
    "SerialDataVisualizer\0on_portDropdown_activated\0"
    "\0index\0on_connectButton_clicked\0checked\0"
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
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x08,    1 /* Private */,
       4,    1,   65,    2, 0x08,    3 /* Private */,
       6,    1,   68,    2, 0x08,    5 /* Private */,
       7,    1,   71,    2, 0x08,    7 /* Private */,
       8,    0,   74,    2, 0x08,    9 /* Private */,
       9,    0,   75,    2, 0x08,   10 /* Private */,
      10,    0,   76,    2, 0x08,   11 /* Private */,
      11,    0,   77,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
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
        case 0: _t->on_portDropdown_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_connectButton_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->on_baudrateDropdown_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_disconnectButton_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->on_viewRawDataButton_clicked(); break;
        case 5: _t->on_startButton_clicked(); break;
        case 6: _t->on_stopButton_clicked(); break;
        case 7: _t->on_clearButton_clicked(); break;
        default: ;
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
, QtPrivate::TypeAndForceComplete<SerialDataVisualizer, std::true_type>
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
