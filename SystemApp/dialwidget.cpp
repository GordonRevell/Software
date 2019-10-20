#include "dialwidget.h"

bool DialWidget::s_registered = DialWidget::registerType<DialWidget>("Test");

DialWidget::DialWidget(QWidget *parent) : LocalWidget(parent)
{
}
