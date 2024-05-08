#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Ewallet.h"
#include "cart.h"

using namespace std;

class User
{
private:
    int ID;
    string Name;
    string Email;
    string Password;
    int Phone_Number;
    int Age;
    bool admin;
    vector<string> Addresses;
    static int ind;
    vector<Ewallet> Ewallets;
    Cart User_Cart;

public:
    // Constructor and Deconstructor
    User(string, int, string, string, int, bool);

    // Getters
    int Get_ID();
    int Get_Age();
    int Get_Phone_Num();
    string Get_Name();
    string Get_Email();
    string Get_password();
    bool IsAdmin();
    vector<Ewallet> *Get_Cards();
    Ewallet *Get_wallet(string);

    Cart *GetCart();
    bool Pay(string);

    void Add_Credit_card(string, float, int, int);
    void Change_Email(string);
    void Change_Password(string);
    void Add_Address(string);
    void recetcart();
    bool Delete_Wallet(string);
    // Save and load
    void save();
    // Display
    void User_Display();
    void Cards_Display();
    ~User();
};

int User::ind = 0;