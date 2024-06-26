#include "../Sources/User.h"

User::User(string n, int a, string e, string pw, int num, bool adm)
    : Name(n), Age(a), Email(e), Password(pw), Phone_Number(num), admin(adm), ID(ind++)
{
}

User::~User()
{
    delete this;
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

Ewallet *User::Get_wallet(string Wname)
{
    for (int i = 0; i < Ewallets.size(); i++)
    {
        if (Ewallets[i].getName() == Wname)
        {
            return &Ewallets[i];
        }
    }
    return nullptr;
}

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

void User::Cards_Display()
{
    for (int i = 0; i < Ewallets.size(); i++)
    {
        cout << "Wallet Number " << i + 1 << endl;
        Ewallets[i].display();
    }
}

vector<Ewallet> *User::Get_Cards()
{
    return &Ewallets;
}

void User::Add_Credit_card(string name, float balance, int CVV, int Card_Number)
{
    Ewallet *temp = new Ewallet(name, balance, CVV, Card_Number);
    Ewallets.push_back(*temp);
}

bool User::Delete_Wallet(string W_Name)
{
    for (int i = 0; i < Ewallets.size(); i++)
    {
        if (Ewallets[i].getName() == W_Name)
        {
            Ewallets.erase(Ewallets.begin() + i);
            return true;
        }
    }
    return false;
}

bool User::Pay(string name)
{
    if (Get_wallet(name)->getBalance() >= User_Cart.Get_Toltal())
    {
        Get_wallet(name)->charge(User_Cart.Get_Toltal());
        return 1;
    }
    else
    {
        return 0;
    }
}

Cart *User::GetCart()
{
    return &User_Cart;
}

// Save and Load
void User::save()
{
    fstream save;
    save.open("allusers.dat", ios::app);
    save << Name << '\t' << Email
         << '\t' << Password << '\t' << ID
         << '\t' << Age << '\t' << Phone_Number
         << '\t' << admin << '\t' << Ewallets.size();
    for (int j = 0; j < Ewallets.size(); j++)
    {
        save << '\t' << Ewallets[j].getName() << '\t'
             << Ewallets[j].getBalance()
             << '\t' << Ewallets[j].getCardNumber()
             << '\t' << Ewallets[j].getCVV();
    }
    save.close();
}

void User::resetcart()
{
    User_Cart.resetcart();
}

void User::Change_Email(string n)
{
    Email = n;
}
