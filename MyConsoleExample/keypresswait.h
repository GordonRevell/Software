#ifndef KEYPRESSWAIT_H
#define KEYPRESSWAIT_H

#include <iostream>
#include <thread>

#include <QObject>
#include <QCoreApplication>

namespace gordon
{
    class KeypressWait : public QObject
    {
        Q_OBJECT
    public:
        explicit KeypressWait(QCoreApplication& application, QObject *parent = nullptr);
        virtual ~KeypressWait();

    signals:
        void keypressed();

    public slots:
    };
}

#endif // KEYPRESSWAIT_H
