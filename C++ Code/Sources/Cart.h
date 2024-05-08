#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
#include <unordered_map>
#include "Product.h"

using namespace std;

class Cart
{
private:
    float total;
    unordered_map<string, Product *> prods;

public:
    Cart();
    void AddProduct(Product *, int);
    int RemoveProduct(string);
    void CalculateTotal();
    void Display();
    void recetcart();
    float Get_Toltal();
};