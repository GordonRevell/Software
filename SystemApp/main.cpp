#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QCoreApplication::setOrganizationName("Gordon");
    QCoreApplication::setOrganizationDomain("gordon.com");
    QCoreApplication::setApplicationName("SystemApp");

    w.show();

    return a.exec();
}
