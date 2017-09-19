#ifndef LOCALDATABASEINTERFACE_H
#define LOCALDATABASEINTERFACE_H


#include <QtSql/QSqlDatabase>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QAbstractAxis>
#include <QtSql/QSqlQuery>
#include "stationobjectmodel.h"


QT_CHARTS_USE_NAMESPACE

class LocalDatabaseInterface : public QObject
{

    Q_OBJECT

public:
    explicit LocalDatabaseInterface(const QString &dbUsername, const QString &dbPassword, const QString &dbName, QObject *parent = 0);
    void start();
    void stop();
    StationObjectModel m_stationModel;
public slots:
    Q_INVOKABLE void initializeDataToGraph(QAbstractSeries *series, QAbstractAxis *axis,const QString &mRFID);
    Q_INVOKABLE void updateDataToGraph(QAbstractSeries *series, const QDateTime &firstTimePoint, const QDateTime &lastTimePoint, const QByteArray &RFID);
    Q_INVOKABLE void setHVON(const int & globalId, const bool &command);
    Q_INVOKABLE void setValveON(const int & globalId, const bool &command);
    Q_INVOKABLE void setProtectON(const int &globalId, const bool &command);
    Q_INVOKABLE void shipStation(const int & globalId);
    Q_INVOKABLE void updateStationFruInfo(const int &id
                                          , const QByteArray &KTPN, const QByteArray &KTSERIALPN, const QByteArray &LPN, const QByteArray &GUNOFFPRESSURE, const QByteArray &PO
                                          , const QString &SUPPLIERTESTDATE, const QString &ReceivedDate, const QString &ShippedDate);

    Q_INVOKABLE  void updateStationSettings(const int &index, const int &id, const QString &name, const QByteArray &eguntype, const double &thresholdDownP, const double &thresholdUpP
                                            ,const double &thresholdDownI, const double &thresholdUpI, const int &pumpType, const int &pumpAddr, const int &pumpCh
                                            ,const int &SDCSAddr, const int &SDCSCh);


    Q_INVOKABLE void updateStationPositions(const int &id);
    bool initializeStationModel();

    void updateStationSettingToDatabaseSlot(const int &id);
signals:
    void updateStationSettingToDatabaseSignal(const int &id);
private:
    QString m_dbUsername;
    QString m_dbPassword;
    QString m_dbName;

    QSqlDatabase localDb;


};

#endif // LOCALDATABASEINTERFACE_H
