#ifndef DATAVIEWERWIDGET_H
#define DATAVIEWERWIDGET_H

#include "internaldataitem.h"
#include "treeitemmodel.h"

#include <QObject>
#include <QDockWidget>
#include <QTreeView>

class DataViewerWidget : public QDockWidget
{
    Q_OBJECT

    InternalDataItem* _root;

    QTreeView* _treeView;
    TreeItemModel* _model;

    std::vector<InternalDataItem*>* _items;

public:
    explicit DataViewerWidget(const QString& title, QWidget* parent = nullptr);
    explicit DataViewerWidget(QWidget* parent = nullptr);

    ~DataViewerWidget() override;
};

#endif // DATAVIEWERWIDGET_H
