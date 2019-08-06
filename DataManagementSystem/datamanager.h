#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>

#include <vector>
#include <thread>
#include <future>
#include <map>

#include "datamanagementsystem_global.h"
#include "gismo.h"

class DATAMANAGEMENTSYSTEMSHARED_EXPORT DataManager : public QObject
{
    Q_OBJECT

public:
    DataManager(QObject* parent = nullptr);
    virtual ~DataManager();

    bool addGismo(QString path, QString typeName);

    static bool registerType(std::string typeName, Gismo* (*funcCreate)(QString, Gismo* parent, QObject*));

private:
    static std::map<std::string, Gismo* (*)(QString, Gismo*, QObject*)> s_types;

    std::vector<Gismo*>* _gismos;
    std::thread* _updateThread;

    std::promise<void> exitSignal;
    std::future<void> futureObj = exitSignal.get_future();

    std::chrono::time_point<std::chrono::high_resolution_clock> _time;

    void updateThreadFunction(std::future<void> futureObj);
    Gismo* createGismo(QString typeName, QString& name, Gismo* parent);
};

#endif // DATAMANAGER_H
