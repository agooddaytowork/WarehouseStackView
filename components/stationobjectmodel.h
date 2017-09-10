#ifndef STATIONOBJECTMODEL_H
#define STATIONOBJECTMODEL_H

#include <QtWidgets/QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include "anlogger.h"
#include <QAbstractListModel>
#include "stationobject.h"

class StationObjectModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum StationObjectRoles
    {
        GlobalId = Qt::UserRole + 1,
        stationName,
        top,
        left,
        RFID,
        KTPN,
        KTSERIALPN,
        LPN,
        GUNOFFPRESSURE,
        PO,
        SUPPLIERTESTDATE,
        ReceviedDate,
        ShippedDate

    };

    StationObjectModel(QObject *parent =0);

    void addStation(const StationObject &station);
    void updateStation(const int &id, const QString &name
                       , const QByteArray &KTPN, const QByteArray &KTSERIALPN, const QByteArray &LPN, const QByteArray &GUNOFFPRESSURE, const QByteArray &PO
                       , const QString &SUPPLIERTESTDATE, const QString &ReceivedDate, const QString &ShippedDate);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QHash<int, StationObject> m_stationObjectHash;
    QList<StationObject> m_stationObjectList;

};



#endif // STATIONOBJECTMODEL_H
