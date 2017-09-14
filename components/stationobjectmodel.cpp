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
    else if (role == egunType)  return station.egunType();
    else if (role == stationState) return station.stationState();
    else if (role == HVON) return station.HVON();
    else if (role == ValveON) return station.ValveON();
    else if (role == ProtectON ) return station.ProtectON();

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
    roles[egunType] = "egunType";
    roles[stationState] = "stationState";
    roles[HVON] = "HVON";
    roles[ValveON] = "ValveON";
    roles[ProtectON] = "ProtectOn";

    return roles;
}

void StationObjectModel::updateStation(const int &id, const QString &name,const QByteArray &egunType, const QByteArray &KTPN, const QByteArray &KTSERIALPN, const QByteArray &LPN, const QByteArray &GUNOFFPRESSURE, const QByteArray &PO, const QString &SUPPLIERTESTDATE, const QString &ReceivedDate, const QString &ShippedDate)
{
    StationObject tmpStation = m_stationObjectHash.value(id);
    tmpStation.setStationName(name);
    tmpStation.setEgunType(egunType);
    tmpStation.setKTPN(KTPN);
    tmpStation.setKTSERIALPN(KTSERIALPN);
    tmpStation.setLPN(LPN);
    tmpStation.setGUNOFFPRESSURE(GUNOFFPRESSURE);
    tmpStation.setPO(PO);
    tmpStation.setSUPPLIERTESTDATE(SUPPLIERTESTDATE);
    tmpStation.setReceivedDate(ReceivedDate);
    tmpStation.setShippedDate(ShippedDate);

    m_stationObjectHash.insert(id, tmpStation);
}

void StationObjectModel::updateStationState(const int &id,  const QByteArray &state)
{
    StationObject tmpStation = m_stationObjectHash.value(id);
    tmpStation.setStationState(state);

    m_stationObjectHash.insert(id, tmpStation);
}


void StationObjectModel::updateStationHVON(const int &id, const bool &command)
{
    StationObject tmpStation = m_stationObjectHash.value(id);
    tmpStation.setHVON(command);

    m_stationObjectHash.insert(id, tmpStation);
}

void StationObjectModel::updateStationValveON(const int &id, const bool &command)
{
    StationObject tmpStation = m_stationObjectHash.value(id);
    tmpStation.setValveON(command);

    m_stationObjectHash.insert(id, tmpStation);
}

void StationObjectModel::updateStationProtectON(const int &id, const bool &command)
{
    StationObject tmpStation = m_stationObjectHash.value(id);
    tmpStation.setProtectON(command);

    m_stationObjectHash.insert(id, tmpStation);
}

