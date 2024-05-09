#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ewallet
{
private:
    string cardname;
    float balance;
    int cvv;
    int cardnum;

public:
    Ewallet(string n, float b, int pass, int num);

    void addBalance(float amount);

    void charge(float amount);

    void display();

    string getName();

    float getBalance();

    int getCardNumber();

    int getCVV();
};