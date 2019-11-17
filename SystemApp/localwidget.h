#ifndef LOCALWIDGET_H
#define LOCALWIDGET_H

#include "widgettype.h"
#include "widgettypecollection.h"

#include <QDockWidget>

#include <iostream>

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

        if(s_widgetTypes == nullptr)
        {
            s_widgetTypes = new WidgetTypeCollection();
        }

        s_widgetTypes->add(new WidgetType(name, id));

        return (id != QMetaType::UnknownType);
    }

    static LocalWidget* createLocalWidget(WidgetType* type)
    {
        LocalWidget* dock = createWidget(type->name());

        if(dock)
        {
            QString objectName = type->name() + QString::number(s_count++);

            dock->setObjectName(objectName);

            if(s_widgets == nullptr)
            {
                s_widgets = new std::vector<LocalWidget*>();
            }

            s_widgets->push_back(dock);

            dock->setType(type);
        }

        return dock;
    }

    static LocalWidget* createLocalWidget(WidgetType* type, QString objectName)
    {
        LocalWidget* dock = createWidget(type->name());

        if(dock)
        {
            dock->setObjectName(objectName);

            if(s_widgets == nullptr)
            {
                s_widgets = new std::vector<LocalWidget*>();
            }

            s_widgets->push_back(dock);

            dock->setType(type);
        }

        return dock;
    }

    static QByteArray save();
    static bool restore(const QByteArray& widgets);

    static WidgetTypeCollection& types()
    {
        return *s_widgetTypes;
    }

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    static unsigned int s_count;
    static std::vector<LocalWidget*>* s_widgets;
    static WidgetTypeCollection* s_widgetTypes;

    static LocalWidget* createWidget(const QString& name)
    {
        LocalWidget* result = nullptr;

        auto c = name.toStdString();
        int id = QMetaType::type(c.c_str());

        if(id != QMetaType::UnknownType)
        {
            LocalWidget* dock = reinterpret_cast<LocalWidget*>(QMetaType::create(id));

            if(dock)
            {
                result = dock;
            }
            else
            {
                std::cout << "Cannot create " << c << " class" << std::endl;
            }
        }
        else
        {
            std::cout << "Cannot find " << c << " class" << std::endl;
        }

        return result;
    }

    WidgetType* _type;

    WidgetType* type() const;
    void setType(WidgetType* type);
};

#endif // LOCALWIDGET_H
