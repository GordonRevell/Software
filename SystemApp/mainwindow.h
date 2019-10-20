#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

protected:
    void closeEvent(QCloseEvent* event) override;
    void showEvent(QShowEvent* event) override;

private slots:
    void on_actionExit_triggered();
    void on_actionDial_triggered();

    void update();

private:
    Ui::MainWindow* ui;

    QDockWidget* explorer;
    QTimer* timer;

    QDockWidget* createExplorer();
    QTimer* createTimer();

    QLabel* statusBarTime;
    void createStatusBar();
};

#endif // MAINWINDOW_H
