#include <QtWidgets/QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include "components/localdatabaseinterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif

    LocalDatabaseInterface localDBInterface("root","159753","userspice");
//    StationObjectModel aModel;
//    aModel.addStation(StationObject(5,"S1",0,0,"FA1239"));
    QQmlContext *thisContext = engine.rootContext();
    thisContext->setContextProperty("myStationModel", &localDBInterface.m_stationModel);
//    thisContext->setContextProperty("myStationModel", &aModel);
    thisContext->setContextProperty("LocalDb", &localDBInterface);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
