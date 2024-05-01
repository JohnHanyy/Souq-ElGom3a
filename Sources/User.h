#pragma once
#include <iostream>
#include <string>
#include <vector>

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
    // vector<Credit_card> Credit_cards;
    // Cart User_Cart;

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
    // Setters
    void Add_Credit_card(int, string, int);
    void Change_Password(string);
    void Add_Address(string);

    // Display
    void User_Display();
    void Cart_Display();
    void Cards_Display();
    ~User();
};

int User::ind = 0;