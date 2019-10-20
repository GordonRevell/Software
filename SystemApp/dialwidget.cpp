#include "dialwidget.h"

bool DialWidget::s_registered = DialWidget::registerType("Gismo");

DialWidget::DialWidget(QWidget *parent) : LocalWidget(parent)
{
}

DialWidget::DialWidget(const DialWidget& w) : LocalWidget(w)
{
}

bool DialWidget::registerType(QString)
{
    return (qRegisterMetaType<DialWidget>("Test") != QMetaType::UnknownType);
}
