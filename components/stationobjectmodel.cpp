#include "stationobjectmodel.h"


StationObjectModel::StationObjectModel(QObject *parent): QAbstractListModel(parent)
{

}

void StationObjectModel::addStation(const StationObject &station)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
//    StationObject tmpStation = new StationObject(station);

//    m_stationObjectList.append(*tmpStation);
    m_stationObjectHash.insert(station.stationId(), station);
    endInsertRows();
}

int StationObjectModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
//    return m_stationObjectList.count();
    return m_stationObjectHash.count();
}

QVariant StationObjectModel::data(const QModelIndex &index, int role) const
{
//    if(index.row() < 0 || index.row() >= m_stationObjectList.count())
    if(index.row() < 0 || index.row() >= m_stationObjectHash.count())
        return QVariant();

//     StationObject station = m_stationObjectList[index.row()];

    StationObject station = m_stationObjectHash.values()[index.row()];
    if(role == GlobalId) return station.stationId();
    else if (role == stationName) return station.stationName();
    else if (role == top) return station.top();
    else if (role == left) return station.left();
    else if (role == RFID) return station.RFID();
    else if (role == KTPN) return station.KTPN();
    else if (role == KTSERIALPN) return station.KTSERIALPN();
    else if (role == LPN) return station.LPN();
    else if (role == GUNOFFPRESSURE) return station.GUNOFFPRESSURE();
    else if (role == PO) return station.PO();
    else if (role == SUPPLIERTESTDATE) return station.SUPPLIERTESTDATE();
    else if (role == ReceviedDate) return station.ReceivedDate();
    else if (role == ShippedDate) return station.ShippedDate();

    return QVariant();
}

QHash<int, QByteArray> StationObjectModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[GlobalId] = "GlobalId";
    roles[stationName] = "stationName";
    roles[top] = "m_top";
    roles[left] = "m_left";
    roles[RFID] = "RFID";
    roles[KTPN] = "KTPN";
    roles[KTSERIALPN] = "KTSERIALPN";
    roles[LPN] = "LPN";
    roles[GUNOFFPRESSURE] ="GUNOFFPRESSURE";
    roles[PO] = "PO";
    roles[SUPPLIERTESTDATE] = "SUPPLIERTESTDATE";
    roles[ReceviedDate] = "ReceviedDate";
    roles[ShippedDate] = "ShippedDate";
    return roles;
}
