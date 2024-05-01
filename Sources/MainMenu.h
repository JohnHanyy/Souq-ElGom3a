#pragma once
#include <iostream>
#include "User.h"
#include "AllUsers.h"
#include "AllProducts.h"
using namespace std;

class MainMenu
{
private:
    User *current_user;
    AllUsers Users;
    Allproducts supermarket;

public:
    MainMenu();
    void Login();
    void Register();
    void Display_Market();
};