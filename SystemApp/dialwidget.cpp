#include "dialwidget.h"

bool DialWidget::s_registered = DialWidget::registerType<DialWidget>("DialWidget");

DialWidget::DialWidget(QWidget *parent) : LocalWidget(parent)
{
}
