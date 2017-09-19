#ifndef GAUGEOBJECTMODEL_H
#define GAUGEOBJECTMODEL_H

#include "anlogger.h"
#include <QAbstractListModel>
#include "gaugeobject.h"

class GaugeObjectModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum GaugeObjectRoles
    {
        GlobalId = Qt::UserRole +1,
        top,
        left,
        SDCSAddr,
        thresholdDownP,
        thresholdUpP
    };
    GaugeObjectModel(QObject *parent =0);
    void addGauge(const GaugeObject &gauge);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

protected:

    QHash<int, QByteArray> roleNames() const;

private:
    QMap<int, GaugeObject> m_GaugeObjectMap;
};

#endif // GAUGEOBJECTMODEL_H
