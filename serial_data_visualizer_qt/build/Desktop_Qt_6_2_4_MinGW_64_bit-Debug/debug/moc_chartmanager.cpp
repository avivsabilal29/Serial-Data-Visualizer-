/****************************************************************************
** Meta object code from reading C++ file 'chartmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../chartmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chartmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChartManager_t {
    const uint offsetsAndSize[16];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ChartManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ChartManager_t qt_meta_stringdata_ChartManager = {
    {
QT_MOC_LITERAL(0, 12), // "ChartManager"
QT_MOC_LITERAL(13, 12), // "chartUpdated"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 8), // "minValue"
QT_MOC_LITERAL(36, 8), // "maxValue"
QT_MOC_LITERAL(45, 12), // "averageValue"
QT_MOC_LITERAL(58, 11), // "updateChart"
QT_MOC_LITERAL(70, 13) // "updateRawData"

    },
    "ChartManager\0chartUpdated\0\0minValue\0"
    "maxValue\0averageValue\0updateChart\0"
    "updateRawData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChartManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   39,    2, 0x08,    5 /* Private */,
       7,    0,   40,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChartManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChartManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->chartUpdated((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 1: _t->updateChart(); break;
        case 2: _t->updateRawData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChartManager::*)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartManager::chartUpdated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ChartManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ChartManager.offsetsAndSize,
    qt_meta_data_ChartManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ChartManager_t
, QtPrivate::TypeAndForceComplete<ChartManager, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ChartManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChartManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChartManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ChartManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ChartManager::chartUpdated(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
