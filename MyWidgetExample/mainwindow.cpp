#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "OptionsDialog/myoptionsdialog.h"

#include <memory>

#include <QVBoxLayout>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings settings;

    settings.beginGroup("MainWindow");
    restoreGeometry(settings.value("geometry").toByteArray());

    _widget = new TestWidget(this);

    setCentralWidget(_widget);

    _dataViewer = new DataViewerWidget("Data Viewer", this);

    addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, _dataViewer);

    restoreState(settings.value("state").toByteArray());
    settings.endGroup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    QSettings settings;

    settings.beginGroup("MainWindow");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("state", saveState());
    settings.endGroup();

    QMainWindow::closeEvent(event);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionOptions_triggered()
{
    std::unique_ptr<Gordon::MyOptionsDialog> dialog(new Gordon::MyOptionsDialog(this));

    auto result = dialog->exec();

    if(result == QDialog::Accepted)
    {
    }
}
