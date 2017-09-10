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
    Q_INVOKABLE void updateDataToGraph(QAbstractSeries *series);
    Q_INVOKABLE void setHVON(const int & globalId, const bool command);
    Q_INVOKABLE void setValveON(const int & globalId, const bool command);
    Q_INVOKABLE void shipStation(const int & globalId);
//    Q_INVOKABLE void updateStation(const int &globalID, const QByteArray &LPN);

private:
    bool initializeStationModel();
    QString m_dbUsername;
    QString m_dbPassword;
    QString m_dbName;

    QSqlDatabase localDb;


};

#endif // LOCALDATABASEINTERFACE_H
