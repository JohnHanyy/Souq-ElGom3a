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