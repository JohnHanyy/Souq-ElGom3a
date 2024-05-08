#include "mainwindow.h"
#include "login.h"
MainWindow::MainWindow()
    : current_user(nullptr)
{
}

void MainWindow::start()
{
    Login L;
    L.show();
}

MainWindow::~MainWindow() {}
