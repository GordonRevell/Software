#include "dataviewerwidget.h"
#include "treeitemmodel.h"

#include <QHeaderView>
#include <QSettings>

DataViewerWidget::DataViewerWidget(const QString& title, QWidget* parent) : QDockWidget(title, parent)
{
    setObjectName("DataViewer");

    _items = new std::vector<InternalDataItem*>();

    _root = new InternalDataItem("Name", "Identification", nullptr);

    InternalDataItem* dynoItem = _root->addChild(new InternalDataItem("Dyno", "dyno", _root));
    InternalDataItem* dataItem = _root->addChild(new InternalDataItem("Data", "data", _root));

    dynoItem->addChild(new InternalDataItem("Speed", "dyno/speed", dynoItem));
    dynoItem->addChild(new InternalDataItem("Force", "dyno/force", dynoItem));
    dynoItem->addChild(new InternalDataItem("Accel", "dyno/accel", dynoItem));

    _treeView = new QTreeView(this);

    _model = new TreeItemModel(_root);

    _treeView->setModel(_model);

    setWidget(_treeView);

    QSettings settings;

    settings.beginGroup("DataViewer");
    QByteArray state = settings.value("headerState").toByteArray();
    settings.endGroup();

    _treeView->header()->restoreState(state);
}

DataViewerWidget::DataViewerWidget(QWidget* parent) : DataViewerWidget("Data Viewer", parent)
{
}

DataViewerWidget::~DataViewerWidget()
{
    QByteArray state = _treeView->header()->saveState();
    QSettings settings;

    settings.beginGroup("DataViewer");
    settings.setValue("headerState", state);
    settings.endGroup();

    delete _model;
}
