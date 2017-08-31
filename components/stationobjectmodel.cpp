#include "stationobjectmodel.h"


StationObjectModel::StationObjectModel(QObject *parent): QAbstractListModel(parent)
{

}

void StationObjectModel::addStation(const StationObject &station)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    StationObject *tmpStation = new StationObject(station);
    m_stationObjectList.append(*tmpStation);
    endInsertRows();
}

int StationObjectModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_stationObjectList.count();
}

QVariant StationObjectModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_stationObjectList.count())
        return QVariant();

     StationObject station = m_stationObjectList[index.row()];

    if(role == GlobalId) return station.stationId();
    else if (role == stationName) return station.stationName();
    else if (role == top) return station.top();
    else if (role == left) return station.left();
    else if (role == RFID) return station.RFID();

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

    return roles;
}
