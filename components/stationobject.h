#ifndef STATIONOBJECT_H
#define STATIONOBJECT_H



#include <QtWidgets/QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include "anlogger.h"
#include <QAbstractListModel>
#include <QDateTime>

class StationObject
{


public:
     StationObject();

     explicit StationObject(const int &id, const QString &name, const double &top, const double &left, const QByteArray &RFID);
     explicit StationObject(const int &id, const QString &name, const double &top, const double &left, const QByteArray &RFID
                            , const QByteArray &KTPN, const QByteArray &KTSERIALPN, const QByteArray &LPN, const QByteArray &GUNOFFPRESSURE, const QByteArray &PO
                            , const QString &SUPPLIERTESTDATE, const QString &ReceivedDate, const QString &ShippedDate);

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

    QByteArray KTPN() const;
    void setKTPN(const QByteArray &KTPN);

    QByteArray KTSERIALPN() const;
    void setKTSERIALPN(const QByteArray &SERIALPN);

    QByteArray LPN() const;
    void setLPN(const QByteArray &LPN);

    QByteArray GUNOFFPRESSURE() const;
    void setGUNOFFPRESSURE(const QByteArray &pressure);

    QByteArray PO() const;
    void setPO(const QByteArray &PO);

    QString SUPPLIERTESTDATE() const;
    void setSUPPLIERTESTDATE(const QString &date);

    QString ReceivedDate() const;
    void setReceivedDate(const QString &date);

    QString ShippedDate() const;
    void setShippedDate(const QString &date);


private:
    int m_id;
    QString m_stationName;

    double m_top;
    double m_left;
    QByteArray m_RFID;
    QByteArray m_KTPN;
    QByteArray m_KTSERIALPN;
    QByteArray m_LPN;
    QByteArray m_GUNOFFPRESSURE;
    QByteArray m_PONumber;
    QString  m_SUPPLIERTESTDATE;
    QString  m_ReceivedDate;
    QString  m_ShippedDate;

};

#endif // STATIONOBJECT_H
