#include "stationobject.h"


StationObject::StationObject()
{

}

StationObject::StationObject(const int &id, const QString &name, const double &top, const double &left, const QByteArray &RFID)
    :m_id(id), m_stationName(name), m_top(top), m_left(left), m_RFID(RFID)
{
}

StationObject::StationObject(const int &id, const QString &name, const double &top, const double &left, const QByteArray &RFID, const QByteArray &KTPN, const QByteArray &KTSERIALPN, const QByteArray &LPN, const QByteArray &GUNOFFPRESSURE, const QByteArray &PO, const QString &SUPPLIERTESTDATE, const QString &ReceivedDate, const QString &ShippedDate)
    :m_id(id), m_stationName(name), m_top(top), m_left(left), m_RFID(RFID), m_KTPN(KTPN), m_KTSERIALPN(KTSERIALPN), m_LPN(LPN), m_GUNOFFPRESSURE(GUNOFFPRESSURE), m_PONumber(PO), m_SUPPLIERTESTDATE(SUPPLIERTESTDATE), m_ReceivedDate(ReceivedDate), m_ShippedDate(ShippedDate)
{

}

int StationObject::stationId() const
{
    return m_id;
}

void StationObject::setStationId(const int &id)
{
    if(id != m_id)
    {
        m_id = id;

    }
}

QString StationObject::stationName() const
{
    return m_stationName;
}

void StationObject::setStationName(const QString &name)
{
    if(name != m_stationName)
    {
        m_stationName = name;

    }
}

double StationObject::top() const
{
    return m_top;
}

void StationObject::setTop(const double &top)
{
    if(top != m_top)
    {
        m_top = top;

    }
}

double StationObject::left() const
{
    return m_left;
}

void StationObject::setLeft(const double &left)
{
    if(left != m_left)
    {
        m_left = left;
    }
}

QByteArray StationObject::RFID() const
{
    return m_RFID;
}

void StationObject::setRFID(const QByteArray &RFID)
{
    if(RFID != m_RFID)
    {
        m_RFID = RFID;
    }
}


QByteArray StationObject::KTPN()const
{
    return m_KTPN;
}

void StationObject::setKTPN(const QByteArray &KTPN)
{
    if(KTPN!= m_KTPN)
    {
        m_KTPN = KTPN;
    }
}

QByteArray StationObject::KTSERIALPN()const
{
    return m_KTSERIALPN;
}

void StationObject::setKTSERIALPN(const QByteArray &SERIALPN)
{
    if(SERIALPN != m_KTSERIALPN)
    {
        m_KTSERIALPN = SERIALPN;
    }
}

QByteArray StationObject::LPN()const
{
    return m_LPN;
}

void StationObject::setLPN(const QByteArray &LPN)
{
    if(LPN != m_LPN)
    {
        m_LPN = LPN;
    }
}

QByteArray StationObject::GUNOFFPRESSURE()const
{
    return m_GUNOFFPRESSURE;
}

void StationObject::setGUNOFFPRESSURE(const QByteArray &pressure)
{
   if(pressure != m_GUNOFFPRESSURE)
   {
       m_GUNOFFPRESSURE = pressure;
   }
}

QByteArray StationObject::PO()const
{
    return m_PONumber;
}

void StationObject::setPO(const QByteArray &PO)
{
    if (PO != m_PONumber)
    {
        m_PONumber = PO;
    }
}

QString StationObject::SUPPLIERTESTDATE()const
{
    return m_SUPPLIERTESTDATE;
}

void StationObject::setSUPPLIERTESTDATE(const QString &date)
{
    m_SUPPLIERTESTDATE = date;
}

QString StationObject::ReceivedDate()const
{
    return m_ReceivedDate;
}

void StationObject::setReceivedDate(const QString &date)
{
    m_ReceivedDate = date;
}

QString StationObject::ShippedDate() const
{
    return m_ShippedDate;
}

void StationObject::setShippedDate(const QString &date)
{
    m_ShippedDate = date;
}
