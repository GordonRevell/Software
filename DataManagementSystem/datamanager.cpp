#include "datamanager.h"

#include <iostream>
#include <chrono>

DataManager::DataManager(QObject* parent) : QObject(parent)
{
    _gismos = new std::vector<Gismo*>();
    _updateThread = new std::thread(&DataManager::updateThreadFunction, this, std::move(futureObj));
}

DataManager::~DataManager()
{
    if(_updateThread)
    {
        exitSignal.set_value();

        _updateThread->join();

        delete _updateThread;
    }

    if(_gismos)
    {
        _gismos->clear();

        delete _gismos;
    }
}

void DataManager::updateThreadFunction(std::future<void> futureObj)
{
    std::chrono::time_point<std::chrono::high_resolution_clock> time;

    std::cout << "Thread start" << std::endl;

    do
    {
        time = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = std::chrono::duration_cast<std::chrono::duration<double>>(time - _time);

        std::cout << "Thread update: " << diff.count() << " s" << std::endl;

        _time = time;
    }
    while(futureObj.wait_until(time + std::chrono::milliseconds(1000)) == std::future_status::timeout);

    std::cout << "Thread end" << std::endl;
}
