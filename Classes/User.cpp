#include "../Sources/User.h"

User::User(string n, int a, string e, string pw, int num, bool adm)
    : Name(n), Age(a), Email(e), Password(pw), Phone_Number(num), admin(adm), ID(ind++)
{
}

// getters
bool User::IsAdmin()
{
    return admin;
}
int User::Get_ID()
{
    return ID;
}

int User::Get_Age()
{
    return Age;
}

int User::Get_Phone_Num()
{
    return Phone_Number;
}

string User::Get_Name()
{
    return Name;
}

string User::Get_Email()
{
    return Email;
}

string User::Get_password()
{
    return Password;
}

// Setters

// void User::Add_Credit_card(int CVV, string card_name, int balance)
// {
//     if (Walletind >= 5)
//     {
//         cout << "The maxmum number of wallets" << endl
//              << "please delete a wallet before trying again" << endl;
//     }
//     else
//     {
//         // Credit_card temp(CVV,card_name,balance);
//         // Credit_cards.push_back(temp);
//     }
// }
void User::Change_Password(string new_password)
{
    Password = new_password;
}
void User::Add_Address(string new_address)
{
    Addresses.push_back(new_address);
}

// Display
void User::User_Display()
{
    cout << "User Name: " << Name << '\t' << "ID: " << ID << endl
         << "Email: " << Email << '\t' << "Age: " << Age << endl;
    if (Phone_Number != -1)
    {
        cout << "Phone Number: " << Phone_Number << endl;
    }
}
// void User::Cart_Display()
// {
//     User_Cart.Display();
// }
// void User::Cards_Display()
// {
//     if (Walletind == 0)
//     {
//         cout << "No Credit Cards added" << endl;
//     }
//     else
//     {
//         cout << "Available Credit Cards" << endl;
//         for (int i = 0; i < Walletind; i++)
//         {
//             Credit_cards[i].Display();
//             cout << "//////////////////////////////////////////////////////////////////////////////\n";
//         }
//     }
// }
User::~User()
{
    delete this;
}