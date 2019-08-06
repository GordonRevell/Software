#include "datamanager.h"

#include <iostream>
#include <chrono>

std::map<std::string, Gismo* (*)(QString, Gismo*, QObject*)> DataManager::s_types;

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

bool DataManager::addGismo(QString path, QString typeName)
{
    bool result = false;
    QStringList pathTokens = path.split(QRegExp("/"));

    if(pathTokens.count() > 0)
    {
        std::cout << "AddGismo " << path.toStdString() << std::endl;

        int nameIndex = pathTokens.count() - 1;
        QString parentPath = "";
        QString name = pathTokens[nameIndex];

        for(int i = 0; i < nameIndex; i++)
        {
            parentPath += "/" + pathTokens[i];
        }

        std::cout << "Parent: " << parentPath.toStdString() << std::endl;

        Gismo* parent = nullptr;

        for(std::vector<Gismo*>::size_type i = 0; i < _gismos->size(); i++)
        {
            Gismo* g = _gismos->at(i);

            if(g)
            {
                if(g->path() == parentPath)
                {
                    parent = g;
                    break;
                }
            }
        }

        Gismo* g = createGismo(typeName, name, parent);

        if(g)
        {
            _gismos->push_back(g);

            result = true;
        }
    }
    return result;
}

bool DataManager::registerType(std::string typeName, Gismo* (*funcCreate)(QString, Gismo* parent, QObject*))
{
    auto result = false;

    if(s_types.find(typeName) == s_types.end())
    {
        s_types[typeName] = funcCreate;
        result = true;
    }

    return result;
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

Gismo* DataManager::createGismo(QString typeName, QString& name, Gismo* parent)
{
    Gismo* result = nullptr;

    if(s_types.find(typeName.toStdString()) != s_types.end())
    {
        result = s_types[typeName.toStdString()](name, parent, this);
    }

    return result;
}
