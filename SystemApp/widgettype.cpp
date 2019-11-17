#include "widgettype.h"

WidgetType::WidgetType(QString& name, int id, QObject* parent) : QObject(parent), _name(name), _id(id)
{
}

WidgetType::~WidgetType()
{
}

QString WidgetType::name() const
{
    return _name;
}
