/****************************************************************************
** Meta object code from reading C++ file 'ModelFactory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../options/ModelFactory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModelFactory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModelFactory_t {
    QByteArrayData data[7];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelFactory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelFactory_t qt_meta_stringdata_ModelFactory = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ModelFactory"
QT_MOC_LITERAL(1, 13, 19), // "currentModelChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "update"
QT_MOC_LITERAL(4, 41, 11), // "optionStyle"
QT_MOC_LITERAL(5, 53, 18), // "updateCurrentModel"
QT_MOC_LITERAL(6, 72, 9) // "modelName"

    },
    "ModelFactory\0currentModelChanged\0\0"
    "update\0optionStyle\0updateCurrentModel\0"
    "modelName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelFactory[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   32,    2, 0x0a /* Public */,
       5,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void ModelFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModelFactory *_t = static_cast<ModelFactory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentModelChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->update((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->updateCurrentModel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModelFactory::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelFactory::currentModelChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ModelFactory::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ModelFactory.data,
      qt_meta_data_ModelFactory,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ModelFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelFactory.stringdata0))
        return static_cast<void*>(const_cast< ModelFactory*>(this));
    return QWidget::qt_metacast(_clname);
}

int ModelFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ModelFactory::currentModelChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
