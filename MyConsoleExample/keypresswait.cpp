#include "keypresswait.h"

namespace gordon
{
    KeypressWait::KeypressWait(QCoreApplication& application, QObject *parent) : QObject(parent)
    {
        connect(this, &KeypressWait::keypressed, &application, &QCoreApplication::quit);

        t = new std::thread([this]()
        {
            std::string buffer;

            std::cout << "Press <Enter> key to exit..." << std::endl;
            std::getline(std::cin, buffer);

            emit keypressed();
        });
    }

    KeypressWait::~KeypressWait()
    {
        delete t;
    }
}
