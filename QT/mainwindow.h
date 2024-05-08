#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "allproducts.h"
#include "allusers.h"
#include "user.h"

class MainWindow
{
private:
    User *current_user;
    AllUsers Users;
    Allproducts supermarket;

public:
    MainWindow();
    void start();
    ~MainWindow();
};
#endif // MAINWINDOW_H
