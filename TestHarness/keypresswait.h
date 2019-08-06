#ifndef KEYPRESSWAIT_H
#define KEYPRESSWAIT_H

#include <iostream>
#include <thread>

#include <QObject>
#include <QCoreApplication>

class KeypressWait : public QObject
{
    Q_OBJECT
public:
    explicit KeypressWait(QCoreApplication& application, QObject *parent = nullptr);
    virtual ~KeypressWait();

signals:
    void keypressed();

public slots:

private:
    std::thread* t;
};

#endif // KEYPRESSWAIT_H
