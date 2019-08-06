#ifndef GISMO_H
#define GISMO_H

#include <QObject>

class Gismo : public QObject
{
    Q_OBJECT
public:
    explicit Gismo(QObject *parent = nullptr);

signals:

public slots:
};

#endif // GISMO_H
