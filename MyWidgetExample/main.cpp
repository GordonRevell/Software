#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationDomain("OrgDomain");
    QCoreApplication::setOrganizationName("OrgName");
    QCoreApplication::setApplicationName("AppName");
    QCoreApplication::setApplicationVersion("1.0.0");

    MainWindow w;

    w.show();

    return a.exec();
}
