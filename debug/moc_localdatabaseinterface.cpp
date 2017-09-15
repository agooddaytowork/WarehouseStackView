/****************************************************************************
** Meta object code from reading C++ file 'localdatabaseinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../components/localdatabaseinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localdatabaseinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LocalDatabaseInterface_t {
    QByteArrayData data[38];
    char stringdata0[435];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LocalDatabaseInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LocalDatabaseInterface_t qt_meta_stringdata_LocalDatabaseInterface = {
    {
QT_MOC_LITERAL(0, 0, 22), // "LocalDatabaseInterface"
QT_MOC_LITERAL(1, 23, 21), // "initializeDataToGraph"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 16), // "QAbstractSeries*"
QT_MOC_LITERAL(4, 63, 6), // "series"
QT_MOC_LITERAL(5, 70, 14), // "QAbstractAxis*"
QT_MOC_LITERAL(6, 85, 4), // "axis"
QT_MOC_LITERAL(7, 90, 5), // "mRFID"
QT_MOC_LITERAL(8, 96, 17), // "updateDataToGraph"
QT_MOC_LITERAL(9, 114, 7), // "setHVON"
QT_MOC_LITERAL(10, 122, 8), // "globalId"
QT_MOC_LITERAL(11, 131, 7), // "command"
QT_MOC_LITERAL(12, 139, 10), // "setValveON"
QT_MOC_LITERAL(13, 150, 12), // "setProtectON"
QT_MOC_LITERAL(14, 163, 11), // "shipStation"
QT_MOC_LITERAL(15, 175, 20), // "updateStationFruInfo"
QT_MOC_LITERAL(16, 196, 2), // "id"
QT_MOC_LITERAL(17, 199, 4), // "KTPN"
QT_MOC_LITERAL(18, 204, 10), // "KTSERIALPN"
QT_MOC_LITERAL(19, 215, 3), // "LPN"
QT_MOC_LITERAL(20, 219, 14), // "GUNOFFPRESSURE"
QT_MOC_LITERAL(21, 234, 2), // "PO"
QT_MOC_LITERAL(22, 237, 16), // "SUPPLIERTESTDATE"
QT_MOC_LITERAL(23, 254, 12), // "ReceivedDate"
QT_MOC_LITERAL(24, 267, 11), // "ShippedDate"
QT_MOC_LITERAL(25, 279, 21), // "updateStationSettings"
QT_MOC_LITERAL(26, 301, 4), // "name"
QT_MOC_LITERAL(27, 306, 8), // "eguntype"
QT_MOC_LITERAL(28, 315, 14), // "thresholdDownP"
QT_MOC_LITERAL(29, 330, 12), // "thresholdUpP"
QT_MOC_LITERAL(30, 343, 14), // "thresholdDownI"
QT_MOC_LITERAL(31, 358, 12), // "thresholdUpI"
QT_MOC_LITERAL(32, 371, 8), // "pumpType"
QT_MOC_LITERAL(33, 380, 8), // "pumpAddr"
QT_MOC_LITERAL(34, 389, 6), // "pumpCh"
QT_MOC_LITERAL(35, 396, 8), // "SDCSAddr"
QT_MOC_LITERAL(36, 405, 6), // "SDCSCh"
QT_MOC_LITERAL(37, 412, 22) // "initializeStationModel"

    },
    "LocalDatabaseInterface\0initializeDataToGraph\0"
    "\0QAbstractSeries*\0series\0QAbstractAxis*\0"
    "axis\0mRFID\0updateDataToGraph\0setHVON\0"
    "globalId\0command\0setValveON\0setProtectON\0"
    "shipStation\0updateStationFruInfo\0id\0"
    "KTPN\0KTSERIALPN\0LPN\0GUNOFFPRESSURE\0"
    "PO\0SUPPLIERTESTDATE\0ReceivedDate\0"
    "ShippedDate\0updateStationSettings\0"
    "name\0eguntype\0thresholdDownP\0thresholdUpP\0"
    "thresholdDownI\0thresholdUpI\0pumpType\0"
    "pumpAddr\0pumpCh\0SDCSAddr\0SDCSCh\0"
    "initializeStationModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocalDatabaseInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
       9,    2,   69,    2, 0x0a /* Public */,
      12,    2,   74,    2, 0x0a /* Public */,
      13,    2,   79,    2, 0x0a /* Public */,
      14,    1,   84,    2, 0x0a /* Public */,
      15,    9,   87,    2, 0x0a /* Public */,
      25,   12,  106,    2, 0x0a /* Public */,
      37,    0,  131,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::QString,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,   17,   18,   19,   20,   21,   22,   23,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QByteArray, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   26,   27,   28,   29,   30,   31,   32,   33,   34,   35,   36,
    QMetaType::Bool,

       0        // eod
};

void LocalDatabaseInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LocalDatabaseInterface *_t = static_cast<LocalDatabaseInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initializeDataToGraph((*reinterpret_cast< QAbstractSeries*(*)>(_a[1])),(*reinterpret_cast< QAbstractAxis*(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->updateDataToGraph((*reinterpret_cast< QAbstractSeries*(*)>(_a[1]))); break;
        case 2: _t->setHVON((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 3: _t->setValveON((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 4: _t->setProtectON((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 5: _t->shipStation((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 6: _t->updateStationFruInfo((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3])),(*reinterpret_cast< const QByteArray(*)>(_a[4])),(*reinterpret_cast< const QByteArray(*)>(_a[5])),(*reinterpret_cast< const QByteArray(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9]))); break;
        case 7: _t->updateStationSettings((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4])),(*reinterpret_cast< const double(*)>(_a[5])),(*reinterpret_cast< const double(*)>(_a[6])),(*reinterpret_cast< const double(*)>(_a[7])),(*reinterpret_cast< const int(*)>(_a[8])),(*reinterpret_cast< const int(*)>(_a[9])),(*reinterpret_cast< const int(*)>(_a[10])),(*reinterpret_cast< const int(*)>(_a[11])),(*reinterpret_cast< const int(*)>(_a[12]))); break;
        case 8: { bool _r = _t->initializeStationModel();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractAxis* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSeries* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSeries* >(); break;
            }
            break;
        }
    }
}

const QMetaObject LocalDatabaseInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LocalDatabaseInterface.data,
      qt_meta_data_LocalDatabaseInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LocalDatabaseInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocalDatabaseInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LocalDatabaseInterface.stringdata0))
        return static_cast<void*>(const_cast< LocalDatabaseInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int LocalDatabaseInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
