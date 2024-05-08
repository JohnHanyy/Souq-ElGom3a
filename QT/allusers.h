#ifndef ALLUSERS_H
#define ALLUSERS_H
#include "user.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AllUsers
{
private:
    vector<User *> All_Users;
    int ind = 0;

public:
    // Constructor and Deconstructor
    AllUsers();
    ~AllUsers();

    User *Search(string);
    User *CreateUser(string, string, string, int, int, bool);

    // read from file and save init
    void save();
    void load();
};
#endif // ALLUSERS_H
