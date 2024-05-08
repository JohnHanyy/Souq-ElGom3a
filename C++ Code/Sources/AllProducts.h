#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
#include <unordered_map>
#include <fstream>
#include "Product.h"

using namespace std;

class Allproducts
{
private:
    unordered_map<string, Product *> prods;

public:
    Allproducts();
    Product *GetProduct(string);
    void CreateProduct(string, float, int);
    void DeleteProduct(string);
    bool Search(string);
    void Refill(string, int);
    void Display();
    void save();
    void load();
};