#include "localwidget.h"

unsigned int LocalWidget::s_count = 0;
std::vector<int> LocalWidget::s_idList;

LocalWidget::LocalWidget(QWidget *parent) : QDockWidget(parent)
{
}

LocalWidget::LocalWidget(const LocalWidget&)
{
}
