#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "User.h"

using namespace std;

class AllUsers
{
private:
    vector<User *> All_Users;

public:
    // Constructor and Deconstructor
    AllUsers();

    User *Search(string);
    User *CreateUser(string, string, string, int, int, bool);

    // read from file and save init
    void save();
    void load();
};