#include "stationobject.h"


StationObject::StationObject()
{

}

StationObject::StationObject(const int &id, const QString &name, const double &top, const double &left, const QByteArray &RFID)
    :m_id(id), m_stationName(name), m_top(top), m_left(left), m_RFID(RFID)
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

