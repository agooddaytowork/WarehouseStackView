#ifndef STATIONOBJECT_H
#define STATIONOBJECT_H



#include <QtWidgets/QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include "anlogger.h"
#include <QAbstractListModel>

class StationObject
{


public:
     StationObject();

     StationObject(const int &id, const QString &name, const double &top, const double &left, const QByteArray &RFID);

    int stationId() const;
    void setStationId(const int &id);

    QString stationName() const;
    void setStationName(const QString &name);

    double top() const;
    void setTop(const double &top);

    double left() const;
    void setLeft(const double &left);

    QByteArray RFID() const;
    void setRFID(const QByteArray &RFID);

private:
    int m_id;
    QString m_stationName;
    double m_top;
    double m_left;
    QByteArray m_RFID;
};

#endif // STATIONOBJECT_H
