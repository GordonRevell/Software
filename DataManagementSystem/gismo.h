#ifndef GISMO_H
#define GISMO_H

#include <QObject>

#include <memory>
#include <iostream>

#include "datamanagementsystem_global.h"

class DATAMANAGEMENTSYSTEMSHARED_EXPORT Gismo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Gismo* parent READ parent WRITE setParent)
    Q_PROPERTY(QString name READ name WRITE setName)

public:
    explicit Gismo(QString& name, Gismo* parent, QObject* gismoCollection = nullptr);
    virtual ~Gismo();

    Gismo* parent() const;
    void setParent(Gismo* parent);

    QString name() const;
    void setName(const QString &name);

    QString path();

    void update()
    {
    }

    static Gismo* CreateMethod(QString name, Gismo* parent, QObject* gismoCollection)
    {
        std::cout << "Gismo created" << std::endl;

        return new Gismo(name, parent, gismoCollection);
    }

signals:

public slots:

private:
    static bool s_registered;

    Gismo* _parent = nullptr;
    QString _name = "";
};

#endif // GISMO_H
