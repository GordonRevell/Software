#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "explorerwidget.h"
#include "localwidget.h"

#include <QSettings>
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createStatusBar();

    explorer = createExplorer();

    for(WidgetType* t : LocalWidget::types())
    {
        if(t)
        {
            QAction* a = new QAction(t->name());
            QVariant v = qVariantFromValue(reinterpret_cast<void*>(t));

            a->setData(v);

            connect(a, &QAction::triggered, this, &MainWindow::addWidget);

            ui->menuAdd->addAction(a);
        }
    }

    timer = createTimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    saveLayout();

    QMainWindow::closeEvent(event);
}

void MainWindow::showEvent(QShowEvent* event)
{
    QSettings settings;

    settings.beginGroup("MainWindow");

    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    LocalWidget::restore(settings.value("widgets").toByteArray());

    settings.endGroup();

    update();

    QMainWindow::showEvent(event);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::addWidget()
{
    QAction* act = qobject_cast<QAction*>(sender());
    QVariant v = act->data();
    WidgetType* t = reinterpret_cast<WidgetType*>(v.value<void*>());

    if(t)
    {
        QDockWidget* dock = LocalWidget::createLocalWidget(t);

        if(dock)
        {
            addDockWidget(Qt::RightDockWidgetArea, dock);

            dock->setFloating(true);
        }
    }

}

void MainWindow::update()
{
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("dddd, dd-MMM-yyyy hh:mm:ss");

    statusBarTime->setText(dateTimeString);
}

QDockWidget* MainWindow::createExplorer()
{
    auto dock = new ExplorerWidget(this);

    addDockWidget(Qt::LeftDockWidgetArea, dock);

    ui->menuView->addAction(dock->toggleViewAction());

    return dock;
}

QTimer* MainWindow::createTimer()
{
    auto t = new QTimer(this);

    connect(t, &QTimer::timeout, this, &MainWindow::update);

    t->start(1000);

    return t;
}

void MainWindow::createStatusBar()
{
    statusBarTime = new QLabel("21-Sep-1962 10:00:00", this);

    statusBar()->addPermanentWidget(statusBarTime);
}

void MainWindow::saveLayout()
{
    QSettings settings;

    settings.beginGroup("MainWindow");

    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("widgets", LocalWidget::save());

    settings.endGroup();
}
