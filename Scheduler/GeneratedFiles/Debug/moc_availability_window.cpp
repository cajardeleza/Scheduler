/****************************************************************************
** Meta object code from reading C++ file 'availability_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../availability_window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'availability_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Availability_Window_t {
    QByteArrayData data[12];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Availability_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Availability_Window_t qt_meta_stringdata_Availability_Window = {
    {
QT_MOC_LITERAL(0, 0, 19), // "Availability_Window"
QT_MOC_LITERAL(1, 20, 34), // "on_calendarWidget_selectionCh..."
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 20), // "on_serverBtn_clicked"
QT_MOC_LITERAL(4, 77, 21), // "on_managerBtn_clicked"
QT_MOC_LITERAL(5, 99, 18), // "on_hostBtn_clicked"
QT_MOC_LITERAL(6, 118, 18), // "on_expoBtn_clicked"
QT_MOC_LITERAL(7, 137, 17), // "on_busBtn_clicked"
QT_MOC_LITERAL(8, 155, 23), // "on_bartenderBtn_clicked"
QT_MOC_LITERAL(9, 179, 22), // "on_RemoveAMBtn_clicked"
QT_MOC_LITERAL(10, 202, 22), // "on_RemovePMBtn_clicked"
QT_MOC_LITERAL(11, 225, 17) // "on_Submit_clicked"

    },
    "Availability_Window\0"
    "on_calendarWidget_selectionChanged\0\0"
    "on_serverBtn_clicked\0on_managerBtn_clicked\0"
    "on_hostBtn_clicked\0on_expoBtn_clicked\0"
    "on_busBtn_clicked\0on_bartenderBtn_clicked\0"
    "on_RemoveAMBtn_clicked\0on_RemovePMBtn_clicked\0"
    "on_Submit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Availability_Window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

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

       0        // eod
};

void Availability_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Availability_Window *_t = static_cast<Availability_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_calendarWidget_selectionChanged(); break;
        case 1: _t->on_serverBtn_clicked(); break;
        case 2: _t->on_managerBtn_clicked(); break;
        case 3: _t->on_hostBtn_clicked(); break;
        case 4: _t->on_expoBtn_clicked(); break;
        case 5: _t->on_busBtn_clicked(); break;
        case 6: _t->on_bartenderBtn_clicked(); break;
        case 7: _t->on_RemoveAMBtn_clicked(); break;
        case 8: _t->on_RemovePMBtn_clicked(); break;
        case 9: _t->on_Submit_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Availability_Window::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Availability_Window.data,
      qt_meta_data_Availability_Window,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Availability_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Availability_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Availability_Window.stringdata0))
        return static_cast<void*>(const_cast< Availability_Window*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Availability_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
