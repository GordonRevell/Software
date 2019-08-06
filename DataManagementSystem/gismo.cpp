#include "gismo.h"
#include "datamanager.h"

bool Gismo::s_registered = DataManager::registerType("Gismo", &Gismo::CreateMethod);

Gismo::Gismo(QString& name, Gismo* parent, QObject* gismoCollection) : QObject(gismoCollection)
{
    _name = name;
    _parent = parent;
}

Gismo::~Gismo()
{
}

Gismo* Gismo::parent() const
{
    return _parent;
}

void Gismo::setParent(Gismo* parent)
{
    _parent = parent;
}

QString Gismo::name() const
{
    return _name;
}

void Gismo::setName(const QString &name)
{
    _name = name;
}

QString Gismo::path()
{
    return _parent ? _parent->path() + _name : _name;
}
