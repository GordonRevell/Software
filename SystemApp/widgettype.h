#ifndef WIDGETTYPE_H
#define WIDGETTYPE_H

#include <QObject>

class WidgetType : public QObject
{
    Q_OBJECT

public:
    explicit WidgetType(QString& name, int id, QObject *parent = nullptr);

    ~WidgetType();

    QString name() const;

signals:

public slots:

private:
    QString _name;
    int _id;
};

#endif // WIDGETTYPE_H
