#include "../Sources/AllUsers.h"
AllUsers::AllUsers(){};
User *AllUsers::Search(string find_Email)
{
    for (int i = 0; i < All_Users.size(); i++)
    {
        if (All_Users[i]->Get_Email() == find_Email)
        {
            return All_Users[i];
        }
    }
    return nullptr;
}

AllUsers::~AllUsers()
{
    save();
}

User *AllUsers::CreateUser(string e, string pw, string n, int a, int num, bool admin)
{
    User *temp = new User(n, a, e, pw, num, admin);
    All_Users.push_back(temp);
    ind++;
    return temp;
}

void AllUsers::save()
{
    ofstream save("allusers.dat", std::ios::trunc);
    save.close();
    for (int i = 0; i < ind; i++)
    {
        All_Users[i]->save();
        if (i < ind - 1)
        {
            save.open("allusers.dat", ios::app);
            save << endl;
            save.close();
        }
    }
}

void AllUsers::Display()
{
    for (int i = 0; i < All_Users.size(); i++)
    {
        All_Users[i]->User_Display();
    }
}

void AllUsers::removeuser(int id)
{
    All_Users.erase(All_Users.begin() + id);
}

void AllUsers::load()
{
    int tempID;
    string tempName;
    string tempEmail;
    string tempPassword;
    int tempPhone_Number;
    int tempAge;
    int walletind;
    bool tempAdmin;
    // Ewallets temp variables
    string card_name;
    float card_balance;
    int card_CVV;
    int Card_Number;

    ifstream load;
    load.open("allusers.dat");
    while (!load.eof())
    {
        load >> tempName;
        load >> tempEmail;
        load >> tempPassword;
        load >> tempID;
        load >> tempAge;
        load >> tempPhone_Number;
        load >> tempAdmin;
        load >> walletind;
        CreateUser(tempEmail, tempPassword, tempName, tempAge, tempPhone_Number, tempAdmin);
        for (int i = 0; i < walletind; i++)
        {
            cout << 3;

            load >> card_name;
            load >> card_balance;
            load >> Card_Number;
            load >> card_CVV;
            All_Users[tempID]->Add_Credit_card(card_name, card_balance, card_CVV, Card_Number);
        }
    }
    load.close();
}
