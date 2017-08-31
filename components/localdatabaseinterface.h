#ifndef LOCALDATABASEINTERFACE_H
#define LOCALDATABASEINTERFACE_H


#include <QtSql/QSqlDatabase>
#include <QtCharts/QAbstractSeries>
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
    void initializeDataToGraph(QAbstractSeries *series);
    void updateDataToGraph(QAbstractSeries *series);

private:
    bool initializeStationModel();
    QString m_dbUsername;
    QString m_dbPassword;
    QString m_dbName;

    QSqlDatabase localDb;


};

#endif // LOCALDATABASEINTERFACE_H
