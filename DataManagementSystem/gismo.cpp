#include "gismo.h"

Gismo::Gismo(QObject *parent) : QObject(parent)
{
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
