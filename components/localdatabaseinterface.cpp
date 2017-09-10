#include "localdatabaseinterface.h"
#include <QRegExp>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>

QT_CHARTS_USE_NAMESPACE
#define LocalDatabaseInterfaceDebuggerEnabled 1


LocalDatabaseInterface::LocalDatabaseInterface(const QString &dbUsername, const QString &dbPassword, const QString &dbName, QObject *parent):
    QObject(parent), m_dbUsername(dbUsername), m_dbPassword(dbPassword), m_dbName(dbName)
{
    // Register MetaType for other slots from QML
//    qRegisterMetaType<QAbstractSeries*>();
//    qRegisterMetaType<QAbstractAxis*>();


    // Configure local data base
    anIf(LocalDatabaseInterfaceDebuggerEnabled, anAck("Database info: "
                                                      << localDb.databaseName() << "-"
                                                      << localDb.userName() << "-"
                                                      << localDb.password()));

    localDb = QSqlDatabase::addDatabase("QMYSQL");
    localDb.setHostName("localhost");
    localDb.setPort(3306);
    localDb.setDatabaseName(m_dbName);
    localDb.setUserName(m_dbUsername);
    localDb.setPassword(m_dbPassword);

    // initialize LocaldatabaseHash



    if(localDb.open())
    {
        anIf(LocalDatabaseInterfaceDebuggerEnabled,
            anAck ("Connected to database");
            anTrk ("Initializing LocalDatabaseStationHash"););


      if(initializeStationModel())
      {
            anIf(LocalDatabaseInterfaceDebuggerEnabled, anTrk("Initialization succeed!"));

      }
      else
      {
            anIf(LocalDatabaseInterfaceDebuggerEnabled, anError("Initialization failed!"));
      }


    }
    else
     {
       anIf(LocalDatabaseInterfaceDebuggerEnabled, anTrk("Could not connect to database!"));
     }

}

bool LocalDatabaseInterface::initializeStationModel()
{
    QSqlQuery tmpQuery;

    if(tmpQuery.exec("SELECT id, stationName, top, left_style, RFID FROM stations "))
    {
        anIf(LocalDatabaseInterfaceDebuggerEnabled, anAck("Query succeeded: SELECT GlobalID, stationName, top, left_style FROM stations"));

        anIf(LocalDatabaseInterfaceDebuggerEnabled,
             anAck("Adding stations to localDatabaseHash"  ));
        while(tmpQuery.next())
        {
            QString tmpTop = tmpQuery.value("top").toString();
            QString tmpLeft = tmpQuery.value("left_style").toString();

            tmpTop = tmpTop.remove((tmpTop.length()-2),2);
            tmpLeft = tmpLeft.remove((tmpLeft.length()-2),2);

            QByteArray aRFID = tmpQuery.value("RFID").toByteArray();
            StationObject aStation(tmpQuery.value("id").toInt(),
                                   tmpQuery.value("stationName").toString(),
                                  tmpTop.toDouble(),
                                   tmpLeft.toDouble(),
                                     aRFID);

               QSqlQuery secondQuery;

               secondQuery.prepare("SELECT*FROM frus WHERE RFID = ? LIMIT 1");
               secondQuery.bindValue(0, aRFID);
               if(secondQuery.exec())
               {
                   anIf(LocalDatabaseInterfaceDebuggerEnabled, anAck("Query succeeded:SELECT * FROM frus WHERE RFID = " + aRFID +" LIMIT 1"));
                    if(secondQuery.next())
                    {
                        aStation.setKTPN(secondQuery.value("PN").toByteArray());
                        aStation.setKTSERIALPN(secondQuery.value("Serial").toByteArray());
                        aStation.setLPN(secondQuery.value("LPN").toByteArray());
                        aStation.setGUNOFFPRESSURE(secondQuery.value("MFGPressure").toByteArray());
                        aStation.setPO(secondQuery.value("PO").toByteArray());
                        aStation.setSUPPLIERTESTDATE(secondQuery.value("TestDate").toDateTime().toString("MM/dd/yy"));
                        aStation.setReceivedDate(secondQuery.value("DateInStock").toDateTime().toString("MM/dd/yy"));
                        aStation.setShippedDate(secondQuery.value("DateShipped").toDateTime().toString("MM/dd/yy"));
                    }
               }
               else
               {
                   anIf(LocalDatabaseInterfaceDebuggerEnabled, anError("Query failed:SELECT * FROM frus WHERE RFID = " + aRFID +" LIMIT 1"));
               }

               m_stationModel.addStation(aStation);
        }
        anIf(LocalDatabaseInterfaceDebuggerEnabled,
             anAck("Finished adding stations to localDatabaseHash; returning"  ));


        return true;
    }

    anIf(LocalDatabaseInterfaceDebuggerEnabled, anError("Query failed: SELECT GlobalID, stationName, top, left_style FROM stations"));

    return false;
}

void LocalDatabaseInterface::start()
{

}

void LocalDatabaseInterface::stop()
{

}

void LocalDatabaseInterface::initializeDataToGraph(QAbstractSeries *series, QAbstractAxis *axis,const QString &mRFID)
{
    QSqlQuery tmpQuery;

    if(tmpQuery.exec("SELECT * FROM (SELECT * FROM "+ mRFID +" ORDER BY Time DESC LIMIT 180) T1 ORDER BY Time ASC"))
    {
        anIf(LocalDatabaseInterfaceDebuggerEnabled, anAck("Query Succeeded: SELECT * FROM (SELECT * FROM "+ mRFID +" ORDER BY Time DESC LIMIT 500) T1 ORDER BY Time ASC"));

        if(series)
        {
            if(axis)
            {
                anIf(LocalDatabaseInterfaceDebuggerEnabled,anAck("series exists"));
                QLineSeries *lineSeries = static_cast<QLineSeries *>(series);
                QDateTimeAxis *xAxis = static_cast<QDateTimeAxis *>(axis);

                lineSeries->clear();

                if(tmpQuery.first())
                {
                    xAxis->setMin(tmpQuery.value("Time").toDateTime());

                }

                QDateTime maxTime;
                anIf(LocalDatabaseInterfaceDebuggerEnabled, anAck("Enter loop to extract data"));
                while(tmpQuery.next())
                {
                    lineSeries->append(tmpQuery.value("Time").toDateTime().toMSecsSinceEpoch(), tmpQuery.value("Pressure").toDouble());

                   maxTime = tmpQuery.value("Time").toDateTime();


                }
                anIf(LocalDatabaseInterfaceDebuggerEnabled, anAck("Finished extracting data"));
                xAxis->setMax(maxTime);
            }

        }
        return;
    }

    anIf(LocalDatabaseInterfaceDebuggerEnabled, anError("Query failed: SELECT * FROM (SELECT * FROM "+ mRFID +" ORDER BY Time DESC LIMIT 500) T1 ORDER BY Time ASC"));

    return;
}

void LocalDatabaseInterface::updateDataToGraph(QAbstractSeries *series)
{

}

void LocalDatabaseInterface::setHVON(const int &globalId, const bool command)
{

}

void LocalDatabaseInterface::setValveON(const int &globalId, const bool command)
{

}

void LocalDatabaseInterface::shipStation(const int &globalId)
{

}


//void LocalDatabaseInterface::updateStation(const int &globalID, const QByteArray &LPN)
//{

//}
