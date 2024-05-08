#include "ewallet.h"
#include <iostream>

using namespace std;

Ewallet::Ewallet(string n, float b, int pass, int num)
    : cardname(n)
    , balance(b)
    , cvv(pass)
    , cardnum(num)
{}

void Ewallet::addBalance(float amount)
{
    balance += amount;
}

void Ewallet::charge(float amount)
{
    balance -= amount;
}

void Ewallet::display()
{
    cout << "card Name: " << cardname << '\t' << "balance: " << balance << '\n'
         << "CVV: " << cvv << '\t' << "card Num: " << cardnum << endl;
}

string Ewallet::getName()
{
    return cardname;
}

float Ewallet::getBalance()
{
    return balance;
}

int Ewallet::getCardNumber()
{
    return cardnum;
}

int Ewallet::getCVV()
{
    return cvv;
}
