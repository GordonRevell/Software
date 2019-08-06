#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>

#include <vector>
#include <thread>
#include <future>

#include "gismo.h"

class DataManager : public QObject
{
    Q_OBJECT

public:
    DataManager(QObject* parent = nullptr);
    virtual ~DataManager();

private:
    std::vector<Gismo*>* _gismos;
    std::thread* _updateThread;

    std::promise<void> exitSignal;
    std::future<void> futureObj = exitSignal.get_future();

    std::chrono::time_point<std::chrono::high_resolution_clock> _time;

    void updateThreadFunction(std::future<void> futureObj);
};

#endif // DATAMANAGER_H
