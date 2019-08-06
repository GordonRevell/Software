#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "testwidget.h"
#include "dataviewerwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    TestWidget* _widget;
    DataViewerWidget* _dataViewer;

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_actionExit_triggered();

    void on_actionOptions_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
