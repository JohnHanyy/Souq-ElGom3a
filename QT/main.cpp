#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login l;
    l.show();
    // MainWindow m;
    // m.start();
    return a.exec();
}
