#ifndef EXPLORERWIDGET_H
#define EXPLORERWIDGET_H

#include <QDockWidget>
#include <QTreeView>

class ExplorerWidget : public QDockWidget
{
public:
    ExplorerWidget(QWidget* parent = nullptr);

private:
    QTreeView* treeView;
};

#endif // EXPLORERWIDGET_H
