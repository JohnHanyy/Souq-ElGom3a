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
    vector<string> Catrgories;

public:
    Allproducts();
    Product *GetProduct(string);
    void CreateProduct(string, float, int, string);
    void DeleteProduct(string);
    bool Search(string);
    bool findcategory(string);
    void Refill(string, int);
    void Display();
    void DisplayCategory(string);
    void DisplayAllCats();
    void Addcategory(string);
    void save();
    void load();
};