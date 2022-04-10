/****************************************************************************
** Meta object code from reading C++ file 'wallpaper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../wallpaper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wallpaper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Wallpaper_t {
    QByteArrayData data[14];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Wallpaper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Wallpaper_t qt_meta_stringdata_Wallpaper = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Wallpaper"
QT_MOC_LITERAL(1, 10, 22), // "on_path_button_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 22), // "on_hoverButton_clicked"
QT_MOC_LITERAL(4, 57, 21), // "on_fillButton_clicked"
QT_MOC_LITERAL(5, 79, 23), // "on_secondButton_clicked"
QT_MOC_LITERAL(6, 103, 22), // "on_firstButton_clicked"
QT_MOC_LITERAL(7, 126, 23), // "on_activatedSysTrayIcon"
QT_MOC_LITERAL(8, 150, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(9, 184, 6), // "reason"
QT_MOC_LITERAL(10, 191, 17), // "on_showMainAction"
QT_MOC_LITERAL(11, 209, 16), // "on_exitAppAction"
QT_MOC_LITERAL(12, 226, 23), // "on_filePath_textChanged"
QT_MOC_LITERAL(13, 250, 4) // "arg1"

    },
    "Wallpaper\0on_path_button_clicked\0\0"
    "on_hoverButton_clicked\0on_fillButton_clicked\0"
    "on_secondButton_clicked\0on_firstButton_clicked\0"
    "on_activatedSysTrayIcon\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0on_showMainAction\0on_exitAppAction\0"
    "on_filePath_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Wallpaper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    1,   64,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void Wallpaper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Wallpaper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_path_button_clicked(); break;
        case 1: _t->on_hoverButton_clicked(); break;
        case 2: _t->on_fillButton_clicked(); break;
        case 3: _t->on_secondButton_clicked(); break;
        case 4: _t->on_firstButton_clicked(); break;
        case 5: _t->on_activatedSysTrayIcon((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 6: _t->on_showMainAction(); break;
        case 7: _t->on_exitAppAction(); break;
        case 8: _t->on_filePath_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Wallpaper::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Wallpaper.data,
    qt_meta_data_Wallpaper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Wallpaper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Wallpaper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Wallpaper.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Wallpaper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
