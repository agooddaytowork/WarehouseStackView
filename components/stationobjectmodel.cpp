#include "stationobjectmodel.h"


StationObjectModel::StationObjectModel(QObject *parent): QAbstractListModel(parent)
{

}

void StationObjectModel::addStation(const StationObject &station)
{
    QModelIndex anIndex = createIndex(rowCount(),0);

    beginInsertRows(anIndex, rowCount(), rowCount());
    m_stationModelIndexHash.insert(station.stationId(), anIndex);
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
    else if (role == thresholdDownP) return station.thresholdDownP();
    else if (role == thresholdUpP) return station.thresholdUpP();
    else if (role == thresholdDownI) return station.thresholdDownI();
    else if (role == thresholdUpI) return station.thresholdUpI();
    else if (role == pumpType) return station.pumpType();
    else if (role == pumpAddr) return station.pumpAddr();
    else if (role == pumpCh)    return station.pumpCh();
    else if (role == SDCSAddr) return station.SDCSAddr();
    else if (role == SDCSCh)    return station.SDCSCh();


    return QVariant();
}

bool StationObjectModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //    if(index.row() < 0 || index.row() >= m_stationObjectList.count())
        if(index.row() < 0 || index.row() >= m_stationObjectHash.count())
            return false;

        StationObject station = m_stationObjectHash.values()[index.row()];

        if (role == stationName)  station.setStationName(value.toString());
        else if (role == top)  station.setTop(value.toDouble());
        else if (role == left)  station.setLeft(value.toDouble());
        else if (role == RFID)  station.setRFID(value.toByteArray());
        else if (role == KTPN)  station.setKTPN(value.toByteArray());
        else if (role == KTSERIALPN)  station.setKTSERIALPN(value.toByteArray());
        else if (role == LPN)  station.setLPN(value.toByteArray());
        else if (role == GUNOFFPRESSURE)  station.setGUNOFFPRESSURE(value.toByteArray());
        else if (role == PO)  station.setPO(value.toByteArray());
        else if (role == SUPPLIERTESTDATE)  station.setSUPPLIERTESTDATE(value.toString());
        else if (role == ReceviedDate)  station.setReceivedDate(value.toString());
        else if (role == ShippedDate)  station.setShippedDate(value.toString());
        else if (role == egunType)   station.setEgunType(value.toByteArray());
        else if (role == stationState)  station.setStationState(value.toByteArray());
        else if (role == HVON)  station.setHVON(value.toBool());
        else if (role == ValveON)  station.setValveON(value.toBool());
        else if (role == ProtectON )  station.setProtectON(value.toBool());
        else if (role == thresholdDownP)  station.setThresholdDownP(value.toDouble());
        else if (role == thresholdUpP)  station.setThresHoldUpP(value.toDouble());
        else if (role == thresholdDownI)  station.setThresholdDownI(value.toDouble());
        else if (role == thresholdUpI)  station.setThresholdUpI(value.toDouble());
        else if (role == pumpType)  station.setPumpType(value.toInt());
        else if (role == pumpAddr)  station.setPumpAddr(value.toInt());
        else if (role == pumpCh)     station.setPumpCh(value.toInt());
        else if (role == SDCSAddr)  station.setSDCSAddr(value.toInt());
        else if (role == SDCSCh)     station.setSDCSCh(value.toInt());

        m_stationObjectHash.insert(station.stationId(), station);

        dataChanged(index, index, QVector<int>() <<role);
        return true;
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
    roles[thresholdDownP] = "thresholdDownP";
    roles[thresholdUpP] = "thresholdUpP";
    roles[thresholdDownI]= "thresholdDownI";
    roles[thresholdUpI] = "thresholdUpI";
    roles[pumpType] = "pumpType";
    roles[pumpAddr] = "pumpAddr";
    roles[pumpCh] = "pumpCh";
    roles[SDCSAddr] ="SDCSAddr";
    roles[SDCSCh] = "SDCSCh";

    return roles;
}

void StationObjectModel::updateStationFruInfo(const int &id, const QByteArray &KTPN, const QByteArray &KTSERIALPN, const QByteArray &LPN, const QByteArray &GUNOFFPRESSURE, const QByteArray &PO, const QString &SUPPLIERTESTDATE, const QString &ReceivedDate, const QString &ShippedDate)
{
    StationObject tmpStation = m_stationObjectHash.value(id);
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

void StationObjectModel::updateStationSettings(const int &index, const int &id, const QString &name, const QByteArray &eguntype, const double &thresholdDownPvalue, const double &thresholdUpPvalue, const double &thresholdDownIvalue, const double &thresholdUpIvalue, const int &pumpTypevalue, const int &pumpAddrvalue, const int &pumpChvalue, const int &SDCSAddrValue, const int &SDCSChValue)
{
//    StationObject tmpStation = m_stationObjectHash.value(id);
//    tmpStation.setStationName(name);
//    tmpStation.setEgunType(eguntype);
//    tmpStation.setThresholdDownP(thresholdDownP);
//    tmpStation.setThresHoldUpP(thresholdUpP);
//    tmpStation.setThresholdDownI(thresholdDownI);
//    tmpStation.setThresholdUpI(thresholdUpI);
//    tmpStation.setPumpType(pumpType);
//    tmpStation.setPumpAddr(pumpAddr);
//    tmpStation.setPumpCh(pumpCh);
//    tmpStation.setSDCSAddr(SDCSAddr);
//    tmpStation.setSDCSCh(SDCSCh);

//    m_stationObjectHash.insert(id, tmpStation);

    QModelIndex anIndex = this ->index(index);

    setData(anIndex,name, stationName);
    setData(anIndex,eguntype, egunType);
    setData(anIndex,thresholdDownPvalue, thresholdDownP);
    setData(anIndex, thresholdUpPvalue, thresholdUpP);
    setData(anIndex, thresholdDownIvalue, thresholdDownI);
    setData(anIndex, thresholdUpIvalue, thresholdUpI);
    setData(anIndex, pumpTypevalue, pumpType);
    setData(anIndex, pumpChvalue, pumpCh);
    setData(anIndex, pumpAddrvalue, pumpAddr);
    setData(anIndex, SDCSAddrValue, SDCSAddr);
    setData(anIndex, SDCSChValue, SDCSCh);
;





}

StationObject StationObjectModel::getStation(const int &id)
{
    return m_stationObjectHash.value(id);
}
