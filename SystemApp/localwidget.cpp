#include "localwidget.h"

unsigned int LocalWidget::s_count = 0;

LocalWidget::LocalWidget(QWidget *parent) : QDockWidget(parent)
{
}

LocalWidget::LocalWidget(const LocalWidget&)
{
}
