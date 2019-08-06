#include "keypresswait.h"

#include <iostream>

#include <QCoreApplication>

#include "datamanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Application start" << std::endl;

    KeypressWait wait(a);
    DataManager* manager = new DataManager();

    manager->addGismo("Dynamometer", "Gismo");
    manager->addGismo("Data Acquistion", "Gismo");

    int result = a.exec();

    delete manager;

    return result;
}
