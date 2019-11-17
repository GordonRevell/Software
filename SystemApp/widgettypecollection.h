#ifndef WIDGETTYPECOLLECTION_H
#define WIDGETTYPECOLLECTION_H

#include "widgettype.h"

#include <functional>

#include <QObject>
#include <QVector>

class WidgetTypeCollection : public QObject
{
    Q_OBJECT

public:
    using ForEachFn = std::function<void(WidgetType*)>;

    explicit WidgetTypeCollection(QObject *parent = nullptr);

    virtual ~WidgetTypeCollection();

    bool add(WidgetType* type);

    QVector<WidgetType*>::iterator begin() noexcept
    {
        return _types.begin();
    }

    QVector<WidgetType*>::const_iterator begin() const noexcept
    {
        return _types.begin();
    }

    QVector<WidgetType*>::iterator end() noexcept
    {
        return _types.end();
    }

    QVector<WidgetType*>::const_iterator end() const noexcept
    {
        return _types.end();
    }

    bool forEach(ForEachFn forEach);
    WidgetType* find(QString typeName);

signals:

public slots:

private:
    QVector<WidgetType*> _types;
};

#endif // WIDGETTYPECOLLECTION_H
