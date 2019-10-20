#include "explorerwidget.h"

#include <QFileSystemModel>

ExplorerWidget::ExplorerWidget(QWidget* parent) : QDockWidget(parent)
{
    setObjectName("Explorer");
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setWindowTitle("Explorer");

    treeView = new QTreeView(this);

    setWidget(treeView);

    QFileSystemModel* treeModel = new QFileSystemModel;

    treeModel->setRootPath(QDir::currentPath());
    treeView->setModel(treeModel);
}
