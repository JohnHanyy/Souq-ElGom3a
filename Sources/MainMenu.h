#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "AllUsers.h"
#include "Cart.h"

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
    void HomePage();
    void NavPage();
    void MarketPage();
    void UserPage();
    void CartPage();
    void WalletsPage();
    void Login();
    void Register();
};