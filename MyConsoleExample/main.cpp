#include <iostream>
#include <thread>

#include <QCoreApplication>

#include "keypresswait.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    gordon::KeypressWait wait(a);

    std::cout << "Hello World" << std::endl;

    return a.exec();
}
