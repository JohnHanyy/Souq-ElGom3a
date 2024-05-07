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

User *AllUsers::CreateUser(string e, string pw, string n, int a, int num, bool admin)
{
    User *temp = new User(n, a, e, pw, num, admin);
    All_Users.push_back(temp);
    ind++;
    return temp;
}

void AllUsers::save()
{
    ofstream save;
    save.open("allusers.dat", ios::trunc);
    save.close();
    for (int i = 0; i < ind; i++)
    {
        All_Users[i]->save();
    }
    save.open("allusers.dat", ios::app);
    save << endl;
    save.close();
}

void AllUsers::load()
{
}
