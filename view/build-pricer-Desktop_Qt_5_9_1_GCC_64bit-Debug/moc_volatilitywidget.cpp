/****************************************************************************
** Meta object code from reading C++ file 'volatilitywidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../options/volatilitywidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'volatilitywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VolatilityWidget_t {
    QByteArrayData data[6];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VolatilityWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VolatilityWidget_t qt_meta_stringdata_VolatilityWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VolatilityWidget"
QT_MOC_LITERAL(1, 17, 17), // "updateBufferValue"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 3), // "val"
QT_MOC_LITERAL(4, 40, 18), // "updateBufferPeriod"
QT_MOC_LITERAL(5, 59, 6) // "period"

    },
    "VolatilityWidget\0updateBufferValue\0\0"
    "val\0updateBufferPeriod\0period"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VolatilityWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void VolatilityWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VolatilityWidget *_t = static_cast<VolatilityWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateBufferValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->updateBufferPeriod((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject VolatilityWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VolatilityWidget.data,
      qt_meta_data_VolatilityWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VolatilityWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VolatilityWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VolatilityWidget.stringdata0))
        return static_cast<void*>(const_cast< VolatilityWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int VolatilityWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
