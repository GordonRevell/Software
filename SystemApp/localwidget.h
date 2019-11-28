#ifndef LOCALWIDGET_H
#define LOCALWIDGET_H

#include "widgettype.h"

#include <QDockWidget>

#include <iostream>
#include <memory>

class LocalWidget : public QDockWidget
{
    Q_OBJECT

public:
    LocalWidget(QWidget *parent = nullptr);
    LocalWidget(const LocalWidget& w);

    template<typename T> static bool registerType(QString name)
    {
        auto c = name.toStdString();
        int id = qRegisterMetaType<T>(c.c_str());

        s_types.push_back(new WidgetType(name, id));

        return (id != QMetaType::UnknownType);
    }

    static LocalWidget* createLocalWidget(WidgetType* type)
    {
        LocalWidget* dock = createWidget(type->name());

        if(dock)
        {
            QString objectName = createObjectName(type->name());

            std::cout << "Create: " << type->name().toStdString() << " " << objectName.toStdString() << std::endl;

            dock->setObjectName(objectName);

            s_widgets.push_back(dock);

            dock->setType(type);
        }

        return dock;
    }

    static LocalWidget* createLocalWidget(WidgetType* type, QString objectName)
    {
        LocalWidget* dock = createWidget(type->name());

        if(dock)
        {
            std::cout << "Create: " << type->name().toStdString() << " " << objectName.toStdString() << std::endl;

            dock->setObjectName(objectName);

            s_widgets.push_back(dock);

            dock->setType(type);
        }

        return dock;
    }

    static QByteArray save();
    static bool restore(const QByteArray& widgets, QMainWindow* mainWindow);

    static std::vector<WidgetType*> widgetTypes();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    static inline std::vector<LocalWidget*> s_widgets;
    static inline std::vector<WidgetType*> s_types;

    WidgetType* _type;

    static LocalWidget* createWidget(const QString& name);
    static QString createObjectName(const QString& typeName);

    WidgetType* type() const;
    void setType(WidgetType* type);
};

#endif // LOCALWIDGET_H
